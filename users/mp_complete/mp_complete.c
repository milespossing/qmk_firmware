#include "mp_complete.h"

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

void vim_save(void) {
  SEND_STRING(":w\n");
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case VIM_SAV:
            if (record->event.pressed) {
              vim_save();
            }
            break;
    }
    return true;
}

void leader_start_user(void) {
  // noop
}

void leader_end_user(void) {
  if (leader_sequence_one_key(KC_S)) {
    // vim save
    vim_save();
  } else if (leader_sequence_three_keys(KC_T, KC_T, KC_P)) {
    // Print Tapping Term
    char buff[8];
    sprintf(buff, "%hu", g_tapping_term);
    send_string(buff);
  } else if (leader_sequence_three_keys(KC_T, KC_T, KC_I)) {
    // Increase Tapping Term
    g_tapping_term += 20;
  } else if (leader_sequence_three_keys(KC_T, KC_T, KC_D)) {
    // Decrease Tapping Term
    g_tapping_term -= 20;
  } else if (leader_sequence_two_keys(KC_M, KC_N)) {
    // Media Next
    SEND_STRING(SS_TAP(X_MNXT));
  }
}

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
