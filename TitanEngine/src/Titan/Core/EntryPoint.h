#pragma once

#ifdef TI_PLATFORM_WINDOWS

extern Titan::Application* Titan::CreateApplication();

int main(int argc, char** argv) 
{
	{
		printf(R""""(
  _______ _ _              ______             _            
 |__   __(_) |            |  ____|           (_)           
    | |   _| |_ __ _ _ __ | |__   _ __   __ _ _ _ __   ___ 
    | |  | | __/ _` | '_ \|  __| | '_ \ / _` | | '_ \ / _ \
    | |  | | || (_| | | | | |____| | | | (_| | | | | |  __/
    |_|  |_|\__\__,_|_| |_|______|_| |_|\__, |_|_| |_|\___|
                                         __/ |             
                                        |___/              
)"""");
		printf(R""""(
Made by TerraSTUDIOS
Apache License : Version 2.0, January 2004
http://www.apache.org/licenses/
Inspired by TheCherno, "GameEngine Series"
Logging: https://github.com/gabime/spdlog
)"""");
	} //Logo and credits

	Titan::Log::Init();

	TI_PROFILE_BEGIN_SESSION("Startup", "Profile/Startup.json");
	auto app = Titan::CreateApplication();
	TI_PROFILE_END_SESSION();
	TI_PROFILE_BEGIN_SESSION("Runtime", "Profile/Runtime.json");
	app->Run();
	TI_PROFILE_END_SESSION();
	TI_PROFILE_BEGIN_SESSION("Shutdown", "Profile/Shutdown.json");
	delete app;
	TI_PROFILE_END_SESSION();
}
#endif