#include "ServiceModuleMain.h"
#include <gtkmm.h>

ServiceModule::ServiceModule()
{
	g_message("Service Module Default Constructor!\n");
	mainView = NULL;
}

void ServiceModule::ShowServiceModule()
{
	g_message("Clicked Module: %s", serviceName.c_str());
	if(mainView != NULL)
	   {
		   //Remove any Widget if there is one
		   rootServiceWindow->remove();
		   //Load the selected widget
		   rootServiceWindow->add(*mainView);
	   }
	else
	{
		g_error("No Glade/Widgets loaded from Module! (ServiceModuleMain::ShowServiceModule)");
	}
}

void ServiceModule::openFile(Glib::RefPtr<Gio::File> file,Glib::ustring filePathString)
{
	  g_message("Attempt to readFile ServiceModule Main");
	  try
	  {
		file = Gio::File::create_for_path(filePathString);
		if(!file)
			g_error("Gio::File::create_for_path() returned an empty RefPtr. (ServiceModuleMain)");
		  //std::cerr << "Gio::File::create_for_path() returned an empty RefPtr." << std::endl;
	  }
	  catch(const Glib::Exception& ex)
	  {
		  g_error("Exception caught @ ServiceModuleMain.");
		//std::cout << "Exception caught: " << ex.what() << std::endl;
	  }
}