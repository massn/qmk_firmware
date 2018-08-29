#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

#define L_T_SFT KC_SPC
#define R_T_SFT KC_ENT

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  |  [   |           |   ]  |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  | HENK |           | L1   |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCTL   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |' / Cmd |
 * |--------+------+------+------+------+------|LGui+ |           |Alt   |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |LAlt  |           |+SPC  |   N  |   M  |   ,  |   .  |  /   | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf|   {  |   (  |                                       |   )  |   }  |   ~  |      | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | Home |       | PgUp  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | LGui |       | LAlt |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_EQL,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_LBRC,
        KC_DELT,        KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   KC_HENK,
        KC_LCTL,        KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,        KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   LGUI(KC_LALT),
        LT(SYMB,KC_GRV),KC_QUOT,      LALT(KC_LSFT),  LSFT(KC_LBRC),  KC_LPRN,
                                              ALT_T(KC_APP),  KC_HOME,
                                                              KC_END,
                                               KC_SPC,KC_BSPC,KC_LGUI,
        // right hand
             KC_RBRC,     KC_6,   KC_7,  KC_8,   KC_9,      KC_0,             KC_MINS,
             TG(SYMB),    KC_Y,   KC_U,  KC_I,   KC_O,      KC_P,             KC_BSLS,
                          KC_H,   KC_J,  KC_K,   KC_L,      KC_SCLN,          GUI_T(KC_QUOT),
         LALT(KC_SPC),    KC_N,   KC_M,  KC_COMM,KC_DOT,    KC_SLSH,          KC_RSFT,
                                  KC_RPRN,LSFT(KC_RBRC), LSFT(KC_GRV),     KC_NO,       KC_FN1,
             KC_PGUP,        CTL_T(KC_ESC),
             KC_PGDN,
             KC_LALT,KC_TAB, KC_ENT
    ),

/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       |      |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       VRSN,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
          EPRM,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       RGB_MOD,KC_TRNS,
                                               KC_TRNS,
                               RGB_VAD,RGB_VAI,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                         KC_TRNS,KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
       RGB_TOG, RGB_SLD,
       KC_TRNS,
       KC_TRNS, RGB_HUD, RGB_HUI
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

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

int keys_combinations_length = sizeof(keys_combinations) / sizeof(keys_combination_t);

keys_combination_t get_keys_combination(int index) {
  keys_combination_t data;
  memcpy_P(&data, &keys_combinations[index], sizeof(keys_combination_t));
  return data;
}

bool is_japanese_mode = false;

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

bool processing_left_t = false;
bool processing_right_t = false;
uint16_t processing_keycode = KC_NO;

bool is_modifier(uint16_t keycode){
    switch(keycode){
        case KC_BSPC:
        case KC_LCTL:
        case KC_TAB:
        case KC_LGUI:
        case KC_LSFT:
        case KC_LPRN:
        case KC_RPRN:
            return true;
            break;
        default:
            return false;
            break;
    }
}
bool processing_modifier = false;

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
    case 1:
      if (record->event.pressed) { // For resetting EEPROM
        eeconfig_init();
      }
      break;
  }
  return MACRO_NONE;
};

void turn_on_japanese_mode(void) {
  if(!is_japanese_mode){
    SEND_STRING(SS_TAP(X_RGUI));
    SEND_STRING(SS_TAP(X_LANG1));
    is_japanese_mode = true;
#ifdef RGBLIGHT_COLOR_LAYER_2
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
#endif
  }
}

void turn_off_japanese_mode(void) {
  if (is_japanese_mode) {
    SEND_STRING(SS_TAP(X_LGUI));
    SEND_STRING(SS_TAP(X_LANG2));
    is_japanese_mode = false;
#ifdef RGBLIGHT_COLOR_LAYER_0
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    if (is_modifier(keycode)){
        if (record->event.pressed){
            processing_modifier = true;
        }else{
            processing_modifier = false;
        }
        return true;
    }else if(processing_modifier){
        return true;
    }

  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
    case KC_HENK:
      if (record->event.pressed && biton32(layer_state) == BASE) {
          if (is_japanese_mode) {
            turn_off_japanese_mode();
          }else{
            turn_on_japanese_mode();
          }
      }
      return false;
      break;
  }

  if (is_japanese_mode) {
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
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_1
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
#endif
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case SYMB:
        turn_off_japanese_mode();
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }

  return state;
};
