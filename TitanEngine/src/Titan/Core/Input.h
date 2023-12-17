#pragma once

#include "Titan/Core/Base.h"

namespace Titan {
	
	class TI_API Input
	{
	public:
		inline static bool IsKeyPressed(int keycode);
		inline static bool IsKeyPressed(KeyCode keycode);

		inline static bool IsMousePressed(int button);
		inline static bool IsMousePressed(MouseCode button);
		inline static std::pair<float, float> GetMousePosition();
		inline static float GetMouseX();
		inline static float GetMouseY();
	};

}