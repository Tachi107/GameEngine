#pragma once
#include "Engine/Core.h"
#include <ostream>
#include <string>
#include <functional>

namespace Engine {

	//Blocking event system

	enum class EventType {
		none,	// = 0
		windowClose, windowResize, windowFocus, windowLostFocus, windowMoved,
		appTick, appUpdate, appRender,
		keyPressed, keyReleased,
		mouseButtonPressed, mouseButtonReleased, mouseMoved, mouseScrolled
	};

	/* 
	 * Useful to filter events
	 * Come una griglia che fa passare solo gli eventi coi bit selezionati
	 */
	enum class EventCategory : uint8_t {	// non-class
		none,
		application	= 0b00000001,
		input		= 0b00000010,
		keyboard	= 0b00000100,
		mouse		= 0b00001000,
		mouseButton	= 0b00010000
	};

	class ENGINE_API Event {
		friend class EventDispatcher;
	public:
		[[nodiscard]] virtual EventType getEventType() const = 0;
		[[nodiscard]] virtual const char* getName() const = 0;
		[[nodiscard]] virtual uint8_t getCategoryFlags() const = 0;
		[[nodiscard]] virtual std::string toString() const { return getName(); }

		[[nodiscard]] bool isInCategory(EventCategory category) const {
			return getCategoryFlags() & static_cast<uint8_t>(category);
		}

	protected:
		bool handled = false;
	};

	class EventDispatcher {
		template<typename type>
		// function that return bool and takes in a type (event) reference
		using eventFunction = std::function<bool(type&)>;

	public:
		explicit EventDispatcher(Event& event) : event(event) {}
		
		template<typename type>
		bool dispatch(eventFunction<type> function) {
			if (event.getEventType() == type::getStaticType()) {
				event.handled = function(*static_cast<type*>(&event));
				return true;
			}
			else return false;
		}

	private:
		Event& event;
	};

	inline std::ostream& operator<<(std::ostream& ostream, const Event& event) {
		return ostream << event.toString();
	}

}  // namespace Engine
