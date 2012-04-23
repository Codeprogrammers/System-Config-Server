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
#include "../../Modules/dhcpd/DhcpdService.h"
#include "../../Modules/bind/BindService.h"

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
	gtkBuilder->get_widget("selectedService", selectedService);
	
	//MainMenu Widgets
	gtkBuilder->get_widget("aboutApp", aboutAppMenuAction);

	//Create Widget Objects that are not in the gtkbuilder

	//Add needed widgets to their containers
	//serviceDetailPane->
	serviceDetailPane->add1(*availibleServicesGrid);

	//Make some temporary services for debugging
	

	//Puts out a nasty warning about pointer returns
	serviceModules = g_list_append(serviceModules, new NetworkService);
	serviceModules = g_list_append(serviceModules, new DhcpdService);
	serviceModules = g_list_append(serviceModules, new BindService);
	PopulateServicesMenu();
	ConnectSignalHandelers();
}
void RootViewController::PopulateServicesMenu()
{
	g_message("populateServices Start with services: %i", g_list_length (serviceModules));

	Gtk::Button* currentServiceButton;
	ServiceModule* currentServiceModule;
	for(int currentService = 0; currentService < g_list_length (serviceModules); currentService++)
	{
		//Create a new button for a specific service and configure it
		currentServiceButton = new Gtk::Button();
		currentServiceModule = ( (ServiceModule *) (g_list_nth_data (serviceModules, currentService)));
		currentServiceButton->set_label(currentServiceModule->serviceName);
		currentServiceButton->set_hexpand(TRUE);
		currentServiceButton->show();
		//The correct line to set signal handlers
		currentServiceModule->rootServiceWindow = selectedService;
		currentServiceButton->signal_clicked().connect(sigc::mem_fun((ServiceModule *) currentServiceModule, &ServiceModule::ShowServiceModule));
		//currentServiceButton->signal_clicked().connect(sigc::mem_fun(*this, &RootViewController::ServiceClicked));
		
		//Add the newly created button to the left hand side service selection page
		//and add the button to it's own list to keep a permanet pointer to it.
		availibleServicesGrid->attach(*currentServiceButton, 1,currentService,1,1);
		serviceModuleButtons = g_list_append(serviceModuleButtons, currentServiceButton);
	}

	//Remove the temporary interation pointers
	currentServiceModule = NULL;
	currentServiceButton = NULL;
	delete currentServiceModule;
	delete currentServiceButton;
}

void RootViewController::ConnectSignalHandelers()
{
	g_message("Connect SignalHandlers Called");
	aboutAppMenuAction->signal_activate().connect(sigc::mem_fun(*this, &RootViewController::AboutAppClicked));
	//aboutAppMenuAction->activate.connect(sigc::mem_fun(*this, &RootViewController::AboutAppClicked));
}

void RootViewController::ServiceClicked()
{
	g_message("Service Clicked");
	NetworkService *test = ( (NetworkService *) (g_list_nth_data (serviceModules, 0)));
	//gtk_scrolled_window_add_with_viewport (*selectedService, *test->mainView );
	selectedService->add(*test->mainView);
}

void RootViewController::AboutAppClicked()
{
	g_message("About Application Called");
	AboutWindowViewController *currentAboutViewController = new AboutWindowViewController();
	currentAboutViewController->mainWindow->show();
}

void RootViewController::printTestMessage()
{
	g_message("Debug Message Tester :P");
}