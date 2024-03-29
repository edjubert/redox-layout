#include QMK_KEYBOARD_H
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

static bool shift_held = false;

void persistent_default_layer_set(uint16_t default_layer) {
	eeconfig_update_default_layer(default_layer);
	default_layer_set(default_layer);
}


// Change LED colors depending on the layer.
uint32_t layer_state_set_user(uint32_t state) {
	switch (biton32(state)) {
		case _SYMB:
			rgblight_setrgb_orange();
			break;
		case _NAV:
			rgblight_setrgb_springgreen();
			break;
		case _INTER:
			rgblight_setrgb_teal();
			break;
		case _ADJUST:
			rgblight_setrgb_red();
			break;
		default: //  for any other layers, or the default layer
			rgblight_setrgb_yellow();
			break;
	}
	return state;
};

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
      default:
        return false;
  }
}



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
      default:
        return false;
  }
}

bool complex_calls(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
      case INV_1P:
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LGUI)SS_DOWN(X_LALT)SS_TAP(X_BSLASH)SS_UP(X_LGUI)SS_UP(X_LALT));
        }
        return false;
        break;
      case ALFRED:
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_SPACE)SS_UP(X_LALT));
        }
        return false;
        break;
      case PASTE:
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LGUI)SS_LSFT("V")SS_UP(X_LGUI));
        }
        return false;
        break;
      default:
        return false;
  }
}

bool held_shift(uint16_t keycode, keyrecord_t *record, bool *shift_held) {
  switch(keycode) {
      case KC_LSFT:
        *shift_held = record->event.pressed;
        return true;
        break;
      case KC_RSFT:
        *shift_held = record->event.pressed;
        return true;
        break;
      default:
        return false;
  }
}

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
	}
	return true;
};


#define KC_BRL  M_BRACKET_LEFT      // (
#define KC_BRR  M_BRACKET_RIGHT     // )
#define KC_SBRL M_SBRACKET_LEFT     // [
#define KC_SBRR M_SBRACKET_RIGHT    // ]
#define KC_CBRL M_CBRACKET_LEFT     // {
#define KC_CBRR M_CBRACKET_RIGHT    // }
#define KC_INF  M_INFERIOR          // <
#define KC_SUP  M_SUPERIOR          // >


// How long (in milliseconds) to wait between animation steps for each of the "Solid color breathing" animations
const uint8_t RGBLED_BREATHING_INTERVALS[] PROGMEM = {30, 20, 10, 5};

// How long (in milliseconds) to wait between animation steps for each of the "Cycling rainbow" animations
const uint8_t RGBLED_RAINBOW_MOOD_INTERVALS[] PROGMEM = {120, 60, 30};

// How long (in milliseconds) to wait between animation steps for each of the "Swirling rainbow" animations
const uint8_t RGBLED_RAINBOW_SWIRL_INTERVALS[] PROGMEM = {100, 50, 20};

// How long (in milliseconds) to wait between animation steps for each of the "Snake" animations
const uint8_t RGBLED_SNAKE_INTERVALS[] PROGMEM = {100, 50, 20};

// How long (in milliseconds) to wait between animation steps for each of the "Knight" animations
const uint8_t RGBLED_KNIGHT_INTERVALS[] PROGMEM = {127, 63, 31};

// How long (in milliseconds) to wait between animation steps for each of the "Twinkle" animations
const uint8_t RGBLED_TWINKLE_INTERVALS[] PROGMEM = {50, 25, 10};

// These control which hues are selected for each of the "Static gradient" modes
const uint8_t RGBLED_GRADIENT_RANGES[] PROGMEM = {255, 170, 127, 85, 64};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_MINS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,PASTE   ,                           INV_1P ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_BSLS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC  ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,KC_LBRC ,                          KC_RBRC ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,KC_QUOT ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,TT_NAV  ,TT_INTER,        TT_INTER,TT_NAV  ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSFT ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     SYM_L   ,TT_ADJ  ,KC_RALT ,KC_LALT ,     KC_LCMD ,    KC_BSPC ,KC_LCTL ,        KC_ENT  ,KC_SPC  ,    KC_RALT ,     KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RIGHT
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),


  [_SYMB] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                                            _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,_______ ,KC_SBRL ,KC_SBRR ,KC_INF  ,KC_SUP  ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,_______ ,KC_EQL  ,KC_PLUS ,KC_MINS ,KC_UNDS ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,        _______ ,_______ ,_______ ,KC_BRL  ,KC_BRR  ,KC_CBRL ,KC_CBRR ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     KC_BTN1 ,    _______ ,_______ ,        _______ ,_______ ,    KC_BTN1 ,     _______ ,_______ ,_______ ,_______
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_SLEP ,KC_MPRV ,KC_MNXT ,KC_MPLY ,XXXXXXX ,_______ ,                          _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,KC_VOLD ,KC_VOLU ,KC_MUTE ,XXXXXXX ,_______ ,                          _______ ,KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RIGHT,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,KC_BRID ,KC_BRIU ,XXXXXXX ,XXXXXXX ,_______ ,_______ ,        _______ ,_______ ,KC_WH_L ,KC_WH_D ,KC_WH_U ,KC_WH_R ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     KC_BTN1 ,    KC_BTN2 ,_______ ,        _______ ,KC_BTN2 ,    KC_BTN1 ,     KC_MS_L ,KC_MS_D ,KC_MS_U ,KC_MS_R
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_INTER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,KC_F11  ,KC_F12  ,KC_F13  ,KC_F14  ,KC_F15  ,                                            KC_F16  ,KC_F17  ,KC_F18  ,KC_F19  ,KC_F20  ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,                          _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,                          _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,        _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     XXXXXXX ,    XXXXXXX ,_______ ,        _______ ,XXXXXXX ,    XXXXXXX ,     _______ ,XXXXXXX ,XXXXXXX ,_______
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     RGB_TOG ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_SAD ,RGB_SAI ,RGB_VAD ,RGB_VAI ,RGB_HUD ,RGB_HUI ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,RGB_M_TW,RGB_M_B ,RGB_M_P ,XXXXXXX ,XXXXXXX ,_______ ,                          _______ ,XXXXXXX ,RESET   ,DEBUG   ,AU_TOG  ,XXXXXXX ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_M_G ,RGB_M_SW,RGB_M_R ,RGB_M_SN,RGB_M_K ,RGB_M_X ,RGB_M_T ,_______ ,        _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     XXXXXXX ,    XXXXXXX ,_______ ,        _______ ,XXXXXXX ,    XXXXXXX ,     _______ ,XXXXXXX ,XXXXXXX ,_______
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  )
};

