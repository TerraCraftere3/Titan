#pragma once

#include "Core.h"
#include "Events/Event.h"

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
