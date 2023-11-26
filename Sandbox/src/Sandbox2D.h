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

	//TODO: Remove Sandbox2D Example Code:
	Titan::Ref<Titan::VertexBuffer> m_VertexBuffer;
	Titan::Ref<Titan::IndexBuffer> m_IndexBuffer;
	Titan::Ref<Titan::VertexArray> m_VertexArray;

	Titan::Ref<Titan::Shader> m_FlatColorShader;
	Titan::OrthographicCameraController m_CameraController;

	glm::vec4 m_SquareColor = { 0.3, 0.8, 0.2, 1.0 };
};