#include "service_module_main.h"

service_module::service_module()
{
	printf("Service Module Default Constructor STUB!\n");
}

//@Loads the Glade file from the specified location
//@then links it to builder variable "gladeGUI".
//@Otherwise throw exception
//@pre:A module filepath must be provided
//@post:gladeGUI is linked to the external .glade file
void service_module::LoadGuiGlade()
{
	printf("Service Module - LoadGuiGlade() Stub\n");
}
