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

void readFile(Glib::RefPtr<Gio::File> file,Glib::ustring filePathString)
{
	  try
	  {
		file = Gio::File::create_for_path("/etc/fstab");
		if(!file)
			  g_error("GIO File returned empty RefPtr");
		  //std::cerr << "Gio::File::create_for_path() returned an empty RefPtr." << std::endl;
	  }
	  catch(const Glib::Exception& ex)
	  {
		  g_error("Something went wrong in the NetworkInterfaceViewController ()");
		//std::cout << "Exception caught: " << ex.what() << std::endl;
	  }
}