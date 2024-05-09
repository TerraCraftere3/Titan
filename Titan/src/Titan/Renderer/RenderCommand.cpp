#include "tipch.h"
#include "Titan/Renderer/RenderCommand.h"

namespace Titan {

	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();

}