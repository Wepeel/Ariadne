project "Event"
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
        "Types",
        "Logging"
    }

    includedirs
    {
        "inc",
        "%{wks.location}/Logging/inc",
        "%{wks.location}/Types/inc",
        IncDirs["spdlog"]
    }

    pchheader "eventpch.h"
    pchsource "src/eventpch.cpp"

    filter "configurations:Debug"
        symbols "on"
        runtime "Debug"

    filter "configurations:Release"
        optimize "on"
        runtime "Release"

    filter "configurations:Dist"
        optimize "on"
        runtime "Release"