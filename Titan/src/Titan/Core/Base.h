#pragma once

#include <memory>

#include "Titan/Core/PlatformDetection.h"

#ifdef TI_DEBUG
	#if defined(TI_PLATFORM_WINDOWS)
		#define TI_DEBUGBREAK() __debugbreak()
	#elif defined(TI_PLATFORM_LINUX)
		#include <signal.h>
		#define TI_DEBUGBREAK() raise(SIGTRAP)
	#else
		#error "Platform doesn't support debugbreak yet!"
	#endif
	#define TI_ENABLE_ASSERTS
#else
	#define TI_DEBUGBREAK()
#endif

#define TI_EXPAND_MACRO(x) x
#define TI_STRINGIFY_MACRO(x) #x

#define BIT(x) (1 << x)

#define TI_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace Titan {

	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}

#include "Titan/Core/Log.h"
#include "Titan/Core/Assert.h"
