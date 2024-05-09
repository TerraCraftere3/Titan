#pragma once

#include "Titan.h"

class ExampleLayer : public Titan::Layer
{
public:
	ExampleLayer();
	virtual ~ExampleLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Titan::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Titan::Event& e) override;
private:
	Titan::ShaderLibrary m_ShaderLibrary;
	Titan::Ref<Titan::Shader> m_Shader;
	Titan::Ref<Titan::VertexArray> m_VertexArray;

	Titan::Ref<Titan::Shader> m_FlatColorShader;
	Titan::Ref<Titan::VertexArray> m_SquareVA;

	Titan::Ref<Titan::Texture2D> m_Texture, m_ChernoLogoTexture;

	Titan::OrthographicCameraController m_CameraController;
	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};

