#include "mp_complete.h"

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
}

