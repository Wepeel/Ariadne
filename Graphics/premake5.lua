project "Graphics"
        kind "StaticLib"
        language "C++"
        cppdialect "C++17"

        targetdir ("%{wks.location}/target/" .. outputDir .. "/%{prj.name}")
        objdir ("%{wks.location}/intermediate/" .. outputDir .. "/%{prj.name}")
        
        files
        {
            "inc/*.h",
            "src/*.cpp"
        }

        links
        {
            "Logging",
            "Types",
            "Event",
            "GLFW",
            "glad"
        }

        includedirs
        {
            "inc",
            "%{wks.location}/Logging/inc",
            "%{wks.location}/Event/inc",
            IncDirs["spdlog"],
            IncDirs["GLFW"],
            IncDirs["glad"]
        }

        pchheader "graphicspch.h"
        pchsource "src/graphicspch.cpp"

        filter "configurations:Debug"
            symbols "on"
            runtime "Debug"

        filter "configurations:Release"
            optimize "on"
            runtime "Release"

        filter "configurations:Dist"
            optimize "on"
            runtime "Release"