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
	m_SpriteSheet = Titan::Texture2D::Create("assets/game/textures/tilemap.png");
	m_CheckerboardTexture = Titan::Texture2D::Create("assets/engine/textures/transparent.png");

	m_HeartEmptyTexture = Titan::SubTexture2D::CreateFromCoords(m_SpriteSheet, { 8,0 }, { 16, 16 });
	m_HeartHalfTexture = Titan::SubTexture2D::CreateFromCoords(m_SpriteSheet, { 9,0 }, { 16, 16 });
	m_HeartFullTexture = Titan::SubTexture2D::CreateFromCoords(m_SpriteSheet, { 10,0 }, { 16, 16 });
	m_HeartTexture = Titan::SubTexture2D::CreateFromCoords(m_SpriteSheet, { 8,0 }, { 16, 16 }, {3, 1});

	//Particle Test
	m_Particle.ColorBegin = { 254 / 255.0f, 212 / 255.0f, 123 / 255.0f, 1.0f };
	m_Particle.ColorEnd = { 254 / 255.0f, 109 / 255.0f, 41 / 255.0f, 1.0f };
	m_Particle.SizeBegin = 0.5f, m_Particle.SizeVariation = 0.3f, m_Particle.SizeEnd = 0.0f;
	m_Particle.LifeTime = 1.0f;
	m_Particle.Velocity = { 0.0f, 0.0f };
	m_Particle.VelocityVariation = { 3.0f, 1.0f };
	m_Particle.Position = { 0.0f, 0.0f };

	m_CameraController.SetZoomLevel(5);
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
			TI_PROFILE_SCOPE("Spritesheet Scene");
			Titan::Renderer2D::BeginScene(m_CameraController.GetCamera());

			Titan::Renderer2D::DrawQuad({   .0f, .0f, 0.0f }, { 3.0f, 1.0f }, m_HeartTexture, 1.0f, m_SpriteSheetColor);

			Titan::Renderer2D::EndScene();
		}

#if 0
		{
		TI_PROFILE_SCOPE("Particles");
			if (Titan::Input::IsMousePressed(TI_MOUSE_BUTTON_LEFT))
			{
				auto [x, y] = Titan::Input::GetMousePosition();
				auto width = Titan::Application::Get().GetWindow().GetWidth();
				auto height = Titan::Application::Get().GetWindow().GetHeight();

				auto bounds = m_CameraController.GetBounds();
				auto pos = m_CameraController.GetCamera().GetPosition();
				x = (x / width) * bounds.GetWidth() - bounds.GetWidth() * 0.5f;
				y = bounds.GetHeight() * 0.5f - (y / height) * bounds.GetHeight();
				m_Particle.Position = { x + pos.x, y + pos.y };
				for (int i = 0; i < 5; i++)
					m_ParticleSystem.Emit(m_Particle);
			}

			m_ParticleSystem.OnUpdate(ts);
			m_ParticleSystem.OnRender(m_CameraController.GetCamera());
		}
#endif
		
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
	ImGui::Text("Spritesheet");
	ImGui::ColorEdit4("Spritesheet Color", glm::value_ptr(m_SpriteSheetColor));
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
