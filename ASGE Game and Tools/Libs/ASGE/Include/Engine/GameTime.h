#pragma once
#include <chrono>
#include <chrono>
namespace ASGE {

	/**
	*  GameTime stores both frame and game deltas.
	*  Stores various measurments of delta time for the
	*  game. It will store the current time point which
	*  is used to calculate the delta between frames, the 
	*  delta of the last frame and the entire delta since the 
	*  game started. This can be used to control simulations
	*  and render functions to use non-fixed time steps.
	*/
	struct GameTime
	{
		/** 
		*  Time point of frame.  
		*  The time at which the previous frame began. 
		*/
		std::chrono::time_point<std::chrono::steady_clock> frame_time = std::chrono::steady_clock::now();

		/**
		*  Frame delta. 
		*  The amount of elapsed time since the last update. 
		*/
		std::chrono::duration<double, std::milli> delta_time;

		/**
		*  Running time. 
		*  The amount of time since the start of the game. 
		*/
		std::chrono::milliseconds game_time;
	};
}