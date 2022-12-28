#include "Log.h"

namespace LaPluma
{
    std::shared_ptr<spdlog::logger> Log::lo_coreLogger;
    std::shared_ptr<spdlog::logger> Log::lo_clientLogger;

    Log::Log()
    {
    };
    
    Log::~Log()
    {
    };
    
    void Log::init()
    {
        spdlog::set_pattern("%^[%Y-%m-%d %T] [%n] %v%$");

        lo_coreLogger = spdlog::stdout_color_mt("LaPluma");
        lo_coreLogger->set_level(spdlog::level::trace);

        lo_clientLogger = spdlog::stdout_color_mt("Application");
        lo_clientLogger->set_level(spdlog::level::trace);

        lo_coreLogger->info("Logger initialized.");
    };
} // namespace LaPluma
