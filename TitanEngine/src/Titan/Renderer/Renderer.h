#pragma once

#include "RenderCommand.h"

namespace Titan {

	class Renderer
	{
	public:
		static void BeginScene(); //TODO: Scene Parameters
		static void EndScene();

		static void Submit(const std::shared_ptr<VertexArray>& vertexArray);

		inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }
	};


}