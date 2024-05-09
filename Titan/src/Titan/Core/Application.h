#pragma once

#include "Titan/Core/Base.h"

#include "Titan/Core/Window.h"
#include "Titan/Core/LayerStack.h"
#include "Titan/Events/Event.h"
#include "Titan/Events/ApplicationEvent.h"

#include "Titan/Core/Timestep.h"

#include "Titan/ImGui/ImGuiLayer.h"

int main(int argc, char** argv);

namespace Titan {

	class Application
	{
	public:
		Application(const std::string& name = "Titan App");
		virtual ~Application();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		Window& GetWindow() { return *m_Window; }

		void Close();

		ImGuiLayer* GetImGuiLayer() { return m_ImGuiLayer; }

		static Application& Get() { return *s_Instance; }
	private:
		void Run();
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);
	private:
		Scope<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
	private:
		static Application* s_Instance;
		friend int ::main(int argc, char** argv);
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}