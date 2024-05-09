#include "tipch.h"
#include "Titan/Core/Window.h"

#ifdef TI_PLATFORM_WINDOWS
	#include "Platform/Windows/WindowsWindow.h"
#endif

namespace Titan
{
	Scope<Window> Window::Create(const WindowProps& props)
	{
	#ifdef TI_PLATFORM_WINDOWS
		return CreateScope<WindowsWindow>(props);
	#else
		TI_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
	#endif
	}

}