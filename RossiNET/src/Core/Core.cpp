#include "rpch.h"
#include "Core.h"
#include <filesystem>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

namespace Core
{
    std::string Core::GetExecutablePath()
    {
        std::vector<char> pathBuffer;
        unsigned int pathSize = 0;

        #ifdef _WIN32
        pathBuffer.resize(MAX_PATH);
        pathSize = GetModuleFileNameA(NULL, &pathBuffer[0], pathBuffer.size());
        while (pathSize == pathBuffer.size()) {
            pathBuffer.resize(pathBuffer.size() * 2);
            pathSize = GetModuleFileNameA(NULL, &pathBuffer[0], pathBuffer.size());
        }
        #else
        pathBuffer.resize(PATH_MAX);
        pathSize = readlink("/proc/self/exe", &pathBuffer[0], pathBuffer.size());
        while (pathSize == pathBuffer.size()) {
            pathBuffer.resize(pathBuffer.size() * 2);
            pathSize = readlink("/proc/self/exe", &pathBuffer[0], pathBuffer.size());
        }
        #endif

        return std::string(pathBuffer.begin(), pathBuffer.begin() + pathSize);
    }

    std::string Core::GetResourcePath(const std::string& executablePath, const std::string& relativeResourcesPath)
    {
        std::filesystem::path exePath(executablePath);
        std::filesystem::path resourcesPath = exePath.parent_path() / relativeResourcesPath;
        return resourcesPath.lexically_normal().string();
    }

    std::string Core::ToStringWithPrecision(double value, int precision)
    {
        std::ostringstream out;
        out << std::fixed << std::setprecision(precision) << value;
        return out.str();
    }

}

