/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * System-Config-Server
 * Copyright (C) Bradley Clemetson 2012 <brad@codeprogrammers.net>
 * 
System-Config-Server is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * System-Config-Server is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.";
 */

//Dummy UI_FILE definition
#define UI_FILE "/home/brad/dev/System-Config-Server/src/GTKBuilderResources/Main.glade"

#include "GTKBuilderViewController.h"

GTKBuilderViewController::GTKBuilderViewController()
{
	gtkBuilderFilePath = UI_FILE;
	try
	{
		gtkBuilder = Gtk::Builder::create_from_file(gtkBuilderFilePath);
	}
	catch (const Glib::FileError & ex)
	{
		//std::cerr << ex.what() << std::endl;
		printf("GTKBUILD File Load FAILURE!!");
	}
}

void GTKBuilderViewController::loadBuilderFile()
{
	g_message("loadBuilderFile STUB!");
}