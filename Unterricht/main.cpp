#include <stdio.h>
#include <stdlib.h>

#include "Application.h"

int main(int argc, char** argv) {
	Application app;

	app.Initialize();
	app.Run();
	app.Shutdown();

	return EXIT_SUCCESS;
}
