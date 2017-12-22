/* simpleconvert-settings.h
 *
 * Copyright © 2017 Bart Kessels <bartkessels@bk-mail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
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

#pragma once

#include <gio/gio.h>
#include <glib.h>

#include "simpleconvert-app.h"

/* Settings keys */
#define SETTINGS_KEY_OVERWRITE_OUTPUT "file-overwrite-output"

/* Public function signatures */
void simpleconvert_settings_set_overwrite_output_file (gboolean overwrite_output_file);

gboolean simpleconvert_settings_get_overwrite_output_file ();