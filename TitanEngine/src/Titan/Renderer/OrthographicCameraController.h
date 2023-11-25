#pragma once

#include "Titan/Renderer/OrthographicCamera.h"
#include "Titan/Core/Timestep.h"

#include "Titan/Events/Event.h"
#include "Titan/Events/MouseEvent.h"
#include "Titan/Events/ApplicationEvent.h"

namespace Titan {

	class OrthographicCameraController
	{
	public:
		OrthographicCameraController(float aspectRatio, bool rotation = false);

		void OnUpdate(Timestep ts);
		void OnEvent(Event& e);

		OrthographicCamera& GetCamera() { return m_Camera; };
		const OrthographicCamera& GetCamera() const { return m_Camera; };

		void SetZoomLevel(float level) { m_ZoomLevel = level; };
		float GetZoomLevel() { return m_ZoomLevel; };
	private:
		bool OnMouseScrolled(MouseScrolledEvent& e);
		bool OnWindowResized(WindowResizeEvent& e);
	private:
		float m_AspectRatio;
		float m_ZoomLevel = 1.0f;
		OrthographicCamera m_Camera;

		bool m_Rotation;
		float m_CameraRotation = 0.0f;
		glm::vec3 m_CameraPosition = { .0f, .0f, .0f };
		float m_CameraTranslationSpeed = 2.0f, m_CameraRotationSpeed = 90.0f;
	};

}