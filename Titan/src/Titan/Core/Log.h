#pragma once

#include "Titan/Core/Base.h"

// This ignores all warnings raised inside External headers
#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)


namespace Titan {

	class Log
	{
	public:
		static void Init();

		static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define TI_CORE_TRACE(...)    ::Titan::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define TI_CORE_INFO(...)     ::Titan::Log::GetCoreLogger()->info(__VA_ARGS__)
#define TI_CORE_WARN(...)     ::Titan::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define TI_CORE_ERROR(...)    ::Titan::Log::GetCoreLogger()->error(__VA_ARGS__)
#define TI_CORE_CRITICAL(...) ::Titan::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define TI_TRACE(...)         ::Titan::Log::GetClientLogger()->trace(__VA_ARGS__)
#define TI_INFO(...)          ::Titan::Log::GetClientLogger()->info(__VA_ARGS__)
#define TI_WARN(...)          ::Titan::Log::GetClientLogger()->warn(__VA_ARGS__)
#define TI_ERROR(...)         ::Titan::Log::GetClientLogger()->error(__VA_ARGS__)
#define TI_CRITICAL(...)      ::Titan::Log::GetClientLogger()->critical(__VA_ARGS__)
