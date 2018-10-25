/** 
 * @file
 * @brief Namespace @ref MOUSE, Enum Class @ref ASGE::MOUSE::CursorMode
 */

#pragma once
namespace ASGE
{

	/**
	* @namespace ASGE::MOUSE
	* @brief mouse button mappings
	*/
	namespace MOUSE {

  	/**
  	 * @brief mouse cursor modes
  	 * 
  	 * Used to control the cursors behaviour
  	 * and visibility.
  	 */
  	enum class CursorMode
  	{
  	  NORMAL,/**< Enables the cursor.
  	         The cursor will be shown and the user is free to leave
  	         the window and interact with other applications. */
  	
  	  HIDDEN,/**< Hides the cursor.
  	         The cursor is no longer shown when positioned over the
  	         active game window, however, upon leaving the window
  	         the cursor will be shown, allowing interaction outside
  	         of the game window. */
  	
  	  LOCKED /**< Locks and hides the cursor.
  	         Simply, the cursor will be hidden and locked to the window.
  	         The user will not be able to leave the windowed area. */
  	};
	
		constexpr int BUTTON_RELEASED = 0;  /**< Mouse Btn Release. The mouse button was released. */
		constexpr int BUTTON_PRESSED  = 1;  /**< Mouse Btn Clicked. The mouse button was clicked. */
		constexpr int MOUSE_BTN1 = 0;       /**< Mouse Button 1. */
		constexpr int MOUSE_BTN2 = 1;       /**< Mouse Button 2. */
		constexpr int MOUSE_BTN3 = 2;       /**< Mouse Button 3. */
		constexpr int MOUSE_BTN4 = 3;       /**< Mouse Button 4. */
		constexpr int MOUSE_BTN5 = 4;       /**< Mouse Button 5. */
	}
};