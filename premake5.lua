workspace "Abyllos"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "ElderEngine"
	location "ElderEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	buildoptions { "/utf-8" }

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"ELD_PLATFORM_WINDOWS",
			"ELD_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Abyllos")
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
		staticruntime "On"
		systemversion "latest"

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
