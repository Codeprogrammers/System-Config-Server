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

#include "../GTKBuilderViewController.h"
#ifndef _ROOTVIEWCONTROLLER_H_
#define _ROOTVIEWCONTROLLER_H_

class RootViewController: public GTKBuilderViewController 
{
public:
	//Basic Requirments for init
	RootViewController();
	void ConnectSignalHandelers();

	void populateServices();
	void setServiceGridSize();
	void AboutAppClicked();
	void ServiceClicked();
	
	//Widget Members
	Gtk::Window *mainWindow;
	Gtk::Toolbar *mainToolbar;
	Gtk::Paned *serviceDetailPane;
	Gtk::Table  *availibleServicesTable;

	//MainMenu Widgets
	Gtk::MenuItem *aboutAppMenuAction;
	
	//Test Widgets
	Gtk::Button *myTestButton;
	
	gint availibleServices;
protected:

private:

};

#endif // _ROOTVIEWCONTROLLER_H_
