--	premake5.lua

workspace "Ariadne"
    architecture "x86_64"
    startproject "Application"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputDir = "%{cfg.buildcfg}/%{cfg.system}/%{cfg.architecture}"

IncDirs = {}

IncDirs["spdlog"] = "%{wks.location}/Logging/ext/spdlog/include"
IncDirs["GLFW"] = "%{wks.location}/ext/src/GLFW/include"
IncDirs["glad"] = "%{wks.location}/ext/src/glad/include"


group "External"
    include "ext/src/GLFW"
    include "ext/src/glad"
group ""


include "Types"
include "Logging"
include "Graphics"
include "Event"
include "Application"