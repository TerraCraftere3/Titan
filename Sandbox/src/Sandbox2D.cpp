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
	m_CircleTexture = Titan::Texture2D::Create("assets/textures/Engine/masks/circle.png");
	m_CheckerboardTexture = Titan::Texture2D::Create("assets/textures/Engine/transparent.png");
}

void Sandbox2D::OnDetach()
{
}

void Sandbox2D::OnUpdate(Titan::Timestep ts)
{
	TI_PROFILE_FUNCTION();


	m_CameraController.OnUpdate(ts);

	Titan::Renderer2D::ResetStats();
	{
		TI_PROFILE_SCOPE("Renderer Prep");
		Titan::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
		Titan::RenderCommand::Clear();
	}

	{
		TI_PROFILE_SCOPE("Renderer Draw");

		{
			TI_PROFILE_SCOPE("Scene 1");
			Titan::Renderer2D::BeginScene(m_CameraController.GetCamera());

			Titan::Renderer2D::DrawQuad({ .0f, .0f, 1.0f }, { 2.0f, 2.0f }, m_CircleTexture, 5.0f, m_CircleColor);
			Titan::Renderer2D::DrawRotatedQuad(glm::vec3(1.5f, 0.5f, 1.0f), glm::vec2(0.75f, 1.0f), m_SquareRot, m_SquareColor);
			Titan::Renderer2D::DrawQuad({ .0, .0, 0 }, { 50, 50 }, m_CheckerboardTexture, 10.0f);

			Titan::Renderer2D::EndScene();
		}
		
		{
			TI_PROFILE_SCOPE("Scene 2");
			Titan::Renderer2D::BeginScene(m_CameraController.GetCamera());
			for (float y = -5.0f; y < 5.0f; y += 0.5f) {
				for (float x = -5.0f; x < 5.0f; x += 0.5f) {
					glm::vec4 color = { (x + 5.0f) / 10, 0.4f, (y + 5.0f) / 10, 0.7f };
					Titan::Renderer2D::DrawQuad({ x,y,0.1 }, { 0.45f, 0.45f }, color);
				}
			}
			Titan::Renderer2D::EndScene();
		}
		
	}
	
}

void Sandbox2D::OnImGuiRender()
{
	TI_PROFILE_FUNCTION();

	//Square
	ImGui::Begin("Settings");
	ImGui::Text("Square");
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::DragFloat("Square Rotation", &m_SquareRot, 1.0f, 0, 360);
	ImGui::Text("Circle");
	ImGui::ColorEdit4("Circle Color", glm::value_ptr(m_CircleColor));
	ImGui::End();

	ImGui::Begin("Stats");
	auto stats = Titan::Renderer2D::GetStats();
	ImGui::Text("Renderer2D Stats:");
	ImGui::Text("Draw Calls: %d", stats.DrawCalls);
	ImGui::Text("Quads: %d", stats.QuadCount);
	ImGui::Text("Triangles: %d", stats.GetTotalTriangleCount());
	ImGui::Text("Vertices: %d", stats.GetTotalVertexCount());
	ImGui::Text("Indices: %d", stats.GetTotalIndexCount());
	ImGui::End();
}

void Sandbox2D::OnEvent(Titan::Event& e)
{
	m_CameraController.OnEvent(e);
}
