/* GIMP - The GNU Image Manipulation Program
 * Copyright (C) 1995 Spencer Kimball and Peter Mattis
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef __SCRIPT_FU_TYPES_H__
#define __SCRIPT_FU_TYPES_H__


#include "script-fu-enums.h"


typedef struct
{
  gdouble           value;
  gdouble           lower;
  gdouble           upper;
  gdouble           step;
  gdouble           page;
  gint              digits;
  SFAdjustmentType  type;
} SFAdjustment;

typedef struct
{
  gchar  *filename;
} SFFilename;

typedef struct
{
  GSList *list;
  gint    history;
} SFOption;

typedef struct
{
  gchar *type_name;
  gint   history;
} SFEnum;

typedef gint32 SFResourceType;

typedef union
{
  gint32         sfa_image;
  gint32         sfa_drawable;
  gint32         sfa_layer;
  gint32         sfa_channel;
  gint32         sfa_vectors;
  gint32         sfa_display;
  GimpRGB        sfa_color;
  gint32         sfa_toggle;
  gchar         *sfa_value;
  SFAdjustment   sfa_adjustment;
  SFFilename     sfa_file;
  SFResourceType sfa_resource;
  SFOption       sfa_option;
  SFEnum         sfa_enum;
} SFArgValue;

typedef struct
{
  SFArgType   type;
  gchar      *label;
  SFArgValue  default_value;
  SFArgValue  value;
} SFArg;

typedef struct
{
  gchar        *name;
  gchar        *menu_label;
  gchar        *blurb;
  gchar        *author;
  gchar        *copyright;
  gchar        *date;
  gchar        *image_types;

  gint          n_args;
  SFArg        *args;
  SFDrawableArity drawable_arity;
  GType           proc_class; /* GimpProcedure or GimpImageProcedure. */
} SFScript;

typedef struct
{
  SFScript *script;   /* script which defined this menu path and label */
  gchar    *menu_path;
} SFMenu;

#endif /*  __SCRIPT_FU_TYPES__  */
