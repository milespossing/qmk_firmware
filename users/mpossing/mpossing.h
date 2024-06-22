#pragma once
#include QMK_KEYBOARD_H

#include "version.h"
#include "eeprom.h"

#include "wrappers.h"

enum userspace_layers {
    _QWERTY,
    _COLEMAK,
    _PLOVER,
    _LOWER,
    _RAISE,
    _MEDIA,
    _ADJUST,
    _GAME,
    LAYER_SAFE_RANGE,
};

enum userspace_keycodes {
    VIM_SAV = SAFE_RANGE,
};

// We always use tristate for _ADJUST
layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case VIM_SAV:
            if (record->event.pressed) {
                SEND_STRING(":w\n");
            }
            break;
    }
    return true;
};
