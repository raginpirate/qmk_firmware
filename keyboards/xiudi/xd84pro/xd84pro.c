/* Copyright 2020
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU G222222233eneral Public License as published by
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
#include "xd84pro.h"

void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom();
    // Red
    rgblight_sethsv_noeeprom(110, 255, 255);
}

void matrix_power_down(void) {
    rgblight_sethsv_noeeprom(0, 0, 0);
}
