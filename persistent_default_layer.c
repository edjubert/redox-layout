void persistent_default_layer_set(uint16_t default_layer) {
	eeconfig_update_default_layer(default_layer);
	default_layer_set(default_layer);
}

