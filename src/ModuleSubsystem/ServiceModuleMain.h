#ifndef SERVICE_MODULE_H
#define SERVICE_MODULE_H

#include <gtkmm.h>
#include <libxml++/libxml++.h>
#include <iostream>

class service_module
{
	public:
			//@Creates a simple Instance of Service Module
			//@in which can be used to load system-config-service
			//@modules into the GUI
			//@pre:A module must be specified (source file)
			//@post:The module is loaded from the file
			//@usage: STUB
			service_module();
			
			
	protected:
			//@Loads the Glade file from the specified location
			//@then links it to builder variable "gladeGUI".
			//@Otherwise throw exception
			//@pre:A module filepath must be provided
			//@post:gladeGUI is linked to the external .glade file
			void LoadGuiGlade();
	
	private:
		Glib::RefPtr<Gtk::Builder> gladeGUI;
		Glib::ustring serviceName;
};
#endif
