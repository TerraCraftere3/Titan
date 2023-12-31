#pragma once

#include "Titan.h"
#include "Panels/SceneHierarchyPanel.h"

namespace Titan {

	class EditorLayer : public Layer
	{
	public:
		EditorLayer();
		virtual ~EditorLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		void OnUpdate(Timestep ts) override;
		virtual void OnImGuiRender() override;
		void OnEvent(Event& e) override;
	private:
		bool OnKeyPressed(KeyPressedEvent& e);

		void NewScene();
		void OpenScene();
		void SaveSceneAs();
	private:
		Ref<Framebuffer> m_Framebuffer;
		Ref<Scene> m_ActiveScene;

		bool m_ViewportFocused = false, m_ViewportHovered = false;
		glm::vec2 m_ViewportSize = { 0, 0 };

		int m_GizmoType = -1;

		SceneHierarchyPanel m_SceneHierarchyPanel;
	};

}