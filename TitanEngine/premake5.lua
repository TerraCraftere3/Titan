project "Engine"
	location "."
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("../bin/" .. outputdir .. "/%{prj.name}")
	objdir ("../bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "tipch.h"
	pchsource "./src/tipch.cpp"

	files
	{
		"%{prj.location}/src/**.h",
		"%{prj.location}/src/**.cpp",
		"%{prj.location}/src/**.hpp",
		"%{prj.location}/src/**.c",
		"../%{IncludeDir.stb_image}/**.cpp",
		"../%{IncludeDir.stb_image}/**.h"
	}

	includedirs
	{
		"../%{prj.location}/src",
		"../%{prj.location}/vendor/spdlog/include",
		"../%{IncludeDir.GLFW}",
		"../%{IncludeDir.Glad}",
		"../%{IncludeDir.ImGui}",
		"../%{IncludeDir.glm}",
		"../%{IncludeDir.stb_image}",
		"../%{IncludeDir.entt}",
		"../%{IncludeDir.yaml_cpp}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib",
		"yaml-cpp"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
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
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox"),
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Neon")
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

	includes()

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