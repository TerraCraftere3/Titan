#include "tipch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <GL/GL.h>

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
		TI_CORE_INFO("  Vendor: {0}", (const char*)glGetString(GL_VENDOR));
		TI_CORE_INFO("  Renderer: {0}", (const char*)glGetString(GL_RENDERER));
		TI_CORE_INFO("  Version: {0}", (const char*)glGetString(GL_VERSION));

		#ifdef TI_ENABLE_ASSERTS
			int versionMajor;
			int versionMinor;

			int minMajor = 4;
			int minMinor = 5;

			glGetIntegerv(GL_MAJOR_VERSION, &versionMajor);
			glGetIntegerv(GL_MINOR_VERSION, &versionMinor);

			TI_CORE_ASSERT(versionMajor > minMajor || (versionMajor == minMajor && versionMinor >= minMinor), "Titan requires at least OpenGL version 4.5!");
		#endif
	}

	void OpenGLContext::SwapBuffers()
	{
		TI_PROFILE_FUNCTION();
		glfwSwapBuffers(m_WindowHandle);
	}

}