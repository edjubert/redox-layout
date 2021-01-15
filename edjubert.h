#ifndef __EDJUBERT_H__
  #define __EDJUBERT_H__

  #ifdef AUDIO_ENABLE
    float tone_colemak[][2] = SONG(ZELDA_TREASURE);
  #endif

  extern keymap_config_t keymap_config;

  // Each layer gets a name for readability, which is then used in the keymap matrix below.
  // The underscores don't mean anything - you can have a layer called STUFF or any other name.
  // Layer names don't all need to be of the same length, obviously, and you can also skip them
  // entirely and just use numbers.
  #define _QWERTY 0
  #define _SYMB 1
  #define _NAV 2
  #define _INTER 3
  #define _ADJUST 4

  enum custom_keycodes {
      COLEMAK = SAFE_RANGE,
      SYMB,
      NAV,
      INTER,
      ADJUST,
      // These use process_record_user()
      M_BRACKET_LEFT,
      M_BRACKET_RIGHT,
      M_SBRACKET_LEFT,
      M_SBRACKET_RIGHT,
      M_CBRACKET_LEFT,
      M_CBRACKET_RIGHT,
      M_SUPERIOR,
      M_INFERIOR,
      M_0_I,
      M_1_I,
      M_2_I,
      M_3_I,
      M_4_I,
      M_5_I,
      M_6_I,
      M_7_I,
      M_8_I,
      M_9_I,
    INV_1P,
    ALFRED,
    PASTE
  };


  // Shortcut to make keymap more readable
  // To declare a keycode for long press:
  // #define KC_MYKEYCODE LT(_LAYERNAME, KC_STDKEY)
  // #define KC_SYQT  LT(_SYMB,KC_QUOT)

  #define SYM_L    TT(_SYMB)
  #define MO_INTR  MO(_INTER)
  
  #define TT_ADJ   TT(_ADJUST)
  #define TT_INTER TT(_INTER)
  #define TT_NAV   TT(_NAV)
  
  bool complex_calls(uint16_t keycode, keyrecord_t *record);
  bool invert_keys(uint16_t keycode, keyrecord_t *record, bool shift_held);
  bool force_brackets(uint16_t keycode, keyrecord_t *record);
  bool held_shift(uint16_t keycode, keyrecord_t *record, bool *shift_held);
  /* bool process_record_user(uint16_t keycode, keyrecord_t *record); */
  uint32_t layer_state_set_user(uint32_t state);
  void persistent_default_layer_set(uint16_t default_layer);

#endif
