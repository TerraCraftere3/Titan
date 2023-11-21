#pragma once

#include "Core.h"

#include "Window.h"
#include "Titan/LayerStack.h"
#include "Titan/Events/Event.h"
#include "Titan/Events/ApplicationEvent.h"

#include "Titan/ImGui/ImGuiLayer.h"

#include "Titan/Renderer/Shader.h"
#include "Titan/Renderer/Buffer.h"
#include "Titan/Renderer/VertexArray.h"

#include "Titan/Renderer/OrthographicCamera.h"

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
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		std::shared_ptr<Shader> m_Shader;
		std::shared_ptr<VertexBuffer> m_VertexBuffer;
		std::shared_ptr<IndexBuffer> m_IndexBuffer;
		std::shared_ptr<VertexArray> m_VertexArray;

		OrthographicCamera m_Camera;
	private:
		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}