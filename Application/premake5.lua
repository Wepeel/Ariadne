project "Application"
        kind "ConsoleApp"
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
            "Graphics",
            "Event",
        }

        includedirs
        {
            "inc",
            "%{wks.location}/Logging/inc",
            "%{wks.location}/Graphics/inc",
            "%{wks.location}/Event/inc",
            IncDirs["spdlog"],
            IncDirs["GLFW"],
            IncDirs["glad"]
        }

        pchheader "apppch.h"
        pchsource "src/apppch.cpp"

        filter "configurations:Debug"
            symbols "on"
            runtime "Debug"

        filter "configurations:Release"
            optimize "on"
            runtime "Release"

        filter "configurations:Dist"
            optimize "on"
            runtime "Release"