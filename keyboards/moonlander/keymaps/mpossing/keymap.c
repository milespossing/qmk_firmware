/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */



#include QMK_KEYBOARD_H
#include "version.h"
#include "mpossing.h"

enum custom_keycodes {
    VRSN = ML_SAFE_RANGE,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_moonlander_home(
          KC_TAB, __QWERTY_L1__, __QWERTY_R1__, XXXXXXX,
         KC_CESC, __QWERTY_L2__, __QWERTY_R2__, KC_QUOT,
         KC_LSPO, __QWERTY_L3__, __QWERTY_R3__, KC_RSPC
    ),
    [_RAISE] = LAYOUT_moonlander_common(
        __RAISE_L1__, __RAISE_R1__, \
        __RAISE_L2__, __RAISE_R2__, \
        __RAISE_L3__, __RAISE_R3__  \
    ),
    [_LOWER] = LAYOUT_moonlander_basic(
                                                    __EMPTY__, XXXXXXX,            XXXXXXX,                                          __EMPTY__, // 14
         KC_TAB,                                __QWERTY_L1__, XXXXXXX,            XXXXXXX,   XXXXXXX,   KC_P7,   KC_P8,   KC_P9, XXXXXXX, XXXXXXX, //14
        KC_CESC,                                __QWERTY_L2__, XXXXXXX,            XXXXXXX,   XXXXXXX,   KC_P4,   KC_P5,   KC_P6, XXXXXXX, XXXXXXX, //14
        KC_LSFT,                                __QWERTY_L3__,                                XXXXXXX,   KC_P1,   KC_P2,   KC_P3, XXXXXXX, XXXXXXX, //12 // makes 36
        KC_LCTL, XXXXXXX, XXXXXXX, KC_LALT, KC_LGUI,            KC_ENT,            XXXXXXX,              KC_P0,   KC_P0, XXXXXXX, XXXXXXX, XXXXXXX, //12 // makes 48
                                              KC_SPC, XXXXXXX, XXXXXXX,            XXXXXXX, XXXXXXX,  KC_ENT                                        //06  // makes 54
    ),
    [_ADJUST] = LAYOUT_moonlander_common(
        ______________________RGB_CTRL______________________,  _______________________EMPTY________________________,\
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TG_GAME,  XXXXXXX, AG_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
        KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT \
    ),
    [_GAME] = LAYOUT_moonlander_basic(
                                            __NUM_ROW_LEFT__, XXXXXXX,             XXXXXXX,  __NUM_ROW_RGHT__, // 14
        KC_TAB,                                __QWERTY_L1__, XXXXXXX,             XXXXXXX,     __QWERTY_R1__,                            XXXXXXX, //14
        KC_ESC,                                __QWERTY_L2__, XXXXXXX,             XXXXXXX,     __QWERTY_R2__,                            KC_QUOT, //14
        KC_LSFT,                               __QWERTY_L3__,                                   __QWERTY_R3__,                            XXXXXXX, //12 // makes 36
        KC_LCTL, XXXXXXX, XXXXXXX, KC_LALT, KC_LGUI,           KC_ENT,         TO(_QWERTY),           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, //12 // makes 48
                                             KC_SPC, XXXXXXX, XXXXXXX,             XXXXXXX, XXXXXXX, XXXXXXX                                       //6  // makes 54
    ),

    [_MEDIA] = LAYOUT_moonlander_common(__MEDIA_ALL__)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
        case VRSN:
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            return false;
        }
    }
    return true;
}
