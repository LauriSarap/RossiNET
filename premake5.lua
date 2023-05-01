workspace "RossiNET"
    architecture "x64"
    startproject "RossiNET"

    configurations
    {
        "Debug",
        "Release"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["SFML"] = "vendor/SFML/include"
IncludeDir["spdlog"] = "vendor/spdlog/include"

project "RossiNET"
    location "RossiNET"
    kind "ConsoleApp"
    language "C++"
    staticruntime "off"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	pchheader "rpch.h"
	pchsource "RossiNET/src/rpch.cpp"

    files 
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/src/**.png",
        "%{prj.name}/src/**.ttf"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{IncludeDir.SFML}",
        "%{IncludeDir.spdlog}"
    }

    libdirs
    {
        "vendor/SFML/lib"
    }

    links 
    {
        "opengl32.lib",
        "freetype.lib", 
        "winmm.lib", 
        "gdi32.lib", 
        "openal32.lib", 
        "flac.lib", 
        "vorbisenc.lib", 
        "vorbisfile.lib", 
        "vorbis.lib", 
        "ogg.lib", 
        "ws2_32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"

        defines
        {
            "RN_PLATFORM_WINDOWS",
            "SFML_STATIC"
        }

    filter "configurations:Debug"
        defines "RN_DEBUG"
        runtime "Debug"
        symbols "On"

        links
        {
            "sfml-graphics-s-d.lib",
            "sfml-window-s-d.lib",
            "sfml-system-s-d.lib",
            "sfml-audio-s-d.lib",
            "sfml-network-s-d.lib"
        }
    
    filter "configurations:Release"
        defines "RN_RELEASE"
        runtime "Release"
        optimize "On"

        links
        {
            "sfml-graphics-s.lib",
            "sfml-window-s.lib",
            "sfml-system-s.lib",
            "sfml-audio-s.lib",
            "sfml-network-s.lib"
        }
