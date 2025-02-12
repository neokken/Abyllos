#pragma once

#include "Elder/Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Elder
{
	class Log
	{
	public:
		static ELDER_API void Init();

		static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static ELDER_API std::shared_ptr<spdlog::logger> s_CoreLogger;
		static ELDER_API std::shared_ptr<spdlog::logger> s_ClientLogger;

	};

}


#define ELD_CORE_TRACE(...)			::Elder::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ELD_CORE_INFO(...)			::Elder::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ELD_CORE_ERROR(...)			::Elder::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ELD_CORE_WARN(...)			::Elder::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ELD_CORE_CRITICAL(...)		::Elder::Log::GetCoreLogger()->critical(__VA_ARGS__)


#define ELD_TRACE(...)			::Elder::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ELD_INFO(...)			::Elder::Log::GetClientLogger()->info(__VA_ARGS__)
#define ELD_ERROR(...)			::Elder::Log::GetClientLogger()->error(__VA_ARGS__)
#define ELD_WARN(...)			::Elder::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ELD_CRITICAL(...)		::Elder::Log::GetClientLogger()->critical(__VA_ARGS__)