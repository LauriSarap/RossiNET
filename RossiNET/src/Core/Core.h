#pragma once

#include "Log.h"
#include "Application.h"
#include "Layer.h"

namespace Core
{
    class Core
    {
    public:
        static std::string GetExecutablePath();
        static std::string GetResourcePath(const std::string& executablePath, const std::string& relativeResourcesPath);

        static std::string ToStringWithPrecision(double value, int precision);
    };
}
