project "Testing"
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

        includedirs
        {
            "inc",
        }

        pchheader "testingpch.h"
        pchsource "src/testingpch.cpp"

        filter "configurations:Debug"
            symbols "on"
            runtime "Debug"

        filter "configurations:Release"
            optimize "on"
            runtime "Release"

        filter "configurations:Dist"
            optimize "on"
            runtime "Release"