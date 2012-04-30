#ifndef SERVICE_MODULE_H
#define SERVICE_MODULE_H

#include <gtkmm.h>
#include <libxml++/libxml++.h>
#include "../ViewControllers/GTKBuilderViewController.h"

class ServiceModule: public GTKBuilderViewController
{
	public:
			//@Creates a simple Instance of Service Module
			//@in which can be used to load system-config-service
			//@modules into the GUI
			//@pre:A module must be specified (source file)
			//@post:The module is loaded from the file
			//@usage: STUB
			ServiceModule();

			void ShowServiceModule();
			void LoadWidgets();
			void ConnectSignalHandlers();

			void readFile();
			Gtk::ScrolledWindow *rootServiceWindow;
			Gtk::Viewport *mainView;
			Glib::ustring serviceName;
			
	protected:
	
	private:
};
#endif
