#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"


namespace Titan {

	class TI_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define TITAN_CORE_TRACE(...)    ::Titan::Log::GetCoreLogger()->trace(__VA_ARGS__);
#define TITAN_CORE_INFO(...)     ::Titan::Log::GetCoreLogger()->info(__VA_ARGS__);
#define TITAN_CORE_WARN(...)     ::Titan::Log::GetCoreLogger()->warn(__VA_ARGS__);
#define TITAN_CORE_ERROR(...)    ::Titan::Log::GetCoreLogger()->error(__VA_ARGS__);
#define TITAN_CORE_FATAL(...)    ::Titan::Log::GetCoreLogger()->critical(__VA_ARGS__);

// Client log macros
#define TITAN_TRACE(...)	     ::Titan::Log::GetClientLogger()->trace(__VA_ARGS__)
#define TITAN_INFO(...)	         ::Titan::Log::GetClientLogger()->info(__VA_ARGS__)
#define TITAN_WARN(...)	         ::Titan::Log::GetClientLogger()->warn(__VA_ARGS__)
#define TITAN_ERROR(...)	     ::Titan::Log::GetClientLogger()->error(__VA_ARGS__)
#define TITAN_FATAL(...)	     ::Titan::Log::GetClientLogger()->critical(__VA_ARGS__)

#ifdef TI_DIST
	//Disable Logging
	#define TITAN_CORE_TRACE(...)
	#define TITAN_CORE_INFO(...)
	#define TITAN_CORE_WARN(...)

	#define TITAN_TRACE(...)
	#define TITAN_INFO(...)
	#define TITAN_WARN(...)
#endif