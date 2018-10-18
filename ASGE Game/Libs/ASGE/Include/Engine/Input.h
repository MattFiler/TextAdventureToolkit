#pragma once
#include <functional>
#include <vector>
#include <memory>
#include <map>

#include "Gamepad.h"
#include "InputEvents.h"
#include "Mouse.h"

namespace ASGE {
	class Renderer;

	/**
	*  The input handler system.
	*  The input class is designed to work alongside the 
	*  renderer and is responsible for sending events 
	*  to interested parties. It will also provide helper 
	*  functions that can retrieve non-event driven data
	*  such as the cursor position or the gamepad status. 
	*  Much of the underlying implementation will be platform
	*  specific, with input offering a compatible interface. 
	*/
	class Input
	{

	public:

		/**
		* Default Constructor.
		*/
		Input();

		/**
		* Destructor.
		* Clears all callback functions.
		*/
		virtual ~Input();
		
		/**
		* Destructor.
		* Initialises and sets up the input system.
		* @param renderer A pointer to the linked renderer system. 
		* @return Returns whether the input system initialised.
		*/
		virtual bool init(Renderer* renderer) = 0;
		
		/**
		* Updates the input handler.
		*/
		virtual void update() = 0;

		/**
		* Gets the cursor's (mouse) position.
		* Grabs the current position in screen space of the mouse
		* cursor. This can be used to detect the location of clicks
		* as well as its current position. The positions are stored
		* directly in the two parameters passed in. 
		* @param xpos The position in the X axis.
		* @param ypos The position in the Y axis.
		*/
		virtual void getCursorPos(double &xpos, double &ypos) const = 0;

		/**
		* Sets the cursor's (mouse) mode.
		* Allows control over the mouse cursors visibility and 
		* whether or not it should be locked to the window. 
		* @param mode The cursor mode to set.
		* @see ASGE::CursorMode
		*/
		virtual void setCursorMode(CursorMode mode) = 0;

		/**
		* Obtains the controllers data.
		* Searches for a controller connected at a specific idx and
		* returns any data relating to it, including naming, axis 
		* and button states. This is currently polled (demanded) rather
		* than event driven and is normally handled by the renderer's
		* window. 
		* @param idx The id of the connected controller.
		* @return The game controllers connected state and data.
		* @see GamePadData
		*/
		virtual const GamePadData getGamePad(int idx) const = 0;

		/**
		* Sends an event.
		* When an event happens, the type of event and the data
		* relating to it is forwarded to any interested parties
		* via their function pointer. NOTE: the data is shared
		* because the events can be sent using threads and this
		* ensures their lifespan. 
		* @param type The type of event registered.
		* @param data The data relating to the event. 
		* @see EventType
		* @see SharedEventData
		*/
		void sendEvent(EventType type, SharedEventData data);

		/**
		* Adds a callback function.
		* Many events are callback driven. This function
		* allows the use of a member function to be called
		* when the event happens. 
		* @param type the type of event being listened for.
		* @param fncPtr the function pointer.
		* @param obj the object (this ptr) the function belongs to. 
		* @see EventType
		* @return the handle for the registered callback.
		*/
		template<typename T, typename T2>
		int addCallbackFnc(EventType type, T fncPtr, T2* obj)
		{
			using namespace std::placeholders;
			return this->registerCallback(type, std::bind(fncPtr, obj, _1));
		}

		/**
		* Adds a callback function.
		* Many events are callback driven. This function
		* allows the use of a function to be called
		* when the event happens.
		* @param type the type of event being listened for.
		* @param fncPtr the function pointer.
		* @see EventType
		* @return the handle for the registered callback.
		*/
		template<typename T>
		int addCallbackFnc(EventType type, T fncPtr)
		{
			using namespace std::placeholders;
			return this->registerCallback(type, std::bind(fncPtr, _1));
		}

		/**
		* Removes a callback function.
		* This requires a valid handle to work correctly.
		* The handle is returned when the function event is
		* added. This prevents callbacks happening for classes
		* or functions that no longer exist. 
		* @param id the handle for the registered callback.
		*/
		void unregisterCallback(unsigned int id);

		/**
		* Allows events to use threads. 
		* Rather than sending events and waiting for their 
		* responses, threads can be used to perform the callbacks
		* asynchronously. When using threads, care must be taken
		* to ensure any operations in the callbacks is thread safe. 
		*/
		bool use_threads = true;

	private:
		using InputFnc = std::function<void(const SharedEventData)>;
		int registerCallback(EventType, InputFnc);
		
		using InputFncPair = std::pair<EventType, InputFnc>;
		using InputFncs = std::vector<InputFncPair>;
		InputFncs callback_funcs;
	};
}

