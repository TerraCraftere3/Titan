#include <Titan.h>

class Sandbox : public Titan::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox() 
	{

	}
};

Titan::Application* Titan::CreateApplication() {

	return new Sandbox();
}