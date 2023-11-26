#include "Sandbox2D.h"
#include <imgui.h>
#include <glm/gtc/type_ptr.hpp>
#include <Platform/OpenGL/OpenGLShader.h>

Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f, true)
{
}

void Sandbox2D::OnAttach()
{
	m_VertexArray = Titan::VertexArray::Create();

	float vertices[4 * 7] = {
		 0.5f,  0.5f,  0.0f, 1, 0, 0, 1,
		 0.5f, -0.5f,  0.0f, 0, 1, 0, 1,
		-0.5f, -0.5f,  0.0f, 0, 0, 1, 1,
		-0.5f,  0.5f,  0.0f, 1, 0, 1, 1
	};

	m_VertexBuffer = Titan::VertexBuffer::Create(vertices, sizeof(vertices));


	{
		Titan::BufferLayout layout = {
					{ Titan::ShaderDataType::Float3, "a_Position" },
					{ Titan::ShaderDataType::Float4, "a_Color"}
		};

		m_VertexBuffer->SetLayout(layout);
	}

	uint32_t indices[6] = { 0, 1, 2, 0, 2, 3 };
	m_IndexBuffer = Titan::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t));

	m_VertexArray->AddVertexBuffer(m_VertexBuffer);
	m_VertexArray->SetIndexBuffer(m_IndexBuffer);

	m_FlatColorShader = Titan::Shader::Create("assets/shaders/Color.glsl");
}

void Sandbox2D::OnDetach()
{
}

void Sandbox2D::OnUpdate(Titan::Timestep ts)
{
	m_CameraController.OnUpdate(ts);

	Titan::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
	Titan::RenderCommand::Clear();

	Titan::Renderer::BeginScene(m_CameraController.GetCamera());

	//TODO: Shader::SetMat4
	//TODO: Shader::SetFloat4
	glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));
	std::dynamic_pointer_cast<Titan::OpenGLShader>(m_FlatColorShader)->Bind();
	std::dynamic_pointer_cast<Titan::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat4("u_Color", m_SquareColor);

	Titan::Renderer::Submit(m_FlatColorShader, m_VertexArray, glm::mat4(1.0f));

	Titan::Renderer::EndScene();
}

void Sandbox2D::OnImGuiRender()
{
	//Square
	ImGui::Begin("Square");
	ImGui::ColorEdit4("Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}

void Sandbox2D::OnEvent(Titan::Event& e)
{
	m_CameraController.OnEvent(e);
}
