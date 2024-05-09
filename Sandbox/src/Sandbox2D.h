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
	
	// Temp
	Titan::Ref<Titan::VertexArray> m_SquareVA;
	Titan::Ref<Titan::Shader> m_FlatColorShader;

	Titan::Ref<Titan::Texture2D> m_CheckerboardTexture;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
};