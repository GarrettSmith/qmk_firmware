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

// Macro Keys
enum custom_keycodes {
  FN_PSTE = SAFE_RANGE,
  FN_DWRD,

  FN_SNIP,
  FN_PRWN,

  FN_QUIT,

  FN_MLFT,
  FN_MRHT,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT( \
// ┌─━━─━━━━┬━━━━━━━━┬━━━━━━━━┬━━━━━━━━┬━━━━━━━━┬━━━━━━━┐ ┌─━━─━━━━┬━━━━━━━━┬━━━━━━━━┬━━━━━━━━┬━━━━━━━━┬━━━━━━━━┐
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,\
// ├─━━─━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━┦ ├─━━─━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━┦
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,\
// ├─━━─━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━┦ ├─━━─━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━┦
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,\
// ├─━━─━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━┦ ├─━━─━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━┦
    LT_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, LT_RSFT,\
// ├─━━─━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━┦ ├─━━─━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━┦
    MT_LCTL, KC_LGUI, XXXXXXX, KC_LALT, LT_RBS,  KC_SPC,   KC_ENT,  LT_RDEL, KC_RALT, XXXXXXX, KC_RGUI, MT_RCTL \
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

[_PLOVER] = LAYOUT( \
// ┌─━━─━━━━┬━━━━━━━━┬━━━━━━━━┬━━━━━━━━┬━━━━━━━━┬━━━━━━━┐ ┌─━━─━━━━┬━━━━━━━━┬━━━━━━━━┬━━━━━━━━┬━━━━━━━━┬━━━━━━━━┐
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TG_PLV, \
// ├─━━─━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━┦ ├─━━─━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━┦
    STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,  STN_N6,   STN_N7,  STN_N8,  STN_N9,  STN_NA,  STN_NB,  STN_NC, \
// ├─━━─━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━┦ ├─━━─━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━┦
    STN_FN,  STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1,  STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR, \
// ├─━━─━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━┦ ├─━━─━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━┦
    XXXXXXX, STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2,  STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR, \
// ├─━━─━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━┦ ├─━━─━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━┦
    XXXXXXX, XXXXXXX, XXXXXXX, STN_A,   STN_O,   XXXXXXX,  XXXXXXX, STN_E,   STN_U,   STN_PWR, STN_RE1, STN_RE2 \
// └─━━─━━━━┴━━━━━━━━┴━━━━━━━━┴━━━━━━━━┴━━━━━━━━┴━━━━━━━┘ └─━━─━━━━┴━━━━━━━━┴━━━━━━━━┴━━━━━━━━┴━━━━━━━━┴━━━━━━━━┘
),

[_RAISE] = LAYOUT( \
// ┌─━━─━━━━┬━━━━━━━━┬━━━━━━━━┬━━━━━━━━┬━━━━━━━━┬━━━━━━━┐ ┌─━━─━━━━┬━━━━━━━━┬━━━━━━━━┬━━━━━━━━┬━━━━━━━━┬━━━━━━━━┐
    KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12, \
// ├─━━─━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━┦ ├─━━─━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━┦
    XXXXXXX, FN_QUIT, FN_DWRD, KC_END,  XXXXXXX, XXXXXXX,  FN_PRWN, KC_PGUP, KC_WFWD, KC_WBAK, KC_PSCR, KC_INS, \
// ├─━━─━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━┦ ├─━━─━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━┦
    KC_PAUS, KC_HOME, FN_SNIP, KC_PGDN, XXXXXXX, XXXXXXX,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,\
// ├─━━─━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━┦ ├─━━─━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━┦
    _______, XXXXXXX,  KC_CUT, KC_COPY, FN_PSTE, KC_MPRV,  KC_MNXT, KC_MUTE, KC_VOLU, KC_VOLD, XXXXXXX, _______,\
// ├─━━─━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━┦ ├─━━─━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━╀━━━━━━━━┦
    _______, _______, _______, FN_MLFT, TG_PLV,  KC_MPLY,  KC_MPLY, TG_PLV,  FN_MRHT, _______, _______, _______ \
// └─━━─━━━━┴━━━━━━━━┴━━━━━━━━┴━━━━━━━━┴━━━━━━━━┴━━━━━━━┘ └─━━─━━━━┴━━━━━━━━┴━━━━━━━━┴━━━━━━━━┴━━━━━━━━┴━━━━━━━━┘
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
    }
  }

  return true;
};

uint32_t layer_state_set_user(uint32_t state) {
  rgblight_enable();
  switch (biton32(state)) {
    case _PLOVER:
      rgblight_setrgb_cyan();
      break;
    case _RAISE:
      rgblight_setrgb_red();
      break;
    default:
      rgblight_disable();
  }
  return state;
}

void matrix_init_user() {
  steno_set_mode(STENO_MODE_GEMINI); // or STENO_MODE_BOLT
}

void suspend_power_down_user(void) {
  rgblight_enable();
}

void suspend_wakeup_init_user(void) {
  rgblight_disable();
}
