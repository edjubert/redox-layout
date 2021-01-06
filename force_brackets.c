bool force_brackets(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
      case M_BRACKET_LEFT:
        if (record->event.pressed) {
            register_code(KC_LSFT);
            register_code(KC_9);
        } else { // Release the key
            unregister_code(KC_LSFT);
            unregister_code(KC_9);
        }
        return false;
      case M_BRACKET_RIGHT:
        if (record->event.pressed) {
            register_code(KC_LSFT);
            register_code(KC_0);
        } else { // Release the key
            unregister_code(KC_LSFT);
            unregister_code(KC_0);
        }
        return false;
      case M_SBRACKET_LEFT:
        if (record->event.pressed) {
          register_code(KC_LBRC);
        } else {
          unregister_code(KC_LBRC);
        }
        return false;
      case M_SBRACKET_RIGHT:
        if (record->event.pressed) {
          register_code(KC_RBRC);
        } else {
          unregister_code(KC_RBRC);
        }
        return false;
      case M_CBRACKET_LEFT:
        if (record->event.pressed) {
          register_code(KC_LSFT);
          register_code(KC_LBRC);
        } else {
          unregister_code(KC_LSFT);
          unregister_code(KC_LBRC);
        }
        return false;
      case M_CBRACKET_RIGHT:
        if (record->event.pressed) {
          register_code(KC_LSFT);
          register_code(KC_RBRC);
        } else {
          unregister_code(KC_LSFT);
          unregister_code(KC_RBRC);
        }
        return false;
      case M_INFERIOR:
        if (record->event.pressed) {
          register_code(KC_LSFT);
          register_code(KC_COMM);
        } else {
          unregister_code(KC_LSFT);
          unregister_code(KC_COMM);
        }
        return false;
      case M_SUPERIOR:
        if (record->event.pressed) {
          register_code(KC_LSFT);
          register_code(KC_DOT);
        } else {
          unregister_code(KC_LSFT);
          unregister_code(KC_DOT);
        }
        return false;
  }
}

