#pragma once

#include "Elder/Core.h"
#include "LayerStack.h"
#include "Elder/Window.h"
#include "Elder/Events/ApplicationEvent.h"

namespace Elder
{

	class Application
	{
	public:
		ELDER_API Application();
		ELDER_API virtual ~Application();

		ELDER_API void Run();

		ELDER_API void OnEvent(Event& e);

		ELDER_API void PushLayer(Layer* layer);
		ELDER_API void PushOverlay(Layer* layer);

		ELDER_API static Application& GetApplication() { return *s_Instance; }
		ELDER_API Window& GetWindow() { return *m_Window; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running{ true };

		LayerStack m_LayerStack;

	private:
		static Application* s_Instance;
	};

	// To be defined in client
	Application* CreateApplication();
}

