// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include "quantum.h"

#ifdef OLED_ENABLE

bool oled_task_user() {
    oled_clear();
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write("Default", false);
            break;

        case 1:
            oled_write("Mouse", false);
            break;

        default:
            oled_write("Unknown", false);
            break;
    }

    if (is_keyboard_left()) {
        oled_set_cursor(1, 1);

        switch (get_highest_layer(layer_state)) {
            case 0:
                oled_write("LDefault", false);
                break;

            case 1:
                oled_write("LMouse", false);
                break;

            default:
                oled_write("LUnknown", false);
                break;
        }

        return false;
    }
    else {
        oled_set_cursor(1, 1);

        switch (get_highest_layer(layer_state)) {
            case 0:
                oled_write("RDefault", false);
                break;

            case 1:
                oled_write("RMouse", false);
                break;

            default:
                oled_write("RUnknown", false);
                break;
        }
    }

    return false;
}

// clang-format off
// static const char PROGMEM logo[] = {
//     0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
//     0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
//     0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
//     0};
// clang-format on
#endif
