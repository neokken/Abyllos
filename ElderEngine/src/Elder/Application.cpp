#include "eldpch.h"
#include "Application.h"

#include "Elder/Events/MouseEvent.h"
#include "Elder/Log.h"

namespace Elder
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		MouseMovedEvent e(200.f,200.f);
		ELD_TRACE(e);

		while (true);
	}

}


