#include <Titan.h>

class ExampleLayer : public Titan::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		if (Titan::Input::IsKeyPressed(TI_KEY_TAB))
			TITAN_INFO("Works...");
	}

	void OnEvent(Titan::Event& event) override
	{
		if (event.GetEventType() == Titan::EventType::KeyPressed)
		{
			Titan::KeyPressedEvent& e = (Titan::KeyPressedEvent&)event;
			TITAN_TRACE("{0}", (char)e.GetKeyCode());
		}
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