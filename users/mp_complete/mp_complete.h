#pragma once
#include QMK_KEYBOARD_H
#include "quantum.h"
#include "layouts.h"

enum userspace_layers {
    _COLEMAK,
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _GAME,
    LAYER_SAFE_RANGE,
};

enum userspace_keycodes {
    VIM_SAV = SAFE_RANGE,
};

#define DF_QWER DF(_QWERTY)
#define DF_COLE DF(_COLEMAK)
#define KC_CESC LCTL_T(KC_ESC)

#define MO_RAZE MO(_RAISE)
#define MO_LOWR MO(_LOWER)
#define KC_BRSE LT(_RAISE, KC_BSPC)


layer_state_t layer_state_set_user(layer_state_t state);
bool process_record_user(uint16_t keycode, keyrecord_t *record);



