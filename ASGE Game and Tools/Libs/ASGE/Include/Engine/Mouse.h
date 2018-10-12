#pragma once
namespace ASGE
{
	/**
	* CursorMode.
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
}