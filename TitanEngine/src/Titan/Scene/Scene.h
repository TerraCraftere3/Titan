#pragma once

#include "entt.hpp"

namespace Titan {

	class Scene
	{
	public:
		Scene();
		~Scene();
	private:
		entt::registry m_Registry;
	};

}