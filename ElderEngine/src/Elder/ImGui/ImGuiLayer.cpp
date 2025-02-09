#include "eldpch.h"
#include "ImGuiLayer.h"

#include "imgui.h"
#include "Platform/OpenGL/imgui_impl_opengl3.h"
#include "GLFW/glfw3.h"
#include "Elder/Application.h"
#include "Elder/KeyCodes.h"

//temp
#include <GLFW/glfw3.h>
#include <glad/glad.h>

ImGuiKey ELDKeyToImGuiKey(ELD_KEY key)
{
    switch (key)
    {
    case ELD_KEY::K_TAB: return ImGuiKey_Tab;
    case ELD_KEY::K_LEFT: return ImGuiKey_LeftArrow;
    case ELD_KEY::K_RIGHT: return ImGuiKey_RightArrow;
    case ELD_KEY::K_UP: return ImGuiKey_UpArrow;
    case ELD_KEY::K_DOWN: return ImGuiKey_DownArrow;
    case ELD_KEY::K_PAGE_UP: return ImGuiKey_PageUp;
    case ELD_KEY::K_PAGE_DOWN: return ImGuiKey_PageDown;
    case ELD_KEY::K_HOME: return ImGuiKey_Home;
    case ELD_KEY::K_END: return ImGuiKey_End;
    case ELD_KEY::K_INSERT: return ImGuiKey_Insert;
    case ELD_KEY::K_DELETE: return ImGuiKey_Delete;
    case ELD_KEY::K_BACKSPACE: return ImGuiKey_Backspace;
    case ELD_KEY::K_SPACE: return ImGuiKey_Space;
    case ELD_KEY::K_ENTER: return ImGuiKey_Enter;
    case ELD_KEY::K_ESCAPE: return ImGuiKey_Escape;
    case ELD_KEY::K_APOSTROPHE: return ImGuiKey_Apostrophe;
    case ELD_KEY::K_COMMA: return ImGuiKey_Comma;
    case ELD_KEY::K_MINUS: return ImGuiKey_Minus;
    case ELD_KEY::K_PERIOD: return ImGuiKey_Period;
    case ELD_KEY::K_SLASH: return ImGuiKey_Slash;
    case ELD_KEY::K_SEMICOLON: return ImGuiKey_Semicolon;
    case ELD_KEY::K_EQUAL: return ImGuiKey_Equal;
    case ELD_KEY::K_LEFT_BRACKET: return ImGuiKey_LeftBracket;
    case ELD_KEY::K_BACKSLASH: return ImGuiKey_Backslash;
    case ELD_KEY::K_RIGHT_BRACKET: return ImGuiKey_RightBracket;
    case ELD_KEY::K_GRAVE_ACCENT: return ImGuiKey_GraveAccent;
    case ELD_KEY::K_CAPS_LOCK: return ImGuiKey_CapsLock;
    case ELD_KEY::K_SCROLL_LOCK: return ImGuiKey_ScrollLock;
    case ELD_KEY::K_NUM_LOCK: return ImGuiKey_NumLock;
    case ELD_KEY::K_PRINT_SCREEN: return ImGuiKey_PrintScreen;
    case ELD_KEY::K_PAUSE: return ImGuiKey_Pause;
    case ELD_KEY::K_KP_0: return ImGuiKey_Keypad0;
    case ELD_KEY::K_KP_1: return ImGuiKey_Keypad1;
    case ELD_KEY::K_KP_2: return ImGuiKey_Keypad2;
    case ELD_KEY::K_KP_3: return ImGuiKey_Keypad3;
    case ELD_KEY::K_KP_4: return ImGuiKey_Keypad4;
    case ELD_KEY::K_KP_5: return ImGuiKey_Keypad5;
    case ELD_KEY::K_KP_6: return ImGuiKey_Keypad6;
    case ELD_KEY::K_KP_7: return ImGuiKey_Keypad7;
    case ELD_KEY::K_KP_8: return ImGuiKey_Keypad8;
    case ELD_KEY::K_KP_9: return ImGuiKey_Keypad9;
    case ELD_KEY::K_KP_DECIMAL: return ImGuiKey_KeypadDecimal;
    case ELD_KEY::K_KP_DIVIDE: return ImGuiKey_KeypadDivide;
    case ELD_KEY::K_KP_MULTIPLY: return ImGuiKey_KeypadMultiply;
    case ELD_KEY::K_KP_SUBTRACT: return ImGuiKey_KeypadSubtract;
    case ELD_KEY::K_KP_ADD: return ImGuiKey_KeypadAdd;
    case ELD_KEY::K_KP_ENTER: return ImGuiKey_KeypadEnter;
    case ELD_KEY::K_KP_EQUAL: return ImGuiKey_KeypadEqual;
    case ELD_KEY::K_LEFT_SHIFT: return ImGuiKey_LeftShift;
    case ELD_KEY::K_LEFT_CONTROL: return ImGuiKey_LeftCtrl;
    case ELD_KEY::K_LEFT_ALT: return ImGuiKey_LeftAlt;
    case ELD_KEY::K_LEFT_SUPER: return ImGuiKey_LeftSuper;
    case ELD_KEY::K_RIGHT_SHIFT: return ImGuiKey_RightShift;
    case ELD_KEY::K_RIGHT_CONTROL: return ImGuiKey_RightCtrl;
    case ELD_KEY::K_RIGHT_ALT: return ImGuiKey_RightAlt;
    case ELD_KEY::K_RIGHT_SUPER: return ImGuiKey_RightSuper;
    case ELD_KEY::K_MENU: return ImGuiKey_Menu;
    case ELD_KEY::K_0: return ImGuiKey_0;
    case ELD_KEY::K_1: return ImGuiKey_1;
    case ELD_KEY::K_2: return ImGuiKey_2;
    case ELD_KEY::K_3: return ImGuiKey_3;
    case ELD_KEY::K_4: return ImGuiKey_4;
    case ELD_KEY::K_5: return ImGuiKey_5;
    case ELD_KEY::K_6: return ImGuiKey_6;
    case ELD_KEY::K_7: return ImGuiKey_7;
    case ELD_KEY::K_8: return ImGuiKey_8;
    case ELD_KEY::K_9: return ImGuiKey_9;
    case ELD_KEY::K_A: return ImGuiKey_A;
    case ELD_KEY::K_B: return ImGuiKey_B;
    case ELD_KEY::K_C: return ImGuiKey_C;
    case ELD_KEY::K_D: return ImGuiKey_D;
    case ELD_KEY::K_E: return ImGuiKey_E;
    case ELD_KEY::K_F: return ImGuiKey_F;
    case ELD_KEY::K_G: return ImGuiKey_G;
    case ELD_KEY::K_H: return ImGuiKey_H;
    case ELD_KEY::K_I: return ImGuiKey_I;
    case ELD_KEY::K_J: return ImGuiKey_J;
    case ELD_KEY::K_K: return ImGuiKey_K;
    case ELD_KEY::K_L: return ImGuiKey_L;
    case ELD_KEY::K_M: return ImGuiKey_M;
    case ELD_KEY::K_N: return ImGuiKey_N;
    case ELD_KEY::K_O: return ImGuiKey_O;
    case ELD_KEY::K_P: return ImGuiKey_P;
    case ELD_KEY::K_Q: return ImGuiKey_Q;
    case ELD_KEY::K_R: return ImGuiKey_R;
    case ELD_KEY::K_S: return ImGuiKey_S;
    case ELD_KEY::K_T: return ImGuiKey_T;
    case ELD_KEY::K_U: return ImGuiKey_U;
    case ELD_KEY::K_V: return ImGuiKey_V;
    case ELD_KEY::K_W: return ImGuiKey_W;
    case ELD_KEY::K_X: return ImGuiKey_X;
    case ELD_KEY::K_Y: return ImGuiKey_Y;
    case ELD_KEY::K_Z: return ImGuiKey_Z;
    case ELD_KEY::K_F1: return ImGuiKey_F1;
    case ELD_KEY::K_F2: return ImGuiKey_F2;
    case ELD_KEY::K_F3: return ImGuiKey_F3;
    case ELD_KEY::K_F4: return ImGuiKey_F4;
    case ELD_KEY::K_F5: return ImGuiKey_F5;
    case ELD_KEY::K_F6: return ImGuiKey_F6;
    case ELD_KEY::K_F7: return ImGuiKey_F7;
    case ELD_KEY::K_F8: return ImGuiKey_F8;
    case ELD_KEY::K_F9: return ImGuiKey_F9;
    case ELD_KEY::K_F10: return ImGuiKey_F10;
    case ELD_KEY::K_F11: return ImGuiKey_F11;
    case ELD_KEY::K_F12: return ImGuiKey_F12;
    case ELD_KEY::K_F13: return ImGuiKey_F13;
    case ELD_KEY::K_F14: return ImGuiKey_F14;
    case ELD_KEY::K_F15: return ImGuiKey_F15;
    case ELD_KEY::K_F16: return ImGuiKey_F16;
    case ELD_KEY::K_F17: return ImGuiKey_F17;
    case ELD_KEY::K_F18: return ImGuiKey_F18;
    case ELD_KEY::K_F19: return ImGuiKey_F19;
    case ELD_KEY::K_F20: return ImGuiKey_F20;
    case ELD_KEY::K_F21: return ImGuiKey_F21;
    case ELD_KEY::K_F22: return ImGuiKey_F22;
    case ELD_KEY::K_F23: return ImGuiKey_F23;
    case ELD_KEY::K_F24: return ImGuiKey_F24;

    default: return ImGuiKey_None;
    }
}




enum KeyModifiers
{
    LEFT_CONTROL = 1 << 0,
    RIGHT_CONTROL = 1 << 1,

    LEFT_SHIFT = 1 << 2,
    RIGHT_SHIFT = 1 << 3,

    LEFT_ALT = 1 << 4,
    RIGHT_ALT = 1 << 5,

    LEFT_SUPER = 1 << 6,
    RIGHT_SUPER = 1 << 7,
};





Elder::ImGuiLayer::ImGuiLayer()
	: Layer("ImGuiLayer")
{
}

Elder::ImGuiLayer::~ImGuiLayer()
{

}

void Elder::ImGuiLayer::OnAttach()
{
	ImGui::CreateContext();
	ImGui::StyleColorsDark();

	ImGuiIO& io = ImGui::GetIO();
	io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
	io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

	ImGui_ImplOpenGL3_Init("#version 410");
}

void Elder::ImGuiLayer::OnDetach()
{
}

void Elder::ImGuiLayer::OnUpdate()
{
	

	ImGuiIO& io = ImGui::GetIO();
	Application& app = Application::GetApplication();
	
	io.DisplaySize = ImVec2((float)app.GetWindow().GetWidth(), (float)app.GetWindow().GetHeight());

	float time = (float)glfwGetTime();
	io.DeltaTime = m_Time > 0.f ? (time - m_Time) : (1.f / 60.f);
	m_Time = time;


	ImGui_ImplOpenGL3_NewFrame();
	ImGui::NewFrame();

	static bool show = true;
	ImGui::ShowDemoWindow(&show);

	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void Elder::ImGuiLayer::OnEvent(Event& event)
{
	EventDispatcher dispatcher(event);
	dispatcher.Dispatch<MouseButtonPressedEvent>(ELD_BIND_EVENT_FN(ImGuiLayer::OnMouseButtonPressedEvent));
	dispatcher.Dispatch<MouseButtonReleasedEvent>(ELD_BIND_EVENT_FN(ImGuiLayer::OnMouseButtonReleasedEvent));
	dispatcher.Dispatch<MouseMovedEvent>(ELD_BIND_EVENT_FN(ImGuiLayer::OnMouseMovedEvent));
	dispatcher.Dispatch<MouseScrolledEvent>(ELD_BIND_EVENT_FN(ImGuiLayer::OnMouseScrolledEvent));
	dispatcher.Dispatch<KeyPressedEvent>(ELD_BIND_EVENT_FN(ImGuiLayer::OnKeyPressedEvent));
	dispatcher.Dispatch<KeyReleasedEvent>(ELD_BIND_EVENT_FN(ImGuiLayer::OnKeyReleasedEvent));
	dispatcher.Dispatch<KeyTypedEvent>(ELD_BIND_EVENT_FN(ImGuiLayer::OnKeyTypesEvent));
	dispatcher.Dispatch<WindowResizeEvent>(ELD_BIND_EVENT_FN(ImGuiLayer::OnWindowResizeEvent));
}



bool Elder::ImGuiLayer::OnMouseButtonPressedEvent(MouseButtonPressedEvent& e)
{
	ImGuiIO& io = ImGui::GetIO();

    io.AddKeyEvent(ImGuiMod_Ctrl, m_KeyModifier & LEFT_CONTROL || m_KeyModifier & RIGHT_CONTROL);
    io.AddKeyEvent(ImGuiMod_Shift, m_KeyModifier & LEFT_SHIFT || m_KeyModifier & RIGHT_SHIFT);
    io.AddKeyEvent(ImGuiMod_Alt, m_KeyModifier & LEFT_ALT || m_KeyModifier & RIGHT_ALT);
    io.AddKeyEvent(ImGuiMod_Super, m_KeyModifier & LEFT_SUPER || m_KeyModifier & RIGHT_SUPER);

    io.AddMouseButtonEvent(static_cast<int>(e.GetButton()), true);

	return false;
}

bool Elder::ImGuiLayer::OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e)
{
	ImGuiIO& io = ImGui::GetIO();
    io.AddMouseButtonEvent(static_cast<int>(e.GetButton()), false);

   	return false;
}

bool Elder::ImGuiLayer::OnMouseMovedEvent(MouseMovedEvent& e)
{
	ImGuiIO& io = ImGui::GetIO();
	io.AddMousePosEvent(e.GetX(), e.GetY());

	return false;
}

bool Elder::ImGuiLayer::OnMouseScrolledEvent(MouseScrolledEvent& e)
{
	ImGuiIO& io = ImGui::GetIO();
	io.AddMouseWheelEvent(e.GetXOffset(), e.GetYOffset());

	return false;
}

bool Elder::ImGuiLayer::OnKeyPressedEvent(KeyPressedEvent& e)
{
	ImGuiIO& io = ImGui::GetIO();
	
    ImGuiKey imgui_key = ELDKeyToImGuiKey(e.GetKeyCode());
    switch (imgui_key)
    {
        case ImGuiKey_LeftCtrl:
            m_KeyModifier |= LEFT_CONTROL;
            break;
        case ImGuiKey_RightCtrl:
            m_KeyModifier |= RIGHT_CONTROL;
            break;

        case ImGuiKey_LeftShift:
            m_KeyModifier |= LEFT_SHIFT;
            break;
        case ImGuiKey_RightShift:
            m_KeyModifier |= RIGHT_SHIFT;
            break;

        case ImGuiKey_LeftAlt:
            m_KeyModifier |= LEFT_ALT;
            break;
        case ImGuiKey_RightAlt:
            m_KeyModifier |= RIGHT_ALT;
            break;

        case ImGuiKey_LeftSuper:
            m_KeyModifier |= LEFT_SUPER;
            break;
        case ImGuiKey_RightSuper:
            m_KeyModifier |= RIGHT_SUPER;
            break;
    }



    io.AddKeyEvent(ImGuiMod_Ctrl, m_KeyModifier&LEFT_CONTROL || m_KeyModifier & RIGHT_CONTROL);
    io.AddKeyEvent(ImGuiMod_Shift, m_KeyModifier&LEFT_SHIFT || m_KeyModifier & RIGHT_SHIFT);
    io.AddKeyEvent(ImGuiMod_Alt, m_KeyModifier&LEFT_ALT || m_KeyModifier & RIGHT_ALT);
    io.AddKeyEvent(ImGuiMod_Super, m_KeyModifier&LEFT_SUPER || m_KeyModifier & RIGHT_SUPER);


    
	io.AddKeyEvent(imgui_key, true);

    // need the modifiers?
    
	return false;
}

bool Elder::ImGuiLayer::OnKeyReleasedEvent(KeyReleasedEvent& e)
{
    ImGuiIO& io = ImGui::GetIO();

    ImGuiKey imgui_key = ELDKeyToImGuiKey(e.GetKeyCode());
    switch (imgui_key)
    {
    case ImGuiKey_LeftCtrl:
        m_KeyModifier &= ~LEFT_CONTROL;
        break;
    case ImGuiKey_RightCtrl:
        m_KeyModifier &= ~RIGHT_CONTROL;
        break;

    case ImGuiKey_LeftShift:
        m_KeyModifier &= ~LEFT_SHIFT;
        break;
    case ImGuiKey_RightShift:
        m_KeyModifier &= ~RIGHT_SHIFT;
        break;

    case ImGuiKey_LeftAlt:
        m_KeyModifier &= ~LEFT_ALT;
        break;
    case ImGuiKey_RightAlt:
        m_KeyModifier &= ~RIGHT_ALT;
        break;

    case ImGuiKey_LeftSuper:
        m_KeyModifier &= ~LEFT_SUPER;
        break;
    case ImGuiKey_RightSuper:
        m_KeyModifier &= ~RIGHT_SUPER;
        break;
    }


    io.AddKeyEvent(imgui_key, false);
    
    return false;
}

bool Elder::ImGuiLayer::OnKeyTypesEvent(KeyTypedEvent& e)
{
    ImGuiIO& io = ImGui::GetIO();
    io.AddInputCharacter(ELDKeyToImGuiKey(e.GetKeyCode()));
    return false;
}

bool Elder::ImGuiLayer::OnWindowResizeEvent(WindowResizeEvent& e)
{
	ImGuiIO& io = ImGui::GetIO();
    io.DisplaySize = ImVec2(static_cast<float>(e.GetWidth()), static_cast<float>(e.GetHeight()));


	io.DisplayFramebufferScale = ImVec2(1.f, 1.f);

	glViewport(0, 0, e.GetWidth(), e.GetHeight());
	return false;
}
