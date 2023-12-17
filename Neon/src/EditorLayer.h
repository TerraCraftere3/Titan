#pragma once

#include "Titan.h"

namespace Titan {

	class EditorLayer : public Layer
	{
	public:
		EditorLayer();
		virtual ~EditorLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		void OnUpdate(Titan::Timestep ts) override;
		virtual void OnImGuiRender() override;
		void OnEvent(Titan::Event& e) override;
	private:
		Titan::OrthographicCameraController m_CameraController;

		Titan::Ref<Texture2D> m_CheckerboardTexture;
		Titan::Ref<Texture2D> m_SpriteSheet;
		Titan::Ref<SubTexture2D> m_HeartTexture;
		Titan::Ref<Framebuffer> m_Framebuffer;

		bool m_ViewportFocused = false, m_ViewportHovered = false;
		glm::vec2 m_ViewportSize = { 0, 0 };

		glm::vec4 m_SpriteSheetColor = { 1.0, 0.3, 0.3, 1.0 };
		float m_SquareRot = 30.0f;
	};

}