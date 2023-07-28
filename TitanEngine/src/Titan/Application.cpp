#include "Application.h"

#include "Titan/Events/ApplicationEvent.h"
#include "Titan/Log.h"

namespace Titan {

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			TITAN_TRACE(e.ToString());
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			TITAN_TRACE(e.ToString());
		}

		while (true);
	}

}
