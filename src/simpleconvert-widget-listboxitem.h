/* simpleconvert-widget-listboxitem.h
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

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define SIMPLECONVERT_TYPE_WIDGET_LISTBOXITEM (simpleconvert_widget_listboxitem_get_type ())

G_DECLARE_FINAL_TYPE (SimpleconvertWidgetListboxitem, simpleconvert_widget_listboxitem,
											SIMPLECONVERT, WIDGET_LISTBOXITEM, GtkLabel)

/* Public function signatures */
SimpleconvertWidgetListboxitem *simpleconvert_widget_listboxitem_new (const GFile *file);
const gchar *simpleconvert_widget_listboxitem_get_file_name (SimpleconvertWidgetListboxitem *self);
const gchar *simpleconvert_widget_listboxitem_get_file_path (SimpleconvertWidgetListboxitem *self);

G_END_DECLS
