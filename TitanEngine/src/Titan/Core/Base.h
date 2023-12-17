#pragma once

#include <memory>

// Platform detection using predefined macros
#ifdef _WIN32
	/* Windows x64/x86 */
	#ifdef _WIN64
	/* Windows x64  */
		#define TI_PLATFORM_WINDOWS
	#else
	/* Windows x86 */
	#error "x86 Builds are not supported!"
#endif

#elif defined(__APPLE__) || defined(__MACH__)
	#include <TargetConditionals.h>
/* TARGET_OS_MAC exists on all the platforms
 * so we must check all of them (in this order)
 * to ensure that we're running on MAC
 * and not some other Apple platform */
	#if TARGET_IPHONE_SIMULATOR == 1
		#define TI_PLATFORM_IOS_SIMULATOR
		#error "IOS simulator is not supported!"
	#elif TARGET_OS_IPHONE == 1
		#define TI_PLATFORM_IOS
		#error "IOS is not supported!"
	#elif TARGET_OS_MAC == 1
		#define TI_PLATFORM_MACOS
		#error "MacOS is not supported!"
	#else
		#error "Unknown Apple platform!"
	#endif
 /* We also have to check __ANDROID__ before __linux__
  * since android is based on the linux kernel
  * it has __linux__ defined */
#elif defined(__ANDROID__)
	#define TI_PLATFORM_ANDROID
	#error "Android is not supported!"
#elif defined(__linux__)
	#define TI_PLATFORM_LINUX
	#error "Linux is not supported!"
#else
	/* Unknown compiler/platform */
	#error "Unknown platform!"
#endif // End of platform detection


// DLL support
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
#endif // End of DLL support

#ifdef TI_DEBUG
#if defined(TI_PLATFORM_WINDOWS)
#define TI_DEBUGBREAK() __debugbreak()
#elif defined(TI_PLATFORM_LINUX)
#include <signal.h>
#define TI_DEBUGBREAK() raise(SIGTRAP)
#endif
#define TI_ENABLE_ASSERTS
#endif

//TODO: TI_ASSERT(bool) with no additional arguments
#ifdef TI_ENABLE_ASSERTS
#define TI_ASSERT(x, ...) { if(!(x)) { TI_ERROR("Assertion Failed: {2}\n\tline: {0}\n\tfile: {1}", __LINE__, __FILE__, __VA_ARGS__); TI_DEBUGBREAK();} }
#define TI_CORE_ASSERT(x, ...) { if(!(x)) { TI_CORE_ERROR("Assertion Failed: {2}\n\tline: {0}\n\tfile: {1}", __LINE__, __FILE__, __VA_ARGS__); TI_DEBUGBREAK(); } }
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

	//Creation methods
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}