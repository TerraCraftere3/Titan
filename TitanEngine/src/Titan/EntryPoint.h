#pragma once

#ifdef TI_PLATFORM_WINDOWS
extern Titan::Application* Titan::CreateApplication();

int main(int argc, char** argv) 
{
	Titan::Log::Init();
	TITAN_CORE_WARN("Initialized Log!");
	auto app = Titan::CreateApplication();
	app->Run();
	delete app;
}
#endif