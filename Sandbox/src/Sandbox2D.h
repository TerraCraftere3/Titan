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

	Titan::Ref<Titan::Texture2D> m_CircleTexture;
	Titan::Ref<Titan::Texture2D> m_CheckerboardTexture;

	glm::vec4 m_SquareColor = { 0.3, 0.8, 0.2, 1.0 };
	glm::vec4 m_CircleColor = { 0.8, 0.2, 0.4, 1.0 };
	float m_SquareRot = 30.0f;
};