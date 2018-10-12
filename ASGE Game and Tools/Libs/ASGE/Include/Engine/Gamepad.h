#pragma once
/**
*  GamePadData.
*  Data that represents the current state of a connected
*  game pad. Includes the number of axis and buttons
*  along with their current state. If a gamepad is not 
*  connected then the status of is_connected will be 
*  false. Do not work with non connected devices as
*  it will lead to undefined behaviour. Currently, gamepad
*  support is via polling and not events. 
*/
struct GamePadData
{
	/**
	* Default constructor.
	* @param id The index of the controller.
	* @param n The name of the controller.
	* @param axis_count The number of axis.
	* @param axis_data The value of each axis.
	* @param button_count The number of buttons.
	* @param btns The state of each button.
	*/
	GamePadData(
		int id,
		const char* n,
		int axis_count,
		const float* axis_data,
		int button_count,
		const unsigned char* btns) noexcept
		: idx(id), name(n), no_of_axis(axis_count), axis(axis_data), no_of_buttons(button_count), buttons(btns)
	{

	}

	const int idx = -1;                      /**< Index. The index for this controller. */
	const int no_of_axis = 0;                /**< Number of axis. Number of axis on the controller */
	const int no_of_buttons = 0;             /**< Number of buttons. Number of buttons on the controller */
	const float* axis = nullptr;             /**< State of axis. The value of each axis. */
	const unsigned char* buttons = nullptr;  /**< State of buttons. The value of each button. */
	const char* name = nullptr;              /**< Name. The name of the connected controller. */
	bool is_connected = false;               /**< Is controller connected? Whether or not the controller is connected. */
};