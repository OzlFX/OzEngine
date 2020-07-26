/** See https://github.com/gabime/spdlog/wiki/3.-Custom-formatting for formatting methods **/
#include "Log.h"
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Oz
{
	std::shared_ptr<spdlog::logger> cLog::s_CoreLogger;
	std::shared_ptr<spdlog::logger> cLog::s_ClientLogger;

	void cLog::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$"); //Set pattern for how loggers will be formatted: Colour, Timestamp, name of logger, log message
		s_CoreLogger = spdlog::stdout_color_mt("OZ LOGGER"); //Name the engine logger
		s_CoreLogger->set_level(spdlog::level::trace); //Set engine logger error level
		s_ClientLogger = spdlog::stdout_color_mt("APP LOGGER"); //Name the client logger
		s_ClientLogger->set_level(spdlog::level::trace); //Set client logger error level
	}
}