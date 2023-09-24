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

#include QMK_KEYBOARD_H
#include <stdio.h>
#include "../../../qmk_utils/utils.c"

#ifdef OLED_DRIVER_ENABLE
#include "oled.c"
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_split_3x6_3(
            //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            NUM_LAYER,  KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
            //|---BKP--+---Q-----+---W----+----E---+----R---+---T----|                   |--------+--------+--------+--------+--------+--------|
            LCTL_T(KC_ESC),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                   KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_DEL,
            //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
            //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                    NAV_LAYER,SYM_LAYER,KC_SPC,   KC_LGUI, FN_LAYER,KC_LALT
            //`--------------------------'  `--------------------------'

            ),


    [_NUMERIC] = LAYOUT_split_3x6_3(
            //,-----------------------------------------------------.                    ,-----------------------------------------------------.
               _______, KC_TAB,  XXXXXXX, XXXXXXX, ASTERISK,XXXXXXX,                      KC_EQL, KC_7,    KC_8,    KC_9,    XXXXXXX, KC_BSPC,
            //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
               KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      PLUS_SIGN,KC_4,   KC_5,    KC_6,    KC_MINUS, KC_DEL,
            //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
               KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      ASTERISK,KC_1,    KC_2,    KC_3,    KC_SLSH, KC_ENT,
            //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                    KC_COMM,  KC_DOT,  KC_SPC,    KC_LGUI,    KC_0, XXXXXXX
            //`--------------------------'  `--------------------------'
            ),

    [_NAVIGATION] = LAYOUT_split_3x6_3(
            //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            LSALT_TAB,  ALT_TAB, DESKTOP_LEFT,DESKTOP_UP,DESKTOP_RIGHT,KC_INS,            KC_PRINT_SCREEN, XXXXXXX, KC_HOME,  KC_END, XXXXXXX, KC_BSPC,
            //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            MISSION_CONTROL, KC_BSPC, WORD_MODIFIER,  KC_DEL,  KC_ENT, XXXXXXX,           KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, KC_DEL,
            //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_LSFT,     UNDO,      CUT,     COPY,    PASTE, SCREENSHOT,                  ENIE, KC_PGDN, KC_PGUP, XXXXXXX, XXXXXXX, KC_ENT,
            //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                    _______, XXXXXXX, XXXXXXX,     KC_LGUI, XXXXXXX, XXXXXXX
            //`--------------------------'  `--------------------------'
            ),

    [_SYMBOLS] = LAYOUT_split_3x6_3(
            //,-----------------------------------------------------.                    ,-----------------------------------------------------.
               FIRULITO,BANG,    PERCENT, HASHTAG, ASTERISK,XXXXXXX,                      XXXXXXX, DOLLAR,  AB_LLAVE,CE_LLAVE,KC_EQL,  KC_BSPC,
            //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
               ARROBA,  DOLLAR,  KC_GRV,  COMILLA_DOBL,KC_QUOT,XXXXXXX,                   LESS_THAN, AB_PARENT,CE_PARENT,XXXXXXX, KC_MINUS,GREATER,
            //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_LSFT,    KC_BSLS, CARET,   AMPERSAND,PIPE,   XXXXXXX,                      XXXXXXX, AB_CORCHE,CE_CORCHE,XXXXXXX,UNDERSCORE,XXXXXXX,
            //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                    XXXXXXX, _______, XXXXXXX,     XXXXXXX, CONF_LAYER, XXXXXXX
            //`--------------------------'  `--------------------------'
            ),

    [_FN_KEYS] = LAYOUT_split_3x6_3(
            //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            XXXXXXX,ARROBA,LESS_THAN,GREATER,XXXXXXX, XXXXXXX,                            XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4, XXXXXXX,
            //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_LCTL, ARROBA,PLUS_SIGN,KC_MINUS, KC_EQL, XXXXXXX,                          XXXXXXX,   KC_F5,   KC_F6,   KC_F7,   KC_F8, XXXXXXX,
            //->--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX,   KC_F9,  KC_F10,  KC_F11,  KC_F12, XXXXXXX,
            //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              KC_LALT, CONF_LAYER, KC_LGUI,    XXXXXXX, _______, XXXXXXX
            //`--------------------------'  `--------------------------'
            ),

    [_CONFIG] = LAYOUT_split_3x6_3(
            //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            KC_TAB, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, SWITCH_TO_WINDOWS,                KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, PERSONAL_EMAIL_2, PERSONAL_EMAIL_1,
            //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, SWITCH_TO_LINUX,                 XXXXXXX, KC_BTN1, KC_BTN2, KC_BTN3, WORK_EMAIL2, WORK_EMAIL,
            //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            RGB_TOG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, SWITCH_TO_MAC,                   XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, DNI, PHONE_NUMBER,
            //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                XXXXXXX, _______,  XXXXXXX,     XXXXXXX, _______, XXXXXXX
            //`--------------------------'  `--------------------------'
            )
};


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

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
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


char keylog_str[24] = {};

const char code_to_name[60] = {
  ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
  'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
  'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
  '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
  'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
  '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
  if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
      (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
      record->event.key.row, record->event.key.col,
      keycode, name);
}

void oled_render_keylog(void) {
  oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
  /* Show Ctrl-Gui Swap options */
  static const char PROGMEM logo[][2][3] = {
    {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
    {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
  };
  if (status) {
    oled_write_ln_P(logo[0][0], false);
    oled_write_ln_P(logo[0][1], false);
  } else {
    oled_write_ln_P(logo[1][0], false);
    oled_write_ln_P(logo[1][1], false);
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
    oled_render_keylog();
  } else {
    oled_render_logo();
  }
  return false;
}
#endif // OLED_ENABLE
