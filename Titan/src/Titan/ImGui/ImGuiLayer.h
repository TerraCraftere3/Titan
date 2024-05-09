#pragma once

#include "Titan/Core/Layer.h"

#include "Titan/Events/ApplicationEvent.h"
#include "Titan/Events/KeyEvent.h"
#include "Titan/Events/MouseEvent.h"

namespace Titan {

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnEvent(Event& e) override;

		void Begin();
		void End();

		void BlockEvents(bool block) { m_BlockEvents = block; }
		
		void SetDarkThemeColors();
	private:
		bool m_BlockEvents = true;
		float m_Time = 0.0f;
	};

}
