#pragma once


#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Sword
{
	class SWORD_API Log
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


// Core Log macros
#define SW_CORE_ERROR(...)	::Sword::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SW_CORE_WARN(...)	::Sword::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SW_CORE_INFO(...)	::Sword::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SW_CORE_TRACE(...)	::Sword::Log::GetCoreLogger()->trace(__VA_ARGS__)

// Client Log macros
#define SW_ERROR(...)		::Sword::Log::GetClientLogger()->error(__VA_ARGS__)
#define SW_WARN(...)		::Sword::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SW_INFO(...)		::Sword::Log::GetClientLogger()->info(__VA_ARGS__)
#define SW_TRACE(...)		::Sword::Log::GetClientLogger()->trace(__VA_ARGS__)