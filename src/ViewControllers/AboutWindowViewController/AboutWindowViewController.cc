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

#include "AboutWindowViewController.h"

AboutWindowViewController::AboutWindowViewController()
{
	gtkBuilderFilePath = "/home/brad/dev/System-Config-Server/src/GTKBuilderResources/AboutWindow.glade";
	loadBuilderFile ();

	gtkBuilder->get_widget("aboutWindow", mainWindow);
}
void AboutWindowViewController::ConnectSignalHandelers()
{
	//mainWindow->signal_response().connect(sigc::mem_fun(CloseClicked));
	//mainWindow->signal_reponse().connect(sigc::mem_fun(*this, &AboutWindowViewController::CloseClicked));
}

void AboutWindowViewController::CloseClicked()
{
	g_message("Close Dialog stub");
}