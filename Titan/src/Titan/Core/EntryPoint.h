#pragma once
#include "Titan/Core/Base.h"

#ifdef TI_PLATFORM_WINDOWS

extern Titan::Application* Titan::CreateApplication();

int main(int argc, char** argv)
{
	Titan::Log::Init();

	TI_PROFILE_BEGIN_SESSION("Startup", "TitanProfile-Startup.json");
	auto app = Titan::CreateApplication();
	TI_PROFILE_END_SESSION();

	TI_PROFILE_BEGIN_SESSION("Runtime", "TitanProfile-Runtime.json");
	app->Run();
	TI_PROFILE_END_SESSION();

	TI_PROFILE_BEGIN_SESSION("Shutdown", "TitanProfile-Shutdown.json");
	delete app;
	TI_PROFILE_END_SESSION();
}

#endif
