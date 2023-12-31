project "Neon"
	location "."
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("../bin/" .. outputdir .. "/%{prj.name}")
	objdir ("../bin-int/" .. outputdir .. "/%{prj.name}")

	debugdir ("../runtime")

	files
	{
		"%{prj.location}/src/**.h",
		"%{prj.location}/src/**.cpp",
		"%{prj.location}/src/**.hpp",
		"%{prj.location}/src/**.c"
	}

	includedirs
	{
		"../TitanEngine/vendor/spdlog/include",
		"../TitanEngine/src",
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
		"Engine",
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib",
		"yaml-cpp"
	}

	defines
	{
		"YAML_CPP_STATIC_DEFINE"
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