/* LIBGIMP - The GIMP Library
 * Copyright (C) 1995-2003 Peter Mattis and Spencer Kimball
 *
 * gimppalette_pdb.c
 *
 * This library is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see
 * <https://www.gnu.org/licenses/>.
 */

/* NOTE: This file is auto-generated by pdbgen.pl */

#include "config.h"

#include "stamp-pdbgen.h"

#include "gimp.h"


/**
 * SECTION: gimppalette
 * @title: gimppalette
 * @short_description: Installable object, a small set of colors a user can choose from.
 *
 * Installable object, a small set of colors a user can choose from.
 **/


/**
 * gimp_palette_new:
 * @name: The requested name of the new palette.
 *
 * Creates a new palette
 *
 * Creates a new palette. The new palette has no color entries. You
 * must add color entries for a user to choose. The actual name might
 * be different than the requested name, when the requested name is
 * already in use.
 *
 * Returns: (transfer none): The palette.
 *
 * Since: 2.2
 **/
GimpPalette *
gimp_palette_new (const gchar *name)
{
  GimpValueArray *args;
  GimpValueArray *return_vals;
  GimpPalette *palette = NULL;

  args = gimp_value_array_new_from_types (NULL,
                                          G_TYPE_STRING, name,
                                          G_TYPE_NONE);

  return_vals = _gimp_pdb_run_procedure_array (gimp_get_pdb (),
                                               "gimp-palette-new",
                                               args);
  gimp_value_array_unref (args);

  if (GIMP_VALUES_GET_ENUM (return_vals, 0) == GIMP_PDB_SUCCESS)
    palette = GIMP_VALUES_GET_PALETTE (return_vals, 1);

  gimp_value_array_unref (return_vals);

  return palette;
}

/**
 * gimp_palette_get_by_name:
 * @name: The name of the palette.
 *
 * Returns the palette with the given name.
 *
 * Returns the palette with the given name.
 *
 * Returns: (transfer none): The palette.
 *
 * Since: 3.0
 **/
GimpPalette *
gimp_palette_get_by_name (const gchar *name)
{
  GimpValueArray *args;
  GimpValueArray *return_vals;
  GimpPalette *palette = NULL;

  args = gimp_value_array_new_from_types (NULL,
                                          G_TYPE_STRING, name,
                                          G_TYPE_NONE);

  return_vals = _gimp_pdb_run_procedure_array (gimp_get_pdb (),
                                               "gimp-palette-get-by-name",
                                               args);
  gimp_value_array_unref (args);

  if (GIMP_VALUES_GET_ENUM (return_vals, 0) == GIMP_PDB_SUCCESS)
    palette = GIMP_VALUES_GET_PALETTE (return_vals, 1);

  gimp_value_array_unref (return_vals);

  return palette;
}

/**
 * gimp_palette_get_color_count:
 * @palette: The palette.
 *
 * Get the count of colors in the palette.
 *
 * Returns the number of colors in the palette.
 *
 * Returns: The number of colors in the palette.
 *
 * Since: 2.2
 **/
gint
gimp_palette_get_color_count (GimpPalette *palette)
{
  GimpValueArray *args;
  GimpValueArray *return_vals;
  gint num_colors = 0;

  args = gimp_value_array_new_from_types (NULL,
                                          GIMP_TYPE_PALETTE, palette,
                                          G_TYPE_NONE);

  return_vals = _gimp_pdb_run_procedure_array (gimp_get_pdb (),
                                               "gimp-palette-get-color-count",
                                               args);
  gimp_value_array_unref (args);

  if (GIMP_VALUES_GET_ENUM (return_vals, 0) == GIMP_PDB_SUCCESS)
    num_colors = GIMP_VALUES_GET_INT (return_vals, 1);

  gimp_value_array_unref (return_vals);

  return num_colors;
}

/**
 * gimp_palette_get_colors:
 * @palette: The palette.
 * @num_colors: (out): Length of the colors array.
 *
 * Gets colors in the palette.
 *
 * Returns an array of colors in the palette.
 *
 * Returns: (array length=num_colors) (element-type GimpRGB) (transfer full):
 *          The colors in the palette.
 *          The returned value must be freed with g_free().
 *
 * Since: 2.6
 **/
GimpRGB *
gimp_palette_get_colors (GimpPalette *palette,
                         gint        *num_colors)
{
  GimpValueArray *args;
  GimpValueArray *return_vals;
  GimpRGB *colors = NULL;

  args = gimp_value_array_new_from_types (NULL,
                                          GIMP_TYPE_PALETTE, palette,
                                          G_TYPE_NONE);

  return_vals = _gimp_pdb_run_procedure_array (gimp_get_pdb (),
                                               "gimp-palette-get-colors",
                                               args);
  gimp_value_array_unref (args);

  *num_colors = 0;

  if (GIMP_VALUES_GET_ENUM (return_vals, 0) == GIMP_PDB_SUCCESS)
    {
      *num_colors = GIMP_VALUES_GET_INT (return_vals, 1);
      colors = GIMP_VALUES_DUP_RGB_ARRAY (return_vals, 2);
    }

  gimp_value_array_unref (return_vals);

  return colors;
}

/**
 * gimp_palette_get_columns:
 * @palette: The palette.
 *
 * Gets the number of columns used to display the palette
 *
 * Gets the preferred number of columns to display the palette.
 *
 * Returns: The number of columns used to display this palette.
 *
 * Since: 2.4
 **/
gint
gimp_palette_get_columns (GimpPalette *palette)
{
  GimpValueArray *args;
  GimpValueArray *return_vals;
  gint num_columns = 0;

  args = gimp_value_array_new_from_types (NULL,
                                          GIMP_TYPE_PALETTE, palette,
                                          G_TYPE_NONE);

  return_vals = _gimp_pdb_run_procedure_array (gimp_get_pdb (),
                                               "gimp-palette-get-columns",
                                               args);
  gimp_value_array_unref (args);

  if (GIMP_VALUES_GET_ENUM (return_vals, 0) == GIMP_PDB_SUCCESS)
    num_columns = GIMP_VALUES_GET_INT (return_vals, 1);

  gimp_value_array_unref (return_vals);

  return num_columns;
}

/**
 * gimp_palette_set_columns:
 * @palette: The palette.
 * @columns: The new number of columns.
 *
 * Sets the number of columns used to display the palette
 *
 * Set the number of colors shown per row when the palette is
 * displayed. Returns an error when the palette is not editable. The
 * maximum allowed value is 64.
 *
 * Returns: TRUE on success.
 *
 * Since: 2.4
 **/
gboolean
gimp_palette_set_columns (GimpPalette *palette,
                          gint         columns)
{
  GimpValueArray *args;
  GimpValueArray *return_vals;
  gboolean success = TRUE;

  args = gimp_value_array_new_from_types (NULL,
                                          GIMP_TYPE_PALETTE, palette,
                                          G_TYPE_INT, columns,
                                          G_TYPE_NONE);

  return_vals = _gimp_pdb_run_procedure_array (gimp_get_pdb (),
                                               "gimp-palette-set-columns",
                                               args);
  gimp_value_array_unref (args);

  success = GIMP_VALUES_GET_ENUM (return_vals, 0) == GIMP_PDB_SUCCESS;

  gimp_value_array_unref (return_vals);

  return success;
}

/**
 * gimp_palette_add_entry:
 * @palette: The palette.
 * @entry_name: A name for the entry.
 * @color: The color for the added entry.
 * @entry_num: (out): The index of the added entry.
 *
 * Appends an entry to the palette.
 *
 * Appends an entry to the palette. Neither color nor name must be
 * unique within the palette. When name is the empty string, this sets
 * the entry name to \"Untitled\". Returns the index of the entry.
 * Returns an error when palette is not editable.
 *
 * Returns: TRUE on success.
 *
 * Since: 2.2
 **/
gboolean
gimp_palette_add_entry (GimpPalette   *palette,
                        const gchar   *entry_name,
                        const GimpRGB *color,
                        gint          *entry_num)
{
  GimpValueArray *args;
  GimpValueArray *return_vals;
  gboolean success = TRUE;

  args = gimp_value_array_new_from_types (NULL,
                                          GIMP_TYPE_PALETTE, palette,
                                          G_TYPE_STRING, entry_name,
                                          GIMP_TYPE_RGB, color,
                                          G_TYPE_NONE);

  return_vals = _gimp_pdb_run_procedure_array (gimp_get_pdb (),
                                               "gimp-palette-add-entry",
                                               args);
  gimp_value_array_unref (args);

  *entry_num = 0;

  success = GIMP_VALUES_GET_ENUM (return_vals, 0) == GIMP_PDB_SUCCESS;

  if (success)
    *entry_num = GIMP_VALUES_GET_INT (return_vals, 1);

  gimp_value_array_unref (return_vals);

  return success;
}

/**
 * gimp_palette_delete_entry:
 * @palette: The palette.
 * @entry_num: The index of the entry to delete.
 *
 * Deletes an entry from the palette.
 *
 * This function will fail and return %FALSE if the index is out or
 * range or if the palette is not editable.
 * Additionally if the palette belongs to an indexed image, it will
 * only be possible to delete palette colors not in use in the image.
 *
 * Returns: TRUE on success.
 *
 * Since: 2.2
 **/
gboolean
gimp_palette_delete_entry (GimpPalette *palette,
                           gint         entry_num)
{
  GimpValueArray *args;
  GimpValueArray *return_vals;
  gboolean success = TRUE;

  args = gimp_value_array_new_from_types (NULL,
                                          GIMP_TYPE_PALETTE, palette,
                                          G_TYPE_INT, entry_num,
                                          G_TYPE_NONE);

  return_vals = _gimp_pdb_run_procedure_array (gimp_get_pdb (),
                                               "gimp-palette-delete-entry",
                                               args);
  gimp_value_array_unref (args);

  success = GIMP_VALUES_GET_ENUM (return_vals, 0) == GIMP_PDB_SUCCESS;

  gimp_value_array_unref (return_vals);

  return success;
}

/**
 * gimp_palette_entry_get_color:
 * @palette: The palette.
 * @entry_num: The index of the entry to get the color of.
 * @color: (out caller-allocates): The color at the index.
 *
 * Gets the color of an entry in the palette.
 *
 * Returns the color of the entry at the given zero-based index into
 * the palette. Returns an error when the index is out of range.
 *
 * Returns: TRUE on success.
 *
 * Since: 2.2
 **/
gboolean
gimp_palette_entry_get_color (GimpPalette *palette,
                              gint         entry_num,
                              GimpRGB     *color)
{
  GimpValueArray *args;
  GimpValueArray *return_vals;
  gboolean success = TRUE;

  args = gimp_value_array_new_from_types (NULL,
                                          GIMP_TYPE_PALETTE, palette,
                                          G_TYPE_INT, entry_num,
                                          G_TYPE_NONE);

  return_vals = _gimp_pdb_run_procedure_array (gimp_get_pdb (),
                                               "gimp-palette-entry-get-color",
                                               args);
  gimp_value_array_unref (args);

  success = GIMP_VALUES_GET_ENUM (return_vals, 0) == GIMP_PDB_SUCCESS;

  if (success)
    GIMP_VALUES_GET_RGB (return_vals, 1, &*color);

  gimp_value_array_unref (return_vals);

  return success;
}

/**
 * gimp_palette_entry_set_color:
 * @palette: The palette.
 * @entry_num: The entry to get.
 * @color: The new color.
 *
 * Sets the color of an entry in the palette.
 *
 * Sets the color of the entry at the zero-based index into the
 * palette. Returns an error when the index is out of range. Returns an
 * error when the palette is not editable.
 *
 * Returns: TRUE on success.
 *
 * Since: 2.2
 **/
gboolean
gimp_palette_entry_set_color (GimpPalette   *palette,
                              gint           entry_num,
                              const GimpRGB *color)
{
  GimpValueArray *args;
  GimpValueArray *return_vals;
  gboolean success = TRUE;

  args = gimp_value_array_new_from_types (NULL,
                                          GIMP_TYPE_PALETTE, palette,
                                          G_TYPE_INT, entry_num,
                                          GIMP_TYPE_RGB, color,
                                          G_TYPE_NONE);

  return_vals = _gimp_pdb_run_procedure_array (gimp_get_pdb (),
                                               "gimp-palette-entry-set-color",
                                               args);
  gimp_value_array_unref (args);

  success = GIMP_VALUES_GET_ENUM (return_vals, 0) == GIMP_PDB_SUCCESS;

  gimp_value_array_unref (return_vals);

  return success;
}

/**
 * gimp_palette_entry_get_name:
 * @palette: The palette.
 * @entry_num: The entry to get.
 * @entry_name: (out) (transfer full): The name of the entry.
 *
 * Gets the name of an entry in the palette.
 *
 * Gets the name of the entry at the zero-based index into the palette.
 * Returns an error when the index is out of range.
 *
 * Returns: TRUE on success.
 *
 * Since: 2.2
 **/
gboolean
gimp_palette_entry_get_name (GimpPalette  *palette,
                             gint          entry_num,
                             gchar       **entry_name)
{
  GimpValueArray *args;
  GimpValueArray *return_vals;
  gboolean success = TRUE;

  args = gimp_value_array_new_from_types (NULL,
                                          GIMP_TYPE_PALETTE, palette,
                                          G_TYPE_INT, entry_num,
                                          G_TYPE_NONE);

  return_vals = _gimp_pdb_run_procedure_array (gimp_get_pdb (),
                                               "gimp-palette-entry-get-name",
                                               args);
  gimp_value_array_unref (args);

  *entry_name = NULL;

  success = GIMP_VALUES_GET_ENUM (return_vals, 0) == GIMP_PDB_SUCCESS;

  if (success)
    *entry_name = GIMP_VALUES_DUP_STRING (return_vals, 1);

  gimp_value_array_unref (return_vals);

  return success;
}

/**
 * gimp_palette_entry_set_name:
 * @palette: The palette.
 * @entry_num: The entry to get.
 * @entry_name: The new name.
 *
 * Sets the name of an entry in the palette.
 *
 * Sets the name of the entry at the zero-based index into the palette.
 * Returns an error if the index is out or range. Returns an error if
 * the palette is not editable.
 *
 * Returns: TRUE on success.
 *
 * Since: 2.2
 **/
gboolean
gimp_palette_entry_set_name (GimpPalette *palette,
                             gint         entry_num,
                             const gchar *entry_name)
{
  GimpValueArray *args;
  GimpValueArray *return_vals;
  gboolean success = TRUE;

  args = gimp_value_array_new_from_types (NULL,
                                          GIMP_TYPE_PALETTE, palette,
                                          G_TYPE_INT, entry_num,
                                          G_TYPE_STRING, entry_name,
                                          G_TYPE_NONE);

  return_vals = _gimp_pdb_run_procedure_array (gimp_get_pdb (),
                                               "gimp-palette-entry-set-name",
                                               args);
  gimp_value_array_unref (args);

  success = GIMP_VALUES_GET_ENUM (return_vals, 0) == GIMP_PDB_SUCCESS;

  gimp_value_array_unref (return_vals);

  return success;
}
