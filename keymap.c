/* Copyright 2023 Brian Low
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum layers {
    _MAIN = 0,
    _SYM,
    _NAV,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | _    |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  Mute |    | Pause |------+------+------+------+------+------|
 * | CAPS |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RSFT  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LALT | LCTL | LSPC | / SYM   /       \ NAV \   | RSFT | RCTL | RALT | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_MAIN] = LAYOUT(
    KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,     KC_7,     KC_8,    KC_9,    KC_0,    KC_GRV,
    KC_TAB,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                       KC_J,     KC_L,     KC_U,    KC_Y,    KC_SCLN,    KC_UNDS,
    KC_BSPC,   KC_A,   KC_R,    KC_S,    KC_T,    KC_G,                       KC_M,     KC_N,     KC_E,    KC_I,    KC_O, KC_QUOT,
    KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_D,    KC_V,   KC_MUTE,   KC_MPLY, KC_K,     KC_H,     KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                      KC_LGUI, KC_LALT, KC_LCTL, KC_SPC, MO(_NAV),  MO(_SYM),  KC_ENT,  KC_RCTL,  KC_RALT, KC_RGUI),
[_SYM] = LAYOUT(
    KC_F1,   KC_F2,    KC_F3,    KC_F4,    KC_F5,   KC_F6,                               KC_F7,  KC_F8,    KC_F9,    KC_F10,    KC_F11, KC_F12,
    KC_ESC,   KC_QUOT,   KC_MINS,    KC_PLUS,    KC_EQL,     XXXXXXX,                       XXXXXXX,   KC_EXLM,     KC_AT,     KC_HASH,     KC_COLN, XXXXXXX,
    KC_TAB,   KC_BSLS,   KC_LPRN,    KC_LBRC,    KC_LCBR,    XXXXXXX,                       XXXXXXX,   KC_DLR,     KC_PERC,    KC_CIRC,    KC_SCLN, XXXXXXX,
    KC_LSFT,  KC_PIPE,   KC_RPRN,    KC_RBRC,    KC_RCBR,    XXXXXXX,   KC_MUTE,   KC_MPLY, XXXXXXX,   KC_AMPR,     KC_ASTR,   KC_UNDS,    KC_QUES, XXXXXXX,
                                     KC_LGUI, KC_LALT, KC_LCTL, KC_SPC, XXXXXXX,   XXXXXXX,  KC_RSFT,  KC_RCTL,  KC_RALT, KC_RGUI),
[_NAV] = LAYOUT(
    QK_BOOT,  XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                          XXXXXXX,   XXXXXXX,     XXXXXXX,   XXXXXXX,    XXXXXXX, XXXXXXX,
    KC_ESC,   XXXXXXX,   KC_BTN2,    KC_MS_U,    KC_BTN1,    XXXXXXX,                        XXXXXXX,   KC_HOME,     KC_UP,     KC_END,     KC_COLN, XXXXXXX,
    KC_TAB,   XXXXXXX,   KC_MS_L,    KC_MS_D,    KC_MS_R,    XXXXXXX,                        XXXXXXX,   KC_LEFT,     KC_DOWN,   KC_RIGHT,   KC_SCLN, XXXXXXX,
    KC_LSFT,  XXXXXXX,   KC_X,       KC_C,       KC_V,       XXXXXXX, KC_MUTE,      KC_MPLY, XXXXXXX,   KC_PGUP,     KC_TAB,    KC_PGDN,    KC_QUES, XXXXXXX,
                         KC_LGUI,    KC_LALT,    KC_LCTL,    KC_SPC,  XXXXXXX,      XXXXXXX,  KC_RSFT,  KC_RCTL,  KC_RALT, KC_RGUI),
};

// const uint16_t PROGMEM backspace_main[] = {KC_M, KC_COMM, COMBO_END};
// const uint16_t PROGMEM backspace_sym[] = {KC_AMPR, KC_ASTR, COMBO_END};
// const uint16_t PROGMEM backspace_nav[] = {KC_PGUP, KC_TAB, COMBO_END};

// const uint16_t PROGMEM ctrl_backspace_main[] = {KC_COMM, KC_DOT, COMBO_END};
// const uint16_t PROGMEM ctrl_backspace_sym[] = {KC_ASTR, KC_UNDS, COMBO_END};
// const uint16_t PROGMEM ctrl_backspace_nav[] = {KC_TAB, KC_PGDN, COMBO_END};

// const uint16_t PROGMEM enter_main[] = {KC_X, KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM enter_sym[] = {KC_RPRN, KC_RBRC, KC_RCBR, COMBO_END};
const uint16_t PROGMEM enter_nav[] = {KC_TAB, KC_PGDN, COMBO_END};

combo_t key_combos[] = {
    // COMBO(backspace_main, KC_BSPC),
    // COMBO(backspace_sym, KC_BSPC),
    // COMBO(backspace_nav, KC_BSPC),

    // COMBO(ctrl_backspace_main, C(KC_BSPC)),
    // COMBO(ctrl_backspace_sym, C(KC_BSPC)),
    // COMBO(ctrl_backspace_nav, C(KC_BSPC)),

    // COMBO(enter_main, KC_ENT),
    COMBO(enter_sym, KC_ENT),
    COMBO(enter_nav, KC_ENT),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_MAIN] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [_SYM] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [_NAV] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
};
#endif
