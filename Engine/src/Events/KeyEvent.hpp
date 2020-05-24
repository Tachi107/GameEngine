#pragma once
#include "Event.hpp"

namespace Engine {

	class ENGINE_API KeyEvent : public Event {
	public:
		[[nodiscard]] int_least32_t getKeyCode() const { return keyCode; }

		[[nodiscard]] uint8_t getCategoryFlags() const override {
			// TODO: Tipo di questa espressione?
			return (static_cast<uint8_t>(EventCategory::keyboard) | static_cast<uint8_t>(EventCategory::input));
		}

	protected:
		int_least32_t keyCode;
		explicit KeyEvent(int_least32_t keyCode) : keyCode(keyCode) {}
	};

	class ENGINE_API KeyPressedEvent : public KeyEvent {
	public:
		KeyPressedEvent(int_least32_t keyCode, uint_least32_t repeatCount) 
			: KeyEvent(keyCode), repeatCount(repeatCount) {}
		
		[[nodiscard]] uint_least32_t getRepeatCount() const { return repeatCount; }

		[[nodiscard]] std::string toString() const override {
			std::ostringstream stringstream;
			stringstream << "KeyPressed event: " << keyCode << " (" << repeatCount << " repeats)";
			return stringstream.str();
		}

		[[nodiscard]] static EventType getStaticType() { return EventType::keyPressed; }
		[[nodiscard]] EventType getEventType() const override { return getStaticType(); }
		[[nodiscard]] const char* getName() const override { return "KeyPressed"; }

	private:
		uint_least32_t repeatCount;
	};

	class ENGINE_API KeyReleasedEvent : public KeyEvent {
	public:
		explicit KeyReleasedEvent(int_least32_t keyCode) : KeyEvent(keyCode) {}

		[[nodiscard]] std::string toString() const override {
			std::ostringstream stringstream;
			stringstream << "KeyReleased event: " << keyCode;
			return stringstream.str();
		}

		[[nodiscard]] static EventType getStaticType() { return EventType::keyReleased; }
		[[nodiscard]] EventType getEventType() const override { return getStaticType(); }
		[[nodiscard]] const char* getName() const override { return "KeyReleased"; }
	};

} // namespace Engine
