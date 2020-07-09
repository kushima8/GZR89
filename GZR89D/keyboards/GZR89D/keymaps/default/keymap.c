/* Copyright 2019 kushima8
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

enum layer_number {
    _FIRST = 0,
    _SECOND,
    _THIRD
};

#define FIRST TO(_FIRST)
#define SECOND TO(_SECOND)
#define THIRD TO(_THIRD)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_FIRST] = LAYOUT(
        LCTL(KC_S), LCTL(KC_LALT), KC_C,         KC_LALT, THIRD,
        LCTL(KC_Z), LCTL(KC_Y),    LALT(KC_SPC), KC_SPC,  SECOND, RGB_TOG
    ),
    [_SECOND] = LAYOUT(
        KC_P,             KC_E,       KC_G,             KC_M,       THIRD,
        LSFT(LCTL(KC_T)), LCTL(KC_U), LSFT(LCTL(KC_N)), LCTL(KC_E), FIRST, RGB_TOG
    ),
    [_THIRD] = LAYOUT(
        RGB_HUI, RGB_SAI, RGB_VAI, RGB_MOD,  FIRST,
        RGB_HUD, RGB_SAD, RGB_VAD, RGB_RMOD, SECOND, RGB_TOG
    ),
};

/* Rotary encoder settings */
void encoder_update_user(uint16_t index, bool clockwise) {
    switch(biton32(layer_state)) {
        case _FIRST:
            if (clockwise) {
                tap_code16(KC_QUOT);    //Rotary encoder clockwise
            } else {
                tap_code16(KC_MINS);    //Rotary encoder Reverse clockwise
            }
            break;
        case _SECOND:
            if (clockwise) {
                tap_code16(KC_RBRC);    //Rotary encoder clockwise
            } else {
                tap_code16(KC_LBRC);    //Rotary encoder Reverse clockwise
            }
            break;
        case _THIRD:
            if (clockwise) {
                tap_code16(KC_UP);      //Rotary encoder clockwise
            } else {
                tap_code16(KC_DOWN);    //Rotary encoder Reverse clockwise
            }
            break;
    }
}

uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(state)) {
        case _FIRST:
            wait_ms(100);
            rgblight_sethsv(rgblight_get_hue(),rgblight_get_sat(),rgblight_get_val());
            break;
        case _SECOND:
            wait_ms(100);
            rgblight_sethsv(rgblight_get_hue(),rgblight_get_sat(),rgblight_get_val());
            rgblight_setrgb_at(RGB_RED,9);
            break;
        case _THIRD:
            wait_ms(100);
            rgblight_sethsv(rgblight_get_hue(),rgblight_get_sat(),rgblight_get_val());
            rgblight_setrgb_at(RGB_BLUE,4);
            break;
    }
    return state;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
