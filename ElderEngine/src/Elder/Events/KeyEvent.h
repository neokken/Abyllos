#pragma once

#include "Elder/Events/Event.h"

namespace Elder
{
	class ELDER_API KeyEvent : public Event
	{
	public:
		int GetKeyCode() const { return m_KeyCode; }


		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(int keyCode) : m_KeyCode{ keyCode } {}

		int m_KeyCode;
	};


	class ELDER_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keyCode, bool repeat)
			: KeyEvent(keyCode), m_Repeating{ repeat } {}

		bool GetRepeating() const { return m_Repeating; }

		std::string ToString() const 
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_Repeating << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		bool m_Repeating;
	};

	
	class ELDER_API KeyReleased : public KeyEvent
	{
	public:
		KeyReleased(int keyCode)
			: KeyEvent(keyCode) {}

		std::string ToString() const
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};

}