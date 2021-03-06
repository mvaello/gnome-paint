/* gp-application.h
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

#ifndef GP_APPLICATION_H_
#define GP_APPLICATION_H_

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define GP_TYPE_APPLICATION (gp_application_get_type ())
G_DECLARE_FINAL_TYPE (GPApplication, gp_application, GP, APPLICATION, GtkApplication)

GtkApplication * gp_application_new (void);

GMenuModel* gp_application_get_hamburger_menu_model (GPApplication *application);

G_END_DECLS

#endif /* GP_APPLICATION_H_ */
