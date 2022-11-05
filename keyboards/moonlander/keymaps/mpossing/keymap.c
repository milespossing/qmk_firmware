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
    [_QWERTY] = LAYOUT_moonlander_basic(
          KC_TAB, __QWERTY_L1__, __QWERTY_R1__, XXXXXXX,
  LCTL_T(KC_ESC), __QWERTY_L2__, __QWERTY_R2__, KC_QUOT,
         KC_LSPO, __QWERTY_L3__, __QWERTY_R3__, KC_RSPC
    ),

    [_LOWER] = LAYOUT_moonlander_basic(
        __LOWER_L1__, __LOWER_R1__, \
        __LOWER_L2__, __LOWER_R2__, \
        __LOWER_L3__, __LOWER_R3__  \
    ),

    [_RAISE] = LAYOUT_moonlander_basic(
        __RAISE_L1__, __RAISE_R1__, \
        __RAISE_L2__, __RAISE_R2__, \
        __RAISE_L3__, __RAISE_R3__  \
    ),

    [_MEDIA] = LAYOUT_moonlander_common(
        __EMPTY__, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT, \
        __MEDIA_L1__, __MEDIA_R1__, \
        __MEDIA_L2__, __MEDIA_R2__, \
        __MEDIA_R3__, __MEDIA_R3__ \
    )
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
