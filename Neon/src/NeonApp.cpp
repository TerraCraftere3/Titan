#include "tipch.h"
#include <Titan.h>

// -------------- Entry Point ----------------
#include "Titan/Core/EntryPoint.h"
// -------------------------------------------

#include "imgui.h"
#include <glm/ext/matrix_transform.hpp>
#include <Platform/OpenGL/OpenGLShader.h>
#include <glm/gtc/type_ptr.hpp>

#include "EditorLayer.h"

namespace Titan {

	class NeonEditor : public Application
	{
	public:
		NeonEditor()
			: Application("Titan Engine | Neon")
		{
			PushLayer(new EditorLayer());
		}

		~NeonEditor()
		{
		}
	};

	Application* Titan::CreateApplication() {
		return new NeonEditor();
	}

}