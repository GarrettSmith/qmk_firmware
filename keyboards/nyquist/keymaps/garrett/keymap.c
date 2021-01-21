#include QMK_KEYBOARD_H

#include "keymap_steno.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _SHIFT 1
#define _RAISE 2
#define _BOARD 3

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Thumb Layers
#define LT_RBS  LT(_RAISE, KC_BSPC)
#define LT_RDEL LT(_RAISE, KC_DEL)

// Shifted Mod Taps
#define MT_LSFT KC_LEFT_PAREN
#define MT_RSFT KC_RIGHT_PAREN

#define MT_LCTL MT(MOD_LCTL, KC_LBRACKET)
#define MT_RCTL MT(MOD_RCTL, KC_RBRACKET)

#define MT_LSCTL MT(MOD_LCTL, KC_LEFT_ANGLE_BRACKET)
#define MT_RSCTL MT(MOD_RCTL, KC_RIGHT_ANGLE_BRACKET)

#define MT_LALT MT(MOD_LALT, KC_LEFT_ANGLE_BRACKET)
#define MT_RALT MT(MOD_RALT, KC_RIGHT_ANGLE_BRACKET)

// Layer Toggles
#define MO_BRD MO(_BOARD)

// Macro Keys
enum custom_keycodes {
  FN_PSTE = SAFE_RANGE,
  FN_COPY,
  FN_CUT,
  FN_DWRD,
  FN_FWRD,
  FN_BWRD,
  FN_CLR,
  FN_OPEN,
  FN_FIND,

  FN_SNIP,
  FN_PRWN,

  FN_QUIT,
  FN_MLFT,
  FN_MRHT,
  FN_WINS,

  FN_EMO,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT( \
// ┌─━━─━━━━┬━━━━━━━━┬━━━━━━━━┬━━━━━━━━┬━━━━━━━━┬━━━━━━━┐ ┌─━━─━━━━┬━━━━━━━━┬━━━━━━━━┬━━━━━━━━┬━━━━━━━━┬━━━━━━━━┐
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    FN_EMO, \
// ├─━━─━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━┦ ├─━━─━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━┦
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,\
// ├─━━─━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━┦ ├─━━─━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━┦
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,\
// ├─━━─━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━┦ ├─━━─━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━┦
    MT_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MT_RSFT,\
// ├─━━─━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━┦ ├─━━─━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━┦
    MT_LCTL, KC_LGUI, XXXXXXX, MT_LALT, LT_RBS,  KC_SPC,   KC_ENT,  LT_RDEL, MT_RALT, XXXXXXX, KC_RGUI, MT_RCTL \
// └─━━─━━━━┴━━━━━━━━┴━━━━━━━━┴━━━━━━━━┴━━━━━━━━┴━━━━━━━┘ └─━━─━━━━┴━━━━━━━━┴━━━━━━━━┴━━━━━━━━┴━━━━━━━━┴━━━━━━━━┘
),

[_SHIFT] = LAYOUT( \
// ┌─━━─━━━━┬━━━━━━━━┬━━━━━━━━┬━━━━━━━━┬━━━━━━━━┬━━━━━━━┐ ┌─━━─━━━━┬━━━━━━━━┬━━━━━━━━┬━━━━━━━━┬━━━━━━━━┬━━━━━━━━┐
    _______, _______, _______, _______, _______, _______,  _______, _______, _______, KC_UNDS, KC_PLUS, _______,\
// ├─━━─━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━┦ ├─━━─━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━┦
    _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______,\
// ├─━━─━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━┦ ├─━━─━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━┦
    _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______,\
// ├─━━─━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━┦ ├─━━─━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━┦
    KC_LCBR, _______, _______, _______, _______, _______,  _______, _______, KC_MINS, KC_EQL,  _______, KC_RCBR,\
// ├─━━─━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━┦ ├─━━─━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━┦
    MT_LSCTL,_______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, MT_RSCTL\
// └─━━─━━━━┴━━━━━━━━┴━━━━━━━━┴━━━━━━━━┴━━━━━━━━┴━━━━━━━┘ └─━━─━━━━┴━━━━━━━━┴━━━━━━━━┴━━━━━━━━┴━━━━━━━━┴━━━━━━━━┘
),

[_RAISE] = LAYOUT( \
// ┌─━━─━━━━┬━━━━━━━━┬━━━━━━━━┬━━━━━━━━┬━━━━━━━━┬━━━━━━━┐ ┌─━━─━━━━┬━━━━━━━━┬━━━━━━━━┬━━━━━━━━┬━━━━━━━━┬━━━━━━━━┐
    KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12, \
// ├─━━─━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━┦ ├─━━─━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━┦
    FN_WINS, FN_QUIT, FN_DWRD, KC_END,  KC_MPRV, XXXXXXX,  FN_COPY, KC_PGUP, KC_INS,  FN_OPEN, FN_PSTE, XXXXXXX,\
// ├─━━─━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━┦ ├─━━─━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━┦
    KC_PAUS, KC_HOME, FN_SNIP, KC_PGDN, FN_FWRD, XXXXXXX,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, FN_MLFT, FN_MRHT,\
// ├─━━─━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━┦ ├─━━─━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━┦
    _______, KC_PSCR,  FN_CUT,  FN_CLR, FN_PRWN, FN_BWRD,  KC_MNXT, KC_MUTE, KC_VOLU, KC_VOLD, FN_FIND, _______,\
// ├─━━─━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━┦ ├─━━─━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━┦
    _______, _______, _______, _______,  MO_BRD, KC_MPLY,  KC_MPLY,  MO_BRD, _______, _______, _______, _______ \
// └─━━─━━━━┴━━━━━━━━┴━━━━━━━━┴━━━━━━━━┴━━━━━━━━┴━━━━━━━┘ └─━━─━━━━┴━━━━━━━━┴━━━━━━━━┴━━━━━━━━┴━━━━━━━━┴━━━━━━━━┘
),

[_BOARD] = LAYOUT( \
// ┌─━━─━━━━┬━━━━━━━━┬━━━━━━━━┬━━━━━━━━┬━━━━━━━━┬━━━━━━━┐ ┌─━━─━━━━┬━━━━━━━━┬━━━━━━━━┬━━━━━━━━┬━━━━━━━━┬━━━━━━━━┐
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
// ├─━━─━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━┦ ├─━━─━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━┦
    XXXXXXX,   RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  RGB_M_P, RGB_HUD, RGB_HUI, RGB_M_R, XXXXXXX, XXXXXXX,\
// ├─━━─━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━┦ ├─━━─━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━┦
    XXXXXXX, XXXXXXX,   DEBUG, XXXXXXX, XXXXXXX, XXXXXXX,  RGB_MOD, RGB_VAD, RGB_VAI, RGB_RMOD,RGB_TOG, XXXXXXX,\
// ├─━━─━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━┦ ├─━━─━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━┦
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  RGB_M_B, RGB_SAD, RGB_SAI, RGB_M_G, XXXXXXX, XXXXXXX,\
// ├─━━─━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━┦ ├─━━─━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━┦
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
// └─━━─━━━━┴━━━━━━━━┴━━━━━━━━┴━━━━━━━━┴━━━━━━━━┴━━━━━━━┘ └─━━─━━━━┴━━━━━━━━┴━━━━━━━━┴━━━━━━━━┴━━━━━━━━┴━━━━━━━━┘
)

};

typedef struct {
  uint16_t h;
  uint8_t s;
  uint8_t v;
} hsv;

const hsv layer_colors[] = {
[_QWERTY] = {0, 255, 255},
[_SHIFT] = {0, 255, 255},
[_RAISE] = {0, 255, 255},
[_BOARD] = {0, 255, 255}
};

static bool shifted = false;

bool register_unshifted_code(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    unregister_mods(MOD_LSFT);
    register_code(keycode);
  } else {
    unregister_code(keycode);
    if (shifted == true) {
      register_mods(MOD_LSFT);
    }
  }
  return false;
}

bool process_shift(uint16_t keycode, keyrecord_t *record) {
  static keyrecord_t sftRecord = {};

  switch (keycode) {
    case MT_LSFT:
    case MT_RSFT: {
      if (record->event.pressed) {
        register_mods(MOD_LSFT);
        shifted = true;
        layer_on(_SHIFT);
        sftRecord = *record;
      } else {
        if (
            !sftRecord.tap.interrupted &&
            TIMER_DIFF_16(record->event.time, sftRecord.event.time) < TAPPING_TERM
        ) {
          register_code(keycode);
          unregister_code(keycode);
        }
        unregister_mods(MOD_LSFT);
        shifted = false;
        layer_off(_SHIFT);
      }
      return false;
    }
  }

  sftRecord.tap.interrupted = true;
  return true;
}

bool process_macros(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case FN_CUT:
        SEND_STRING(SS_LCTRL("x"));
        return false;
      case FN_COPY:
        SEND_STRING(SS_LCTRL("c"));
        return false;
      case FN_PSTE:
        SEND_STRING(SS_LSFT(SS_TAP(X_INSERT)));
        return false;
      case FN_FIND:
        SEND_STRING(SS_LCTRL("cfv"));
        return false;

      case FN_DWRD:
        SEND_STRING(SS_LCTRL(SS_LSFT(SS_TAP(X_LEFT))) SS_TAP(X_DELETE));
        return false;
      case FN_BWRD:
        SEND_STRING(SS_LCTRL(SS_TAP(X_LEFT)));
        return false;
      case FN_FWRD:
        SEND_STRING(SS_LCTRL(SS_TAP(X_RIGHT)));
        return false;
      case FN_CLR:
        SEND_STRING(SS_LCTRL("a") SS_TAP(X_DELETE));
        return false;
      case FN_OPEN:
        SEND_STRING(SS_TAP(X_END) SS_TAP(X_ENTER));
        return false;

      case FN_PRWN:
        SEND_STRING(SS_LALT(SS_TAP(X_PSCREEN)));
        return false;
      case FN_SNIP:
        SEND_STRING(SS_LGUI(SS_LSFT("s")));
        return false;

      case FN_QUIT:
        SEND_STRING(SS_LALT(SS_TAP(X_F4)));
        return false;
      case FN_MLFT:
        SEND_STRING(SS_LGUI(SS_TAP(X_LEFT)));
        return false;
      case FN_MRHT:
        SEND_STRING(SS_LGUI(SS_TAP(X_RIGHT)));
        return false;
      case FN_WINS:
        SEND_STRING(SS_LGUI(SS_TAP(X_TAB)));
        return false;

      case FN_EMO:
        SEND_STRING(SS_LGUI(SS_TAP(X_DOT)));
        return false;
    }
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_shift(keycode, record)) return false;
  if (!process_macros(keycode, record)) return false;

  // unshifted keys
  switch (keycode) {
    case KC_MINS:
      return register_unshifted_code(KC_MINS, record);
    case KC_EQL:
      return register_unshifted_code(KC_EQL, record);
  }

  return true;
};

uint32_t layer_state_set_user(uint32_t state) {
  uint32_t stateBit = biton32(state);
  hsv layerColor = layer_colors[stateBit];
  rgblight_sethsv(layerColor.h, layerColor.s, layerColor.v);
  return state;
}

void matrix_init_user() {
  steno_set_mode(STENO_MODE_GEMINI); // or STENO_MODE_BOLT
}

void suspend_power_down_user(void) {
}

void suspend_wakeup_init_user(void) {
}
