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
	
	private:
		Glib::ustring serviceName;
};
#endif
