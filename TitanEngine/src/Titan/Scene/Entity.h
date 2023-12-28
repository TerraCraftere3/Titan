#pragma once

#include "Scene.h"

#include "entt.hpp";

namespace Titan {

	class Entity
	{
	public:
		Entity() = default;
		Entity(entt::entity handle, Scene* scene);
		Entity(const Entity& other) = default;

		template<typename T, typename... Args>
		T& AddComponent(Args&&... args) 
		{ 
			TI_CORE_ASSERT(!HasComponent<T>(), "Entity already has component!");
			
			return m_Scene->m_Registry.emplace<T>(m_EntityHandle, std::forward<Args>(args)...); 
		}

		template<typename T>
		T& GetComponent()
		{
			TI_CORE_ASSERT(HasComponent<T>(), "Entity does not have component!");

			return m_Scene->m_Registry.get<T>(m_EntityHandle);
		}

		template<typename T>
		bool HasComponent()
		{
			return m_Scene->m_Registry.all_of<T>(m_EntityHandle);
		}

		template<typename T>
		void RemoveComponent()
		{
			TI_CORE_ASSERT(HasComponent<T>(), "Entity does not have component!");

			return m_Scene->m_Registry.remove<T>(m_EntityHandle);
		}

		operator bool() const { return m_EntityHandle != entt::null; };
	private:
		entt::entity m_EntityHandle{ entt::null }; // 4 Bytes
		Scene* m_Scene = nullptr; // 12 Bytes
	};
}