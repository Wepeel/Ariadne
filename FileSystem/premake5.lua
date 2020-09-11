project "FileSystem"
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

        --pchheader "filesys.h"
        --pchsource "src/filesys.cpp"

        filter "configurations:Debug"
            symbols "on"
            runtime "Debug"

        filter "configurations:Release"
            optimize "on"
            runtime "Release"

        filter "configurations:Dist"
            optimize "on"
            runtime "Release"