#include "rpch.h"
#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Core
{
   std::shared_ptr<spdlog::logger> Log::spdLogLogger;

   void Log::Initialization()
   {
      spdlog::set_pattern("%^[%T] %n: %v%$");
      
      spdLogLogger = spdlog::stdout_color_mt("ROSSINET");
      spdLogLogger->set_level(spdlog::level::trace);
   }
}
