#pragma once

#ifdef TI_PLATFORM_WINDOWS

extern Titan::Application* Titan::CreateApplication();

int main(int argc, char** argv) 
{
	printf(titanEngineLogo.c_str());
	printf("Made by TerraSTUDIOS");
	auto app = Titan::CreateApplication();
	app->Run();
	delete app;
}
#endif