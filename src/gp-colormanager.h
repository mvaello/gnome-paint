/* gp-colormanager.h
 *
 * Copyright (C) 2017 Marcin Kolny
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

#ifndef GP_COLOR_MANAGER_H_
#define GP_COLOR_MANAGER_H_

#include <gdk/gdk.h>

G_BEGIN_DECLS

#define GP_TYPE_COLOR_MANAGER (gp_color_manager_get_type ())
G_DECLARE_FINAL_TYPE (GPColorManager, gp_color_manager, GP, COLORL_MANAGER, GObject)

GPColorManager * gp_color_manager_default (void);

void gp_color_manager_get_color (const GPColorManager *color_manager, GdkRGBA *fg_color, GdkRGBA *bg_color);
void gp_color_manager_set_color (GPColorManager *color_manager, const GdkRGBA *fg_color, const GdkRGBA *bg_color);

gsize gp_color_manager_get_palette_size (GPColorManager *color_manager);
GdkRGBA gp_color_manager_get_palette_color (GPColorManager *color_manager, gsize pos);

G_END_DECLS

#endif /* GP_COLOR_MANAGER_H_ */
