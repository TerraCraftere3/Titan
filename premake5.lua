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
IncludeDir["ImGuizmo"] = "TitanEngine/vendor/ImGuizmo"

function includes()
	includedirs
	{
		"%{prj.location}/src",
		"TitanEngine/src",
		"TitanEngine/vendor/spdlog/include",
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
		"Engine",
		"yaml-cpp"
	}
end

group "Dependencies"

include "TitanEngine/vendor/GLFW/"
include "TitanEngine/vendor/Glad/"
include "TitanEngine/vendor/imgui/"
include "TitanEngine/vendor/yaml-cpp/"

group "Titan"

include "TitanEngine/"
include "Neon/"
include "Sandbox/"