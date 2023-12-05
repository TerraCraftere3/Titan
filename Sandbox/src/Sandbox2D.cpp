#include "Sandbox2D.h"
#include <glm/gtc/type_ptr.hpp>
#include <imgui.h>
#include <Platform/OpenGL/OpenGLShader.h>

#include <chrono>

#include "Titan/Debug/Instrumentor.h"

Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f, true)
{
}

void Sandbox2D::OnAttach()
{
	m_Texture = Titan::Texture2D::Create("assets/textures/Engine/masks/circle.png");
}

void Sandbox2D::OnDetach()
{
}

void Sandbox2D::OnUpdate(Titan::Timestep ts)
{
	TI_PROFILE_FUNCTION();


	m_CameraController.OnUpdate(ts);

	Titan::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
	Titan::RenderCommand::Clear();

	{
		TI_PROFILE_SCOPE("Renderer Draw");

		Titan::Renderer2D::BeginScene(m_CameraController.GetCamera());
		
		Titan::Renderer2D::DrawQuad({  .0f, .0f,   .0f }, { 1.25f, 1.25f }, m_Texture, 5.0f);
		Titan::Renderer2D::DrawRotatedQuad(glm::vec3(1.5f, 0.5f, -0.1f ), glm::vec2(1.0f, 1.0f ), glm::radians(m_SquareRot), m_SquareColor);
		
		Titan::Renderer2D::EndScene();
	}

	/*std::dynamic_pointer_cast<Titan::OpenGLShader>(m_FlatColorShader)->Bind();
	std::dynamic_pointer_cast<Titan::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat4("u_Color", m_SquareColor);*/
	
}

void Sandbox2D::OnImGuiRender()
{
	TI_PROFILE_FUNCTION();

	//Square
	ImGui::Begin("Square");
	ImGui::ColorEdit4("Color", glm::value_ptr(m_SquareColor));
	ImGui::DragFloat("Rotation", &m_SquareRot, 1.0f, 0, 360);
	ImGui::End();
}

void Sandbox2D::OnEvent(Titan::Event& e)
{
	m_CameraController.OnEvent(e);
}
