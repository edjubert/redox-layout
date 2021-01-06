#ifndef __EDJUBERT_H__
  #define __EDJUBERT_H__

  bool complex_calls(uint16_t keycode, keyrecord_t *record);
  bool invert_keys(uint16_t keycode, keyrecord_t *record);
  bool force_brackets(uint16_t keycode, keyrecord_t *record);
  bool held_shift(uint16_t keycode, keyrecord_t *record);
  bool process_record_user(uint16_t keycode, keyrecord_t *record);

#endif
