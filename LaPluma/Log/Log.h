#pragma once

#include <memory>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include "Core/Core.h"

namespace LaPluma
{
    class LP_API Log
    {
    public:
        Log();
        ~Log();

        static void init();
        static inline std::shared_ptr<spdlog::logger>& getCoreLogger() { return lo_coreLogger; };
        static inline std::shared_ptr<spdlog::logger>& getClientLogger() { return lo_clientLogger; };
    private:
        static std::shared_ptr<spdlog::logger> lo_coreLogger;
        static std::shared_ptr<spdlog::logger> lo_clientLogger;
    };
} // namespace LaPluma

// ClientLogger
#define LoggerTrace(...)    ::LaPluma::Log::getClientLogger()->trace(__VA_ARGS__)
#define LoggerInfo(...)     ::LaPluma::Log::getClientLogger()->info(__VA_ARGS__)
#define LoggerWarn(...)     ::LaPluma::Log::getClientLogger()->warn(__VA_ARGS__)
#define LoggerError(...)    ::LaPluma::Log::getClientLogger()->error(__VA_ARGS__)