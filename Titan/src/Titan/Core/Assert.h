#pragma once

#include "Titan/Core/Base.h"
#include "Titan/Core/Log.h"
#include <filesystem>

#ifdef TI_ENABLE_ASSERTS

	// Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and
	// provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message
	#define TI_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { TI##type##ERROR(msg, __VA_ARGS__); TI_DEBUGBREAK(); } }
	#define TI_INTERNAL_ASSERT_WITH_MSG(type, check, ...) TI_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
	#define TI_INTERNAL_ASSERT_NO_MSG(type, check) TI_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", TI_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

	#define TI_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
	#define TI_INTERNAL_ASSERT_GET_MACRO(...) TI_EXPAND_MACRO( TI_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, TI_INTERNAL_ASSERT_WITH_MSG, TI_INTERNAL_ASSERT_NO_MSG) )

	// Currently accepts at least the condition and one additional parameter (the message) being optional
	#define TI_ASSERT(...) TI_EXPAND_MACRO( TI_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
	#define TI_CORE_ASSERT(...) TI_EXPAND_MACRO( TI_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
	#define TI_ASSERT(...)
	#define TI_CORE_ASSERT(...)
#endif
