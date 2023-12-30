workspace "TitanEngine"
	architecture 'x64'
	startproject 'Neon-Editor'

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "TitanEngine/vendor/GLFW/include"
IncludeDir["Glad"] = "TitanEngine/vendor/Glad/include"
IncludeDir["ImGui"] = "TitanEngine/vendor/imgui"
IncludeDir["glm"] = "TitanEngine/vendor/glm"
IncludeDir["stb_image"] = "TitanEngine/vendor/stb_image"
IncludeDir["entt"] = "TitanEngine/vendor/entt/include"
IncludeDir["yaml_cpp"] = "TitanEngine/vendor/yaml-cpp/include"

function pch()
	pchheader "tipch.h"
	pchsource "TitanEngine/src/tipch.cpp"
end

group "Dependencies"

include "TitanEngine/vendor/GLFW"
include "TitanEngine/vendor/Glad"
include "TitanEngine/vendor/imgui"
include "TitanEngine/vendor/yaml-cpp"

group "Titan"

project "Engine"
	location "TitanEngine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pch()

	files
	{
		"%{prj.location}/src/**.h",
		"%{prj.location}/src/**.cpp",
		"%{prj.location}/src/**.hpp",
		"%{prj.location}/vendor/stb_image/**.cpp",
		"%{prj.location}/vendor/stb_image/**.h",
		"%{IncludeDir.glm}/glm/**.hpp",
		"%{IncludeDir.glm}/glm/**.inl",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.location}/src",
		"%{prj.location}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}",
		"%{IncludeDir.entt}",
		"%{IncludeDir.yaml_cpp}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib",
		"yaml-cpp"
	}


	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"TI_BUILD_DLL",
			"TI_PLATFORM_WINDOWS",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "TI_DEBUG"
		buildoptions "/MDd"
		symbols "on"

	filter "configurations:Release"
		defines "TI_RELEASE"
		buildoptions "/MD"
		symbols "on"

	filter "configurations:Dist"
		defines "TI_DIST"
		buildoptions "/MD"
		symbols "on"

	filter { "system:windows", "configurations:Release" }
		buildoptions "/MT"

project "Neon"
	location "Neon"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	debugdir ("runtime")

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
		"TitanEngine/src",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}",
		"%{IncludeDir.entt}",
		"%{IncludeDir.yaml_cpp}"
	}

	links
	{
		"Engine",
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
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
		buildoptions "/MDd"
		symbols "on"

	filter "configurations:Release"
		defines "TI_RELEASE"
		buildoptions "/MD"
		symbols "on"

	filter "configurations:Dist"
		defines "TI_DIST"
		buildoptions "/MD"
		symbols "on"

	filter { "system:windows", "configurations:Release" }
		buildoptions "/MT"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	debugdir ("runtime")

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
		"TitanEngine/src",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}",
		"%{IncludeDir.entt}",
		"%{IncludeDir.yaml_cpp}"
	}

	links
	{
		"Engine",
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
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
		buildoptions "/MDd"
		symbols "on"

	filter "configurations:Release"
		defines "TI_RELEASE"
		buildoptions "/MD"
		symbols "on"

	filter "configurations:Dist"
		defines "TI_DIST"
		buildoptions "/MD"
		symbols "on"

	filter { "system:windows", "configurations:Release" }
		buildoptions "/MT"