include "./vendor/premake/premake_customization/solution_items.lua"

workspace "Titan"
	architecture "x86_64"
	startproject "Neon"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	solution_items
	{
		".editorconfig"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/Titan/vendor/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/Titan/vendor/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/Titan/vendor/imgui"
IncludeDir["glm"] = "%{wks.location}/Titan/vendor/glm"
IncludeDir["stb_image"] = "%{wks.location}/Titan/vendor/stb_image"
IncludeDir["entt"] = "%{wks.location}/Titan/vendor/entt/include"
IncludeDir["yaml_cpp"] = "%{wks.location}/Titan/vendor/yaml-cpp/include"
IncludeDir["ImGuizmo"] = "%{wks.location}/Titan/vendor/ImGuizmo"

group "Dependencies"
	include "vendor/premake"
	include "Titan/vendor/GLFW"
	include "Titan/vendor/Glad"
	include "Titan/vendor/imgui"
	include "Titan/vendor/yaml-cpp"
group ""

include "Titan"
include "Sandbox"
include "Neon"
