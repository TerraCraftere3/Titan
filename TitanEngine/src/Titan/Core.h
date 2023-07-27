#pragma once

#ifdef TI_PLATFORM_WINDOWS
	#ifdef TI_BUILD_DLL
		#define TI_API __declspec(dllexport)
	#else
		#define TI_API __declspec(dllimport)
	#endif
#else
	#error Titan only supports Windows
#endif