#pragma once

#include "Core.h"

#include "Titan/Events/Event.h"
#include "Titan/Events/ApplicationEvent.h"

namespace Titan {
	class TI_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};
	
	// Clientside
	Application* CreateApplication();
}
