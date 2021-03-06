/* gp-linetool.c
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

#include "gp-linetool.h"
#include "gp-sizetoolproperty.h"
#include "gp-cairoutils.h"

#include "gp-shapetool-priv.h"

struct _GPLineTool
{
    GPShapeTool parent_instance;
    GPtrArray *properties;
};

typedef enum
{
    TOOL_PROPERTY_SIZE = 0,
} ToolProperties;

G_DEFINE_TYPE (GPLineTool, gp_line_tool, GP_TYPE_SHAPE_TOOL)

static GdkRectangle
gp_line_tool_draw (GPShapeTool *tool,
                   cairo_t     *cairo_context)
{
    GPShapeToolPrivate *priv = gp_shape_tool_get_priv (tool);
    GdkRectangle bounding_box;

    gp_size_tool_property_apply (GP_SIZE_TOOL_PROPERTY (GP_LINE_TOOL (tool)->properties->pdata[TOOL_PROPERTY_SIZE]), cairo_context);

    cairo_move_to (cairo_context,
                   priv->start_point.x,
                   priv->start_point.y);
    cairo_line_to (cairo_context,
                   priv->start_point.x + priv->width,
                   priv->start_point.y + priv->height);

    bounding_box = gp_cairo_stroke_get_bbox (cairo_context);
    cairo_stroke (cairo_context);

    return bounding_box;
}

static GtkWidget*
gp_line_tool_create_icon (GPTool *tool)
{
    return gtk_image_new_from_resource ("/org/gnome/Paint/toolicons/line.png");
}

static const GPtrArray*
gp_line_tool_get_properties (GPTool *tool)
{
    return GP_LINE_TOOL (tool)->properties;
}

static void
gp_line_tool_free_property (gpointer data)
{
    g_object_unref (G_OBJECT (data));
}

static void
gp_line_tool_finalize (GObject *gobj)
{
    GPLineTool *line_tool = GP_LINE_TOOL (gobj);

    g_ptr_array_free (line_tool->properties, TRUE);
    line_tool->properties = NULL;
}

static void
gp_line_tool_init (GPLineTool *self)
{
    self->properties = g_ptr_array_new_with_free_func (gp_line_tool_free_property);

    g_ptr_array_add (self->properties, gp_size_tool_property_create ());
}

static void
gp_line_tool_class_init (GPLineToolClass *klass)
{
    GPToolClass *tool_class = GP_TOOL_CLASS (klass);
    GPShapeToolClass *shape_tool_class = GP_SHAPE_TOOL_CLASS (klass);
    GObjectClass *gobject_class = G_OBJECT_CLASS (klass);

    tool_class->create_icon = gp_line_tool_create_icon;
    tool_class->get_properties = gp_line_tool_get_properties;

    shape_tool_class->draw_shape = gp_line_tool_draw;

    gobject_class->finalize = gp_line_tool_finalize;
}

GPTool*
gp_line_tool_create ()
{
    return  GP_TOOL (g_object_new (GP_TYPE_LINE_TOOL, NULL));
}

