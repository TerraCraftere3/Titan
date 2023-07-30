#pragma once

#include "Core.h"
#include "Titan/Log.h"
#include "Window.h"

#include "Titan/LayerStack.h"
#include "Titan/Events/Event.h"
#include "Titan/Events/ApplicationEvent.h"


namespace Titan {
	class TI_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClosed(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
		static Application* s_Instance;
	};
	
	// Clientside
	Application* CreateApplication();
}
