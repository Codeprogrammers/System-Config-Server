/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * main.cc
 * Copyright (C) Bradley Clemetson 2012 <brad@codeprogrammers.net>
 * 
system-config-server is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * system-config-server is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.";
 */

#include <gtkmm.h>
#include <iostream>

#include "config.h"
#include "main.h"
#include "ViewControllers/RootViewController/RootViewController.h"
#include "ModuleSubsystem/ServiceModuleMain.h"


#ifdef ENABLE_NLS
#  include <libintl.h>
#endif



/* For testing propose use the local (not installed) ui file */
/* #define UI_FILE PACKAGE_DATA_DIR"/system_config_server/ui/system_config_server.ui" */
//#define UI_FILE "../src/system_config_server.glade"
#define UI_FILE "/home/brad/dev/System-Config-Server/src/GTKBuilderResources/Main.glade"
   
int main (int argc, char *argv[])
{
	Gtk::Main kit(argc, argv);

	RootViewController *rootController = new RootViewController();
	if(rootController->mainWindow)
	{
		kit.run(*rootController->mainWindow);
	}
	return 0;
}
