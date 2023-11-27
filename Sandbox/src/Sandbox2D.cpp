#include "Sandbox2D.h"
#include <glm/gtc/type_ptr.hpp>
#include <imgui.h>
#include <Platform/OpenGL/OpenGLShader.h>

#include <chrono>

template<typename Fn>
class Timer
{
public:
	Timer(const char* name, Fn func)
		: m_Name(name), m_Stopped(false), m_Func(func)
	{
		m_StartTimepoint = std::chrono::high_resolution_clock::now();
	}

	~Timer()
	{
		if (!m_Stopped)
			Stop();
	}

	void Stop()
	{
		auto endTimepoint = std::chrono::high_resolution_clock::now();
		
		long long start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch().count();
		long long end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();

		m_Stopped = true;

		float duration = (end - start) * 0.001f;

		//std::cout << m_Name << ": " << duration << "ms" << std::endl;
		m_Func({ m_Name, duration });
	}
	
private:
	const char* m_Name;
	std::chrono::time_point<std::chrono::steady_clock> m_StartTimepoint;
	bool m_Stopped;
	Fn m_Func;
};

#define PROFILE_SCOPE(name) Timer timer##__LINE__(name, [&](ProfileResult profileResult) {m_ProfileResults.push_back(profileResult); })

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
	PROFILE_SCOPE("Sandbox2D::OnUpdate");

	{
		PROFILE_SCOPE("CameraController::OnUpdate");
		m_CameraController.OnUpdate(ts);
	}

	{
		PROFILE_SCOPE("Renderer::Clear");
		Titan::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
		Titan::RenderCommand::Clear();
	}

	{
		PROFILE_SCOPE("Renderer::Scene");
		Titan::Renderer2D::BeginScene(m_CameraController.GetCamera());
		
		Titan::Renderer2D::DrawQuad({  .0f, .0f,   .0f }, { 1.0f, 1.0f }, m_Texture);
		Titan::Renderer2D::DrawQuad({ 0.0f, .0f, -0.1f }, { 2.0f, 2.0f }, m_SquareColor);
		
		Titan::Renderer2D::EndScene();
	}

	/*std::dynamic_pointer_cast<Titan::OpenGLShader>(m_FlatColorShader)->Bind();
	std::dynamic_pointer_cast<Titan::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat4("u_Color", m_SquareColor);*/
	
}

void Sandbox2D::OnImGuiRender()
{
	//Square
	ImGui::Begin("Square");
	ImGui::ColorEdit4("Color", glm::value_ptr(m_SquareColor));
	ImGui::End();

	ImGui::Begin("Profiler");
	for(ProfileResult& result : m_ProfileResults)
	{
		char label[50];
		strcpy(label, "%.3fms  ");
		strcat(label, result.Name);
		ImGui::Text(label, result.Time);
	}

	m_ProfileResults.clear();
	ImGui::End();
}

void Sandbox2D::OnEvent(Titan::Event& e)
{
	m_CameraController.OnEvent(e);
}
