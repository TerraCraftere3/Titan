#include <Titan.h>

#include "imgui.h"
#include <glm/ext/matrix_transform.hpp>
#include <Platform/OpenGL/OpenGLShader.h>
#include <glm/gtc/type_ptr.hpp>

class ExampleLayer : public Titan::Layer
{
public:
	ExampleLayer()
		: Layer("Example"), m_CameraController(1280.0f/720.0f, true), m_SquarePosition(0.0f)
	{
		auto colorShader = m_ShaderLibrary.Load("assets/shaders/Color.glsl");
		auto textureShader = m_ShaderLibrary.Load("assets/shaders/Texture.glsl");

		std::dynamic_pointer_cast<Titan::OpenGLShader>(textureShader)->Bind();
		std::dynamic_pointer_cast<Titan::OpenGLShader>(textureShader)->UploadUniformInt("u_Texture", 0);


		//Tiles
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
		}
		
		//Square
		{

			m_SquareVA.reset(Titan::VertexArray::Create());

			float vertices[4 * 5] = {
				-0.5f, -0.5f,  0.0f, 0.0f, 0.0f,
				 0.5f, -0.5f,  0.0f, 1.0f, 0.0f,
				 0.5f,  0.5f,  0.0f, 1.0f, 1.0f,
				-0.5f,  0.5f,  0.0f, 0.0f, 1.0f
			};

			m_SquareVB.reset(Titan::VertexBuffer::Create(vertices, sizeof(vertices)));


			{
				Titan::BufferLayout layout = {
					{ Titan::ShaderDataType::Float3, "a_Position" },
					{ Titan::ShaderDataType::Float2, "a_TexCoord"}
				};

				m_SquareVB->SetLayout(layout);
			}

			uint32_t indices[6] = { 0, 1, 2, 2, 3, 0 };
			m_SquareIB.reset(Titan::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));

			m_SquareVA->AddVertexBuffer(m_SquareVB);
			m_SquareVA->SetIndexBuffer(m_SquareIB);

			//https://youtu.be/N94fHNZEHas?list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT&t=67
			m_Texture = Titan::Texture2D::Create("assets/textures/Engine/masks/circle.png");
			m_TextureTransparent = Titan::Texture2D::Create("assets/textures/Engine/transparent.png");
		}
		
	}

	void OnUpdate(Titan::Timestep ts) override
	{
		m_CameraController.OnUpdate(ts);

		//Input
		{
			if (Titan::Input::IsKeyPressed(TI_KEY_J))
				m_SquarePosition.x -= 2 * ts;
			if (Titan::Input::IsKeyPressed(TI_KEY_L))
				m_SquarePosition.x += 2 * ts;
			if (Titan::Input::IsKeyPressed(TI_KEY_K))
				m_SquarePosition.y -= 2 * ts;
			if (Titan::Input::IsKeyPressed(TI_KEY_I))
				m_SquarePosition.y += 2 * ts;
		}
		
		//Screen Reset
		{
			Titan::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
			Titan::RenderCommand::Clear();
		}

		//Scene
		{
			Titan::Renderer::BeginScene(m_CameraController.GetCamera());
			

			//Tiles
			{
				auto flatColorShader = m_ShaderLibrary.Get("Color");
				
				glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));
				std::dynamic_pointer_cast<Titan::OpenGLShader>(flatColorShader)->Bind();
				std::dynamic_pointer_cast<Titan::OpenGLShader>(flatColorShader)->UploadUniformFloat3("u_Color", m_TileColor);

				for (int x = 0; x < m_Tiles; x++) {
					for (int y = 0; y < m_Tiles; y++) {
						glm::vec3 pos((0.1f * x + (x * 0.01f)) - 0.5f, (0.1f * y + (y * 0.01f)) - 0.5f, 0.0f);
						glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * scale;
						Titan::Renderer::Submit(flatColorShader, m_VertexArray, transform);
					}
				}
			}
			
			//Square
			{
				auto textureShader = m_ShaderLibrary.Get("Texture");

				m_TextureTransparent->Bind();
				Titan::Renderer::Submit(textureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));
				m_Texture->Bind();
				Titan::Renderer::Submit(textureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));
			}

			Titan::Renderer::EndScene();
		}
	}

	virtual void OnImGuiRender() override
	{
		//Camera
		ImGui::Begin("Camera");
		auto camPos = m_CameraController.GetCamera().GetPosition();
		ImGui::Text("Pos: %f, %f, %f", camPos.x, camPos.y, camPos.z);
		ImGui::Text("Rot: %f", m_CameraController.GetCamera().GetRotation());
		ImGui::End();

		//Square
		/*
		ImGui::Begin("Square");
		ImGui::Text("Pos: %f, %f, %f", m_SquarePosition.x, m_SquarePosition.y, m_SquarePosition.z);
		ImGui::End();
		*/

		//Tiless
		ImGui::Begin("Tiles");
		ImGui::ColorEdit3("Color", glm::value_ptr(m_TileColor));
		ImGui::SliderInt("Count", &m_Tiles, 5, 20);
		ImGui::End();

		//Tutorial
		ImGui::Begin("Tutorial");
		ImGui::Text("Use WASD to move the camera");
		ImGui::Text("Use Q and E to rotate the camera");
		ImGui::Text("Use IKJL to move the square");
		ImGui::Text("You can edit the color of the tiles");
		ImGui::End();
	}

	void OnEvent(Titan::Event& e) override
	{
		m_CameraController.OnEvent(e);
	}

private:
	Titan::ShaderLibrary m_ShaderLibrary;
	Titan::Ref<Titan::Shader> m_FlatColorShader;
	Titan::Ref<Titan::VertexBuffer> m_VertexBuffer, m_SquareVB;
	Titan::Ref<Titan::IndexBuffer> m_IndexBuffer, m_SquareIB;
	Titan::Ref<Titan::VertexArray> m_VertexArray, m_SquareVA;

	Titan::Ref<Titan::Texture2D> m_Texture, m_TextureTransparent;

	Titan::OrthographicCameraController m_CameraController;

	glm::vec3 m_SquarePosition;

	int m_Tiles = 16;

	glm::vec3 m_TileColor = { 0.8, 0.3, 0.2 };

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