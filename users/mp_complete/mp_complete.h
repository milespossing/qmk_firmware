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

// CUSTOM KEYBOARD CONFIGS
#if defined(KEYBOARD_crkbd_rev4_0_standard)
#define LAYOUT_6x3(L00, L01, L02, L03, L04, L05, R00, R01, R02, R03, R04, R05, \
                   L10, L11, L12, L13, L14, L15, R10, R11, R12, R13, R14, R15, \
                   L20, L21, L22, L23, L24, L25, R20, R21, R22, R23, R24, R25) \
  LAYOUT_split_3x6_3(L00, L01, L02, L03, L04, L05, R00, R01, R02, R03, R04, R05,\
                     L10, L11, L12, L13, L14, L15, R10, R11, R12, R13, R14, R15,\
                     L20, L21, L22, L23, L24, L25, R20, R21, R22, R23, R24, R25,\
       KC_LGUI, _______, KC_SPC, KC_ENT, _______, KC_BSPC)
#define BASE_LAYOUT(L00, L01, L02, L03, L04, R00, R01, R02, R03, R04, \
                    L10, L11, L12, L13, L14, R10, R11, R12, R13, R14,   \
                    L20, L21, L22, L23, L24, R20, R21)   \
  LAYOUT_split_3x6_3_ex2(KC_TAB, L00, L01, L02, L03, L04, XXXXXXX, XXXXXXX, R00, R01, R02, R03, R04, QK_LEAD, \
                         KC_CESC, L10, L11, L12, L13, L14, CW_TOGG, VIM_SAV, R10, R11, R12, R13, R14, ALT_T(KC_QUOT), \
                         SC_LSPO, L20, L21, L22, L23, L24,                   R20, R21, KC_COMM, KC_DOT, KC_SLSH, SC_RCPC, \
                         KC_LGUI, MO_LOWR, KC_SPC, KC_ENT, MO_RAZE, KC_BSPC)
#define LAYOUT_ADJUST_6x3(R00, R01, R02, R03, R04, R05,                 \
                          R10, R11, R12, R13, R14, R15,                 \
                          R20, R21, R22, R23, R24, R25)                 \
  LAYOUT_split_3x6_3_ex2(XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT, XXXXXXX, R00, R01, R02, R03, R04, R05, \
                         RM_TOGG, RM_HUEU, RM_SATU, RM_VALU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, R10, R11, R12, R13, R14, R15, \
                         RM_NEXT, RM_HUED, RM_SATD, RM_VALD, XXXXXXX, XXXXXXX, R20, R21, R22, R23, R24, R25, \
                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX)

#elif defined(KEYBOARD_lily58)

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

#define LAYOUT_6x3(L00, L01, L02, L03, L04, L05, R00, R01, R02, R03, R04, R05, \
                   L10, L11, L12, L13, L14, L15, R10, R11, R12, R13, R14, R15, \
                   L20, L21, L22, L23, L24, L25, R20, R21, R22, R23, R24, R25) \
  LAYOUT(XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
         L00, L01, L02, L03, L04, L05, R00, R01, R02, R03, R04, R05,    \
         L10, L11, L12, L13, L14, L15, R10, R11, R12, R13, R14, R15,    \
         L20, L21, L22, L23, L24, L25, XXXXXXX, XXXXXXX, R20, R21, R22, R23, R24, R25, \
         KC_LALT, KC_LGUI, _______, KC_SPC, KC_ENT, _______, KC_BSPC, KC_RCTL)
#define BASE_LAYOUT(L00, L01, L02, L03, L04, R00, R01, R02, R03, R04, \
                    L10, L11, L12, L13, L14, R10, R11, R12, R13, R14,   \
                    L20, L21, L22, L23, L24, R20, R21)   \
  LAYOUT(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL, \
         KC_TAB, L00, L01, L02, L03, L04, R00, R01, R02, R03, R04, QK_LEAD, \
         KC_CESC, L10, L11, L12, L13, L14, R10, R11, R12, R13, R14, ALT_T(KC_QUOT), \
         SC_LSPO, L20, L21, L22, L23, L24, CW_TOGG, VIM_SAV, R20, R21, KC_COMM, KC_DOT, KC_SLSH, SC_RCPC, \
         KC_LALT, KC_LGUI, MO_LOWR, KC_SPC, KC_ENT, MO_RAZE, KC_BSPC, KC_RCTL)


#define LAYOUT_ADJUST_6x3(R00, R01, R02, R03, R04, R05,                 \
                          R10, R11, R12, R13, R14, R15,                 \
                          R20, R21, R22, R23, R24, R25)                 \
  LAYOUT(XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, R00, R01, R02, R03, R04, R05, \
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, R10, R11, R12, R13, R14, R15, \
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, R20, R21, R22, R23, R24, R25, \
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX)
    

#endif // END CUSTOM KEYBOAD CONFIGS

/*
  General Keyboard configs
*/

#define LAYOUT_COLEMAK BASE_LAYOUT(KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_SCLN,\
                                   KC_A, KC_R, KC_S, KC_T, KC_D, KC_H, KC_N, KC_E, KC_I, KC_O,\
                                   KC_Z, KC_X, KC_C, KC_V, KC_B, KC_K, KC_M)

#define LAYOUT_QWERTY BASE_LAYOUT(KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,\
                                  KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN,\
                                  KC_Z,KC_X,KC_C,KC_V,KC_B, KC_N,KC_M)

#define LAYOUT_RAISE LAYOUT_6x3(\
      KC_GRV, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,       KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, _______,  KC_GRV, \
SFT_T(KC_F7),   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,       XXXXXXX, KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS)

#define LAYOUT_LOWER LAYOUT_6x3(\
      KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,          KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,\
     KC_LCTL, XXXXXXX, KC_MPRV, XXXXXXX, KC_MPLY, KC_MNXT,       XXXXXXX,    KC_4,    KC_5,    KC_6,KC_RIGHT, XXXXXXX,\
     KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          KC_0,    KC_1,    KC_2,    KC_3, XXXXXXX, XXXXXXX)

#define LAYOUT_ADJUST LAYOUT_ADJUST_6x3(_______, _______, _______, _______, _______, _______, \
                                          KC_HOME, KC_PGDN, KC_PGUP,  KC_END, _______, _______, \
                                          DF_QWER, DF_COLE, _______, _______, _______, _______)


layer_state_t layer_state_set_user(layer_state_t state);
bool process_record_user(uint16_t keycode, keyrecord_t *record);


void leader_start_user(void);
void leader_end_user(void);

