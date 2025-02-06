#pragma once

#include "Elder/Layer.h"
#include "Elder/Events/KeyEvent.h"
#include "Elder/Events/MouseEvent.h"
#include "Elder/Events/ApplicationEvent.h"

namespace Elder
{

	class ImGuiLayer : public Layer
	{
	public:
		ELDER_API ImGuiLayer();
		ELDER_API ~ImGuiLayer();

		ELDER_API void OnAttach();
		ELDER_API void OnDetach();

		ELDER_API void OnUpdate();
		ELDER_API void OnEvent(Event& event);

	private:
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);

		bool OnMouseMovedEvent(MouseMovedEvent& e);
		bool OnMouseScrolledEvent(MouseScrolledEvent& e);

		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);

		bool OnKeyTypesEvent(KeyTypedEvent& e);
		bool OnWindowResizeEvent(WindowResizeEvent& e);


        
	private:
		float m_Time{ 0.f };

		char m_KeyModifier{ 0 }; // since we only need 1 byte. Since we have 4*2 modifiers.
		

	};



}