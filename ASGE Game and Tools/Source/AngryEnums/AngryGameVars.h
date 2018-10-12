#pragma once
#include "AngryDestructionStates.h"

/*
	Define some game vars.
*/
enum class GameVars : int
{
	//Game window sizes
	GAME_WIDTH = 1920,
	GAME_HEIGHT = 1080,

	//Slingshot position
	SLINGSHOT_X_ORIGIN = 250,
	SLINGSHOT_Y_ORIGIN = 625,

	//Flight curvature modifiers
	FLIGHT_FORCE_MODIFIER = 10,
	FLIGHT_ANGLE_MODIFIER = 10,
	FLIGHT_TIME_MODIFIER = 1000,

	//Leeway for dragging the bird in the slingshot
	BIRD_CLICK_HITBOX_LEEWAY = 25,
	BIRD_DRAG_RADIUS = 170,

	//Despawn sprite holding location
	DESPAWN_X_POS = 0,
	DESPAWN_Y_POS = 0,

	//Bird count (player lives)
	NUMBER_OF_STARTING_BIRDS = 6,

	//Number of flight path tracking dots available to use.
	NUMBER_OF_FLIGHT_MARKER_DOTS = 100,

	//Number of blocks, variations and details
	NUMBER_OF_BLOCKS_PER_VARIATION = 5,
	NUMBER_OF_BLOCK_VARIATIONS = 3, //This is hard-coded. Do not modify!
	NUMBER_OF_BLOCK_DESTRUCTION_LEVELS = (int)DestructionStates::DESTRUCTION_COUNT,

	//Number of pigs available to use
	NUMBER_OF_PIGS = 10,

	//Total characters available to use
	NUMBER_OF_CHARACTERS = NUMBER_OF_STARTING_BIRDS + NUMBER_OF_PIGS,

	//Main menu option count
	NUMBER_OF_MAIN_MENU_OPTIONS = 2,

	//Number of levels
	NUMBER_OF_LEVELS = 4,

	//Number of level entities available
	NUMBER_OF_LEVEL_ENTITIES = NUMBER_OF_PIGS + (NUMBER_OF_BLOCKS_PER_VARIATION * NUMBER_OF_BLOCK_VARIATIONS),

	//Number of cursors
	NUMBER_OF_CURSOR_STATES = 6, //2 cursors, 4 level editor blocks.

	//Number of frames for FX & number of each FX available per frame
	NUMBER_OF_FRAMES_IN_FX = 4,
	NUMBER_OF_FX_AVAILABLE = 3,

	//Number of character frames
	NUMBER_OF_CHARACTER_FRAMES = 6
};