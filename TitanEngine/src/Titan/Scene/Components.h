#pragma once

#include <glm/glm.hpp>

#include "SceneCamera.h"

#include "ScriptableEntity.h"

namespace Titan {
	//component name should be: [NAME]Component

	struct TagComponent
	{
		std::string Tag;

		TagComponent() = default;
		TagComponent(const TagComponent&) = default;
		TagComponent(const std::string tag)
			:Tag(tag) {}

		operator std::string& () { return Tag; };
		operator const std::string& () const { return Tag; };
	};

	struct TransformComponent
	{
		glm::mat4 Transform = glm::mat4(1.0);

		TransformComponent() = default;
		TransformComponent(const TransformComponent&) = default;
		TransformComponent(const glm::mat4& transform)
			:Transform(transform) {}

		operator glm::mat4& () { return Transform; };
		operator const glm::mat4& () const { return Transform; };
	};

	struct SpriteRendererComponent
	{
		glm::vec4 Color = glm::vec4(1.0f, 0.0f, 1.0f, 1.0f);

		SpriteRendererComponent() = default;
		SpriteRendererComponent(const SpriteRendererComponent&) = default;
		SpriteRendererComponent(const glm::vec4& color)
			:Color(color) {}

		operator glm::vec4& () { return Color; };
		operator const glm::vec4& () const { return Color; };
	};

	struct CameraComponent
	{
		SceneCamera Camera;
		bool Primary = true; //TODO: think about moving to scene
		bool FixedAspectRation = false; //if true it doesnt resize on window resize.

		CameraComponent() = default;
		CameraComponent(const CameraComponent&) = default;
	};

	struct NativeScriptComponent
	{
		ScriptableEntity* Instance = nullptr;

		ScriptableEntity* (*InstantiateScript)();
		void (*DestroyScript)(NativeScriptComponent*);

		template<typename T>
		void Bind()
		{
			InstantiateScript = []() { return static_cast<ScriptableEntity*>(new T()); };
			DestroyScript = [](NativeScriptComponent* nsc) { delete nsc->Instance; nsc->Instance = nullptr; };
		}
	};
}