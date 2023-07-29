#include "tipch.h"

#include "Application.h"

#include "Titan/Events/Event.h"
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
		TITAN_TRACE(e.ToString());

		while (true);
	}

}
