#pragma once

#include "Core.h"

namespace Elder
{

	class ELDER_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in client
	Application* CreateApplication();
}

