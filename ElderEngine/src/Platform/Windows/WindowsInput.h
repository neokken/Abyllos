#pragma once
#include "Elder/Input.h"





int ELDKEYToGLFW(ELD_KEY key)
{
	return static_cast<int>(key);
}

int ELDMOUSEToGLFW(ELD_MOUSE button)
{
	return static_cast<int>(button);
}



namespace Elder
{
	class WindowsInput : public Input
	{
	protected:
		virtual bool IsKeyPressedImpl(ELD_KEY keycode) override;
		virtual bool IsMouseButtonPressedImpl(ELD_MOUSE button) override;

		virtual std::pair<float, float> GetMousePositionImpl() override;
		virtual float GetMouseXImpl() override;
		virtual float GetMouseYImpl() override;
	};


}
