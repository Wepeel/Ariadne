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
            "Event"
        }

        includedirs
        {
            "inc",
            "%{wks.location}/Logging/inc",
            IncDirs["spdlog"]
        }

        filter "configurations:Debug"
            symbols "on"
            runtime "Debug"

        filter "configurations:Release"
            optimize "on"
            runtime "Release"

        filter "configurations:Dist"
            optimize "on"
            runtime "Release"