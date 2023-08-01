#include <Titan.h>
#include <imgui/imgui.h>

class ExampleLayer : public Titan::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}
};

class Sandbox : public Titan::Application
{
public:
	Sandbox()
	{
		TITAN_TRACE("This is 'TITAN_TRACE()'");
		TITAN_INFO("This is 'TITAN_INFO()'");
		TITAN_WARN("This is 'TITAN_WARN()'");
		TITAN_ERROR("This is 'TITAN_ERROR()'");
		TITAN_FATAL("This is 'TITAN_FATAL()'");
		PushLayer(new ExampleLayer());
		PushOverlay(new Titan::ImGuiLayer());
	}

	~Sandbox() 
	{
	}
};

Titan::Application* Titan::CreateApplication() {
	return new Sandbox();
}