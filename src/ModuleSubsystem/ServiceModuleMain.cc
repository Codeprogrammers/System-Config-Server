#include "ServiceModuleMain.h"
#include <gtkmm.h>

service_module::service_module()
{
	g_message("Service Module Default Constructor STUB!\n");
}

//@Loads the Glade file from the specified location
//@then links it to builder variable "gladeGUI".
//@Otherwise throw exception
//@pre:A module filepath must be provided
//@post:gladeGUI is linked to the external .glade file
void service_module::LoadGuiGlade()
{
	g_message("Service Module - LoadGuiGlade() Stub\n");
}
