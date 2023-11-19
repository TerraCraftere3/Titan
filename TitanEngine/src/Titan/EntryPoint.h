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
	TITAN_CORE_WARN("Initialized Log!");

	auto app = Titan::CreateApplication();
	app->Run();
	delete app;
}
#endif