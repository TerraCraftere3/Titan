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
	}

	void OnEvent(Titan::Event& event) override
	{
		TITAN_TRACE("{0}", event.ToString());
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
	}

	~Sandbox() 
	{
	}
};

Titan::Application* Titan::CreateApplication() {
	return new Sandbox();
}