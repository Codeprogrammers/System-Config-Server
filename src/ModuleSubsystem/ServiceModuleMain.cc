#include "ServiceModuleMain.h"
#include <gtkmm.h>

ServiceModule::ServiceModule()
{
	g_message("Service Module Default Constructor STUB!\n");
}

void ServiceModule::ShowServiceModule()
{
	g_message("Clicked Module: %s", serviceName.c_str());
	if(rootServiceWindow != NULL)
	   {
		   rootServiceWindow->remove();
		   rootServiceWindow->add(*mainView);
	   }
	
}