#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _COLEMAK 0
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
	SHRUG,
	WAVE,
	YOSHI,
	THUMB_UP,
	NBSP,
  INV_1P,
  ALFRED,
  PASTE
};

// Is shift being held? Let's store this in a bool.
static bool shift_held = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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
      case KC_LSFT:
        shift_held = record->event.pressed;
        return true;
        break;
      case KC_RSFT:
        shift_held = record->event.pressed;
        return true;
        break;
      case M_BRACKET_LEFT:
        if (record->event.pressed) {
            register_code(KC_LSFT);
            register_code(KC_9);
        } else { // Release the key
            unregister_code(KC_LSFT);
            unregister_code(KC_9);
        }
        return false;
        break;
      case M_BRACKET_RIGHT:
        if (record->event.pressed) {
            register_code(KC_LSFT);
            register_code(KC_0);
        } else { // Release the key
            unregister_code(KC_LSFT);
            unregister_code(KC_0);
        }
        return false;
        break;
      case M_SBRACKET_LEFT:
        if (record->event.pressed) {
          register_code(KC_LBRC);
        } else {
          unregister_code(KC_LBRC);
        }
        return false;
        break;
      case M_SBRACKET_RIGHT:
        if (record->event.pressed) {
          register_code(KC_RBRC);
        } else {
          unregister_code(KC_RBRC);
        }
        return false;
        break;
      case M_CBRACKET_LEFT:
        if (record->event.pressed) {
          register_code(KC_LSFT);
          register_code(KC_LBRC);
        } else {
          unregister_code(KC_LSFT);
          unregister_code(KC_LBRC);
        }
        return false;
        break;
      case M_CBRACKET_RIGHT:
        if (record->event.pressed) {
          register_code(KC_LSFT);
          register_code(KC_RBRC);
        } else {
          unregister_code(KC_LSFT);
          unregister_code(KC_RBRC);
        }
        return false;
        break;
      case M_INFERIOR:
        if (record->event.pressed) {
          register_code(KC_LSFT);
          register_code(KC_COMM);
        } else {
          unregister_code(KC_LSFT);
          unregister_code(KC_COMM);
        }
        return false;
        break;
      case M_SUPERIOR:
        if (record->event.pressed) {
          register_code(KC_LSFT);
          register_code(KC_DOT);
        } else {
          unregister_code(KC_LSFT);
          unregister_code(KC_DOT);
        }
        return false;
        break;
	}
	return true;
};

// Shortcut to make keymap more readable
// To declare a keycode for long press:
// #define KC_MYKEYCODE LT(_LAYERNAME, KC_STDKEY)
// #define KC_SYQT  LT(_SYMB,KC_QUOT)

#define SYM_L    MO(_SYMB)
#define MO_INTR  MO(_INTER)

#define TT_ADJ   TT(_ADJUST)
#define TT_INTER TT(_INTER)
#define TT_NAV   TT(_NAV)

#define KC_BRL  M_BRACKET_LEFT      // (
#define KC_BRR  M_BRACKET_RIGHT     // )
#define KC_SBRL M_SBRACKET_LEFT     // [
#define KC_SBRR M_SBRACKET_RIGHT    // ]
#define KC_CBRL M_CBRACKET_LEFT     // {
#define KC_CBRR M_CBRACKET_RIGHT    // }
#define KC_INF  M_INFERIOR          // <
#define KC_SUP  M_SUPERIOR          // >


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_MINS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,PASTE   ,                           INV_1P ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_BSLS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC  ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,KC_LBRC,                           KC_RBRC ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,KC_QUOT ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,TT_NAV  ,TT_INTER,        TT_INTER,TT_NAV  ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSFT ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     SYM_L   ,KC_LCTL ,KC_HYPR ,KC_LALT ,     KC_LCMD ,    KC_BSPC ,KC_LCTL ,        KC_ENT  ,KC_SPC  ,    ALFRED  ,     KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RIGHT
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),


  [_SYMB] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                                            _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,_______ ,KC_SBRL ,KC_SBRR ,KC_INF  ,KC_SUP  ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                         ,_______ ,_______ ,KC_EQL  ,KC_PLUS ,KC_MINS ,KC_UNDS ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______          _______ ,_______ ,_______ ,KC_BRL  ,KC_BRR  ,KC_CBRL ,KC_CBRR ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     KC_BTN1 ,    _______ ,_______ ,        _______ ,_______ ,    KC_BTN1 ,     _______ ,_______ ,_______ ,_______
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,KC_MPRV ,KC_MNXT ,KC_MPLY ,XXXXXXX ,_______ ,                          _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
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
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,XXXXXXX ,RGB_VAD ,RGB_VAI ,RGB_TOG ,XXXXXXX ,_______ ,                          _______ ,XXXXXXX ,RESET   ,DEBUG   ,AU_TOG  ,XXXXXXX ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,        _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     XXXXXXX ,    XXXXXXX ,_______ ,        _______ ,XXXXXXX ,    XXXXXXX ,     _______ ,XXXXXXX ,XXXXXXX ,_______
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  )

};

#ifdef AUDIO_ENABLE
float tone_colemak[][2]     = SONG(ZELDA_TREASURE);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
	eeconfig_update_default_layer(default_layer);
	default_layer_set(default_layer);
}

// Set unicode in Mac OS.
void eeconfig_init_user(void) {
  set_unicode_input_mode(UC_OSX);
};

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
