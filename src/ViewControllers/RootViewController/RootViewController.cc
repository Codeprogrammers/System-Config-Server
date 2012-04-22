/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * System-Config-Server
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

#include "RootViewController.h"
#include "../../Modules/network/NetworkService.h"
#include "../AboutWindowViewController/AboutWindowViewController.h"

RootViewController::RootViewController()
{
	gtkBuilderFilePath = "/home/brad/dev/System-Config-Server/src/GTKBuilderResources/Main.glade";
	loadBuilderFile ();

	//Now that we have the glade files loaded we can start
	//assigning widgets to different sections of the GUI
	mainWindow = 0;
	gtkBuilder->get_widget("main_window", mainWindow);
	gtkBuilder->get_widget("mainToolbar", mainToolbar);
	gtkBuilder->get_widget("serviceDetailPane", serviceDetailPane);
	gtkBuilder->get_widget("availibleServicesGrid", availibleServicesGrid);
	
	//MainMenu Widgets
	gtkBuilder->get_widget("aboutApp", aboutAppMenuAction);

	//Create Widget Objects that are not in the gtkbuilder

	//Add needed widgets to their containers
	//serviceDetailPane->
	serviceDetailPane->add1(*availibleServicesGrid);

	//Make some temporary services for debugging
	
	NetworkService *netService = new NetworkService();

	
	PopulateServices();
	ConnectSignalHandelers();
}
void RootViewController::PopulateServices()
{
	g_message("populateServices Start");
	myTestButton.set_label ("Service");
	myTestButton.set_hexpand (TRUE);
	myTestButton.show();
	availibleServicesGrid->attach(myTestButton,1,1,1,1);
	
}

void RootViewController::ServiceClicked()
{
	g_message("Service Object Clicked, Load Service Module");
}

void RootViewController::ConnectSignalHandelers()
{
	g_message("Connect SignalHandlers Called");
	aboutAppMenuAction->signal_activate().connect(sigc::mem_fun(*this, &RootViewController::AboutAppClicked));
	//aboutAppMenuAction->activate.connect(sigc::mem_fun(*this, &RootViewController::AboutAppClicked));
}

void RootViewController::AboutAppClicked()
{
	g_message("About Application Called");
	AboutWindowViewController *currentAboutViewController = new AboutWindowViewController();
	currentAboutViewController->mainWindow->show();
}