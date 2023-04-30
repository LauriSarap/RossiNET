#include "rpch.h"
#include "Core/Core.h"

int main()
{
	while (true)
	{
		auto app = Core::Application();
		app.Run();
		delete &app;
	}
}
