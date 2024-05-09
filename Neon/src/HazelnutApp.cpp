#include <Titan.h>
#include <Titan/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Titan {

	class Titannut : public Application
	{
	public:
		Titannut()
			: Application("Titannut")
		{
			PushLayer(new EditorLayer());
		}

		~Titannut()
		{
		}
	};

	Application* CreateApplication()
	{
		return new Titannut();
	}

}