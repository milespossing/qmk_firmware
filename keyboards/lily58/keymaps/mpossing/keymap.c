#include QMK_KEYBOARD_H
#include "mpossing.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 *  v-----------------------------------------v   Fn Keys 13-24    v-----------------------------------------v
 * ,------------------------------------------.                    ,-----------------------------------------.
 * |       |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |-------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab   |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |-------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |esc/ctl|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |-------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  | Ent  |
 * `------------------------------------------/       /     \      \-----------------------------------------'
 *                    | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                    |      |      |      |/       /         \      \ |      |      |      |
 *                    `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT_lily_common(
          KC_TAB, __QWERTY_L1__, __QWERTY_R1__, XXXXXXX,
  LCTL_T(KC_ESC), __QWERTY_L2__, __QWERTY_R2__, KC_QUOT,
         KC_LSPO, __QWERTY_L3__, __QWERTY_R3__, KC_RSPC
),
[_LOWER] = LAYOUT_lily_common(
          KC_TAB, __QWERTY_L1__, XXXXXXX,   KC_P7,   KC_P8,   KC_P9, XXXXXXX, XXXXXXX, \
  LCTL_T(KC_ESC), __QWERTY_L2__, XXXXXXX,   KC_P4,   KC_P6,   KC_P7, XXXXXXX, XXXXXXX, \
         KC_LSPO, __QWERTY_L3__,   KC_P0,   KC_P1,   KC_P2,   KC_P3, XXXXXXX, XXXXXXX  \
),
[_RAISE] = LAYOUT_lily_common(
  __RAISE_L1__, __RAISE_R1__, \
  __RAISE_L2__, __RAISE_R2__, \
  __RAISE_L3__, __RAISE_R3__  \
),
[_ADJUST] = LAYOUT_lily(
  XXXXXXX, XXXXXXX, XXXXXXX, DM_REC1, DM_RSTP, DM_PLY1,                   _______________________EMPTY________________________,
  _______________________EMPTY________________________,                   _______________________EMPTY________________________,
  _______________________EMPTY________________________, XXXXXXX, XXXXXXX, _______________________EMPTY________________________,
  _______________________EMPTY________________________,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX
),
[_MEDIA] = LAYOUT_lily_common(__MEDIA_ALL__)
};

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE
