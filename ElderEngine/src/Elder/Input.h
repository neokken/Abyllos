#pragma once

#include "Elder/Core.h"
#include "Elder/KeyCodes.h"
#include "Elder/MouseButtonCodes.h"


namespace Elder
{

	class ELDER_API Input
	{
	public:
		static bool IsKeyPressed(ELD_KEY keycode) { return s_Instance->IsKeyPressedImpl(keycode); }
		
		static bool IsMouseButtonPressed(ELD_MOUSE button) { return s_Instance->IsMouseButtonPressedImpl(button); }
		
		static std::pair<float,float> GetMousePosition() { return s_Instance->GetMousePositionImpl(); }
		static float GetMouseX() { return s_Instance->GetMouseXImpl(); }
		static float GetMouseY() { return s_Instance->GetMouseYImpl(); }



	protected:
		virtual bool IsKeyPressedImpl(ELD_KEY keycode) = 0;
		virtual bool IsMouseButtonPressedImpl(ELD_MOUSE button) = 0;
		virtual std::pair<float, float> GetMousePositionImpl() = 0;
		virtual float GetMouseXImpl() = 0;
		virtual float GetMouseYImpl() = 0;

	private:
		static Input* s_Instance;
	};


}