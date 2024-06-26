project "Neon"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/Titan/vendor/spdlog/include",
		"%{wks.location}/Titan/src",
		"%{wks.location}/Titan/vendor",
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}",
		"%{IncludeDir.ImGuizmo}"
	}

	links
	{
		"Titan"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "TI_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "TI_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "TI_DIST"
		runtime "Release"
		optimize "on"
