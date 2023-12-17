#pragma once
//TODO: Remove
#include <Titan/Core/Input.h>
#ifdef TI_PLATFORM_WINDOWS
#include "Windows/WindowsInput.h"
#elif TI_PLATFORM_LINUX
#error We dont use that here :)
#endif