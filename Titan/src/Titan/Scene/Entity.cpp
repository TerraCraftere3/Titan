#include "tipch.h"
#include "Entity.h"

namespace Titan {

	Entity::Entity(entt::entity handle, Scene* scene)
		: m_EntityHandle(handle), m_Scene(scene)
	{
	}

}