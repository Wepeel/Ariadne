--	premake5.lua

workspace "Ariadne"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputDir = "%{cfg.buildcfg}/%{cfg.system}/%{cfg.architecture}"

    project "Logging"
        location "Logging"
        kind "ConsoleApp"
        language "C++"
        cppdialect "C++17"

        targetdir ("%{wks.location}/target/" .. outputDir .. "/%{prj.name}")
        objdir ("%{wks.location}/intermediate/" .. outputDir .. "/%{prj.name}")
        
        files
        {
            "%{prj.name}/inc/**.h",
            "%{prj.name}/src/**.cpp"
        }

        includedirs
        {
            "%{prj.name}/inc",
            "%{prj.name}/ext/spdlog/include"
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

    project "Graphics"
        location "Graphics"
        kind "StaticLib"
        language "C++"
        cppdialect "C++17"

        targetdir ("%{wks.location}/" .. outputDir .. "/%{prj.name}")
        objdir ("%{wks.location}/intermediate/" .. outputDir .. "/%{prj.name}")
        
        files
        {
            "%{prj.name}/inc/**.h",
            "%{prj.name}/src/**.cpp"
        }

        includedirs
        {
            "%{prj.name}/inc"
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