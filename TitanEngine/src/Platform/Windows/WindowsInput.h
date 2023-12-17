#include "tipch.h"

#include "Titan/Core/Input.h"

#include "Titan/Core/Application.h"

#include <GLFW/glfw3.h>

namespace Titan {

	bool Input::IsKeyPressed(int keycode)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());

		auto state = glfwGetKey(window, keycode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	inline bool Input::IsKeyPressed(KeyCode keycode)
	{
		return IsKeyPressed((int)keycode);
	}

	bool Input::IsMousePressed(int button)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());

		auto state = glfwGetMouseButton(window, button);
		return state == GLFW_PRESS;
	}

	inline bool Input::IsMousePressed(MouseCode button)
	{
		return IsMousePressed((int)button);
	}

	std::pair<float, float> Input::GetMousePosition()
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());

		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);
		return {xpos, ypos};
	}

	float Input::GetMouseX()
	{
		auto [x, y] = GetMousePosition();
		return x;
	}

	float Input::GetMouseY()
	{
		auto [x, y] = GetMousePosition();
		return y;
	}

}