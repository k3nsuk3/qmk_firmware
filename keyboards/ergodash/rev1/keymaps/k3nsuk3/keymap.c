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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | BREAK|   1  |   2  |   3  |   4  |   5  |   -  |                    |   =  |   6  |   7  |   8  |   9  |   0  |   \  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | DEBUG|   Q  |   W  |   E  |   R  |   T  |   [  |                    |   ]  |   Y  |   U  |   I  |   O  |   P  |  `   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | TAB  |   A  |   S  |   D  |   F  |   G  |  ->  |                    |  <-  |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | SHIFT|   Z  |   X  |   C  |   V  |   B  |  DEL |                    | BACK |   N  |   M  |   ,  |   .  |   Up | Down |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | LOCK | PRINT|  F7  |  ESC |||||||| CTRL |  GUI | Lower|||||||| Raise| Enter| ALT|||||||| SPACE |  PGDN |  PGUP|   /  |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT( \
    LGUI(KC_DOT),  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS,                        KC_EQL, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS, \
    LGUI(KC_R),  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,                        KC_RBRC , KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_GRV, \
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_RGHT ,                        KC_LEFT, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_DEL ,                        KC_BSPC , KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP, KC_DOWN, \
    G(C(KC_Q)), SGUI(KC_4), KC_F7, KC_ESC,            KC_LCTL,   KC_LGUI ,LOWER,         RAISE,KC_ENT , KC_RALT,            KC_SPC, KC_PGDN, KC_PGUP,   KC_SLSH  \
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | BREAK|  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   \  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | DEBUG|   !  |   +  |   1  |   2  |   3  |   [  |                    |   ]  |   ^  |   &  |   *  |   (  |   )  |  `   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | TAB  |   ^  |   -  |   4  |   5  |   6  |  ->  |                    |  <-  |  Left| Down |   Up | Right|   ;  |  '   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | SHIFT|   %  |   *  |   7  |   8  |   9  |  DEL |                    | BACK |   N  |   M  |   ,  |   .  |  Up  | Down |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | LOCK | PRINT|   /  |  0   |||||||| CTRL |  GUI | Lower|||||||| Raise| Enter|  ALT |||||||| SPACE|PageDn|PageUp|   /  |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT(
    LGUI(KC_DOT),  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_F7, KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,  KC_BSLS,  \
    LGUI(KC_R), KC_EXLM, KC_KP_PLUS,   KC_KP_1, KC_KP_2,  KC_KP_3, KC_LBRC,                        KC_RBRC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_GRV, \
    KC_TAB,  KC_CIRC,    KC_KP_MINUS,    KC_KP_4,    KC_KP_5,    KC_KP_6,    KC_RGHT ,                        KC_LEFT, KC_LEFT,    KC_DOWN,    KC_UP,    KC_RGHT,    KC_SCLN, KC_QUOT , \
    KC_LSFT, KC_PERC,    KC_KP_ASTERISK,    KC_KP_7,    KC_KP_8,    KC_KP_9,    KC_DEL ,                        KC_BSPC , KC_N,    KC_M,    KC_COMM,   KC_DOT,   KC_UP, KC_DOWN, \
    G(C(KC_Q)), SGUI(KC_4), KC_KP_SLASH, KC_KP_0,             KC_LCTL,   KC_LGUI ,LOWER,         RAISE,KC_ENT , KC_RALT,            KC_SPC, KC_PGDN, KC_PGUP, KC_SLSH   \
  ),

  /* Raise
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | BREAK|  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   \  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | DEBUG|   !  |   +  |   1  |   2  |   3  |   [  |                    |   ]  |   ^  |   &  |   *  |   (  |   )  |  `   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | TAB  |   ^  |   -  |   4  |   5  |   6  |  ->  |                    |  <-  |  Left| Down |   Up | Right|   ;  |  '   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | SHIFT|   %  |   *  |   7  |   8  |   9  |  DEL |                    | BACK |   N  |   M  |   ,  |   .  |  Up  | Down |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | LOCK | PRINT|   /  |  0   |||||||| CTRL |  GUI | Lower|||||||| Raise| Enter|  ALT |||||||| SPACE|PageDn|PageUp|   /  |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_RAISE] = LAYOUT(
    LGUI(KC_DOT),  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_F7, KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,  KC_BSLS,  \
    LGUI(KC_R), KC_EXLM, KC_KP_PLUS,   KC_KP_1, KC_KP_2,  KC_KP_3, KC_LBRC,                        KC_RBRC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_GRV, \
    KC_TAB,  KC_CIRC,    KC_KP_MINUS,    KC_KP_4,    KC_KP_5,    KC_KP_6,    KC_RGHT ,                        KC_LEFT, KC_LEFT,    KC_DOWN,    KC_UP,    KC_RGHT,    KC_SCLN, KC_QUOT , \
    KC_LSFT, KC_PERC,    KC_KP_ASTERISK,    KC_KP_7,    KC_KP_8,    KC_KP_9,    KC_DEL ,                        KC_BSPC , KC_N,    KC_M,    KC_COMM,   KC_DOT,   KC_UP, KC_DOWN, \
    G(C(KC_Q)), SGUI(KC_4), KC_KP_SLASH, KC_KP_0,             KC_LCTL,   KC_LGUI ,LOWER,         RAISE,KC_ENT , KC_RALT,            KC_SPC, KC_PGDN, KC_PGUP, KC_SLSH   \
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
