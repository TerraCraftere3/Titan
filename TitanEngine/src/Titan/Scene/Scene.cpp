#include "tipch.h"
#include "Scene.h"

#include <glm/glm.hpp>

namespace Titan {

	Scene::Scene()
	{
		TI_PROFILE_FUNCTION();

		struct MeshComponent //Example: MeshComponent
		{
		
		};
		struct TransformComponent //Example: TransformComponent
		{
			glm::mat4 Transform;

			TransformComponent() = default;
			TransformComponent(const TransformComponent&) = default;
			TransformComponent(const glm::mat4& transform)
				:Transform(transform) {}

			operator glm::mat4& () { return Transform; };
			operator const glm::mat4& () const { return Transform; };
		};

		entt::entity entity = m_Registry.create(); //Creates Entity
		m_Registry.emplace<TransformComponent>(entity, glm::mat4(1.0)); //Adds TransformComponent to entity

		TransformComponent& transform = m_Registry.get<TransformComponent>(entity); //Get TransformComponent from specific entity

		auto view = m_Registry.view<TransformComponent>(); //List of entitys with TransformComponent
	}

	Scene::~Scene()
	{
		TI_PROFILE_FUNCTION();
	}

}