#include "tipch.h"
#include "Titan/Renderer/GraphicsContext.h"

#include "Titan/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLContext.h"

namespace Titan {

	Scope<GraphicsContext> GraphicsContext::Create(void* window)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    TI_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
		}

		TI_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}