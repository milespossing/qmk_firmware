#pragma once
#include QMK_KEYBOARD_H


// QWERTY
#define __QWERTY_L1__   KC_Q, KC_W, KC_E, KC_R, KC_T
#define __QWERTY_L2__   KC_A, KC_S, KC_D, KC_F, KC_G
#define __QWERTY_L3__   KC_Z, KC_X, KC_C, KC_V, KC_B

#define __QWERTY_R1__   KC_Y, KC_U, KC_I,    KC_O,   KC_P
#define __QWERTY_R2__   KC_H, KC_J, KC_K,    KC_L,   KC_SCLN
#define __QWERTY_R3__   KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH
#define __QWERTY__ __QWERTY_L1__, __QWERTY_R1__, \
                   __QWERTY_L2__, __QWERTY_R2__, \
                   __QWERTY_L3__, __QWERTY_R3__

// COLEMAK
#define __COLEMAK_L1__ KC_Q, KC_W, KC_F, KC_P, KC_G
#define __COLEMAK_L2__ KC_A, KC_R, KC_S, KC_T, KC_D
#define __COLEMAK_L3__ __QWERTY_L3__

#define __COLEMAK_R1__ KC_J, KC_L, KC_U, KC_Y, KC_SCLN
#define __COLEMAK_R2__ KC_H, KC_N, KC_E, KC_I, KC_O
#define __COLEMAK_R3__ KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH
#define __COLEMAK__ __COLEMAK_L1__, __COLEMAK_R1__, \
                    __COLEMAK_L2__, __COLEMAK_R2__, \
                    __COLEMAK_L3__, __COLEMAK_R3__


#define __EMPTY__ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

#define __FKEY_ROW_1__ KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6
#define __FKEY_ROW_2__ KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12
#define __FKEY_Aug_1__ MT(MOD_LCTL, KC_F1), KC_F2, KC_F3, KC_F4, KC_F5, KC_F6
#define __FKEY_Aug_2__ MT(MOD_LSFT, KC_F7), KC_F8, KC_F9, KC_F10, KC_F11, KC_F12
#define __SYM_ROW_LEFT__  KC_GRV, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC
#define __SYM_ROW_RGHT__ KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX
#define __SYM_ROW_LRGT__ XXXXXXX, KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS
#define __SYM_ROW_LLFT__ XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE
#define __NUM_ROW_LEFT__  KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5
#define __NUM_ROW_RGHT__ KC_6, KC_7, KC_8, KC_9, KC_0, XXXXXXX
