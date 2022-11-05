#pragma once
#include QMK_KEYBOARD_H

#include "version.h"
#include "eeprom.h"

#include "wrappers.h"

enum userspace_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _MEDIA,
    _ADJUST,
    _GAME,
    LAYER_SAFE_RANGE,
};
