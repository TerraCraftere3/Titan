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

			Titan::Renderer2D::DrawQuad({   .0f, .0f, 0.0f }, { 50.0f, 50.0f }, m_CheckerboardTexture, 25.0f);
			Titan::Renderer2D::DrawQuad({   .0f, .0f, 0.1f }, { 3.0f, 1.0f }, m_HeartTexture, 1.0f, m_SpriteSheetColor);

			Titan::Renderer2D::EndScene();
		}
	}
	
}

void Sandbox2D::OnImGuiRender()
{
    TI_PROFILE_FUNCTION();

	ImGui::Begin("Spritesheet");
	ImGui::ColorEdit4("Spritesheet Color", glm::value_ptr(m_SpriteSheetColor));
	ImGui::Text("Texture");
	uint32_t textureID = m_SpriteSheet.get()->GetRendererID();
	ImGui::Image((void*)textureID, ImVec2{ 16 * 17, 16 * 8 });
	ImGui::End();
}

void Sandbox2D::OnEvent(Titan::Event& e)
{
	m_CameraController.OnEvent(e);
}
