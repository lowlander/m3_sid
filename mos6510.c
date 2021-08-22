/*
 * Copyright (c) 2020 Erwin Rol <erwin@erwinrol.com
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "mos6510.h"

const struct mos6510_opcode mos6510_opcode_table[256] = {
  /* 0x00 */ {MOS6510_TYPE_BRK, MOS6510_MODE_IMP },
  /* 0x01 */ {MOS6510_TYPE_ORA, MOS6510_MODE_INDX },
  /* 0x02 */ {MOS6510_TYPE_XXX, MOS6510_MODE_XXX },
  /* 0x03 */ {MOS6510_TYPE_SLO, MOS6510_MODE_INDX },
  /* 0x04 */ {MOS6510_TYPE_NOP, MOS6510_MODE_ZP },
  /* 0x05 */ {MOS6510_TYPE_ORA, MOS6510_MODE_ZP },
  /* 0x06 */ {MOS6510_TYPE_ASL, MOS6510_MODE_ZP },
  /* 0x07 */ {MOS6510_TYPE_SLO, MOS6510_MODE_ZP },
  /* 0x08 */ {MOS6510_TYPE_PHP, MOS6510_MODE_IMP },
  /* 0x09 */ {MOS6510_TYPE_ORA, MOS6510_MODE_IMM },
  /* 0x0a */ {MOS6510_TYPE_ASL, MOS6510_MODE_ACC },
  /* 0x0b */ {MOS6510_TYPE_ANC, MOS6510_MODE_IMM },
  /* 0x0c */ {MOS6510_TYPE_NOP, MOS6510_MODE_ABS },
  /* 0x0d */ {MOS6510_TYPE_ORA, MOS6510_MODE_ABS },
  /* 0x0e */ {MOS6510_TYPE_ASL, MOS6510_MODE_ABS },
  /* 0x0f */ {MOS6510_TYPE_SLO, MOS6510_MODE_ABS },
  /* 0x10 */ {MOS6510_TYPE_BPL, MOS6510_MODE_REL },
  /* 0x11 */ {MOS6510_TYPE_ORA, MOS6510_MODE_INDY },
  /* 0x12 */ {MOS6510_TYPE_XXX, MOS6510_MODE_XXX },
  /* 0x13 */ {MOS6510_TYPE_SLO, MOS6510_MODE_INDY },
  /* 0x14 */ {MOS6510_TYPE_NOP, MOS6510_MODE_ZPX },
  /* 0x15 */ {MOS6510_TYPE_ORA, MOS6510_MODE_ZPX },
  /* 0x16 */ {MOS6510_TYPE_ASL, MOS6510_MODE_ZPX },
  /* 0x17 */ {MOS6510_TYPE_SLO, MOS6510_MODE_ZPX },
  /* 0x18 */ {MOS6510_TYPE_CLC, MOS6510_MODE_IMP },
  /* 0x19 */ {MOS6510_TYPE_ORA, MOS6510_MODE_ABSY },
  /* 0x1a */ {MOS6510_TYPE_NOP, MOS6510_MODE_ACC },
  /* 0x1b */ {MOS6510_TYPE_SLO, MOS6510_MODE_ABSY },
  /* 0x1c */ {MOS6510_TYPE_NOP, MOS6510_MODE_ABSX },
  /* 0x1d */ {MOS6510_TYPE_ORA, MOS6510_MODE_ABSX },
  /* 0x1e */ {MOS6510_TYPE_ASL, MOS6510_MODE_ABSX },
  /* 0x1f */ {MOS6510_TYPE_SLO, MOS6510_MODE_ABSX },
  /* 0x20 */ {MOS6510_TYPE_JSR, MOS6510_MODE_ABS },
  /* 0x21 */ {MOS6510_TYPE_AND, MOS6510_MODE_INDX },
  /* 0x22 */ {MOS6510_TYPE_XXX, MOS6510_MODE_XXX },
  /* 0x23 */ {MOS6510_TYPE_RLA, MOS6510_MODE_INDX },
  /* 0x24 */ {MOS6510_TYPE_BIT, MOS6510_MODE_ZP },
  /* 0x25 */ {MOS6510_TYPE_AND, MOS6510_MODE_ZP },
  /* 0x26 */ {MOS6510_TYPE_ROL, MOS6510_MODE_ZP },
  /* 0x27 */ {MOS6510_TYPE_RLA, MOS6510_MODE_ZP },
  /* 0x28 */ {MOS6510_TYPE_PLP, MOS6510_MODE_IMP },
  /* 0x29 */ {MOS6510_TYPE_AND, MOS6510_MODE_IMM },
  /* 0x2a */ {MOS6510_TYPE_ROL, MOS6510_MODE_ACC },
  /* 0x2b */ {MOS6510_TYPE_ANC, MOS6510_MODE_IMM },
  /* 0x2c */ {MOS6510_TYPE_BIT, MOS6510_MODE_ABS },
  /* 0x2d */ {MOS6510_TYPE_AND, MOS6510_MODE_ABS },
  /* 0x2e */ {MOS6510_TYPE_ROL, MOS6510_MODE_ABS },
  /* 0x2f */ {MOS6510_TYPE_RLA, MOS6510_MODE_ABS },
  /* 0x30 */ {MOS6510_TYPE_BMI, MOS6510_MODE_REL },
  /* 0x31 */ {MOS6510_TYPE_AND, MOS6510_MODE_INDY },
  /* 0x32 */ {MOS6510_TYPE_XXX, MOS6510_MODE_XXX },
  /* 0x33 */ {MOS6510_TYPE_RLA, MOS6510_MODE_INDY },
  /* 0x34 */ {MOS6510_TYPE_NOP, MOS6510_MODE_ZPX },
  /* 0x35 */ {MOS6510_TYPE_AND, MOS6510_MODE_ZPX },
  /* 0x36 */ {MOS6510_TYPE_ROL, MOS6510_MODE_ZPX },
  /* 0x37 */ {MOS6510_TYPE_RLA, MOS6510_MODE_ZPX },
  /* 0x38 */ {MOS6510_TYPE_SEC, MOS6510_MODE_IMP },
  /* 0x39 */ {MOS6510_TYPE_AND, MOS6510_MODE_ABSY },
  /* 0x3A */ {MOS6510_TYPE_NOP, MOS6510_MODE_ACC },
  /* 0x3B */ {MOS6510_TYPE_RLA, MOS6510_MODE_ABSY },
  /* 0x3C */ {MOS6510_TYPE_NOP, MOS6510_MODE_ABSX },
  /* 0x3D */ {MOS6510_TYPE_AND, MOS6510_MODE_ABSX },
  /* 0x3E */ {MOS6510_TYPE_ROL, MOS6510_MODE_ABSX },
  /* 0x3F */ {MOS6510_TYPE_RLA, MOS6510_MODE_ABSX },
  /* 0x40 */ {MOS6510_TYPE_RTI, MOS6510_MODE_IMP },
  /* 0x41 */ {MOS6510_TYPE_EOR, MOS6510_MODE_INDX },
  /* 0x42 */ {MOS6510_TYPE_XXX, MOS6510_MODE_XXX },
  /* 0x43 */ {MOS6510_TYPE_SRE, MOS6510_MODE_INDX },
  /* 0x44 */ {MOS6510_TYPE_NOP, MOS6510_MODE_ZP },
  /* 0x45 */ {MOS6510_TYPE_EOR, MOS6510_MODE_ZP },
  /* 0x46 */ {MOS6510_TYPE_LSR, MOS6510_MODE_ZP },
  /* 0x47 */ {MOS6510_TYPE_SRE, MOS6510_MODE_ZP },
  /* 0x48 */ {MOS6510_TYPE_PHA, MOS6510_MODE_IMP },
  /* 0x49 */ {MOS6510_TYPE_EOR, MOS6510_MODE_IMM },
  /* 0x4A */ {MOS6510_TYPE_LSR, MOS6510_MODE_ACC },
  /* 0x4B */ {MOS6510_TYPE_ALR, MOS6510_MODE_IMM },
  /* 0x4C */ {MOS6510_TYPE_JMP, MOS6510_MODE_ABS },
  /* 0x4D */ {MOS6510_TYPE_EOR, MOS6510_MODE_ABS },
  /* 0x4E */ {MOS6510_TYPE_LSR, MOS6510_MODE_ABS },
  /* 0x4F */ {MOS6510_TYPE_SRE, MOS6510_MODE_ABS },
  /* 0x50 */ {MOS6510_TYPE_BVC, MOS6510_MODE_REL },
  /* 0x51 */ {MOS6510_TYPE_EOR, MOS6510_MODE_INDY },
  /* 0x52 */ {MOS6510_TYPE_XXX, MOS6510_MODE_XXX },
  /* 0x53 */ {MOS6510_TYPE_SRE, MOS6510_MODE_INDY },
  /* 0x54 */ {MOS6510_TYPE_NOP, MOS6510_MODE_ZPX },
  /* 0x55 */ {MOS6510_TYPE_EOR, MOS6510_MODE_ZPX },
  /* 0x56 */ {MOS6510_TYPE_LSR, MOS6510_MODE_ZPX },
  /* 0x57 */ {MOS6510_TYPE_SRE, MOS6510_MODE_ZPX },
  /* 0x58 */ {MOS6510_TYPE_CLI, MOS6510_MODE_IMP },
  /* 0x59 */ {MOS6510_TYPE_EOR, MOS6510_MODE_ABSY },
  /* 0x5A */ {MOS6510_TYPE_NOP, MOS6510_MODE_ACC },
  /* 0x5B */ {MOS6510_TYPE_SRE, MOS6510_MODE_ABSY },
  /* 0x5C */ {MOS6510_TYPE_NOP, MOS6510_MODE_ABSX },
  /* 0x5D */ {MOS6510_TYPE_EOR, MOS6510_MODE_ABSX },
  /* 0x5E */ {MOS6510_TYPE_LSR, MOS6510_MODE_ABSX },
  /* 0x5F */ {MOS6510_TYPE_SRE, MOS6510_MODE_ABSX },
  /* 0x60 */ {MOS6510_TYPE_RTS, MOS6510_MODE_IMP },
  /* 0x61 */ {MOS6510_TYPE_ADC, MOS6510_MODE_INDX },
  /* 0x62 */ {MOS6510_TYPE_XXX, MOS6510_MODE_XXX },
  /* 0x63 */ {MOS6510_TYPE_RRA, MOS6510_MODE_INDX },
  /* 0x64 */ {MOS6510_TYPE_NOP, MOS6510_MODE_ZP },
  /* 0x65 */ {MOS6510_TYPE_ADC, MOS6510_MODE_ZP },
  /* 0x66 */ {MOS6510_TYPE_ROR, MOS6510_MODE_ZP },
  /* 0x67 */ {MOS6510_TYPE_RRA, MOS6510_MODE_ZP },
  /* 0x68 */ {MOS6510_TYPE_PLA, MOS6510_MODE_IMP },
  /* 0x69 */ {MOS6510_TYPE_ADC, MOS6510_MODE_IMM },
  /* 0x6A */ {MOS6510_TYPE_ROR, MOS6510_MODE_ACC },
  /* 0x6B */ {MOS6510_TYPE_ARR, MOS6510_MODE_IMM },
  /* 0x6C */ {MOS6510_TYPE_JMP, MOS6510_MODE_IND },
  /* 0x6D */ {MOS6510_TYPE_ADC, MOS6510_MODE_ABS },
  /* 0x6E */ {MOS6510_TYPE_ROR, MOS6510_MODE_ABS },
  /* 0x6F */ {MOS6510_TYPE_RRA, MOS6510_MODE_ABS },
  /* 0x70 */ {MOS6510_TYPE_BVS, MOS6510_MODE_REL },
  /* 0x71 */ {MOS6510_TYPE_ADC, MOS6510_MODE_INDY },
  /* 0x72 */ {MOS6510_TYPE_XXX, MOS6510_MODE_XXX },
  /* 0x73 */ {MOS6510_TYPE_RRA, MOS6510_MODE_INDY },
  /* 0x74 */ {MOS6510_TYPE_NOP, MOS6510_MODE_ZPX },
  /* 0x75 */ {MOS6510_TYPE_ADC, MOS6510_MODE_ZPX },
  /* 0x76 */ {MOS6510_TYPE_ROR, MOS6510_MODE_ZPX },
  /* 0x77 */ {MOS6510_TYPE_RRA, MOS6510_MODE_ZPX },
  /* 0x78 */ {MOS6510_TYPE_SEI, MOS6510_MODE_IMP },
  /* 0x79 */ {MOS6510_TYPE_ADC, MOS6510_MODE_ABSY },
  /* 0x7A */ {MOS6510_TYPE_NOP, MOS6510_MODE_ACC },
  /* 0x7B */ {MOS6510_TYPE_RRA, MOS6510_MODE_ABSY },
  /* 0x7C */ {MOS6510_TYPE_NOP, MOS6510_MODE_ABSX },
  /* 0x7D */ {MOS6510_TYPE_ADC, MOS6510_MODE_ABSX },
  /* 0x7E */ {MOS6510_TYPE_ROR, MOS6510_MODE_ABSX },
  /* 0x7F */ {MOS6510_TYPE_RRA, MOS6510_MODE_ABSX },
  /* 0x80 */ {MOS6510_TYPE_NOP, MOS6510_MODE_IMM },
  /* 0x81 */ {MOS6510_TYPE_STA, MOS6510_MODE_INDX },
  /* 0x82 */ {MOS6510_TYPE_NOP, MOS6510_MODE_IMM },
  /* 0x83 */ {MOS6510_TYPE_SAX, MOS6510_MODE_INDX },
  /* 0x84 */ {MOS6510_TYPE_STY, MOS6510_MODE_ZP },
  /* 0x85 */ {MOS6510_TYPE_STA, MOS6510_MODE_ZP },
  /* 0x86 */ {MOS6510_TYPE_STX, MOS6510_MODE_ZP },
  /* 0x87 */ {MOS6510_TYPE_SAX, MOS6510_MODE_ZP },
  /* 0x88 */ {MOS6510_TYPE_DEY, MOS6510_MODE_IMP },
  /* 0x89 */ {MOS6510_TYPE_NOP, MOS6510_MODE_IMM },
  /* 0x8A */ {MOS6510_TYPE_TXA, MOS6510_MODE_ACC },
  /* 0x8B */ {MOS6510_TYPE_XAA, MOS6510_MODE_IMM },
  /* 0x8C */ {MOS6510_TYPE_STY, MOS6510_MODE_ABS },
  /* 0x8D */ {MOS6510_TYPE_STA, MOS6510_MODE_ABS },
  /* 0x8E */ {MOS6510_TYPE_STX, MOS6510_MODE_ABS },
  /* 0x8F */ {MOS6510_TYPE_SAX, MOS6510_MODE_ABS },
  /* 0x90 */ {MOS6510_TYPE_BCC, MOS6510_MODE_REL },
  /* 0x91 */ {MOS6510_TYPE_STA, MOS6510_MODE_INDY },
  /* 0x92 */ {MOS6510_TYPE_XXX, MOS6510_MODE_XXX },
  /* 0x93 */ {MOS6510_TYPE_AHX, MOS6510_MODE_INDY },
  /* 0x94 */ {MOS6510_TYPE_STY, MOS6510_MODE_ZPX },
  /* 0x95 */ {MOS6510_TYPE_STA, MOS6510_MODE_ZPX },
  /* 0x96 */ {MOS6510_TYPE_STX, MOS6510_MODE_ZPY },
  /* 0x97 */ {MOS6510_TYPE_SAX, MOS6510_MODE_ZPY },
  /* 0x98 */ {MOS6510_TYPE_TYA, MOS6510_MODE_IMP },
  /* 0x99 */ {MOS6510_TYPE_STA, MOS6510_MODE_ABSY },
  /* 0x9A */ {MOS6510_TYPE_TXS, MOS6510_MODE_ACC },
  /* 0x9B */ {MOS6510_TYPE_TAS, MOS6510_MODE_ABSY },
  /* 0x9C */ {MOS6510_TYPE_SHY, MOS6510_MODE_ABSX },
  /* 0x9D */ {MOS6510_TYPE_STA, MOS6510_MODE_ABSX },
  /* 0x9E */ {MOS6510_TYPE_SHX, MOS6510_MODE_ABSY },
  /* 0x9F */ {MOS6510_TYPE_AHX, MOS6510_MODE_ABSY },
  /* 0xA0 */ {MOS6510_TYPE_LDY, MOS6510_MODE_IMM },
  /* 0xA1 */ {MOS6510_TYPE_LDA, MOS6510_MODE_INDX },
  /* 0xA2 */ {MOS6510_TYPE_LDX, MOS6510_MODE_IMM },
  /* 0xA3 */ {MOS6510_TYPE_LAX, MOS6510_MODE_INDX },
  /* 0xA4 */ {MOS6510_TYPE_LDY, MOS6510_MODE_ZP },
  /* 0xA5 */ {MOS6510_TYPE_LDA, MOS6510_MODE_ZP },
  /* 0xA6 */ {MOS6510_TYPE_LDX, MOS6510_MODE_ZP },
  /* 0xA7 */ {MOS6510_TYPE_LAX, MOS6510_MODE_ZP },
  /* 0xA8 */ {MOS6510_TYPE_TAY, MOS6510_MODE_IMP },
  /* 0xA9 */ {MOS6510_TYPE_LDA, MOS6510_MODE_IMM },
  /* 0xAA */ {MOS6510_TYPE_TAX, MOS6510_MODE_ACC },
  /* 0xAB */ {MOS6510_TYPE_LAX, MOS6510_MODE_IMM },
  /* 0xAC */ {MOS6510_TYPE_LDY, MOS6510_MODE_ABS },
  /* 0xAD */ {MOS6510_TYPE_LDA, MOS6510_MODE_ABS },
  /* 0xAE */ {MOS6510_TYPE_LDX, MOS6510_MODE_ABS },
  /* 0xAF */ {MOS6510_TYPE_LAX, MOS6510_MODE_ABS },
  /* 0xB0 */ {MOS6510_TYPE_BCS, MOS6510_MODE_REL },
  /* 0xB1 */ {MOS6510_TYPE_LDA, MOS6510_MODE_INDY },
  /* 0xB2 */ {MOS6510_TYPE_XXX, MOS6510_MODE_XXX },
  /* 0xB3 */ {MOS6510_TYPE_LAX, MOS6510_MODE_INDY },
  /* 0xB4 */ {MOS6510_TYPE_LDY, MOS6510_MODE_ZPX },
  /* 0xB5 */ {MOS6510_TYPE_LDA, MOS6510_MODE_ZPX },
  /* 0xB6 */ {MOS6510_TYPE_LDX, MOS6510_MODE_ZPY },
  /* 0xB7 */ {MOS6510_TYPE_LAX, MOS6510_MODE_ZPY },
  /* 0xB8 */ {MOS6510_TYPE_CLV, MOS6510_MODE_IMP },
  /* 0xB9 */ {MOS6510_TYPE_LDA, MOS6510_MODE_ABSY },
  /* 0xBA */ {MOS6510_TYPE_TSX, MOS6510_MODE_ACC },
  /* 0xBB */ {MOS6510_TYPE_LAS, MOS6510_MODE_ABSY },
  /* 0xBC */ {MOS6510_TYPE_LDY, MOS6510_MODE_ABSX },
  /* 0xBD */ {MOS6510_TYPE_LDA, MOS6510_MODE_ABSX },
  /* 0xBE */ {MOS6510_TYPE_LDX, MOS6510_MODE_ABSY },
  /* 0xBF */ {MOS6510_TYPE_LAX, MOS6510_MODE_ABSY },
  /* 0xC0 */ {MOS6510_TYPE_CPY, MOS6510_MODE_IMM },
  /* 0xC1 */ {MOS6510_TYPE_CMP, MOS6510_MODE_INDX },
  /* 0xC2 */ {MOS6510_TYPE_NOP, MOS6510_MODE_IMM },
  /* 0xC3 */ {MOS6510_TYPE_DCP, MOS6510_MODE_INDX },
  /* 0xC4 */ {MOS6510_TYPE_CPY, MOS6510_MODE_ZP },
  /* 0xC5 */ {MOS6510_TYPE_CMP, MOS6510_MODE_ZP },
  /* 0xC6 */ {MOS6510_TYPE_DEC, MOS6510_MODE_ZP },
  /* 0xC7 */ {MOS6510_TYPE_DCP, MOS6510_MODE_ZP },
  /* 0xC8 */ {MOS6510_TYPE_INY, MOS6510_MODE_IMP },
  /* 0xC9 */ {MOS6510_TYPE_CMP, MOS6510_MODE_IMM },
  /* 0xCA */ {MOS6510_TYPE_DEX, MOS6510_MODE_ACC },
  /* 0xCB */ {MOS6510_TYPE_AXS, MOS6510_MODE_IMM },
  /* 0xCC */ {MOS6510_TYPE_CPY, MOS6510_MODE_ABS },
  /* 0xCD */ {MOS6510_TYPE_CMP, MOS6510_MODE_ABS },
  /* 0xCE */ {MOS6510_TYPE_DEC, MOS6510_MODE_ABS },
  /* 0xCF */ {MOS6510_TYPE_DCP, MOS6510_MODE_ABS },
  /* 0xD0 */ {MOS6510_TYPE_BNE, MOS6510_MODE_REL },
  /* 0xD1 */ {MOS6510_TYPE_CMP, MOS6510_MODE_INDY },
  /* 0xD2 */ {MOS6510_TYPE_XXX, MOS6510_MODE_XXX },
  /* 0xD3 */ {MOS6510_TYPE_DCP, MOS6510_MODE_INDY },
  /* 0xD4 */ {MOS6510_TYPE_NOP, MOS6510_MODE_ZPX },
  /* 0xD5 */ {MOS6510_TYPE_CMP, MOS6510_MODE_ZPX },
  /* 0xD6 */ {MOS6510_TYPE_DEC, MOS6510_MODE_ZPX },
  /* 0xD7 */ {MOS6510_TYPE_DCP, MOS6510_MODE_ZPX },
  /* 0xD8 */ {MOS6510_TYPE_CLD, MOS6510_MODE_IMP },
  /* 0xD9 */ {MOS6510_TYPE_CMP, MOS6510_MODE_ABSY },
  /* 0xDA */ {MOS6510_TYPE_NOP, MOS6510_MODE_ACC },
  /* 0xDB */ {MOS6510_TYPE_DCP, MOS6510_MODE_ABSY },
  /* 0xDC */ {MOS6510_TYPE_NOP, MOS6510_MODE_ABSX },
  /* 0xDD */ {MOS6510_TYPE_CMP, MOS6510_MODE_ABSX },
  /* 0xDE */ {MOS6510_TYPE_DEC, MOS6510_MODE_ABSX },
  /* 0xDF */ {MOS6510_TYPE_DCP, MOS6510_MODE_ABSX },
  /* 0xE0 */ {MOS6510_TYPE_CPX, MOS6510_MODE_IMM },
  /* 0xE1 */ {MOS6510_TYPE_SBC, MOS6510_MODE_INDX },
  /* 0xE2 */ {MOS6510_TYPE_NOP, MOS6510_MODE_IMM },
  /* 0xE3 */ {MOS6510_TYPE_ISC, MOS6510_MODE_INDX },
  /* 0xE4 */ {MOS6510_TYPE_CPX, MOS6510_MODE_ZP },
  /* 0xE5 */ {MOS6510_TYPE_SBC, MOS6510_MODE_ZP },
  /* 0xE6 */ {MOS6510_TYPE_INC, MOS6510_MODE_ZP },
  /* 0xE7 */ {MOS6510_TYPE_ISC, MOS6510_MODE_ZP },
  /* 0xE8 */ {MOS6510_TYPE_INX, MOS6510_MODE_IMP },
  /* 0xE9 */ {MOS6510_TYPE_SBC, MOS6510_MODE_IMM },
  /* 0xEA */ {MOS6510_TYPE_NOP, MOS6510_MODE_ACC },
  /* 0xEB */ {MOS6510_TYPE_SBC, MOS6510_MODE_IMM },
  /* 0xEC */ {MOS6510_TYPE_CPX, MOS6510_MODE_ABS },
  /* 0xED */ {MOS6510_TYPE_SBC, MOS6510_MODE_ABS },
  /* 0xEE */ {MOS6510_TYPE_INC, MOS6510_MODE_ABS },
  /* 0xEF */ {MOS6510_TYPE_ISC, MOS6510_MODE_ABS },
  /* 0xF0 */ {MOS6510_TYPE_BEQ, MOS6510_MODE_REL },
  /* 0xF1 */ {MOS6510_TYPE_SBC, MOS6510_MODE_INDY },
  /* 0xF2 */ {MOS6510_TYPE_XXX, MOS6510_MODE_XXX },
  /* 0xF3 */ {MOS6510_TYPE_ISC, MOS6510_MODE_INDY },
  /* 0xF4 */ {MOS6510_TYPE_NOP, MOS6510_MODE_ZPX },
  /* 0xF5 */ {MOS6510_TYPE_SBC, MOS6510_MODE_ZPX },
  /* 0xF6 */ {MOS6510_TYPE_INC, MOS6510_MODE_ZPX },
  /* 0xF7 */ {MOS6510_TYPE_ISC, MOS6510_MODE_ZPX },
  /* 0xF8 */ {MOS6510_TYPE_SED, MOS6510_MODE_IMP },
  /* 0xF9 */ {MOS6510_TYPE_SBC, MOS6510_MODE_ABSY },
  /* 0xFA */ {MOS6510_TYPE_NOP, MOS6510_MODE_ACC },
  /* 0xFB */ {MOS6510_TYPE_ISC, MOS6510_MODE_ABSY },
  /* 0xFC */ {MOS6510_TYPE_NOP, MOS6510_MODE_ABSX },
  /* 0xFD */ {MOS6510_TYPE_SBC, MOS6510_MODE_ABSX },
  /* 0xFE */ {MOS6510_TYPE_INC, MOS6510_MODE_ABSX },
  /* 0xFF */ {MOS6510_TYPE_ISC, MOS6510_MODE_ABSX },
};
