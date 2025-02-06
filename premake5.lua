workspace "Abyllos"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


IncludeDir = {}
IncludeDir["Glad"] = "ElderEngine/vendor/Glad/include"

include "ElderEngine/vendor/Glad"


project "ElderEngine"
	location "ElderEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	buildoptions { "/utf-8" }

	pchheader "eldpch.h"
	pchsource "ElderEngine/src/eldpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/src",
		"%{prj.name}/vendor/glfw/include",
		"%{IncludeDir.Glad}"
	}


	
	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"
		staticruntime "Off"

		defines
		{
			"ELD_PLATFORM_WINDOWS",
			"ELD_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Abyllos")
		}

		

	filter "configurations:Debug"
		defines "ELD_DEBUG"
		symbols "On"
		libdirs { "%{prj.name}/vendor/glfw/lib/Debug" }
		links 
		{ 
			"glfw3",
			"opengl32.lib",
			"dwmapi.lib",
			"Glad"
		}


	filter "configurations:Release"
		defines "ELD_RELEASE"
		optimize "On"
		libdirs { "%{prj.name}/vendor/glfw/lib/Release" }
		links 
		{ 
			"glfw3",
			"opengl32.lib",
			"dwmapi.lib",
			"Glad"
		}

	filter "configurations:Dist"
		defines "ELD_DIST"
		optimize "On"
		libdirs { "%{prj.name}/vendor/glfw/lib/Release" }
		links 
		{ 
			"glfw3",
			"opengl32.lib",
			"dwmapi.lib",
			"Glad"
		}




project "Abyllos"
	location "Abyllos"
	kind "ConsoleApp"
	language "C++"

	buildoptions { "/utf-8" }

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"ElderEngine/vendor/spdlog/include",
		"ElderEngine/src"
	}

	links
	{
		"ElderEngine"
	}


	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"
		staticruntime "Off"

		defines
		{
			"ELD_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "ELD_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ELD_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ELD_DIST"
		optimize "On"
