bool invert_keys(uint16_t keycode, keyrecord_t *record, bool shift_helded) {
  switch(keycode) {
      case M_0_I:
        if (record->event.pressed) {
          if (shift_helded) {
            unregister_code(KC_LSFT);
            unregister_code(KC_RSFT);
          } else {
            register_code(KC_LSFT);
          }
          register_code(KC_0);
        } else {
          unregister_code(KC_LSFT);
          unregister_code(KC_0);
        }
        return false;
      case M_1_I:
        if (record->event.pressed){
          if (shift_helded) {
            unregister_code(KC_LSFT);
            unregister_code(KC_RSFT);
          } else {
            register_code(KC_LSFT);
          }
          register_code(KC_1);
        } else {
          unregister_code(KC_LSFT);
          unregister_code(KC_1);
        }
        return false;
      case M_2_I:
        if (record->event.pressed){
          if (shift_helded) {
            unregister_code(KC_LSFT);
            unregister_code(KC_RSFT);
          } else {
            register_code(KC_LSFT);
          }
          register_code(KC_2);
        } else {
          unregister_code(KC_LSFT);
          unregister_code(KC_2);
        }
        return false;
      case M_3_I:
        if (record->event.pressed){
          if (shift_helded) {
            unregister_code(KC_LSFT);
            unregister_code(KC_RSFT);
          } else {
            register_code(KC_LSFT);
          }
          register_code(KC_3);
        } else {
          unregister_code(KC_LSFT);
          unregister_code(KC_3);
        }
        return false;
      case M_4_I:
        if (record->event.pressed){
          if (shift_helded) {
            unregister_code(KC_LSFT);
            unregister_code(KC_RSFT);
          } else {
            register_code(KC_LSFT);
          }
          register_code(KC_4);
        } else {
          unregister_code(KC_LSFT);
          unregister_code(KC_4);
        }
        return false;
      case M_5_I:
        if (record->event.pressed){
          if (shift_helded) {
            unregister_code(KC_LSFT);
            unregister_code(KC_RSFT);
          } else {
            register_code(KC_LSFT);
          }
          register_code(KC_5);
        } else {
          unregister_code(KC_LSFT);
          unregister_code(KC_5);
        }
        return false;
      case M_6_I:
        if (record->event.pressed){
          if (shift_helded) {
            unregister_code(KC_LSFT);
            unregister_code(KC_RSFT);
          } else {
            register_code(KC_LSFT);
          }
          register_code(KC_6);
        } else {
          unregister_code(KC_LSFT);
          unregister_code(KC_6);
        }
        return false;
      case M_7_I:
        if (record->event.pressed){
          if (shift_helded) {
            unregister_code(KC_LSFT);
            unregister_code(KC_RSFT);
          } else {
            register_code(KC_LSFT);
          }
          register_code(KC_7);
        } else {
          unregister_code(KC_LSFT);
          unregister_code(KC_7);
        }
        return false;
      case M_8_I:
        if (record->event.pressed){
          if (shift_helded) {
            unregister_code(KC_LSFT);
            unregister_code(KC_RSFT);
          } else {
            register_code(KC_LSFT);
          }
          register_code(KC_8);
        } else {
          unregister_code(KC_LSFT);
          unregister_code(KC_8);
        }
        return false;
      case M_9_I:
        if (record->event.pressed){
          if (shift_helded) {
            unregister_code(KC_LSFT);
            unregister_code(KC_RSFT);
          } else {
            register_code(KC_LSFT);
          }
          register_code(KC_9);
        } else {
          unregister_code(KC_LSFT);
          unregister_code(KC_9);
        }
        return false;
  }
}


