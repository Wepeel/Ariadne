--	premake5.lua

workspace "Ariadne"
    architecture "x86_64"
    startproject "Graphics"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputDir = "%{cfg.buildcfg}/%{cfg.system}/%{cfg.architecture}"

IncDirs = {}

IncDirs["spdlog"] = "%{wks.location}/Logging/ext/spdlog/include"

include "Logging"
include "Graphics"