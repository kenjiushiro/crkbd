/*
   Copyright 2019 @foostan
   Copyright 2020 Drashna Jaelre <@drashna>

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
   */
#pragma once
#include QMK_KEYBOARD_H
#include "quantum.h"
#include <stdio.h>
#include "../../../qmk_utils/utils.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_split_3x6_3(
        //---TAB---|----Q----|----W----|----E----|----R----|----T----|              |----Y----|----U----|----I----|----O----|----P----|---BKP---|
          NUM_LYR,  KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                    KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
        //---ESC---|----A----|----S----|----D----|----F----|----G----|              |----H----|----J----|----K----|----L----|----;----|---DEL---|
         LCTL_T(KC_ESC),KC_A, KC_S,     KC_D,     KC_F,     KC_G,                    KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_DEL,
        //---SFT---|----Z----|----X----|----C----|----V----|----B----|              |----N----|----M----|----,----|----.----|----/----|---ENT---|
         KC_LSFT,   KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                    KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_ENT,
                                            //---NAV---|---SYM---|---SPC---|  |---GUI---|---FNC---|---ALT---|
                                              NAV_LYR,  SYM_LYR,  KC_SPC,      KC_LGUI,  FN_LYR,   KC_LALT
            ),

    [_NUMERIC] = LAYOUT_split_3x6_3(
        //---TAB---|----Q----|----W----|----E----|----R----|----T----|              |----Y----|----U----|----I----|----O----|----P----|---BKP---|
          _______,  KC_TAB,   XXXXXXX,  XXXXXXX,  KC_ASTR, XXXXXXX,                  KC_EQL,   KC_7,     KC_8,     KC_9,     XXXXXXX,  KC_BSPC,
        //---ESC---|----A----|----S----|----D----|----F----|----G----|              |----H----|----J----|----K----|----L----|----;----|---DEL---|
          KC_LCTL,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                 KC_PLUS,  KC_4,     KC_5,     KC_6,     KC_MINUS, KC_DEL,
        //---SFT---|----Z----|----X----|----C----|----V----|----B----|              |----N----|----M----|----,----|----.----|----/----|---ENT---|
          KC_LSFT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                 KC_ASTR,  KC_1,     KC_2,     KC_3,     KC_SLSH,  KC_ENT,
                                            //---NAV---|---SYM---|---SPC---|  |---GUI---|---FNC---|---ALT---|
                                              KC_COMM,  KC_DOT,   KC_SPC,      KC_LGUI,  KC_0,     XXXXXXX
            ),

    [_NAVIGATION] = LAYOUT_split_3x6_3(
        //---TAB---|----Q----|----W----|----E----|----R----|----T----|              |----Y----|----U----|----I----|----O----|----P----|---BKP---|
          LSALT_TAB,ALT_TAB,  PREV_DSK, SHOW_DSK, NEXT_DSK, KC_INS,                  XXXXXXX,  XXXXXXX,  KC_HOME,  KC_END,   XXXXXXX,  KC_BSPC,
        //---ESC---|----A----|----S----|----D----|----F----|----G----|              |----H----|----J----|----K----|----L----|----;----|---DEL---|
          MSN_CTRL, KC_BSPC,  WORD_MOD, KC_DEL,   KC_ENT,   XXXXXXX,                 KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, XXXXXXX,  KC_DEL,
        //---SFT---|----Z----|----X----|----C----|----V----|----B----|              |----N----|----M----|----,----|----.----|----/----|---ENT---|
          KC_LSFT,  UNDO,     CUT,      COPY,     PASTE,    SCREENSHOT,              ENIE,     KC_PGDN,  KC_PGUP,  XXXXXXX,  XXXXXXX,  KC_ENT,
                                            //---NAV---|---SYM---|---SPC---|  |---GUI---|---FNC---|---ALT---|
                                              _______,  XXXXXXX,  XXXXXXX,     KC_LGUI,  XXXXXXX,  XXXXXXX
            ),

    [_SYMBOLS] = LAYOUT_split_3x6_3(
        //---TAB---|----Q----|----W----|----E----|----R----|----T----|              |----Y----|----U----|----I----|----O----|----P----|---BKP---|
          KC_TILDE, KC_EXLM,  KC_PERC,  KC_HASH,  KC_ASTR,  XXXXXXX,                 XXXXXXX,  KC_DLR,   KC_LCBR , KC_RCBR,  KC_EQL,   KC_BSPC,
        //---ESC---|----A----|----S----|----D----|----F----|----G----|              |----H----|----J----|----K----|----L----|----;----|---DEL---|
          KC_AT,    KC_DLR,   KC_GRV,   KC_DQT,   KC_QUOT,  XXXXXXX,                 KC_LT,    KC_LPRN,  KC_RPRN,  XXXXXXX,  KC_MINUS, KC_GT,
        //---SFT---|----Z----|----X----|----C----|----V----|----B----|              |----N----|----M----|----,----|----.----|----/----|---ENT---|
          KC_LSFT,  KC_BSLS,  KC_CIRC,  KC_AMPR,  KC_PIPE,  XXXXXXX,                 XXXXXXX,  KC_LBRC,  KC_RBRC,  XXXXXXX,  KC_UNDS,  XXXXXXX,
                                            //---NAV---|---SYM---|---SPC---|  |---GUI---|---FNC---|---ALT---|
                                              XXXXXXX,  _______,  XXXXXXX,     XXXXXXX,  CONF_LYR, XXXXXXX
            ),

    [_FN_KEYS] = LAYOUT_split_3x6_3(
        //---TAB---|----Q----|----W----|----E----|----R----|----T----|              |----Y----|----U----|----I----|----O----|----P----|---BKP---|
          XXXXXXX,  KC_AT,    KC_LT,    KC_GT,    XXXXXXX,  XXXXXXX,                 XXXXXXX,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    XXXXXXX,
        //---ESC---|----A----|----S----|----D----|----F----|----G----|              |----H----|----J----|----K----|----L----|----;----|---DEL---|
          KC_LCTL,  KC_AT,    KC_PLUS,  KC_MINUS, KC_EQL,   XXXXXXX,                 XXXXXXX,  KC_F5,    KC_F6,    KC_F7,    KC_F8,    XXXXXXX,
        //---SFT---|----Z----|----X----|----C----|----V----|----B----|              |----N----|----M----|----,----|----.----|----/----|---ENT---|
          KC_LSFT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                 XXXXXXX,  KC_F9,    KC_F10,   KC_F11,   KC_F12,   XXXXXXX,
                                            //---NAV---|---SYM---|---SPC---|  |---GUI---|---FNC---|---ALT---|
                                              KC_LALT,  CONF_LYR, KC_LGUI,     XXXXXXX,  _______,  XXXXXXX
            ),

    [_CONFIG] = LAYOUT_split_3x6_3(
        //---TAB---|----Q----|----W----|----E----|----R----|----T----|              |----Y----|----U----|----I----|----O----|----P----|---BKP---|
          KC_TAB,   XXXXXXX,  KC_MS_U,  XXXXXXX,  XXXXXXX,  WIN_LYR,                 KC_WH_L,  KC_WH_D,  KC_WH_U,  KC_WH_R,  EMAIL2,   EMAIL1,
        //---ESC---|----A----|----S----|----D----|----F----|----G----|              |----H----|----J----|----K----|----L----|----;----|---DEL---|
          XXXXXXX,  KC_MS_L,  KC_MS_D,  KC_MS_R,  XXXXXXX,  MAC_LYR,                 XXXXXXX,  KC_BTN1,  KC_BTN2,  KC_BTN3,  WRK_EMAIL2,WRK_EMAIL,
        //---SFT---|----Z----|----X----|----C----|----V----|----B----|              |----N----|----M----|----,----|----.----|----/----|---ENT---|
          QK_BOOT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  LNX_LYR,                 XXXXXXX,  KC_MPRV,  KC_MPLY,  KC_MNXT,  DNI,      PHONE_NUMBER,
                                            //---NAV---|---SYM---|---SPC---|  |---GUI---|---FNC---|---ALT---|
                                              XXXXXXX,  _______,  XXXXXXX,     XXXXXXX,  _______,  XXXXXXX
            )
};

#ifdef OLED_ENABLE
void writeOsName(void) {
  switch (currentOS) {
    case _WINDOWS:
      oled_write_ln_P(PSTR("Windows"), false);
      break;
    case _MAC:
      oled_write_ln_P(PSTR("Mac"), false);
      break;
    case _LINUX:
      oled_write_ln_P(PSTR("Linux"), false);
      break;
  }
}

#define L_BASE 0
#define L_NUMERIC 2
#define L_NAVIGATION 4
#define L_SYMBOLS 8
#define L_FUNCTION_KEYS 16
#define L_MOUSE 32

void oled_render_layer_state(void) {
  oled_write_P(PSTR("Layer: "), false);
  switch (layer_state) {
    case L_BASE:
      writeOsName();
      break;
    case L_NUMERIC:
      oled_write_ln_P(PSTR("Numeric"), false);
      break;
    case L_NAVIGATION:
      oled_write_ln_P(PSTR("Navigation"), false);
      break;
    case L_SYMBOLS:
      oled_write_ln_P(PSTR("Symbols"), false);
      break;
    case L_FUNCTION_KEYS:
      oled_write_ln_P(PSTR("Function Keys"), false);
      break;
    case L_MOUSE:
      oled_write_ln_P(PSTR("Mouse mode"), false);
      break;
    case L_SYMBOLS|L_NUMERIC:
    case L_SYMBOLS|L_NAVIGATION:
    case L_SYMBOLS|L_NUMERIC|L_NAVIGATION:
      oled_write_ln_P(PSTR("Adjust"), false);
      break;
  }
}


void oled_render_logo(void) {
  static const char PROGMEM crkbd_logo[] = {
    0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
    0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
    0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
    0};
  oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    oled_render_layer_state();
  } else {
    oled_render_logo();
  }
  return false;
}
#endif // OLED_ENABLE
