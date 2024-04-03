// Copyright 2023 Drashna Jael're (@Drashna Jael're)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

//#define POINTING_DEVICE_TASK_THROTTLE_MS 1
#define SPLIT_LAYER_STATE_ENABLE

#define POINTING_DEVICE_CS_PIN B6
#define POINTING_DEVICE_COMBINED
#define SPLIT_POINTING_ENABLE

// #define ROTATIONAL_TRANSFORM_ANGLE -9 5000
#define POINTING_DEVICE_ROTATION_90_RIGHT
#define POINTING_DEVICE_INVERT_X_RIGHT

#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#define AUTO_MOUSE_DEFAULT_LAYER 1
#define AUTO_MOUSE_THRESHOLD 5000
#define AUTO_MOUSE_TIME 500

// for RP2040 converter
#define SPI_SCK_PIN B1
#define SPI_MISO_PIN B3
#define SPI_MOSI_PIN B2
#define SPI_DRIVER SPID0
