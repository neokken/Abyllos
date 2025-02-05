#pragma once

#include "Elder/Core.h"
#include "Elder/Window.h"

namespace Elder
{

	class Application
	{
	public:
		ELDER_API Application();
		ELDER_API virtual ~Application();

		ELDER_API void Run();

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running{ true };
	};

	// To be defined in client
	Application* CreateApplication();
}

