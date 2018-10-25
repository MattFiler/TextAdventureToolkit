/** 
 * @file
 * @brief Enum   @ref ASGE::EventType, Struct @ref ASGE::EventData, Struct @ref ASGE::KeyEvent, 
 *        Struct @ref ASGE::ClickEvent, Struct @ref ASGE::ScrollEvent, Struct @ref ASGE::MoveEvent,
 *        Struct @ref ASGE::GamePadEvent
 */

#pragma once
#include <memory>
#include "Keys.h"

namespace ASGE
{
	/**
	* @brief subscribable event types.
	* 
	* Events that can be listened or subscribed to are 
	* listed here. Note not all input is event driven.
	*/
	enum EventType
	{
		E_KEY,            /**< Keyboard input. A key has been pressed or released. */
		E_MOUSE_CLICK,    /**< Mouse click. A mouse button has been pressed. */
		E_MOUSE_SCROLL,   /**< Scroll wheel. The scrollwheel for the mouse has been used. */
		E_MOUSE_MOVE,     /**< Mouse movement. The mouse has been moved. */
		E_GAMEPAD_STATUS  /**< Controller support. The gamepad has been removed or a new one added. */
	};



	/**
	* @brief event data used to signal input events
	* 
	* Purely a base class at the moment, used to allow
	* polypmorphic support for sending event data through
	* the engine's generic input callback system.
	*/
	struct EventData
	{
		// @todo
		// create a look up hash table, referened by hash/string
		// returns a value, should we us	e <T> or a generic value 

	};

	/**
	* @brief a key event
	* 
	* A key event provides any related information that
	* can be used to drive a game. 
	* @see EventData
	*/
	struct KeyEvent : public EventData
	{
		int key			= -1; /**< The key.    The key in question. */
		int scancode	= -1; /**< Scancode.   The unique scancode used to to represent the character. */
		int action		= -1; /**< Key action. A key has been pressed or released. */
		int mods		= -1; /**< Modifiers.  Any modifiers applied i.e. ctrl, shift etc. */
	};

	/**
	* @brief a mouse click event
	* 
	* A click event provides any related information that
	* can be used to drive a game through mouse clicks.
	* @see EventData
	*/
	struct ClickEvent : public EventData
	{
		int button	= -1; /**< Mouse button. The mouse button clicked. */
		int action	= -1; /**< Button action. Has it been pressed or released? */
		int mods	= -1; /**< Modifiers. Any modifiers applied i.e. ctrl, shift etc. */
		double xpos =  0; /**< X. The current mouse position on the X axis. */
		double ypos =  0; /**< Y. The current mouse position on the Y axis. */
	};

	/**
	* @brief a mouse scrolling event
	* 
	* A scroll event provides any related information that
	* can be used to drive a game or it's interface.
	* @see EventData
	*/
	struct ScrollEvent : public EventData
	{
		double xoffset = 0; /**< Delta X. The amount of change incurred by the scrolling action. */
		double yoffset = 0; /**< Delta Y. The amount of change incurred by the scrolling action. */
	};

	/**
	* @brief a mouse movement event
	* 
	* A mouse movement event provides any related 
	* information that can be used to drive a game.
	* @see EventData
	*/
	struct MoveEvent : public EventData
	{
		double xpos = 0; /**< X. The current mouse position on the X axis. */
		double ypos = 0; /**< Y. The current mouse position on the Y axis. */
	};

	/**
	* @brief a controller Connection Event
	* 
	* An event that provides an update when the
	* controller is either connected or disconnected. 
	* @see EventData
	*/
	struct GamePadEvent : public EventData
	{
		int  idx = 0; /**< IDX of joystick/gamepad */
		bool connected = false; /**< Was connected? */
	};

	using SharedEventData = std::shared_ptr<const EventData>;
}