#pragma once

#include "Titan.h"

class Sandbox2D : public Titan::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Titan::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Titan::Event& e) override;
private:
	Titan::OrthographicCameraController m_CameraController;

	Titan::Ref<Titan::Texture2D> m_CheckerboardTexture;
	Titan::Ref<Titan::Texture2D> m_SpriteSheet;
	Titan::Ref<Titan::SubTexture2D> m_HeartEmptyTexture, m_HeartHalfTexture, m_HeartFullTexture;
	Titan::Ref<Titan::SubTexture2D> m_HeartTexture;	

	glm::vec4 m_SpriteSheetColor = { 1.0, 0.3, 0.3, 1.0 };
	float m_SquareRot = 30.0f;
};