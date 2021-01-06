// Is shift being held? Let's store this in a bool.
static bool shift_held = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch(keycode) {
      case INV_1P:
      case ALFRED:
      case PASTE:
        return complex_calls(keycode, record);
      case KC_LSFT:
      case KC_RSFT:
        return held_shift(keycode, record, &shift_held);
      case M_BRACKET_LEFT:
      case M_BRACKET_RIGHT:
      case M_SBRACKET_LEFT:
      case M_SBRACKET_RIGHT:
      case M_CBRACKET_LEFT:
      case M_CBRACKET_RIGHT:
      case M_INFERIOR:
      case M_SUPERIOR:
        return force_brackets(keycode, record);
      case M_0_I:
      case M_1_I:
      case M_2_I:
      case M_3_I:
      case M_4_I:
      case M_5_I:
      case M_6_I:
      case M_7_I:
      case M_8_I:
      case M_9_I:
        return invert_keys(keycode, record, shift_held);
	}
	return true;
};

