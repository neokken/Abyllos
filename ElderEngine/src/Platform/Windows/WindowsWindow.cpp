#include "eldpch.h"
#include "WindowsWindow.h"


namespace Elder
{
	static bool s_GLFWInitialized = false;
	
	Window* Window::Create(const WindowProperties& props)
	{
		return new WindowsWindow(props);
	}




	WindowsWindow::WindowsWindow(const WindowProperties& props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WindowsWindow::SetVSync(bool enable)
	{
		if (enable)
		{
			glfwSwapInterval(1);
		}
		else
		{
			glfwSwapInterval(0);
		}
		m_WindowData.VSync = enable;
	}

	void WindowsWindow::Init(const WindowProperties& props)
	{
		m_WindowData.Title = props.Title;
		m_WindowData.Height = props.Height;
		m_WindowData.Width = props.Width;

		ELD_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

		if (!s_GLFWInitialized)
		{
			int succes = glfwInit();
			ELD_ASSERT(succes, "Couldn't initialize GLFW!")

			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow(static_cast<int>(m_WindowData.Width), 
									static_cast<int>(m_WindowData.Height), 
									m_WindowData.Title.c_str(), nullptr, nullptr);

		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_WindowData);
		SetVSync(true);

	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}

}