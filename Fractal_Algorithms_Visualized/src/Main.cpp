#define OLC_PGE_APPLICATION

#include "Application.h"

int main()
{
	Application* app = new Application();

	if (app->Construct(1000, 800, 1, 1))
		app->Start();

	app = nullptr;
	delete app;

	return 0;
}