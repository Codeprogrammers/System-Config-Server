/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * system-config-server.c
 * Copyright (C) Bradley Clemetson 2012 <brad@codeprogrammers.net>
 * 
System-Config-Server is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * System-Config-Server is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "system-config-server.h"

#include <glib/gi18n.h>



/* For testing propose use the local (not installed) ui file */
/* #define UI_FILE PACKAGE_DATA_DIR"/system_config_server/ui/system_config_server.ui" */
#define UI_FILE "src/system_config_server.ui"
#define TOP_WINDOW "window"


G_DEFINE_TYPE (Systemconfigserver, system_config_server, GTK_TYPE_APPLICATION);

/* Create a new window loading a file */
static void
system_config_server_new_window (GApplication *app,
                           GFile        *file)
{
	GtkWidget *window;

	GtkBuilder *builder;
	GError* error = NULL;

	/* Load UI from file */
	builder = gtk_builder_new ();
	if (!gtk_builder_add_from_file (builder, UI_FILE, &error))
	{
		g_critical ("Couldn't load builder file: %s", error->message);
		g_error_free (error);
	}

	/* Auto-connect signal handlers */
	gtk_builder_connect_signals (builder, NULL);

	/* Get the window object from the ui file */
	window = GTK_WIDGET (gtk_builder_get_object (builder, TOP_WINDOW));
        if (!window)
        {
                g_critical ("Widget \"%s\" is missing in file %s.",
				TOP_WINDOW,
				UI_FILE);
        }
	g_object_unref (builder);
	
	
	gtk_window_set_application (GTK_WINDOW (window), GTK_APPLICATION (app));
	if (file != NULL)
	{
		/* TODO: Add code here to open the file in the new window */
	}
	gtk_widget_show_all (GTK_WIDGET (window));
}


/* GApplication implementation */
static void
system_config_server_activate (GApplication *application)
{
  system_config_server_new_window (application, NULL);
}

static void
system_config_server_open (GApplication  *application,
                     GFile        **files,
                     gint           n_files,
                     const gchar   *hint)
{
  gint i;

  for (i = 0; i < n_files; i++)
    system_config_server_new_window (application, files[i]);
}

static void
system_config_server_init (Systemconfigserver *object)
{

}

static void
system_config_server_finalize (GObject *object)
{

	G_OBJECT_CLASS (system_config_server_parent_class)->finalize (object);
}

static void
system_config_server_class_init (SystemconfigserverClass *klass)
{
	G_APPLICATION_CLASS (klass)->activate = system_config_server_activate;
	G_APPLICATION_CLASS (klass)->open = system_config_server_open;

	G_OBJECT_CLASS (klass)->finalize = system_config_server_finalize;
}

Systemconfigserver *
system_config_server_new (void)
{
	g_type_init ();

	return g_object_new (system_config_server_get_type (),
	                     "application-id", "org.gnome.system_config_server",
	                     "flags", G_APPLICATION_HANDLES_OPEN,
	                     NULL);
}
