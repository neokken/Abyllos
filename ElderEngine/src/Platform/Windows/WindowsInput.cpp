#include "eldpch.h"
#include "WindowsInput.h"

#include <GLFW/glfw3.h>
#include "Elder/Application.h"


Elder::Input* Elder::Input::s_Instance = new Elder::WindowsInput();


bool Elder::WindowsInput::IsKeyPressedImpl(ELD_KEY keycode)
{
	GLFWwindow* window = static_cast<GLFWwindow*>(Application::GetApplication().GetWindow().GetNativeWindow());

	auto state = glfwGetKey(window, ELDKEYToGLFW(keycode));
	return state == GLFW_PRESS || state == GLFW_REPEAT;

}

bool Elder::WindowsInput::IsMouseButtonPressedImpl(ELD_MOUSE button)
{
	GLFWwindow* window = static_cast<GLFWwindow*>(Application::GetApplication().GetWindow().GetNativeWindow());

	return (glfwGetMouseButton(window, ELDMOUSEToGLFW(button)) == GLFW_PRESS);
}

std::pair<float, float> Elder::WindowsInput::GetMousePositionImpl()
{
	GLFWwindow* window = static_cast<GLFWwindow*>(Application::GetApplication().GetWindow().GetNativeWindow());
	double xPos, yPos;

	glfwGetCursorPos(window, &xPos, &yPos);
	return { (float)xPos, (float)yPos };
}

float Elder::WindowsInput::GetMouseXImpl()
{
	auto [x, y] = GetMousePositionImpl();
	return x;
}

float Elder::WindowsInput::GetMouseYImpl()
{
	auto [x, y] = GetMousePositionImpl();
	return y;
}
