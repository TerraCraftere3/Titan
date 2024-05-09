#include "tipch.h"
#include "Platform/OpenGL/OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Titan {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		TI_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		TI_PROFILE_FUNCTION();

		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		TI_CORE_ASSERT(status, "Failed to initialize Glad!");

		TI_CORE_INFO("OpenGL Info:");
		TI_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		TI_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		TI_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));

		TI_CORE_ASSERT(GLVersion.major > 4 || (GLVersion.major == 4 && GLVersion.minor >= 5), "Titan requires at least OpenGL version 4.5!");
	}

	void OpenGLContext::SwapBuffers()
	{
		TI_PROFILE_FUNCTION();

		glfwSwapBuffers(m_WindowHandle);
	}

}
