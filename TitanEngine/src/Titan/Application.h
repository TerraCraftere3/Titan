#pragma once

#include "Core.h"
#include "Titan/Log.h"
#include "Window.h"


namespace Titan {
	class TI_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};
	
	// Clientside
	Application* CreateApplication();
}
