#include "ServiceModuleMain.h"
#include <gtkmm.h>

ServiceModule::ServiceModule()
{
	g_message("Service Module Default Constructor STUB!\n");
}

void ServiceModule::ShowServiceModule()
{
	g_message("Time to show module");
}