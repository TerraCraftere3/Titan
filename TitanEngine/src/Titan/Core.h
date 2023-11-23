#pragma once

#include <memory>

#ifdef TI_PLATFORM_WINDOWS
	#if TI_DYNAMIC_LINK
		#ifdef TI_BUILD_DLL
			#define TI_API __declspec(dllexport)
		#else
		#define TI_API __declspec(dllimport)
	#endif
	#else
		#define TI_API
	#endif
#else
	#error Titan only supports Windows!
#endif

#ifdef HZ_DEBUG
	#define HZ_ENABLE_ASSERTS
#endif

#ifdef HZ_ENABLE_ASSERTS
	#define TI_ASSERT(x, ...) { if(!(x)) { HZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define TI_CORE_ASSERT(x, ...) { if(!(x)) { HZ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define TI_ASSERT(x, ...)
	#define TI_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define TI_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

namespace Titan {

	template<typename T>
	using Scope = std::unique_ptr<T>;

	template<typename T>
	using Ref = std::shared_ptr<T>;

}