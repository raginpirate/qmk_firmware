/*
Copyright 2017 Luiz Ribeiro <luizribeiro@gmail.com>
Modified 2018 Wayne K Jones <github.com/WarmCatUK>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#define _MAIN 0

enum custom_keycodes {
    P_MACRO_LOCK = SAFE_RANGE,
    P_MACRO_STAB
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* 0: Main Layer
     * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
     * │ ESC │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │PRSCR│ DEL │ FN  │
     * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┤
     * │  `  │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │  -  │  =  │ BACKSPACE │HOME │
     * ├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬────────┼─────┤
     * │  TAB   │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │  [  │  ]  │   \    │ END │
     * ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴────────┼─────┤
     * │  CAPS   │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │  '  │    RETURN   │PG_UP│
     * ├─────────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴───────┬─────┼─────┤
     * │   LSHIFT   │  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │  RSHIFT  │ UP  │PG_DN│
     * ├──────┬─────┴┬────┴─┬───┴─────┴─────┴─────┴─────┴─────┴────┬┴─────┴─┬───┴────┬─────┼─────┼─────┤
     * │LCTRL │L_GUI │L_ALT │                SPACE                 │ R_ALT  │ R_CTRL │LEFT │DOWN │RIGHT│
     * └──────┴──────┴──────┴──────────────────────────────────────┴────────┴────────┴─────┴─────┴─────┘
     */
    [_MAIN] = LAYOUT(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_NLCK,  KC_PSCR, P_MACRO_STAB,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,      KC_BSPC,        P_MACRO_LOCK,
        KC_TAB,     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,       KC_HOME,
        KC_CAPS,     KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN  ,KC_QUOT,        KC_ENT,             KC_VOLU,
        KC_LSFT,       KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,    KC_RSFT,              KC_UP,    KC_VOLD,
        KC_LCTL,  KC_LGUI,  KC_LALT,                  KC_SPC,                                    KC_RALT,  KC_RGUI,  KC_RCTL,          KC_LEFT,   KC_DOWN,   KC_RGHT
    ),
};

// GBP £ Macro (sends alt 156 - windows users only)
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case KC_CAPS:
                if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
                    rgblight_sethsv_noeeprom(20, 255, 255);
                } else {
                    rgblight_sethsv_noeeprom(255, 255, 128);
                }
                break;
            case P_MACRO_STAB:
                register_code(KC_LALT);
                register_code(KC_LSFT);
                register_code(KC_LCTL);
                tap_code(KC_A);
                unregister_code(KC_LCTL);
                unregister_code(KC_LSFT);
                unregister_code(KC_LALT);
                break;
            case P_MACRO_LOCK:
                register_code(KC_LGUI);
                tap_code(KC_L);
                unregister_code(KC_LGUI);
                break;
        }
    }
    return true;
};
