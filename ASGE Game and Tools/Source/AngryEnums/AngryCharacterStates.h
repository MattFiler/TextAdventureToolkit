#pragma once

/*
	Define all character states.
*/
enum class CharacterStates : int
{
	//Spawning in
	SHOULD_SPAWN, //Character should be spawned
	SPAWNED, //Character has spawned with no active job
	
	//Despawning out
	SHOULD_DESPAWN, //Character is offscreen and should despawn
	DESPAWNED, //Character is not being rendered

	//Bird specific
	IN_LINEUP, //Character is idle in lineup
	IN_CANNON, //Character is idle in cannon
	ABOUT_TO_BE_FIRED, //Character is about to be fired (player has control over its position)
	HAS_BEEN_FIRED, //Character has just been fired from cannon (player has released mouse button)
	IS_IN_AIR, //Character is currently in the air
	HAS_HIT, //Character has hit an object

	//Pig specific
	HAS_BEEN_HIT //Unused atm
};