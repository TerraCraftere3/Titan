workspace "TitanEngine"
	architecture 'x64'
	configurations { 
		"Debug", 
		"Release", 
		"Dist" 
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Engine"
	location "TitanEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "tipch.h"
	pchsource "Engine/src/tipch.cpp"
	
	files
	{
		"%{prj.location}/src/**.h",
		"%{prj.location}/src/**.cpp",
		"%{prj.location}/src/**.hpp",
		"%{prj.location}/src/**.c"
	}

	includedirs
	{
		"%{prj.location}/vendor/spdlog/include",
		"%{prj.location}/src"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"TI_BUILD_DLL",
			"TI_PLATFORM_WINDOWS"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "TI_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "TI_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "TI_DIST"
		optimize "On"

	filter { "system:windows", "configurations:Release" }
		buildoptions "/MT"
	
project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.location}/src/**.h",
		"%{prj.location}/src/**.cpp",
		"%{prj.location}/src/**.hpp",
		"%{prj.location}/src/**.c"
	}

	includedirs
	{
		"TitanEngine/vendor/spdlog/include",
		"TitanEngine/src"
	}

	links
	{
		"Engine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"TI_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "TI_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "TI_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "TI_DIST"
		optimize "On"

	filter { "system:windows", "configurations:Release" }
		buildoptions "/MT"