#include <Titan.h>

#include "imgui.h"

class ExampleLayer : public Titan::Layer
{
public:
	ExampleLayer()
		: Layer("Example"), m_Camera(-1.6f, 1.6f, -0.9f, 0.9f), m_CameraPos(0, 0, 0)
	{
		m_VertexArray.reset(Titan::VertexArray::Create());

		float vertices[4 * 7] = {
			 0.5f, 0.5f, 0.0f, 1, 0, 0, 1,
			 0.5f, -0.5f, 0.0f, 1, 1, 0, 1,
		   -0.5f,  -0.5f, 0.0f, 0, 1, 0, 1,
		   -0.5f,  0.5f, 0.0f, 0, 0, 0, 1,

		};

		m_VertexBuffer.reset(Titan::VertexBuffer::Create(vertices, sizeof(vertices)));

		{
			Titan::BufferLayout layout = {
						{ Titan::ShaderDataType::Float3, "a_Position" },
						{ Titan::ShaderDataType::Float4, "a_Color"}
			};

			m_VertexBuffer->SetLayout(layout);
		}

		uint32_t indices[6] = { 0, 1, 2, 0, 2, 3 };
		m_IndexBuffer.reset(Titan::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));

		m_VertexArray->AddVertexBuffer(m_VertexBuffer);
		m_VertexArray->SetIndexBuffer(m_IndexBuffer);

		std::string vertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;

			uniform mat4 u_ViewProjection;

			out vec3 v_Position;
			out vec4 v_Color;

			void main()
			{
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = u_ViewProjection * vec4(a_Position, 1.0);	
			}
		)";

		std::string fragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;

			in vec3 v_Position;
			in vec4 v_Color;

			void main()
			{
				color = vec4(v_Position * 1 + 0.5, 1.0);
				color = v_Color;
			}
		)";

		m_Shader.reset(new Titan::Shader(vertexSrc, fragmentSrc));
	}

	void OnUpdate() override
	{
		if (Titan::Input::IsKeyPressed(TI_KEY_A))
			m_CameraPos.x -= m_CameraSpeed;
		if (Titan::Input::IsKeyPressed(TI_KEY_D))
			m_CameraPos.x += m_CameraSpeed;
		if (Titan::Input::IsKeyPressed(TI_KEY_S))
			m_CameraPos.y -= m_CameraSpeed;
		if (Titan::Input::IsKeyPressed(TI_KEY_W))
			m_CameraPos.y += m_CameraSpeed;

		if (Titan::Input::IsKeyPressed(TI_KEY_Q))
			m_Camera.SetRotation(m_Camera.GetRotation() + 2.0f);
		if (Titan::Input::IsKeyPressed(TI_KEY_E))
			m_Camera.SetRotation(m_Camera.GetRotation() - 2.0f);

		Titan::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
		Titan::RenderCommand::Clear();

		m_Camera.SetPosition(m_CameraPos);

		Titan::Renderer::BeginScene(m_Camera);

		Titan::Renderer::Submit(m_Shader, m_VertexArray);

		Titan::Renderer::EndScene();
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Example");
		ImGui::Text("This window and the mesh is being created in SandboxApp.cpp");
		ImGui::End();
	}

	void OnEvent(Titan::Event& event) override
	{
		
	}

private:
	std::shared_ptr<Titan::Shader> m_Shader;
	std::shared_ptr<Titan::VertexBuffer> m_VertexBuffer;
	std::shared_ptr<Titan::IndexBuffer> m_IndexBuffer;
	std::shared_ptr<Titan::VertexArray> m_VertexArray;

	Titan::OrthographicCamera m_Camera;
	glm::vec3 m_CameraPos;
	float m_CameraSpeed = 0.025f;

};

class Sandbox : public Titan::Application
{
public:
	Sandbox()
	{
		TITAN_TRACE("This is 'TITAN_TRACE()'");
		TITAN_INFO("This is 'TITAN_INFO()'");
		TITAN_WARN("This is 'TITAN_WARN()'");
		TITAN_ERROR("This is 'TITAN_ERROR()'");
		TITAN_FATAL("This is 'TITAN_FATAL()'");
		PushLayer(new ExampleLayer());
	}

	~Sandbox() 
	{
	}
};

Titan::Application* Titan::CreateApplication() {
	return new Sandbox();
}