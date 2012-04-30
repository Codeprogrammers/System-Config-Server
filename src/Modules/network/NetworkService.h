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

#ifndef _NETWORKSERVICE_H_
#define _NETWORKSERVICE_H_
#include "../../ModuleSubsystem/ServiceModuleMain.h"
#include "./NetworkServiceViewControllers/NetworkInterfaceViewController.h"

class NetworkService: public ServiceModule 
{
public:
	NetworkService();

	void LoadWidgets();
	void ConnectSignalHandlers();

	//Widgets
	Gtk::ScrolledWindow *basicNetworkInterface;
	Gtk::Button *applySettings;
	Gtk::Button *resetSettings;

	Gtk::TextView *configFileTextBox;
	
	//Internal Data structures

	GList networkInterfaces;
	//InterfaceSelector Data Structures

	//TextView Data Structures
	Glib::RefPtr<Gtk::TextBuffer> rawConfigTextBuffer;

	//File Specific Data
	Glib::ustring *filePath;
	Glib::RefPtr<Gio::File> networkFile;
	Glib::RefPtr<Gio::FileInputStream> networkFileStream;

	
	//Debug Functions & Widgets
	NetworkInterfaceViewController *testInterface;
	void CheezTest();	
	
	//Column TreeModel Class
	class ModelColumns : public Gtk::TreeModel::ColumnRecord
	{
		public:

		ModelColumns()
		{ 
			add(m_col_id); add(m_col_name); 
		}

		Gtk::TreeModelColumn<int> m_col_id;
		Gtk::TreeModelColumn<Glib::ustring> m_col_name;
	};
	
	//ComboBox (interfaceSelector) Data Structures
	Gtk::ComboBox *interfaceSelector;
	Glib::RefPtr<Gtk::ListStore> interfaceSelectorTreeModel;
	ModelColumns interfaceSelectorColumns;
	
protected:

private:

};

#endif // _NETWORKSERVICE_H_
