/*
 * Copyright (c) 2021 Erwin Rol <erwin@erwinrol.com
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "hal.h"
#include "hw_reg_access.h"
#include "drivers/mss_gpio/mss_gpio.h"
#include "drivers/mss_uart/mss_uart.h"
#include "drivers/mss_timer/mss_timer.h"
#include "CMSIS/system_m2sxxx.h"
#include "SID_PLAYER_hw_platform.h"

#include "c64.h"
#include "sid.h"
#include "sid_file.h"

static struct sid_info info;

static void delay(void)
{
    volatile uint32_t delay_count = SystemCoreClock / 128u;

    while(delay_count > 0u)
    {
        --delay_count;
    }
}

void main(void)
{
	SystemCoreClockUpdate();
    MSS_GPIO_init();

    MSS_GPIO_config( MSS_GPIO_0 , MSS_GPIO_OUTPUT_MODE );
    MSS_GPIO_config( MSS_GPIO_1 , MSS_GPIO_OUTPUT_MODE );
    MSS_GPIO_config( MSS_GPIO_2 , MSS_GPIO_OUTPUT_MODE );
    MSS_GPIO_config( MSS_GPIO_3 , MSS_GPIO_OUTPUT_MODE );
    MSS_GPIO_config( MSS_GPIO_4 , MSS_GPIO_OUTPUT_MODE );
    MSS_GPIO_config( MSS_GPIO_5 , MSS_GPIO_OUTPUT_MODE );
    MSS_GPIO_config( MSS_GPIO_6 , MSS_GPIO_OUTPUT_MODE );
    MSS_GPIO_config( MSS_GPIO_7 , MSS_GPIO_OUTPUT_MODE );

    MSS_GPIO_config( MSS_GPIO_9 , MSS_GPIO_OUTPUT_MODE );

    MSS_GPIO_set_outputs( 0 );

    // reset SID
    HW_set_32bit_reg(SID_BRIDGE_0 + 0x00, 0);
    delay();
    HW_set_32bit_reg(SID_BRIDGE_0 + 0x00, 1);


    // clear the whole SID
    for (uint8_t addr = 0; addr < 0x19; addr++) {
    	sid_poke( addr, 0);
    }

    c64_init();

    sid_load_from_memory(sid_file, sid_file_size, &info);

    sid_poke(24, 15); // volume at max

    c64_cpu_jsr(info.init_addr, 0);

    MSS_TIM1_init(MSS_TIMER_PERIODIC_MODE);
    MSS_TIM1_load_immediate(g_FrequencyPCLK0 / 50);
    MSS_TIM1_start();
    MSS_TIM1_enable_irq();

    uint8_t leds = 0x00;
    while(1) {
    	delay();
        MSS_GPIO_set_outputs( leds );
        leds = leds == 0 ? 1 : 0;
    }
}

void Timer1_IRQHandler(void)
{
    c64_cpu_jsr(info.play_addr, 0);

    MSS_TIM1_clear_irq();
}
