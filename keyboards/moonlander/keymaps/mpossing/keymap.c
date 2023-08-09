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

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_moonlander_home(
         __QWERTY_WL1__, __QWERTY_WR1__,
         __QWERTY_WL2__, __QWERTY_WR2__,
         __QWERTY_WL3__, __QWERTY_WR3__
    ),
    [_COLEMAK] = LAYOUT_moonlander_home(
         __COLEMAK_WL1__, __COLEMAK_WR1__,
         __COLEMAK_WL2__, __COLEMAK_WR2__,
         __COLEMAK_WL3__, __COLEMAK_WR3__
    ),
    [_RAISE] = LAYOUT_moonlander_common(
        __RAISE_L1__, __RAISE_R1__, \
        __RAISE_L2__, __RAISE_R2__, \
        __RAISE_L3__, __RAISE_R3__  \
    ),
    [_LOWER] = LAYOUT_moonlander_top(
        _______________________EMPTY________________________, XXXXXXX,            XXXXXXX, _______________________EMPTY________________________, // 14
         KC_TAB, _________________QWERTY_L1_________________, XXXXXXX,            XXXXXXX, XXXXXXX,   KC_P7,   KC_P8,   KC_P9, XXXXXXX, XXXXXXX, //14
        KC_CESC, _________________QWERTY_L2_________________, XXXXXXX,            XXXXXXX, XXXXXXX,   KC_P4,   KC_P5,   KC_P6, XXXXXXX, XXXXXXX, //14
        KC_LSFT, _________________QWERTY_L3_________________,                              XXXXXXX,   KC_P1,   KC_P2,   KC_P3, XXXXXXX, XXXXXXX, //12 // makes 36
        KC_LCTL, XXXXXXX, XXXXXXX, KC_LALT, KC_LGUI,           KC_ENT,            XXXXXXX,            KC_P0,   KC_P0, XXXXXXX, XXXXXXX, XXXXXXX  //12 // makes 48
    ),
    [_ADJUST] = LAYOUT_moonlander_common(
        ______________________RGB_CTRL______________________,  _______________________EMPTY________________________,\
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TG_GAME,  AG_TOGG,  KC_NUM, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
        KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, DF_COLE, DF_QWER, DF_PLOV, XXXXXXX, QK_BOOT \
    ),
    [_PLOVER] = LAYOUT_moonlander_basic(
        _______________________EMPTY________________________, XXXXXXX,           XXXXXXX, _______________________EMPTY________________________,
        _______________________EMPTY________________________, XXXXXXX,           XXXXXXX, _______________________EMPTY________________________,
                                      XXXXXXX, __PLOVER_L1__, XXXXXXX,           XXXXXXX, __PLOVER_R1__,
                                      XXXXXXX, __PLOVER_L2__,                             __PLOVER_R2__,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,           TO(_QWERTY),      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                            XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_GAME] = LAYOUT_moonlander_basic(
                                            __NUM_ROW_LEFT__, XXXXXXX,             XXXXXXX, __NUM_ROW_RGHT__,
        KC_TAB,                                __QWERTY_L1__, XXXXXXX,             XXXXXXX,    __QWERTY_R1__,                            KC_BSPC,
        KC_ESC,                                __QWERTY_L2__, XXXXXXX,             XXXXXXX,    __QWERTY_R2__,                            KC_QUOT,
        KC_LSFT,                               __QWERTY_L3__,                                  __QWERTY_R3__,                            XXXXXXX,
        KC_LCTL, XXXXXXX, XXXXXXX, KC_LALT, KC_LGUI,           KC_ENT,         TO(_QWERTY),          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                             KC_SPC, XXXXXXX, XXXXXXX,             XXXXXXX, MO_RAZE, XXXXXXX
    ),
    [_MEDIA] = LAYOUT_moonlander_common(__MEDIA_ALL__)
};
