/** Wrapper for the logging system of the engine **/
#ifndef _CLOG_H_
#define _CLOG_H_
//Includes
#include <spdlog/spdlog.h>
#include <memory>

#include "OzEngine/Core/Core.h"

namespace Oz
{
	class OZ_API cLog
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

/* MACROS to handle logging (NOT CURRENTLY USED) */
//Core
#define OZ_CORE_CRITICAL(...) ::Oz::cLog::GetCoreLogger()->critical(__VA_ARGS__)
#define OZ_CORE_ERROR(...) ::Oz::cLog::GetCoreLogger()->error(__VA_ARGS__)
#define OZ_CORE_WARN(...)  ::Oz::cLog::GetCoreLogger()->warn(__VA_ARGS__)
#define OZ_CORE_INFO(...)  ::Oz::cLog::GetCoreLogger()->info(__VA_ARGS__)
#define OZ_CORE_TRACE(...) ::Oz::cLog::GetCoreLogger()->trace(__VA_ARGS__)

//Client
#define OZ_CRITICAL(...) ::Oz::cLog::GetClientLogger()->critical(__VA_ARGS__)
#define OZ_ERROR(...) ::Oz::cLog::GetClientLogger()->error(__VA_ARGS__)
#define OZ_WARN(...)  ::Oz::cLog::GetClientLogger()->warn(__VA_ARGS__)
#define OZ_INFO(...)  ::Oz::cLog::GetClientLogger()->info(__VA_ARGS__)
#define OZ_TRACE(...) ::Oz::cLog::GetClientLogger()->trace(__VA_ARGS__)

#endif