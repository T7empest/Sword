#pragma once
#include <sstream>

#include "Event.h"

namespace Sword
{
	class SWORD_API KeyEvent : Event
	{
	public:
		inline int32_t GetKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(int32_t keycode)
			: m_KeyCode(keycode) {}

		int32_t m_KeyCode;
	};

	class SWORD_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(uint32_t keycode, int32_t repeatCount)
			: KeyEvent(keycode), m_repeatCount(repeatCount) {}

		inline int32_t GetRepeatCount() { return m_repeatCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_repeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int32_t m_repeatCount;
	};

	class SWORD_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(uint32_t keycode)
			: KeyEvent(keycode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};
}
