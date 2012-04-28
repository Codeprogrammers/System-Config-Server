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

#include "../../../ViewControllers/GTKBuilderViewController.h"
#ifndef _NETWORK_CONTROLLER_H_
#define _NETWORK_CONTROLLER_H_

class NetworkInterfaceViewController : public GTKBuilderViewController
{
public:
		NetworkInterfaceViewController();
		void LoadWidgets();
		void ConnectSignalHandlers();

		//Widgets
		Gtk::Viewport *mainView;
	
		Gtk::Entry *ipV4TextBox;
		Gtk::Entry *subnetTextBox;
		Gtk::Entry *gatewayTextBox;
		Gtk::Entry *ipV6TextBox;
		Gtk::Entry *ipV6PrefixTextBox;

		//Objects
		Glib::ustring *ethernetName;
		Glib::ustring *ethernetNickName;
		Glib::ustring *ipV4Address;
		Glib::ustring *subnet;
		Glib::ustring *gateway;
		Glib::ustring *ipV6Address;
		Glib::ustring *ipV6Prefix;

		gboolean *ipV6Enabled;
		
		GList *dnsList;
protected:

private:

};

#endif // _NETWORK_CONTROLLER_H_
