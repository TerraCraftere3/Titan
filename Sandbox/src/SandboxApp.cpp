#include <Titan.h>

class Sandbox : public Titan::Application
{
public:
	Sandbox()
	{
		TITAN_INFO ("This is 'TITAN_INFO()'");
		TITAN_WARN ("This is 'TITAN_WARN()'");
		TITAN_ERROR("This is 'TITAN_ERROR()'");
		TITAN_TRACE("This is 'TITAN_TRACE()'");
		TITAN_FATAL("This is 'TITAN_FATAL()'");
	}

	~Sandbox() 
	{
		TITAN_WARN("Here it destroyes the application :)");
	}
};

Titan::Application* Titan::CreateApplication() {
	return new Sandbox();
}