// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// always required before the auto mouse feature will work
void pointing_device_init_user(void) {
    set_auto_mouse_enable(true);
}

enum custom_keycodes {
    DRAG_SCROLL = QK_USER,
};

bool set_scrolling = false;

// Modify these values to adjust the scrolling speed
#define SCROLL_DIVISOR_H 32.0f
#define SCROLL_DIVISOR_V 32.0f

// Variables to store accumulated scroll values
float scroll_accumulated_h = 0;
float scroll_accumulated_v = 0;

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (set_scrolling) {
        // Calculate and accumulate scroll values based on mouse movement and divisors
        scroll_accumulated_h += (float)mouse_report.x / SCROLL_DIVISOR_H;
        scroll_accumulated_v += (float)mouse_report.y / SCROLL_DIVISOR_V;

        // Assign integer parts of accumulated scroll values to the mouse report
        mouse_report.h = (int8_t)scroll_accumulated_h;
        mouse_report.v = (int8_t)scroll_accumulated_v;

        // Update accumulated scroll values by subtracting the integer parts
        scroll_accumulated_h -= (int8_t)scroll_accumulated_h;
        scroll_accumulated_v -= (int8_t)scroll_accumulated_v;

        // Clear the X and Y values of the mouse report
        mouse_report.x = 0;
        mouse_report.y = 0;
    }

    return mouse_report;
}

// Function to handle key events and enable/disable drag scrolling
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DRAG_SCROLL:
            // Toggle set_scrolling when DRAG_SCROLL key is pressed or released
            // set_scrolling = record->event.pressed;
            if (record->event.pressed) {
                set_scrolling = true;
            }
            return false;
        default:
            break;
    }
    return true;
}

// Function to handle layer changes and disable drag scrolling when not in AUTO_MOUSE_DEFAULT_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    // Disable set_scrolling if the current layer is not the AUTO_MOUSE_DEFAULT_LAYER
    if (get_highest_layer(state) != 1) {
        set_scrolling = false;
    }
    return state;
}

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     if (keycode == DRAG_SCROLL && record->event.pressed) {
//         set_scrolling = !set_scrolling;
//         return false;
//     }
//
//     return true;
// }
//
// // Function to handle layer changes and disable drag scrolling when not in AUTO_MOUSE_DEFAULT_LAYER
// layer_state_t layer_state_set_user(layer_state_t state) {
//     // Disable set_scrolling if the current layer is not the AUTO_MOUSE_DEFAULT_LAYER
//     if (get_highest_layer(state) != 1) {
//         set_scrolling = false;
//     }
//     return state;
// }

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                            KC_Y     , KC_U     , KC_I     , KC_O ,           KC_P     ,
    KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                            KC_H     , KC_J     , KC_K     , KC_L ,           KC_SEMICOLON  ,
    KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,                            KC_N     , KC_M     , KC_COMM  , KC_DOT ,         KC_SLSH  ,
    KC_LSFT  , KC_LGUI  , KC_LCTL  , KC_LALT  , KC_LGUI  , KC_SPC ,               KC_SPC   , KC_RGUI  ,                                     KC_ENT
  ),

  [1] = LAYOUT(
    _______  , _______  , _______  , _______  , _______  ,                                   _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  ,                                   _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  ,                                   _______  , KC_BTN1  , KC_BTN2  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,     _______  , _______  ,                                              _______
  ),
};
