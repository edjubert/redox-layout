bool held_shift(uint16_t keycode, keyrecord_t *record, bool *shift_held) {
  switch(keycode) {
      case KC_LSFT:
        *shift_held = record->event.pressed;
        return true;
      case KC_RSFT:
        *shift_held = record->event.pressed;
        return true;
  }
}

