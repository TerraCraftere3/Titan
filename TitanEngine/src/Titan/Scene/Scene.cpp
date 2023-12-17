#include "tipch.h"
#include "Scene.h"

#include "Components.h"

#include <glm/glm.hpp>

#include <Titan/Renderer/Renderer2D.h>

#include "Entity.h"

namespace Titan {

	Scene::Scene()
	{
		TI_PROFILE_FUNCTION();
	}

	Scene::~Scene()
	{
		TI_PROFILE_FUNCTION();
	}

	Entity Scene::CreateEntity(const std::string& name)
	{
		TI_PROFILE_FUNCTION();

		Entity entity = { m_Registry.create() , this };
		entity.AddComponent<TransformComponent>();
		auto& tag = entity.AddComponent<TagComponent>();
		tag.Tag = name.empty() ? "Unnamed Entity" : name;
		return entity;
	}

	void Scene::OnUpdate(Timestep ts)
	{
		auto group = m_Registry.group<TransformComponent>(entt::get<SpriteRendererComponent>);
		for (auto entity : group) {
			auto& [transform, sprite] = group.get<TransformComponent, SpriteRendererComponent>(entity);
			
			Renderer2D::DrawQuad(transform, sprite);
		}
	}

}