/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * system-config-server.h
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

#ifndef _SYSTEM_CONFIG_SERVER_
#define _SYSTEM_CONFIG_SERVER_

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define SYSTEM_CONFIG_SERVER_TYPE_APPLICATION             (system_config_server_get_type ())
#define SYSTEM_CONFIG_SERVER_APPLICATION(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), SYSTEM_CONFIG_SERVER_TYPE_APPLICATION, Systemconfigserver))
#define SYSTEM_CONFIG_SERVER_APPLICATION_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), SYSTEM_CONFIG_SERVER_TYPE_APPLICATION, SystemconfigserverClass))
#define SYSTEM_CONFIG_SERVER_IS_APPLICATION(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SYSTEM_CONFIG_SERVER_TYPE_APPLICATION))
#define SYSTEM_CONFIG_SERVER_IS_APPLICATION_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), SYSTEM_CONFIG_SERVER_TYPE_APPLICATION))
#define SYSTEM_CONFIG_SERVER_APPLICATION_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), SYSTEM_CONFIG_SERVER_TYPE_APPLICATION, SystemconfigserverClass))

typedef struct _SystemconfigserverClass SystemconfigserverClass;
typedef struct _Systemconfigserver Systemconfigserver;

struct _SystemconfigserverClass
{
	GtkApplicationClass parent_class;
};

struct _Systemconfigserver
{
	GtkApplication parent_instance;
};

GType system_config_server_get_type (void) G_GNUC_CONST;
Systemconfigserver *system_config_server_new (void);

/* Callbacks */

G_END_DECLS

#endif /* _APPLICATION_H_ */
