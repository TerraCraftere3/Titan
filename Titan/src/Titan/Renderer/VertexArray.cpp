#include "tipch.h"
#include "Titan/Renderer/VertexArray.h"

#include "Titan/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Titan {

	Ref<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    TI_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateRef<OpenGLVertexArray>();
		}

		TI_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}