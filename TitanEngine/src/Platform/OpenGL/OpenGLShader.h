#pragma once

#pragma once

#include "Titan/Renderer/Shader.h"
#include <glm/glm.hpp>

namespace Titan {

	class OpenGLShader : public Shader
	{
	public:
		OpenGLShader(const std::string& vertexSrc, const std::string& fragmentSrc);
		virtual ~OpenGLShader();

		void Bind() const;
		void Unbind() const;

		//Uniforms
		void UploadUniformMat3(const std::string& name, const glm::mat4& matrix);   //Mat
		void UploadUniformMat4(const std::string& name, const glm::mat4& matrix);   //Mat

		void UploadUniformFloat(const std::string& name, const float& value);       //Float
		void UploadUniformFloat2(const std::string& name, const glm::vec2& values); //Float
		void UploadUniformFloat3(const std::string& name, const glm::vec3& values); //Float
		void UploadUniformFloat4(const std::string& name, const glm::vec4& values); //Float

		void UploadUniformInt(const std::string& name, const int& value);           //Int
	private:
		uint32_t m_RendererID;
	};
}