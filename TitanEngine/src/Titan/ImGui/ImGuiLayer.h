#pragma once

#include "Titan/Core/Layer.h"

#include "Titan/Events/ApplicationEvent.h"
#include "Titan/Events/KeyEvent.h"
#include "Titan/Events/MouseEvent.h"

namespace Titan {

	class TI_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		virtual void OnEvent(Event& event) override;

		void Begin();
		void End();

		void SetBlockEvents(bool b) { m_BlockEvents = b; };
		bool GetBlockEvents() { return m_BlockEvents; };
	private:
		bool m_BlockEvents = true;
		float m_Time = 0.0f;
	};

}