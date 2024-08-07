project "llib"
    kind "StaticLib"
    language "C"
    cdialect "C99"

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
        ["Source Files/*"] = "Source/**.c"
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