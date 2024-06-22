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
#include "mp_complete.h"


#   define layout(...) LAYOUT_moonlander(__VA_ARGS__)
#   define WRAPPER_baselayer(k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, \
                                k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, \
                                k20, k21, k22, k23, k24, k25, k26, k27, k28, k29) \
           LAYOUT_moonlander( \
        KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,                                    KC_5,    KC_LEFT,           KC_RGHT, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
        KC_TAB, k00, k01, k02, k03, k04, XXXXXXX,                                 XXXXXXX, k05, k06, k07, k08, k09, KC_BSPC, \
        KC_CESC,k10, k11, k12, k13, k14, XXXXXXX,                                 VIM_SAV, k15, k16, k17, k18, k19, KC_QUOT, \
        SC_LSPO,k20, k21, k22, k23, k24,                                                   k25, k26, k27, k28, k29, SC_RCPC, \
    LT(_LOWER,KC_GRV),WEBUSB_PAIR,A(KC_LSFT),KC_LGUI, MO_LOWR,  LALT_T(KC_APP),   VIM_SAV, KC_BRSE, KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX, \
                                             KC_SPC,  MO_LOWR, KC_LGUI,           KC_BSPC,  MO_RAZE,  KC_ENT)
# define baselayer(...) WRAPPER_baselayer(__VA_ARGS__)


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = baselayer(__QWERTY__),
    [_COLEMAK] = baselayer(__COLEMAK__),
    [_LOWER] = layout(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______,  _______, _______,
                                           __NUM_ROW_LEFT__ , _______,           _______,                                      __NUM_ROW_RGHT__,
        _______, _______, KC_MPRV, KC_VOLU, KC_MPLY, KC_MNXT, _______,           _______, _______,    KC_4,    KC_5,    KC_6,  _______, _______,
        KC_LSFT, _______, _______, KC_VOLD, _______, _______,                                KC_0,    KC_1,    KC_2,    KC_3,  _______,  KC_DEL,
        EE_CLR,  _______, _______, _______, _______,          _______,  _______,          _______, _______, _______, _______,  _______,
                                            _______, _______, _______,  _______, _______, _______
    ),
    [_RAISE] = layout(
        LED_LEVEL,_______,_______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, QK_BOOT,
                                            __SYM_ROW_LEFT__, _______,           _______,                                     __SYM_ROW_RGHT__,
                                              __FKEY_Aug_1__, _______,           _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______, KC_MPLY,
                                              __FKEY_Aug_2__,                                                                 __SYM_ROW_LRGT__,
        _______, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),
    [_ADJUST] = layout(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______,  _______, _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______,  _______, _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  _______, _______,
        _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______,  _______, QK_BOOT,
        _______, _______, _______, _______, _______,          _______,  _______,          _______, _______, _______, _______,  _______,
                                            _______, _______, _______,  _______, _______, _______
    ),
};

