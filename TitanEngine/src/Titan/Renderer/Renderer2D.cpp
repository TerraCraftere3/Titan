#include "tipch.h"

#include "RenderCommand.h"
#include "Renderer2D.h"
#include "Shader.h"
#include "VertexArray.h"
#include <glm/ext/matrix_transform.hpp>


namespace Titan
{

	struct Renderer2DStorage
	{
		Ref<VertexArray> QuadVertexArray;
		Ref<Shader> FlatColorShader;
	};

	static Renderer2DStorage* s_Storage;

	void Renderer2D::Init()
	{
		s_Storage = new Renderer2DStorage();

		s_Storage->QuadVertexArray = VertexArray::Create();

		float vertices[4 * 3] = {
			 0.5f,  0.5f,  0.0f, 
			 0.5f, -0.5f,  0.0f, 
			-0.5f, -0.5f,  0.0f, 
			-0.5f,  0.5f,  0.0f
		};

		Ref<VertexBuffer> QuadVertexBuffer = VertexBuffer::Create(vertices, sizeof(vertices));


		{
			BufferLayout layout = {
						{ ShaderDataType::Float3, "a_Position" }
			};

			QuadVertexBuffer->SetLayout(layout);
		}

		uint32_t indices[6] = { 0, 1, 2, 0, 2, 3 };
		Ref<IndexBuffer> QuadIndexBuffer = IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t));

		s_Storage->QuadVertexArray->AddVertexBuffer(QuadVertexBuffer);
		s_Storage->QuadVertexArray->SetIndexBuffer(QuadIndexBuffer);

		s_Storage->FlatColorShader = Shader::Create("assets/shaders/Color.glsl");
	}

	void Renderer2D::Shutdown()
	{
		delete s_Storage;
	}

	void Renderer2D::BeginScene(const OrthographicCamera& camera)
	{
		s_Storage->FlatColorShader->Bind();
		s_Storage->FlatColorShader->SetMat4("u_ViewProjection", camera.GetViewProjectionMatrix());
	}

	void Renderer2D::EndScene()
	{

	}

	void Renderer2D::DrawQuad(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color)
	{
		DrawQuad(glm::vec3(position, 0), size, color);
	}

	void Renderer2D::DrawQuad(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color)
	{
		s_Storage->FlatColorShader->Bind();
		s_Storage->FlatColorShader->SetFloat4("u_Color", color);

		glm::mat4 transform = glm::translate(glm::mat4(1.0), position) * glm::scale(glm::mat4(1.0), glm::vec3(size, 0));
		s_Storage->FlatColorShader->SetMat4("u_Transform", transform);

		s_Storage->QuadVertexArray->Bind();
		RenderCommand::DrawIndexed(s_Storage->QuadVertexArray);
	}

}
