#pragma once

#include "Core.h"


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
