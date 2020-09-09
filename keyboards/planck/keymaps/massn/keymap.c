#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define BASE 0
#define LOWER 1
#define RAISE 2
#define FUNCTION 3

#define L_T_SFT KC_SPC
#define R_T_SFT KC_ENT

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Base
   * ,-----------------------------------------------------------------------------------.
   * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  -   |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  \   |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Henk |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Cmd  | Opt  |   (  | lower| Space|  BS  |  Tab | Enter| Raise|   )  |  `   | =    |
   * `-----------------------------------------------------------------------------------'
   */
  [BASE] = LAYOUT_planck_grid(
      KC_ESC,   KC_Q,    KC_W,    KC_E,     KC_R,    KC_T,    KC_Y,    KC_U,   KC_I,     KC_O,    KC_P,    KC_MINS,
      KC_LCTRL, KC_A,    KC_S,    KC_D,     KC_F,    KC_G,    KC_H,    KC_J,   KC_K,     KC_L,    KC_SCLN, KC_BSLS,
      KC_LSFT,  KC_Z,    KC_X,    KC_C,     KC_V,    KC_B,    KC_N,    KC_M,   KC_COMM,  KC_DOT,  KC_SLSH, KC_HENK ,
      KC_LGUI,  KC_LALT, KC_LPRN, MO(LOWER),KC_SPC,  KC_BSPC, KC_TAB,  KC_ENT, MO(RAISE),KC_RPRN, KC_QUOT, KC_EQL
      ),

  /* Lower
   * ,-----------------------------------------------------------------------------------.
   * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  |  F12 |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |
   * `-----------------------------------------------------------------------------------'
   */
  [LOWER] = LAYOUT_planck_grid(
      KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12,
      KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
      KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
      KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS
      ),

  /* Raise
   * ,-----------------------------------------------------------------------------------.
   * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |      |      |      |      |      |      |  left|  down|  up  | right|      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |  Del |      |      |      |      |      |
   * `-----------------------------------------------------------------------------------'
   */
  [RAISE] = LAYOUT_planck_grid(
      KC_TRNS,KC_1,   KC_2,   KC_3,   KC_4,   KC_5,    KC_6,    KC_7,    KC_8,   KC_9,    KC_0,   KC_TRNS,
      KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT,KC_TRNS,KC_TRNS,
      KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS,KC_TRNS,
      KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_DELT, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS,KC_TRNS
      )
};

/*const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)*/
/*{*/
  /*return MACRO_NONE;*/
/*};*/

bool processing_modifier = false;
bool is_japanese_mode = false;

bool is_modifier(uint16_t keycode){
  switch(keycode){
    case KC_LCTL:
    case KC_LGUI:
    case KC_LSFT:
    case KC_LPRN:
    case KC_RPRN:
    /*case L_T_SFT:*/
    /*case R_T_SFT:*/
      return true;
      break;
    default:
      return false;
      break;
  }
}

bool process_modifier(uint16_t keycode, keyrecord_t *record){
  if (is_modifier(keycode)){
    if (record->event.pressed){
      processing_modifier = true;
    }else{
      processing_modifier = false;
    }
    return true;
  }
  if(processing_modifier){
    return true;
  }
  return false;
}

void turn_on_japanese_mode(void) {
  if(!is_japanese_mode){
    SEND_STRING(SS_TAP(X_RGUI));
    SEND_STRING(SS_TAP(X_LANG1));
    is_japanese_mode = true;
  }
}

void turn_off_japanese_mode(void) {
  if (is_japanese_mode) {
    SEND_STRING(SS_TAP(X_LGUI));
    SEND_STRING(SS_TAP(X_LANG2));
    is_japanese_mode = false;
  }
}

bool process_henk(uint8_t keycode, keyrecord_t *record){
  if (keycode == KC_HENK){
      if (record->event.pressed && biton32(layer_state) == BASE) {
	if (is_japanese_mode) {
	  turn_off_japanese_mode();
	}else{
	  turn_on_japanese_mode();
	}
      }
      return true;
  }
  return false;
}

typedef struct {
    bool left_thumb_shift;
    bool right_thumb_shift;
    uint16_t keycode;
    uint16_t key_sequence[3];
} keys_combination_t;

const keys_combination_t PROGMEM keys_combinations[] = {
  // 1st left
  // Q
  {false, false, KC_Q, {KC_DOT}},
  {true,  false, KC_Q, {KC_X, KC_A}},

  // W
  {false, false, KC_W, {KC_K, KC_A}},
  {true,  false, KC_W, {KC_E}},
  {false, true,  KC_W, {KC_G, KC_A}},

  // E
  {false, false, KC_E, {KC_T, KC_A}},
  {true,  false, KC_E, {KC_R, KC_I}},
  {false, true,  KC_E, {KC_D, KC_A}},

  // R
  {false, false, KC_R, {KC_K, KC_O}},
  {true,  false, KC_R, {KC_X, KC_Y, KC_A}},
  {false, true,  KC_R, {KC_G, KC_O}},

  // T
  {false, false, KC_T, {KC_S, KC_A}},
  {true,  false, KC_T, {KC_R, KC_E}},
  {false, true,  KC_T, {KC_Z, KC_A}},

  // 1st right
  // Y
  {false, false, KC_Y, {KC_R, KC_A}},
  {true,  false, KC_Y, {KC_P, KC_A}},
  {false, true,  KC_Y, {KC_Y, KC_O}},

  // U
  {false, false, KC_U, {KC_T, KC_I}},
  {true,  false, KC_U, {KC_D, KC_I}},
  {false, true,  KC_U, {KC_N, KC_I}},

  // I
  {false, false, KC_I, {KC_K, KC_U}},
  {true,  false, KC_I, {KC_G, KC_U}},
  {false, true,  KC_I, {KC_R, KC_U}},

  // O
  {false, false, KC_O, {KC_T, KC_U}},
  {true,  false, KC_O, {KC_D, KC_U}},
  {false, true,  KC_O, {KC_M, KC_A}},

  // P
  {false, false, KC_P, {KC_COMM}},
  {true,  false, KC_P, {KC_P, KC_I}},
  {false, true,  KC_P, {KC_X, KC_E}},

  // 2nd left
  // A
  {false, false, KC_A, {KC_U}},
  {true,  false, KC_A, {KC_W, KC_O}},
  {false, true,  KC_A, {KC_V, KC_U}},

  // S
  {false, false, KC_S, {KC_S, KC_I}},
  {true,  false, KC_S, {KC_A}},
  {false, true,  KC_S, {KC_J, KC_I}},

  // D
  {false, false, KC_D, {KC_T, KC_E}},
  {true,  false, KC_D, {KC_N, KC_A}},
  {false, true,  KC_D, {KC_D, KC_E}},

  // F
  {false, false, KC_F, {KC_K, KC_E}},
  {true,  false, KC_F, {KC_X, KC_Y, KC_U}},
  {false, true,  KC_F, {KC_G, KC_E}},

  // G
  {false, false, KC_G, {KC_S, KC_E}},
  {true,  false, KC_G, {KC_M, KC_O}},
  {false, true,  KC_G, {KC_Z, KC_E}},

  // 2nd right
  // H
  {false, false, KC_H, {KC_H, KC_A}},
  {true,  false, KC_H, {KC_B, KC_A}},
  {false, true,  KC_H, {KC_M, KC_I}},

  // J
  {false, false, KC_J, {KC_T, KC_O}},
  {true,  false, KC_J, {KC_D, KC_O}},
  {false, true,  KC_J, {KC_O}},

  // K
  {false, false, KC_K, {KC_K, KC_I}},
  {true,  false, KC_K, {KC_G, KC_I}},
  {false, true,  KC_K, {KC_N, KC_O}},

  // L
  {false, false, KC_L, {KC_I}},
  {true,  false, KC_L, {KC_P, KC_O}},
  {false, true,  KC_L, {KC_X, KC_Y, KC_O}},

  // ;
  {false, false, KC_SCOLON, {KC_N, KC_N}},
  {false,  true, KC_SCOLON, {KC_X, KC_T, KC_U}},

  // 3rd left
  // Z
  {false, false, KC_Z, {KC_DOT}},
  {true,  false, KC_Z, {KC_X, KC_U}},

  // X
  {false, false, KC_X, {KC_H, KC_I}},
  {true,  false, KC_X, {KC_MINUS}},
  {false, true,  KC_X, {KC_B, KC_I}},

  // C
  {false, false, KC_C, {KC_S, KC_U}},
  {true,  false, KC_C, {KC_R, KC_O}},
  {false, true,  KC_C, {KC_Z, KC_U}},

  // V
  {false, false, KC_V, {KC_F, KC_U}},
  {true,  false, KC_V, {KC_Y, KC_A}},
  {false, true,  KC_V, {KC_B, KC_U}},

  // B
  {false, false, KC_B, {KC_H, KC_E}},
  {true,  false, KC_B, {KC_X, KC_I}},
  {false, true,  KC_B, {KC_B, KC_E}},

  // 3rd right
  // N
  {false, false, KC_N, {KC_M, KC_E}},
  {true,  false, KC_N, {KC_P, KC_U}},
  {false, true,  KC_N, {KC_N, KC_U}},

  // M
  {false, false, KC_M, {KC_S, KC_O}},
  {true,  false, KC_M, {KC_Z, KC_O}},
  {false, true,  KC_M, {KC_Y, KC_U}},

  // ,
  {false, false, KC_COMMA, {KC_N, KC_E}},
  {true,  false, KC_COMMA, {KC_P, KC_E}},
  {false, true,  KC_COMMA, {KC_M, KC_U}},

  // .
  {false, false, KC_DOT, {KC_H, KC_O}},
  {true,  false, KC_DOT, {KC_B, KC_O}},
  {false, true,  KC_DOT, {KC_W, KC_A}},

  // /
  {false, true,  KC_SLASH, {KC_X, KC_O}},

};

keys_combination_t get_keys_combination(int index) {
  /*keys_combination_t data;*/
  /*memcpy_P(&data, &keys_combinations[index], sizeof(keys_combination_t));*/
  /*return data;*/
  return keys_combinations[index];
}

int keys_combinations_length = sizeof(keys_combinations) / sizeof(keys_combination_t);

bool send_key_sequence(bool left_thumb_shift, bool right_thumb_shift, uint16_t input_keycode) {
  for (int i = 0; i < keys_combinations_length; i++) {
    keys_combination_t c = get_keys_combination(i);
    if ( c.keycode == input_keycode &&
	!(c.left_thumb_shift ^ left_thumb_shift) &&
	!(c.right_thumb_shift ^ right_thumb_shift)) {
      int length = sizeof(c.key_sequence) / sizeof(uint16_t);
      for (int j = 0; j < length; j++) {
	uint16_t t = c.key_sequence[j];
	register_code(t);
	unregister_code(t);
      }
      return false;
    }
  }
  uint16_t send_kc = KC_NO;
  if (input_keycode != KC_NO) {
    send_kc = input_keycode;
  }else if(left_thumb_shift){
    send_kc = L_T_SFT;
  }else if(right_thumb_shift){
    send_kc = R_T_SFT;
  }
  register_code(send_kc);
  unregister_code(send_kc);
  return true;
}

uint16_t processing_keycode = KC_NO;
bool processing_left_t = false;
bool processing_right_t = false;

bool process_kana(uint8_t keycode, keyrecord_t *record){
  if (record->event.pressed) {
      switch (keycode) {
	case L_T_SFT:
	  processing_left_t = true;
	  break;
	case R_T_SFT:
	  processing_right_t = true;
	  break;
	default:
	  processing_keycode = keycode;
	  break;
      }
      return false;
    }else{
      bool l = processing_left_t;
      bool r = processing_right_t;
      uint16_t c = processing_keycode;
      processing_left_t = false;
      processing_right_t = false;
      processing_keycode = KC_NO;
      return send_key_sequence(l, r, c);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (process_modifier(keycode, record)){
    return true;
  }
  if (process_henk(keycode, record)){
    return false;
  }
  if (is_japanese_mode) {
    return process_kana(keycode, record);
  }
  return true;
}
