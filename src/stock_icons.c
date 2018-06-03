
/*
 * Osmo - a handy personal organizer
 *
 * Copyright (C) 2007 Tomasz Maka <pasp@users.sourceforge.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#include "gui.h"
#include "i18n.h"
#include "stock_icons.h"
#include "stock_icons_data.h"

/*------------------------------------------------------------------------------*/

void
kanatest_register_stock_icons(void) {

GdkPixbuf *pixbuf;
gint i, h;

gchar * kanatest_stock_items[] = {
    KANATEST_STOCK_BUTTON_STATISTICS,
    KANATEST_STOCK_BUTTON_CHART,     
    KANATEST_STOCK_BUTTON_OPTIONS,   
    KANATEST_STOCK_BUTTON_ABOUT,     
};

const guint8 * kanatest_stock_item_data[] = {
    kanatest_stock_button_statistics,
    kanatest_stock_button_chart,
    kanatest_stock_button_options,
    kanatest_stock_button_about,
};

	for(i = 0; i < G_N_ELEMENTS(kanatest_stock_item_data); i++) {
		pixbuf = gdk_pixbuf_new_from_inline(-1, kanatest_stock_item_data[i], FALSE, NULL);
        h = gdk_pixbuf_get_height (pixbuf);
        gtk_icon_theme_add_builtin_icon(kanatest_stock_items[i], h, pixbuf);
        g_object_unref(pixbuf);
    }

}

/*------------------------------------------------------------------------------*/


