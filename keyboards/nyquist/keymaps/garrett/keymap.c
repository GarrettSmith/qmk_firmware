#include QMK_KEYBOARD_H

#include "keymap_steno.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _SHIFT 1
#define _PLOVER 2
#define _RAISE 3

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Thumb Layers
#define LT_RBS  LT(_RAISE, KC_BSPC)
#define LT_RSPC LT(_RAISE, KC_SPC)
#define LT_RENT LT(_RAISE, KC_ENT)
#define LT_RDEL LT(_RAISE, KC_DEL)

  // Shifted Mod Taps
#define LT_LSFT LT(_SHIFT, KC_LEFT_PAREN)
#define LT_RSFT LT(_SHIFT, KC_RIGHT_PAREN)

#define MT_LCTL MT(MOD_LCTL, KC_LBRACKET)
#define MT_RCTL MT(MOD_RCTL, KC_RBRACKET)

#define MT_LSCTL MT(MOD_LCTL, KC_LEFT_ANGLE_BRACKET)
#define MT_RSCTL MT(MOD_RCTL, KC_RIGHT_ANGLE_BRACKET)

// Toggle Steno
#define TG_PLV TG(_PLOVER)

enum custom_keycodes {
  FN_PSTE = SAFE_RANGE,
  FN_DWRD,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------. ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  | |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  | |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  | |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  | |   N  |   M  |   ,  |   .  |   /  | Shift|
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Ctrl | LGUI |      | Alt  | Bspc |Space | |Enter | Del  | Alt  |      |      | Ctrl |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_QWERTY] = LAYOUT( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  LT_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, LT_RSFT, \
  MT_LCTL, KC_LALT, XXXXXXX, KC_LGUI, LT_RBS,  KC_SPC,     KC_ENT,  LT_RDEL, KC_RGUI, XXXXXXX, XXXXXXX, MT_RCTL  \
),

/* Shift
 * ,-----------------------------------------. ,-----------------------------------------.
 * |      |      |      |      |      |      | |      |      |      |   _  |   +  |Plover|
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |  {   |      |      |      |      |      | |      |      |   -  |   =  |      |  }   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |  <   |      |      |      |      |      | |      |      |      |      |      |  >   |
 * `-----------------------------------------' `-----------------------------------------'
 */

[_SHIFT] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,    _______, _______, _______, KC_UNDS, KC_PLUS,  TG_PLV, \
  _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, \
  KC_LCBR, _______, _______, _______, _______, _______,    _______, _______, KC_MINS, KC_EQL,  _______, KC_RCBR, \
  MT_LSCTL,_______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,MT_RSCTL  \
),

/* Steno
 * ,-----------------------------------------. ,-----------------------------------------.
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_PLOVER] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  TG_PLV, \
  STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,  STN_N6,     STN_N7,   STN_N8,  STN_N9,  STN_NA,  STN_NB,  STN_NC, \
  STN_FN,  STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1,    STN_ST3,  STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR, \
  XXXXXXX, STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2,    STN_ST4,  STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR, \
  XXXXXXX, XXXXXXX, XXXXXXX, STN_A,   STN_O,   XXXXXXX,    XXXXXXX,  STN_E,   STN_U,   STN_PWR, STN_RE1, STN_RE2 \
),

/* Raise
 * ,-----------------------------------------. ,-----------------------------------------.
 * | F11  |  F1  |  F2  |  F3  |  F4  |  F5  | |  F6  |  F7  |  F8  |  F9  |  F10 | F12  |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |D Word|      |      |      | | Home | PgDn | PgUp | End  | PrSc | Ins  |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | | Left | Down |  Up  | Right|      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |PASTE |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_RAISE] = LAYOUT( \
  KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,  \
  _______, _______, FN_DWRD, _______, _______, _______,    KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_PSCR, KC_INS,  \
  _______, _______, _______, _______, _______, _______,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, \
  _______, _______, _______, _______, FN_PSTE, _______,    _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______  \
)

};

bool register_unshifted_code(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    unregister_mods(MOD_LSFT);
    register_code(keycode);
  } else {
    unregister_code(keycode);
    register_mods(MOD_LSFT);
  }
  return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    // shift layer
    case LT_LSFT:
    case LT_RSFT: {
      if (record->event.pressed) {
        register_mods(MOD_LSFT);
      } else {
        unregister_mods(MOD_LSFT);
      }
      break;
    }
    case TG_PLV:
      if (record->event.pressed) {
        rgblight_toggle();
      }
      break;

    // unshifted keys
    case KC_MINS:
      return register_unshifted_code(KC_MINS, record);
    case KC_EQL:
      return register_unshifted_code(KC_EQL, record);
  }

  // macros
  if (record->event.pressed) {
    switch (keycode) {
      case FN_PSTE:
        SEND_STRING(SS_LSFT(SS_TAP(X_INSERT)));
        return false;
      case FN_DWRD:
        SEND_STRING(SS_LCTRL(SS_LSFT(SS_TAP(X_LEFT))) SS_TAP(X_DELETE));
        return false;
    }
  }

  return true;
};

void matrix_init_user() {
  steno_set_mode(STENO_MODE_GEMINI); // or STENO_MODE_BOLT
}
