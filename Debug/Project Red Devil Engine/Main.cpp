///
/// Red Devil Engine Code
/// Property of Astro Dynamics 2021
/// jkringstad@astro-dynamics.net
///

#include "AppWindow.h"

int main() {
	AppWindow app;
	
	if (app.init())
	{
		while (app.isRun())
		{
			app.broadcast();
		}
	}

	return 0;
}