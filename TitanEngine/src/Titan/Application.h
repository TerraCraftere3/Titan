#pragma once

#include "Core.h"
#include "Titan/Log.h"
#include "Window.h"
#include "Events/ApplicationEvent.h"


namespace Titan {
	class TI_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
	private:
		bool OnWindowClosed(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};
	
	// Clientside
	Application* CreateApplication();
}
