#pragma once

#include "Elder/Events/Event.h"
#include "Elder/KeyCodes.h"

namespace Elder
{
	class ELDER_API KeyEvent : public Event
	{
	public:
		ELD_KEY GetKeyCode() const { return m_KeyCode; }


		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(int keyCode) : m_KeyCode{ keyCode } {}

		ELD_KEY m_KeyCode;
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
			ss << "KeyPressedEvent: " << static_cast<int>(m_KeyCode) << " (" << m_Repeating << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		bool m_Repeating;
	};

	
	class ELDER_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keyCode)
			: KeyEvent(keyCode) {}

		std::string ToString() const
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << static_cast<int>(m_KeyCode);
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};


	class ELDER_API KeyTypedEvent : public KeyEvent
	{
	public:
		KeyTypedEvent(int keyCode)
			: KeyEvent(keyCode) {}

		std::string ToString() const
		{
			std::stringstream ss;
			ss << "KeyTypedEvent: " << static_cast<int>(m_KeyCode);
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyTyped)
	};

}