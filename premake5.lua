project "PDCurses"
    kind "StaticLib"
    language "C"
    cdialect "C99"

    targetdir("../bin/" .. outputdir .. "/%{prj.name}")
    objdir("../bin-int/" .. outputdir .. "/%{prj.name}")

    configurations {
        "Debug",
        "Release",
        "Dist"
    }

    files {
        "Source/**.c",
        "Source/**.h"
    }

    includedirs {
        "Source"
    }

    vpaths {
        ["Header Files"] = "Source/**.h",
        ["Source Files/*"] = "Source/**.c",
        ["Resource Files"] = "Source/pdcurses.rc"
    }

    filter { "configurations:Debug" }
        buildoptions "/MTd"
        runtime "Debug"
        symbols "on"
    
    filter { "configurations:Release" }
        buildoptions "/MT"
        runtime "Release"
        optimize "on"
        symbols "on"
    
    filter { "configurations:Dist" }
        buildoptions "/MT"
        runtime "Release"
        optimize "on"
        symbols "off"