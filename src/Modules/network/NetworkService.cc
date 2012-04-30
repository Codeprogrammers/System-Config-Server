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

#include "NetworkService.h"

NetworkService::NetworkService()
{
	serviceName = "Network";
	gtkBuilderFilePath = "/home/brad/dev/System-Config-Server/src/Modules/network/NetworkService.glade";
	loadBuilderFile();
	LoadWidgets();
	ConnectSignalHandlers();

	//This is only on Debian/Ubuntu Dirivs
	filePath = new Glib::ustring("/etc/network/interfaces");
	openFile (networkFile, *filePath);
	
	testInterface = new NetworkInterfaceViewController();
	testInterface->ethernetName = new Glib::ustring("eth0");

	//Setup interfaceSelection ComboBox
	interfaceSelectorTreeModel = Gtk::ListStore::create(interfaceSelectorColumns);
	interfaceSelector->set_model(interfaceSelectorTreeModel);


	
	//New objects
	rawConfigTextBuffer = Gtk::TextBuffer::create();
	//Debug
	CheezTest ();
}

void NetworkService::LoadWidgets()
{
	g_message("Loading Network Service Widgets");
	gtkBuilder->get_widget("mainView", mainView);
	gtkBuilder->get_widget("basicNetworkInterface", basicNetworkInterface);
	gtkBuilder->get_widget("interfaceSelector", interfaceSelector);
	gtkBuilder->get_widget("configFileTextBox", configFileTextBox);
	
	testInterface = new NetworkInterfaceViewController;
	
	//GTK Entry

	//GTK Buttons

	basicNetworkInterface->remove();
	basicNetworkInterface->add(*testInterface->mainView);
}

void NetworkService::ConnectSignalHandlers()
{
}

void NetworkService::CheezTest()
{
	g_message("We haz readFile.");
	rawConfigTextBuffer->set_text("Hi There");
	configFileTextBox->set_buffer(rawConfigTextBuffer);

	Glib::RefPtr<Gio::File> f = Gio::File::create_for_path("/etc/profile");
	Glib::RefPtr<Gio::FileInputStream> file_stream = f->read();
	Glib::RefPtr<Gio::DataInputStream> data_stream = Gio::DataInputStream::create(file_stream);

	//rawConfigTextBuffer->set_text("Hello");
	//configFileTextBox->set_buffer(data_stream->get_stream);

	  Gtk::TreeModel::Row row = *(interfaceSelectorTreeModel->append());
	  row[interfaceSelectorColumns.m_col_id] = 1;
      row[interfaceSelectorColumns.m_col_name] = "eth0 - Ethernet";

		interfaceSelector->pack_start(interfaceSelectorColumns.m_col_id);
		interfaceSelector->pack_start(interfaceSelectorColumns.m_col_name);
}