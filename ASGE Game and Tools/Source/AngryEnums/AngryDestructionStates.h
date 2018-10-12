#pragma once

/*
Define all destruction states & health values for blocks
*/
enum class DestructionStates : int
{
	//Destruction states
	DEFAULT,
	DAMAGE_LOW,
	DAMAGE_MEDIUM,
	DAMAGE_HIGH,

	//Maximum destruction available
	DESTRUCTION_COUNT,

	//Block destruction increment (acts as health variants)
	ROCK_DAMAGE_PER_HIT = 1,
	ICE_DAMAGE_PER_HIT = 3,
	WOOD_DAMAGE_PER_HIT = 2
};