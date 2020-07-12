#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

#define EISU LALT(KC_GRV)

enum user_macro {
    UM_EMHL,
    UM_KHKR
};

#define M_EMHL MACROTAP(UM_EMHL)
#define M_KHKR MACROTAP(UM_KHKR)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | BREAK|   1  |   2  |   3  |   4  |   5  |   >  |                    |   <  |   6  |   7  |   8  |   9  |   0  |   \  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | DEBUG|   Q  |   W  |   E  |   R  |   T  |   Up  |                    |   Down  |   Y  |   U  |   I  |   O  |   P  |  `   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | TAB  |   A  |   S  |   D  |   F  |   G  |  PGDN |                    | PGUP |   H  |   J  |   K  |   L  |  ;   |  '   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | SHIFT|   Z  |   X  |   C  |   V  |   B  |  ALT |                    | DEL |   N  |   M  |   ,  |   .  |   [ | ] |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | F7 | PRINT|  LOCK  |  ESC |||||||| Lower |  GUI | CTRL |||||||| BACK | Enter| Raise |||||||| SPACE |  / |  - | =  |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT( \
    LGUI(KC_DOT),  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_RGHT,                        KC_LEFT, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS, \
    LGUI(KC_R),  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_UP,                        KC_DOWN , KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_GRV, \
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_PGDN ,                        KC_PGUP, KC_H,    KC_J,    KC_K,    KC_L,  KC_SCLN  ,  KC_QUOT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LALT ,                        KC_DEL , KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_LBRC , KC_RBRC, \
    KC_F7, LSFT(SGUI(KC_4)), G(C(KC_Q)), KC_ESC,            M_EMHL,   KC_LGUI ,KC_LCTL,         KC_BSPC,KC_ENT , M_KHKR,            KC_SPC, KC_SLSH, KC_MINS, KC_EQL  \
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | BREAK|  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   \  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | DEBUG|   !  |   +  |   1  |   2  |   3  |   [  |                    |   ]  |   ^  |   &  |   *  |   (  |   )  |  `   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | TAB  |   ^  |   -  |   4  |   5  |   6  |  PGDN  |                    |  PGUP  |  Left| Down |   Up | Right |  ;   |  '   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | SHIFT|   %  |   *  |   7  |   8  |   9  |  ALT |                    | DEL |   N  |   M  |   ,  |   .  |  [  |  ]  |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | F7 | PRINT|   /  |  0   |||||||| Lower |  GUI | CTRL |||||||| BACK | Enter |  Raise |||||||| SPACE| / | - | = |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT(
    LGUI(KC_DOT),  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_F7, KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,  KC_BSLS,  \
    LGUI(KC_R), KC_EXLM, KC_KP_PLUS,   KC_KP_1, KC_KP_2,  KC_KP_3, KC_LBRC,                        KC_RBRC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_GRV, \
    KC_TAB,  KC_CIRC,    KC_KP_MINUS,    KC_KP_4,    KC_KP_5,    KC_KP_6,    KC_PGDN ,                        KC_PGUP, KC_LEFT,    KC_DOWN,    KC_UP,    KC_RGHT, KC_SCLN , KC_QUOT, \
    KC_LSFT, KC_PERC,    KC_KP_ASTERISK,    KC_KP_7,    KC_KP_8,    KC_KP_9,    KC_LALT ,                        KC_DEL , KC_N,    KC_M,    KC_COMM,   KC_DOT,  KC_LBRC, KC_RBRC, \
    KC_F7, LSFT(SGUI(KC_4)), KC_KP_SLASH, KC_KP_0,             M_EMHL,   KC_LGUI , KC_LCTL,         KC_BSPC,KC_ENT , M_KHKR,            KC_SPC, KC_SLSH, KC_MINS, KC_EQL    \
  ),



  /* Raise
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | BREAK|  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   \  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | DEBUG|   !  |   +  |   1  |   2  |   3  |   [  |                    |   ]  |   ^  |   &  |   *  |   (  |   )  |  `   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | TAB  |   ^  |   -  |   4  |   5  |   6  |  PGDN  |                    |  PGUP  |  Left| Down |   Up | Right |  ;   |  '   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | SHIFT|   %  |   *  |   7  |   8  |   9  |  ALT |                    | DEL |   N  |   M  |   ,  |   .  |  [  |  ]  |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | F7 | PRINT|   /  |  0   |||||||| Lower |  GUI | CTRL |||||||| BACK | Enter |  Raise |||||||| SPACE| / | - | = |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_RAISE] = LAYOUT(
    LGUI(KC_DOT),  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_F7, KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,  KC_BSLS,  \
    LGUI(KC_R), KC_EXLM, KC_KP_PLUS,   KC_KP_1, KC_KP_2,  KC_KP_3, KC_LBRC,                        KC_RBRC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_GRV, \
    KC_TAB,  KC_CIRC,    KC_KP_MINUS,    KC_KP_4,    KC_KP_5,    KC_KP_6,    KC_PGDN ,                        KC_PGUP, KC_LEFT,    KC_DOWN,    KC_UP,    KC_RGHT,  KC_SCLN, KC_QUOT, \
    KC_LSFT, KC_PERC,    KC_KP_ASTERISK,    KC_KP_7,    KC_KP_8,    KC_KP_9,    KC_LALT ,                        KC_DEL , KC_N,    KC_M,    KC_COMM,   KC_DOT,  KC_LBRC, KC_RBRC, \
    KC_F7, LSFT(SGUI(KC_4)), KC_KP_SLASH, KC_KP_0,             M_EMHL,   KC_LGUI , KC_LCTL,         KC_BSPC,KC_ENT , M_KHKR,            KC_SPC, KC_SLSH, KC_MINS, KC_EQL   \
  ),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      | Reset|RGB ON|  MODE|  HUE-|  HUE+|      |                    |      |  SAT-|  SAT+|  VAL-|  VAL+|      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      | BL ON|  BRTG|  INC|   DEC|      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT(
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,_______,                       _______, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, _______, \
    _______, _______, BL_TOGG, BL_BRTG, BL_INC , BL_DEC ,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______,          _______,_______,_______,       _______,_______, _______,          _______, _______, _______, _______  \
  )
};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
         print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    switch (id) {
        case UM_EMHL:
            return MACRO_TAP_HOLD_LAYER(record, MACRO(T(MHEN), T(LANG2), END), _LOWER);
        case UM_KHKR:
            return MACRO_TAP_HOLD_LAYER(record, MACRO(T(HENK), T(LANG1), END), _RAISE);
    };
    return MACRO_NONE;
}
