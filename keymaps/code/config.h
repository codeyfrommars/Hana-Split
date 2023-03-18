/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

#pragma once

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define TAPPING_FORCE_HOLD  // Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_TERM 200
// #define IGNORE_MOD_TAP_INTERRUPT // Prevent normal rollover on alphas from accidentally triggering mods.

/* oled stuff */
#define SPLIT_WPM_ENABLE
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_MODS_ENABLE
#define SPLIT_OLED_ENABLE
#define OLED_TIMEOUT 60000 * 5 // turn off oled after this many ms
// #define SPLIT_TRANSPORT_MIRROR

// custom transport for displaying on both side
#define SPLIT_TRANSACTION_IDS_USER USER_SYNC_POPCAT
