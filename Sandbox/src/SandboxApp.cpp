#include <Titan.h>

#include "imgui.h"
#include <glm/ext/matrix_transform.hpp>
#include <Platform/OpenGL/OpenGLShader.h>
#include <glm/gtc/type_ptr.hpp>

class ExampleLayer : public Titan::Layer
{
public:
	ExampleLayer()
		: Layer("Example"), m_Camera(-1.6f, 1.6f, -0.9f, 0.9f), m_CameraPos(0, 0, 0), m_SquarePosition(0.0f)
	{
		m_VertexArray.reset(Titan::VertexArray::Create());

		float vertices[4 * 7] = {
			 0.5f,  0.5f,  0.0f, 1, 0, 0, 1,
			 0.5f, -0.5f,  0.0f, 0, 1, 0, 1,
		    -0.5f, -0.5f,  0.0f, 0, 0, 1, 1,
		    -0.5f,  0.5f,  0.0f, 1, 0, 1, 1
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
			uniform mat4 u_Transform;

			out vec3 v_Position;
			out vec4 v_Color;

			void main()
			{
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);	
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

		std::string flatColorVertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;

			out vec3 v_Position;
			out vec4 v_Color;

			void main()
			{
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);	
			}
		)";

		std::string flatColorFragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;

			in vec3 v_Position;

			uniform vec3 u_Color;

			void main()
			{
				color = vec4(v_Position * 1 + 0.5, 1.0);
				color = vec4(u_Color, 1.0);
			}
		)";

		m_Shader.reset(Titan::Shader::Create(vertexSrc, fragmentSrc));
		m_FlatColorShader.reset(Titan::Shader::Create(flatColorVertexSrc, flatColorFragmentSrc));
	}

	void OnUpdate(Titan::Timestep ts) override
	{
		//TITAN_TRACE("Delta time: {0}s ({1}ms)", ts.GetSeconds(), ts.GetMilliseconds());
		
		if (Titan::Input::IsKeyPressed(TI_KEY_A))
			m_CameraPos.x -= m_CameraSpeed * ts;
		if (Titan::Input::IsKeyPressed(TI_KEY_D))
			m_CameraPos.x += m_CameraSpeed * ts;
		if (Titan::Input::IsKeyPressed(TI_KEY_S))
			m_CameraPos.y -= m_CameraSpeed * ts;
		if (Titan::Input::IsKeyPressed(TI_KEY_W))
			m_CameraPos.y += m_CameraSpeed * ts;

		if (Titan::Input::IsKeyPressed(TI_KEY_Q))
			m_Camera.SetRotation(m_Camera.GetRotation() + m_CameraRotSpeed * ts);
		if (Titan::Input::IsKeyPressed(TI_KEY_E))
			m_Camera.SetRotation(m_Camera.GetRotation() - m_CameraRotSpeed * ts);

		if (Titan::Input::IsKeyPressed(TI_KEY_J))
			m_SquarePosition.x -= m_CameraSpeed * ts;
		if (Titan::Input::IsKeyPressed(TI_KEY_L))
			m_SquarePosition.x += m_CameraSpeed * ts;
		if (Titan::Input::IsKeyPressed(TI_KEY_K))
			m_SquarePosition.y -= m_CameraSpeed * ts;
		if (Titan::Input::IsKeyPressed(TI_KEY_I))
			m_SquarePosition.y += m_CameraSpeed * ts;

		Titan::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
		Titan::RenderCommand::Clear();

		m_Camera.SetPosition(m_CameraPos);

		Titan::Renderer::BeginScene(m_Camera);

		glm::mat4 transformSquare = glm::translate(glm::mat4(1.0f), m_SquarePosition);

		Titan::Renderer::Submit(m_Shader, m_VertexArray, transformSquare);

		glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));
		/*
		Titan::MaterialRef material = new Titan::Material(m_FlatColorShader);
		Titan::MaterialInstanceRef mi = new Titan::MaterialInstance(material);

		material->Set("u_Color", redColor);
		squareMesh->SetMaterial(mi);
		*/
		std::dynamic_pointer_cast<Titan::OpenGLShader>(m_FlatColorShader)->Bind();
		std::dynamic_pointer_cast<Titan::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat3("u_Color", m_TileColor);

		for (int x = 0; x < m_Tiles; x++) {
			for (int y = 0; y < m_Tiles; y++) {
				glm::vec3 pos((0.1f * x + (x * 0.01f))-0.5f, (0.1f*y+(y*0.01f))-0.5f, 0.0f);
				glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * scale;
				Titan::Renderer::Submit(m_FlatColorShader, m_VertexArray, transform);
			}
		}

		Titan::Renderer::EndScene();
	}

	virtual void OnImGuiRender() override
	{
		//Camera
		ImGui::Begin("Camera");
		ImGui::Text("Pos: %f, %f, %f", m_CameraPos.x, m_CameraPos.y, m_CameraPos.z);
		ImGui::Text("Rot: %f", m_Camera.GetRotation());
		ImGui::End();

		//Square
		ImGui::Begin("Tiles");
		ImGui::Text("Pos: %f, %f, %f", m_SquarePosition.x, m_SquarePosition.y, m_SquarePosition.z);
		ImGui::ColorEdit3("Tile Color", glm::value_ptr(m_TileColor));
		ImGui::End();

		//Tutorial
		ImGui::Begin("Tutorial");
		ImGui::Text("Use WASD to move the camera");
		ImGui::Text("Use Q and E to rotate the camera");
		ImGui::Text("Use IKJL to move the square");
		ImGui::Text("You can edit the color of the tiles");
		ImGui::End();
	}

	void OnEvent(Titan::Event& event) override
	{
		
	}

private:
	std::shared_ptr<Titan::Shader> m_Shader;
	std::shared_ptr<Titan::Shader> m_FlatColorShader;
	std::shared_ptr<Titan::VertexBuffer> m_VertexBuffer;
	std::shared_ptr<Titan::IndexBuffer> m_IndexBuffer;
	std::shared_ptr<Titan::VertexArray> m_VertexArray;

	Titan::OrthographicCamera m_Camera;
	glm::vec3 m_CameraPos;

	float m_CameraSpeed = 2.0f;
	float m_CameraRotSpeed = 90.0f;

	glm::vec3 m_SquarePosition;

	float m_Tiles = 8;

	glm::vec3 m_TileColor = { 0.2, 0.2, 0.2 };

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