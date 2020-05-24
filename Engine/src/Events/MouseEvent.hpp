#pragma once
#include "Event.hpp"
#include <sstream>

namespace Engine {

	class ENGINE_API MouseMovedEvent : public Event {
	public:
		MouseMovedEvent(float x, float y) : mouseX(x), mouseY(y) {}

		[[nodiscard]] float getX() const { return mouseX; }
		[[nodiscard]] float getY() const { return mouseY; }

		[[nodiscard]] std::string toString() const override {
			std::ostringstream stringstream;
			stringstream << "MouseMoved event: " << mouseX << ", " << mouseY;
			return stringstream.str();
		}

		[[nodiscard]] static EventType getStaticType() { return EventType::mouseMoved; }
		[[nodiscard]] EventType getEventType() const override { return getStaticType(); }
		[[nodiscard]] const char* getName() const override { return "MouseMoved"; }

		[[nodiscard]] uint8_t getCategoryFlags() const override {
			return (static_cast<uint8_t>(EventCategory::mouse) | static_cast<uint8_t>(EventCategory::input));
		}
	private:
		float mouseX, mouseY;
	};

	class ENGINE_API MouseScrolledEvent : public Event {
	public:
		MouseScrolledEvent(float xOffset, float yOffset) : xOffset(xOffset), yOffset(yOffset) {}

		[[nodiscard]] float getXOffset() const { return xOffset; }
		[[nodiscard]] float getYOffset() const { return yOffset; }

		[[nodiscard]] std::string toString() const override {
			std::ostringstream stringstream;
			stringstream << "MouseScrolled event: " << getXOffset() << ", " << getYOffset();
			return stringstream.str();
		}

		[[nodiscard]] static EventType getStaticType() { return EventType::mouseScrolled; }
		[[nodiscard]] EventType getEventType() const override { return getStaticType(); }
		[[nodiscard]] const char* getName() const override { return "MouseScrolled"; }

		[[nodiscard]] uint8_t getCategoryFlags() const override {
			return (static_cast<uint8_t>(EventCategory::mouse) | static_cast<uint8_t>(EventCategory::input));
		}

	private:
		float xOffset, yOffset;
	};

	class ENGINE_API MouseButtonEvent : public Event {
	public:
		[[nodiscard]] int_least32_t getMouseButton() const { return button; }
		
		[[nodiscard]] uint8_t getCategoryFlags() const override {
			return (static_cast<uint8_t>(EventCategory::mouse) | static_cast<uint8_t>(EventCategory::input));
		}
	
	protected:
		int_least32_t button;
		explicit MouseButtonEvent(int_least32_t button) : button(button) {}
	};

	class ENGINE_API MouseButtonPressedEvent : public MouseButtonEvent {
	public:
		explicit MouseButtonPressedEvent(int_least32_t button) : MouseButtonEvent(button) {}

		[[nodiscard]] std::string toString() const override {
			std::ostringstream stringstream;
			stringstream << "MouseButtonPressed event: " << button;
			return stringstream.str();
		}

		[[nodiscard]] static EventType getStaticType() { return EventType::mouseButtonPressed; }
		[[nodiscard]] EventType getEventType() const override { return getStaticType(); }
		[[nodiscard]] const char* getName() const override { return "MouseButtonPressed"; }
	};

	class ENGINE_API MouseButtonReleasedEvent : public MouseButtonEvent {
	public:
		explicit MouseButtonReleasedEvent(int_least32_t button) : MouseButtonEvent(button) {}

		[[nodiscard]] std::string toString() const override {
			std::ostringstream stringstream;
			stringstream << "MouseButtonReleased event: " << button;
			return stringstream.str();
		}

		[[nodiscard]] static EventType getStaticType() { return EventType::mouseButtonReleased; }
		[[nodiscard]] EventType getEventType() const override { return getStaticType(); }
		[[nodiscard]] const char* getName() const override { return "MouseButtonReleased"; }
	};

}  // namespace Engine