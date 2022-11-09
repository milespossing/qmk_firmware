#pragma once
#include QMK_KEYBOARD_H

#define ALFRED G(KC_SPC)

// QWERTY
#define __QWERTY_L1__   KC_Q, KC_W, KC_E, KC_R, KC_T
#define __QWERTY_L2__   KC_A, KC_S, KC_D, KC_F, KC_G
#define __QWERTY_L3__   KC_Z, KC_X, KC_C, KC_V, KC_B

#define __QWERTY_R1__   KC_Y, KC_U, KC_I,    KC_O,   KC_P
#define __QWERTY_R2__   KC_H, KC_J, KC_K,    KC_L,   KC_SCLN
#define __QWERTY_R3__   KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH

// Utils
#define __EMPTY__ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define _______________________EMPTY________________________ __EMPTY__
#define KC_CESC LCTL_T(KC_ESC)
#define ______________________RGB_CTRL______________________  RGB_TOG, RGB_MODE_FORWARD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_VAI
#define TG_GAME TG(_GAME)
#define MO_RAZE MO(_RAISE)
#define TG_HOME TG(_QWERTY)
#define KC_BRSE LT(_RAISE, KC_BSPC)
#define KC_BLWR LT(_LOWER, KC_BSPC)
#define MO_LOWR MO(_LOWER)

#define __NUM_ROW_LEFT__  KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5
#define __NUM_ROW_RGHT__ KC_6, KC_7, KC_8, KC_9, KC_0, XXXXXXX
#define __SYM_ROW_LEFT__  (KC_GRV), KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC
#define __SYM_ROW_RGHT__ KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX
#define __SYM_ROW_LRGT__ XXXXXXX, KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS
#define __SYM_ROW_LLFT__ XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE

// Raise
#define __RAISE_L1__  __NUM_ROW_LEFT__
#define __RAISE_L2__  __SYM_ROW_LEFT__
#define __RAISE_L3__  KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

#define __RAISE_R1__  __NUM_ROW_RGHT__
#define __RAISE_R2__  __SYM_ROW_RGHT__
#define __RAISE_R3__  __SYM_ROW_LRGT__

// Lower
#define __LOWER_L1__  __SYM_ROW_LEFT__
#define __LOWER_L2__  __EMPTY__
#define __LOWER_L3__  __RAISE_L3__

#define __LOWER_R1__  __SYM_ROW_RGHT__
#define __LOWER_R2__  __EMPTY__
#define __LOWER_R3__  __SYM_ROW_LLFT__


// MEDIA
#define __MEDIA_L1__   XXXXXXX, XXXXXXX, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U
#define __MEDIA_L2__   XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D
#define __MEDIA_L3__   XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX, XXXXXXX, XXXXXXX

#define __MEDIA_R1__   KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, XXXXXXX
#define __MEDIA_R2__   KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______, KC_MPLY
#define __MEDIA_R3__   KC_VOLD, KC_VOLU, KC_MPRV, KC_MNXT, XXXXXXX, XXXXXXX

#define __MEDIA_ALL__       __MEDIA_L1__, __MEDIA_R1__, \
                            __MEDIA_L2__, __MEDIA_R2__, \
                            __MEDIA_L3__, __MEDIA_R3__


#if defined(KEYBOARD_moonlander)
  #include "moonlander.h"
/** Moonlander Empty
 * ( \
        k00, k01, k02, k03, k04, k05, k06,   k60, k61, k62, k63, k64, k65, k66, \
        k10, k11, k12, k13, k14, k15, k16,   k70, k71, k72, k73, k74, k75, k76, \
        k20, k21, k22, k23, k24, k25, k26,   k80, k81, k82, k83, k84, k85, k86, \
        k30, k31, k32, k33, k34, k35,             k91, k92, k93, k94, k95, k96, \
        k40, k41, k42, k43, k44,      k53,   kb3,      ka2, ka3, ka4, ka5, ka6, \
                            k50, k51, k52,   kb4, kb5, kb6 \
    ) \
 */
#   define WRAPPER_moonlander(...)    LAYOUT_moonlander(__VA_ARGS__)
#   define WRAPPER_moonlander_top(                                                                                                                        \
    L01, L02, L03, L04, L05, L06, CL1,   CR1, R01, R02, R03, R04, R05, R06,                                                                               \
    L11, L12, L13, L14, L15, L16, CL2,   CR2, R11, R12, R13, R14, R15, R16,                                                                               \
    L21, L22, L23, L24, L25, L26, CL3,   CR3, R21, R22, R23, R24, R25, R26,                                                                               \
    L31, L32, L33, L34, L35, L36,             R31, R32, R33, R34, R35, R36,                                                                               \
    L41, L42, L43, L44, L45,      RDL,   RDR,      R42, R43, R44, R45, R46                                                                                \
) WRAPPER_moonlander(                                                                                                                                     \
    L01, L02, L03, L04, L05, L06, CL1,   CR1, R01, R02, R03, R04, R05, R06,                                                                               \
    L11, L12, L13, L14, L15, L16, CL2,   CR2, R11, R12, R13, R14, R15, R16,                                                                               \
    L21, L22, L23, L24, L25, L26, CL3,   CR3, R21, R22, R23, R24, R25, R26,                                                                               \
    L31, L32, L33, L34, L35, L36,             R31, R32, R33, R34, R35, R36,                                                                               \
    L41, L42, L43, L44, L45,      RDL,   RDR,      R42, R43, R44, R45, R46,                                                                               \
      KC_SPC, MO_LOWR, TG(_LOWER),           KC_BSPC, KC_BRSE,  KC_ENT                                      )
#   define WRAPPER_moonlander_common(                                                                                                           \
    L11, L12, L13, L14, L15, L16,   R11, R12, R13, R14, R15, R16,                                                                               \
    L21, L22, L23, L24, L25, L26,   R21, R22, R23, R24, R25, R26,                                                                               \
    L31, L32, L33, L34, L35, L36,   R31, R32, R33, R34, R35, R36                                                                                \
) WRAPPER_moonlander_top(                                                                                                                           \
          KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,  KC_F13,            KC_F16,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, \
            L11,     L12,     L13,     L14,     L15,     L16, DM_REC1,            KC_F17,     R11,     R12,     R13,     R14,     R15,     R16, \
            L21,     L22,     L23,     L24,     L25,     L26, DM_RSTP,           DM_PLY1,     R21,     R22,     R23,     R24,     R25,     R26, \
            L31,     L32,     L33,     L34,     L35,     L36,                                 R31,     R32,     R33,     R34,     R35,     R36, \
        KC_LCTL, XXXXXXX, XXXXXXX, KC_LALT, KC_LGUI,           ALFRED,           VIM_SAV,          KC_BSPC, XXXXXXX, XXXXXXX, XXXXXXX,  KC_DEL  )
#   define WRAPPER_moonlander_gamepad(                                                                                  \
    T01, T02, T03, T04, T05, T06, T07,                                                                                  \
    L11, L12, L13, L14, L15, L16, L17,                                                                                  \
    L21, L22, L23, L24, L25, L26, L27,                                                                                  \
    L31, L32, L33, L34, L35, L36,                                                                                       \
    L41, L42, L43, L44, L45,      Red, P1, P2, P3                                                                       \
) WRAPPER_moonlander(                                                                                                   \
        T01, T02, T03, T04, T05, T06, T07,               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        L11, L12, L13, L14, L15, L16, L17,               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        L21, L22, L23, L24, L25, L26, L27,               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        L31, L32, L33, L34, L35, L36,                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        L41, L42, L43, L44, L45,             Red,        XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                                      P1, P2, P3,        XXXXXXX, KC_BRSE, TG(_QWERTY)                                  )
#   define WRAPPER_moonlander_home(\
    L11, L12, L13, L14, L15, L16,   R11, R12, R13, R14, R15, R16, \
    L21, L22, L23, L24, L25, L26,   R21, R22, R23, R24, R25, R26, \
    L31, L32, L33, L34, L35, L36,   R31, R32, R33, R34, R35, R36  \
    ) WRAPPER_moonlander_common( \
            L11,     L12,     L13,     L14,     L15,     L16,           R11,     R12,     R13,     R14,             R15,     R16,      \
            L21,     L22,     L23,     L24,     L25,     L26,           R21,     R22,     R23,     R24, LT(_MEDIA, R25),     R26,      \
            L31,     L32,     L33,     L34,     L35,     L36,           R31,     R32,     R33,     R34,             R35,     R36      \
    )

#   define LAYOUT_moonlander_top(...)     WRAPPER_moonlander_top(__VA_ARGS__)
#   define LAYOUT_moonlander_basic(...)   WRAPPER_moonlander(__VA_ARGS__)
#   define LAYOUT_moonlander_home(...)    WRAPPER_moonlander_home(__VA_ARGS__)
#   define LAYOUT_moonlander_common(...)  WRAPPER_moonlander_common(__VA_ARGS__)
#   define LAYOUT_moonlander_game(...)    WRAPPER_moonlander_game(__VA_ARGS__)
// #   define LAYOUT_moonlander_mods(...)    WRAPPER_moonlander_mods(__VA_ARGS__)
// #   define LAYOUT_moonlander_gamepad(...) WRAPPER_moonlander_gamepad(__VA_ARGS__)
#elif defined(KEYBOARD_lily58)
    #include "rev1.h"
    #define LAYOUT_lily58_rev1(...) LAYOUT(__VA_ARGS__)
/*
Layout Empty
    L00, L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, R05,  \
    L10, L11, L12, L13, L14, L15,           R10, R11, R12, R13, R14, R15,  \
    L20, L21, L22, L23, L24, L25,           R20, R21, R22, R23, R24, R25,  \
    L30, L31, L32, L33, L34, L35, L45, R40, R30, R31, R32, R33, R34, R35, \
                   L41, L42, L43, L44, R41, R42, R43, R44  \
*/
#   define WRAPPER_lily58(...)            LAYOUT_lily58_rev1(__VA_ARGS__)
#   define WRAPPER_lily58_common(\
    L11, L12, L13, L14, L15, L16,   R11, R12, R13, R14, R15, R16, \
    L21, L22, L23, L24, L25, L26,   R21, R22, R23, R24, R25, R26, \
    L31, L32, L33, L34, L35, L36,   R31, R32, R33, R34, R35, R36 \
) WRAPPER_lily58( \
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                  KC_F7,   KC_F8,   KC_F9,  KC_F10,          KC_F11,  KC_F11, \
        L11,     L12,     L13,     L14,     L15,     L16,                    R11,     R12,     R13,     R14,             R15,     R16, \
        L21,     L22,     L23,     L24,     L25,     L26,                    R21,     R22,     R23,     R24, LT(_MEDIA, R25),     R26, \
        L31,     L32,     L33,     L34,     L35,     L36, ALFRED,  VIM_SAV,  R31,     R32,     R33,     R34,             R35,     R36, \
                          KC_LALT, KC_LGUI, MO(_LOWER), KC_SPC,        KC_ENT, MO(_RAISE), KC_BSPC,  KC_DEL                            \
)
#   define LAYOUT_lily(...)        WRAPPER_lily58(__VA_ARGS__)
#   define LAYOUT_lily_common(...) WRAPPER_lily58_common(__VA_ARGS__)
#endif
