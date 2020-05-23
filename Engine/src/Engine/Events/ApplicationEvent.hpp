#pragma once
#include "Event.hpp"
#include <sstream>

namespace Engine {

	class ENGINE_API WindowResizeEvent : public Event {
	public:
		WindowResizeEvent(uint_least32_t width, uint_least32_t height) : width(width), height(height) {}

		 [[nodiscard]] uint_least32_t getWidth() const { return width; }
		 [[nodiscard]] uint_least32_t getHeight() const { return height; }

		 [[nodiscard]] std::string toString() const override {
			 std::ostringstream stringstream;
			 stringstream << "WindowResize event: " << width << ", " << height;
			 return stringstream.str();
		 }

		[[nodiscard]] static EventType getStaticType() { return EventType::windowResize; }
		[[nodiscard]] EventType getEventType() const override { return getStaticType(); }
		[[nodiscard]] const char* getName() const override { return "WindowResize"; }

		[[nodiscard]] uint8_t getCategoryFlags() const override {
			return static_cast<uint8_t>(EventCategory::application);
		}
	private:
		uint_least32_t width, height;
	};

	class ENGINE_API WindowCloseEvent : public Event {
	public:
		[[nodiscard]] static EventType getStaticType() { return EventType::windowClose; }
		[[nodiscard]] EventType getEventType() const override { return getStaticType(); }
		[[nodiscard]] const char* getName() const override { return "WindowClose"; }

		[[nodiscard]] uint8_t getCategoryFlags() const override {
			return static_cast<uint8_t>(EventCategory::application);
		}
	};

	class ENGINE_API AppTickEvent : public Event {
	public:
		[[nodiscard]] static EventType getStaticType() { return EventType::appTick; }
		[[nodiscard]] EventType getEventType() const override { return getStaticType(); }
		[[nodiscard]] const char* getName() const override { return "AppTick"; }

		[[nodiscard]] uint8_t getCategoryFlags() const override {
			return static_cast<uint8_t>(EventCategory::application);
		}
	};

	class ENGINE_API AppUpdateEvent : public Event {
	public:
		[[nodiscard]] static EventType getStaticType() { return EventType::appUpdate; }
		[[nodiscard]] EventType getEventType() const override { return getStaticType(); }
		[[nodiscard]] const char* getName() const override { return "AppUpdate"; }

		[[nodiscard]] uint8_t getCategoryFlags() const override {
			return static_cast<uint8_t>(EventCategory::application);
		}
	};

	class ENGINE_API AppRenderEvent : public Event {
		[[nodiscard]] static EventType getStaticType() { return EventType::appRender; }
		[[nodiscard]] EventType getEventType() const override { return getStaticType(); }
		[[nodiscard]] const char* getName() const override { return "AppRender"; }

		[[nodiscard]] uint8_t getCategoryFlags() const override {
			return static_cast<uint8_t>(EventCategory::application);
		}
	};
	
} // namespace Engine
