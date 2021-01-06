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
