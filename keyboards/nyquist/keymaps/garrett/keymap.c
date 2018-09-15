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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------. ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  | |   6  |   7  |   8  |   9  |   0  | Steno|
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  | |   Y  |   U  |   I  |   O  |   P  |  |   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  | |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  | |   N  |   M  |   ,  |   .  |   /  | Shift|
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Ctrl | LGUI |      | Alt  | Bspc |Space | |Enter | Del  | Alt  |      |      | Ctrl |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_QWERTY] = LAYOUT( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    TG_PLV, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_PIPE, \
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  LT_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, LT_RSFT, \
  MT_LCTL, KC_LALT, XXXXXXX, KC_LGUI, LT_RBS,  LT_RSPC, LT_RENT, LT_RDEL, KC_RGUI, XXXXXXX, XXXXXXX, MT_RCTL  \
),

/* Shift
 * ,-----------------------------------------. ,-----------------------------------------.
 * |      |      |      |      |      |      | |      |      |      |   _  |   +  |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |  {   |      |      |      |      |      | |      |      |   -  |   =  |      |  }   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |  <   |      |      |      |      |      | |      |      |      |      |      |  >   |
 * `-----------------------------------------' `-----------------------------------------'
 */

[_SHIFT] = LAYOUT( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  KC_LCBR, _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  _______, KC_RCBR, \
  MT_LSCTL,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,MT_RSCTL  \
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
   STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5, STN_N6,     STN_N7,   STN_N8,  STN_N9,  STN_NA,  STN_NB,  STN_NC, \
   STN_FN,  STN_S1,  STN_TL,  STN_PL,  STN_HL, STN_ST1,    STN_ST3,  STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR, \
  XXXXXXX,  STN_S2,  STN_KL,  STN_WL,  STN_RL, STN_ST2,    STN_ST4,  STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR, \
  XXXXXXX, XXXXXXX, XXXXXXX,  STN_A,   STN_O,  XXXXXXX,    XXXXXXX,  STN_E,   STN_U,   STN_PWR, STN_RE1, STN_RE2 \
),

/* Raise
 * ,-----------------------------------------. ,-----------------------------------------.
 * | F11  |  F1  |  F2  |  F3  |  F4  |  F5  | |  F6  |  F7  |  F8  |  F9  |  F10 |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | F12  |      |      |      |      |      | | Home | PgDn | PgUp | End  | PrSc | Ins  |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | | Left | Down |  Up  | Right|      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_RAISE] = LAYOUT( \
  KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, \
  KC_F12,  _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_PSCR, KC_INS,  \
  _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
)

};

// Allow shifted keycodes in mod taps
// https://github.com/qmk/qmk_firmware/pull/2055
bool process_action_user(keyrecord_t *record, action_t action) {
  uint8_t tap_count = record->tap.count;
  keyevent_t event = record->event;

  switch(action.kind.id) {
    case ACT_LMODS_TAP:
    case ACT_RMODS_TAP: {
      uint8_t mods = (action.kind.id == ACT_LMODS_TAP) ?  action.key.mods : action.key.mods << 4;
      uint16_t shift = mods & (MOD_LSFT | (MOD_RSFT << 4));

      if (event.pressed) {
        if (tap_count > 0) {
#ifndef IGNORE_MOD_TAP_INTERRUPT
          if (record->tap.interrupted) {
            dprint("mods_tap: tap: cancel: add_mods\n");
            // ad hoc: set 0 to cancel tap
            record->tap.count = 0;
            register_mods(mods);
            // If shift is present, but not
            // the only modifier, consider it
            // part of the tapped keycode.
            // Don't register it as a
            // modifier.
            if (shift && mods != shift) {
              register_mods(mods & ~shift);
            } else {
              register_mods(mods);
            }
          } else {
#endif
            dprint("MODS_TAP: Tap: register_code\n");
            // Send a shifted keycode, if
            // shift was part of the
            // modifiers.
            if (shift && mods != shift) {
              register_mods(shift);
            }
            register_code(action.key.code);
            // Stop sending shifted keycodes,
            // if the tap was interrupted.
            // This prevents registering an
            // unwanted shift, if the mod-tap
            // key is followed by another key
            // within the tapping term.
            if (record->tap.interrupted) {
              if (shift && mods != shift) {
                unregister_mods(shift);
              }
            }
          }
        } else {
          dprint("MODS_TAP: No tap: add_mods\n");
          register_mods(mods);
          if (shift && mods != shift) {
            register_mods(mods & ~shift);
          } else {
            register_mods(mods);
          }
        }
      } else {
        if (tap_count > 0) {
          dprint("MODS_TAP: Tap: unregister_code\n");
          unregister_code(action.key.code);
          if (shift && mods != shift) {
            unregister_mods(shift);
          }
        } else {
          dprint("MODS_TAP: No tap: add_mods\n");
          unregister_mods(mods);
          if (shift && mods != shift) {
            unregister_mods(mods & ~shift);
          } else {
            unregister_mods(mods);
          }
        }
      }
      return false;
    }
  }
  return true;
}

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
    case KC_MINS:
      return register_unshifted_code(KC_MINS, record);
    case KC_EQL:
      return register_unshifted_code(KC_EQL, record);
  }
  action_t action = store_or_get_action(record->event.pressed, record->event.key);
  return process_action_user(record, action);
};

void matrix_init_user() {
  steno_set_mode(STENO_MODE_GEMINI); // or STENO_MODE_BOLT
}
