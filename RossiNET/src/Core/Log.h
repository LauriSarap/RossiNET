#pragma once
#include "spdlog/spdlog.h"

namespace Core
{
    class Log
    {
    public:
        static void Initialization();

        inline static std::shared_ptr<spdlog::logger>& GetLogger() { return spdLogLogger; }

    private:
        static std::shared_ptr<spdlog::logger> spdLogLogger;
    };
}

// Log macros
#define LOG_INFO(...)           ::Core::Log::GetLogger()->trace(__VA_ARGS__)
#define LOG_WARN(...)           ::Core::Log::GetLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...)          ::Core::Log::GetLogger()->error(__VA_ARGS__)
