#include "eldpch.h"
#include "Application.h"

#include "Elder/Events/MouseEvent.h"
#include "Elder/Log.h"

namespace Elder
{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (m_Running)
		{

			m_Window->OnUpdate();
		}
	}

}


