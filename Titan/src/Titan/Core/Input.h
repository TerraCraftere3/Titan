#pragma once

#include <glm/glm.hpp>

#include "Titan/Core/KeyCodes.h"
#include "Titan/Core/MouseCodes.h"

namespace Titan {

	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static glm::vec2 GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}
