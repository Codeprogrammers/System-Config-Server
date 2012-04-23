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