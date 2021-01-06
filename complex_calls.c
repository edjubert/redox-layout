bool complex_calls(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
      case INV_1P:
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LGUI)SS_DOWN(X_LALT)SS_TAP(X_BSLASH)SS_UP(X_LGUI)SS_UP(X_LALT));
        }
        return false;
      case ALFRED:
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_SPACE)SS_UP(X_LALT));
        }
        return false;
      case PASTE:
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LGUI)SS_LSFT("V")SS_UP(X_LGUI));
        }
        return false;
  }
}

