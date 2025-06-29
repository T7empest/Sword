workspace "Sword"
	architecture "x64"
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

filter "action:vs*"
    buildoptions { "/utf-8" }

project "Sword"
	location "Sword"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++latest"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"SW_PLATFORM_WINDOWS",
			"SW_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/DevGame")
		}

	filter "configurations:Debug"
		defines "SW_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SW_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "SW_DIST"
		optimize "On"


project "DevGame"
	location "DevGame"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Sword/vendor/spdlog/include",
		"Sword/src"
	}

	links
	{
		"Sword"
	}

	filter "system:windows"
		cppdialect "C++latest"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"SW_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "SW_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SW_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "SW_DIST"
		optimize "On"