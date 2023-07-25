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

#ifdef OLED_DRIVER_ENABLE
#include "oled.c"
#endif

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

enum OS {
  _MAC,
  _WINDOWS,
  _LINUX,
};

int currentOS = _WINDOWS;

enum layers {
  _QWERTY,
  _NUMERIC,
  _NAVIGATION,
  _SYMBOLS,
  _FN_KEYS,
  _CONFIG,
};

enum custom_keycodes  {
  GMAIL_EMAIL = SAFE_RANGE,
  LIVE_EMAIL,
  WORK_EMAIL,
  WORK_EMAIL2,
  DNI,
  PHONE_NUMBER,
  ALT_TAB,
  LSALT_TAB,
  DESKTOP_LEFT,
  DESKTOP_RIGHT,
  DESKTOP_UP,
  SWITCH_TO_MAC,
  SWITCH_TO_WINDOWS,
  SWITCH_TO_LINUX,
  WORD_MODIFIER,
  UNDO,
  CUT,
  COPY,
  PASTE,
  SCREENSHOT,
  ENIE,
  MISSION_CONTROL,
};


#define NUM_LAYER LT(_NUMERIC, KC_TAB)
#define NAV_LAYER MO(_NAVIGATION)
#define SYM_LAYER MO(_SYMBOLS)
#define FN_LAYER MO(_FN_KEYS)
#define CONF_LAYER MO(_CONFIG)
#define PLUS_SIGN LSFT(KC_EQL)
#define ASTERISK LSFT(KC_8)
#define BANG LSFT(KC_1)
#define PERCENT LSFT(KC_5)
#define HASHTAG LSFT(KC_3)
#define FIRULITO LSFT(KC_GRV)
#define CARET LSFT(KC_6)
#define AMPERSAND LSFT(KC_7)
#define ARROBA LSFT(KC_2)
#define DOLLAR LSFT(KC_4)
#define PIPE LSFT(KC_BSLS)
#define COMILLA_SIMP KC_QUOT
#define COMILLA_DOBL LSFT(KC_QUOT)
#define AB_PARENT LSFT(KC_9)
#define CE_PARENT LSFT(KC_0)
#define AB_CORCHE KC_LBRC
#define CE_CORCHE KC_RBRC
#define AB_LLAVE LSFT(KC_LBRC)
#define CE_LLAVE LSFT(KC_RBRC)
#define UNDERSCORE LSFT(KC_MINUS)
#define GREATER LSFT(KC_DOT)
#define LESS_THAN LSFT(KC_COMM)


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
            KC_TAB, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, SWITCH_TO_WINDOWS,                KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, LIVE_EMAIL, GMAIL_EMAIL,
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

void mission_control(void) {
  switch (currentOS) {
    case _WINDOWS:
      register_code(KC_LALT);
      tap_code(KC_SPC);
      unregister_code(KC_LALT);
      break;
    case _MAC:
      register_code(KC_LGUI);
      tap_code(KC_SPC);
      unregister_code(KC_LGUI);
      break;
    case _LINUX:
      tap_code(KC_LGUI);
      break;
  }
}

void register_desktop_switch_modifier(void) {
  switch (currentOS) {
    case _MAC:
      register_code(KC_LCTL);
      break;
    case _WINDOWS:
    case _LINUX:
      register_code(KC_LCTL);
      register_code(KC_LGUI);
      break;
  }
}

void unregister_desktop_switch_modifier(void) {
  switch (currentOS) {
    case _MAC:
      unregister_code(KC_LCTL);
      break;
    case _WINDOWS:
    case _LINUX:
      unregister_code(KC_LCTL);
      unregister_code(KC_LGUI);
      break;
  }
}

void previous_desktop(void) {
  register_desktop_switch_modifier();
  if (currentOS == _LINUX) {
    tap_code(KC_UP);
  } else {
    tap_code(KC_LEFT);
  }
  unregister_desktop_switch_modifier();
}

void next_desktop(void) {
  register_desktop_switch_modifier();
  if (currentOS == _LINUX) {
    tap_code(KC_DOWN);
  } else {
    tap_code(KC_RIGHT);
  }
  unregister_desktop_switch_modifier();
}

void show_desktops(void) {
  if (currentOS == _LINUX) {
    register_code(KC_LGUI);
    tap_code(KC_D);
    unregister_code(KC_LGUI);
  } else if (currentOS == _WINDOWS) {
    register_code(KC_LGUI);
    tap_code(KC_TAB);
    unregister_code(KC_LGUI);
  } else if (currentOS == _MAC) {
    register_code(KC_LCTL);
    tap_code(KC_UP);
    unregister_code(KC_LCTL);
  }
}

void register_alt_tab_modifier(void) {
  switch (currentOS) {
    case _MAC:
      register_code(KC_LGUI);
      break;
    case _WINDOWS:
    case _LINUX:
      register_code(KC_LALT);
      break;
  }
}

void unregister_alt_tab_modifier(void) {
  switch (currentOS) {
    case _MAC:
      unregister_code(KC_LGUI);
      break;
    case _WINDOWS:
    case _LINUX:
      unregister_code(KC_LALT);
      break;
  }
}

void hold_word_modifier(void) {
  switch (currentOS) {
    case _MAC:
      register_code(KC_LALT);
      break;
    case _WINDOWS:
    case _LINUX:
      register_code(KC_LCTL);
      break;
  }
}

void release_word_modifier(void) {
  switch (currentOS) {
    case _MAC:
      unregister_code(KC_LALT);
      break;
    case _WINDOWS:
    case _LINUX:
      unregister_code(KC_LCTL);
      break;
  }
}

void undo(void) {
  switch (currentOS) {
    case _MAC:
      register_code(KC_LGUI);
      tap_code(KC_Z);
      unregister_code(KC_LGUI);
      break;
    case _WINDOWS:
    case _LINUX:
      register_code(KC_LCTL);
      tap_code(KC_Z);
      unregister_code(KC_LCTL);
      break;
  }
}

void cut(void) {
  switch (currentOS) {
    case _MAC:
      register_code(KC_LGUI);
      tap_code(KC_X);
      unregister_code(KC_LGUI);
      break;
    case _WINDOWS:
    case _LINUX:
      register_code(KC_LCTL);
      tap_code(KC_X);
      unregister_code(KC_LCTL);
      break;
  }
}

void copy(void) {
  switch (currentOS) {
    case _MAC:
      register_code(KC_LGUI);
      tap_code(KC_C);
      unregister_code(KC_LGUI);
      break;
    case _WINDOWS:
    case _LINUX:
      register_code(KC_LCTL);
      tap_code(KC_C);
      unregister_code(KC_LCTL);
      break;
  }
}

void paste(void) {
  switch (currentOS) {
    case _MAC:
      register_code(KC_LGUI);
      tap_code(KC_V);
      unregister_code(KC_LGUI);
      break;
    case _WINDOWS:
    case _LINUX:
      register_code(KC_LCTL);
      tap_code(KC_V);
      unregister_code(KC_LCTL);
      break;
  }
}

void screenshot(void) {
  switch (currentOS) {
    case _MAC:
      register_code(KC_LGUI);
      register_code(KC_LSFT);
      tap_code(KC_X);
      unregister_code(KC_LGUI);
      unregister_code(KC_LSFT);
      break;
    case _WINDOWS:
    case _LINUX:
      tap_code(KC_PSCR);
      break;
  }
}

void enie(void) {
  switch (currentOS) {
    case _MAC:
      register_code(KC_LALT);
      tap_code(KC_N);
      unregister_code(KC_LALT);
      tap_code(KC_N);
      break;
    case _WINDOWS:
      register_code(KC_LALT);
      tap_code(KC_KP_0);
      tap_code(KC_KP_2);
      tap_code(KC_KP_4);
      tap_code(KC_KP_1);
      unregister_code(KC_LALT);
      break;
    case _LINUX:
      break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case GMAIL_EMAIL:
      if (record->event.pressed) {
        SEND_STRING("kenjimartinushiro@gmail.com");
      }
      return false;
      break;
    case LIVE_EMAIL:
      if (record->event.pressed) {
        SEND_STRING("kenjiushiro@live.com");
      }
      return false;
      break;
    case WORK_EMAIL:
      if (record->event.pressed) {
        SEND_STRING("workemail1@work.com");
      }
      return false;
      break;
    case WORK_EMAIL2:
      if (record->event.pressed) {
        SEND_STRING("workemail2@work.com");
      }
      return false;
      break;
    case DNI:
      if (record->event.pressed) {
        SEND_STRING("38521991");
      }
      return false;
      break;
    case PHONE_NUMBER:
      if (record->event.pressed) {
        SEND_STRING("1164484715");
      }
      return false;
      break;
    case ENIE:
      if (record->event.pressed) {
        enie();
      }
      return false;
      break;
    case MISSION_CONTROL:
      if (record->event.pressed) {
        mission_control();
      }
      return false;
      break;
    case ALT_TAB:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_alt_tab_modifier();
        }
        alt_tab_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      break;
    case LSALT_TAB:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        alt_tab_timer = timer_read();
        register_code(KC_LSFT);
        register_code(KC_TAB);
        unregister_code(KC_LSFT);
      } else {
        unregister_code(KC_TAB);
      }
      break;
    case SCREENSHOT:
      if (record->event.pressed) {
        screenshot();
        return false;
      }
      break;

    case DESKTOP_LEFT:
      if (record->event.pressed) {
        previous_desktop();
      }
      return false;
      break;
    case DESKTOP_RIGHT:
      if (record->event.pressed) {
        next_desktop();
      }
      return false;
      break;
    case DESKTOP_UP:
      if (record->event.pressed) {
        show_desktops();
      }
      return false;
      break;
    case SWITCH_TO_MAC:
      if (record->event.pressed) {
        currentOS = _MAC;
      }
      return false;
      break;
    case SWITCH_TO_WINDOWS:
      if (record->event.pressed) {
        currentOS = _WINDOWS;
      }
      return false;
      break;
    case SWITCH_TO_LINUX:
      if (record->event.pressed) {
        currentOS = _LINUX;
      }
      return false;
      break;
    case WORD_MODIFIER:
      if (record->event.pressed) {
        hold_word_modifier();
      } else {
        release_word_modifier();
      }
      return false;
      break;
    case UNDO:
      if (record->event.pressed) {
        undo();
      }
      return false;
      break;
    case CUT:
      if (record->event.pressed) {
        cut();
      }
      return false;
      break;
    case COPY:
      if (record->event.pressed) {
        copy();
      }
      return false;
      break;
    case PASTE:
      if (record->event.pressed) {
        paste();
      }
      return false;
      break;

  }
  return true;
}

void matrix_scan_user(void) { // The very important timer.
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 866) {
      unregister_alt_tab_modifier();
      is_alt_tab_active = false;
    }
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
