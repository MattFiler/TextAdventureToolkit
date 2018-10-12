#include <Engine\Renderer.h>
#include "Character.h"

Character::Character()
{
	//Character defaults
	character_state = CharacterStates::SHOULD_SPAWN;
	character_injuries = CharacterInjuries::FEELIN_FINE;
}


/*
	-- STATES --
*/

/* Get/Set Injury State */
CharacterInjuries Character::getInjuryLevel()
{
	return character_injuries;
}
void Character::setInjuryLevel(CharacterInjuries injuryLevel)
{
	character_injuries = injuryLevel;

	if (character_injuries == CharacterInjuries::FEELIN_FINE)
	{
		setCurrentFrame(0, 0);
	}
	else if (character_injuries == CharacterInjuries::SLIGHTLY_INJURED)
	{
		setCurrentFrame(2, 0); 
		sound_engine->play2D("Resources\\CHARACTERS\\PIGS\\SFX\\2.mp3", false);
	}
	else if (character_injuries == CharacterInjuries::HIGHLY_INJURED)
	{
		setCurrentFrame(4, 0);
		sound_engine->play2D("Resources\\CHARACTERS\\PIGS\\SFX\\3.mp3", false);
	}
}

/* Get/Set Character Entity State */
CharacterStates Character::getState()
{
	return character_state;
}
void Character::setState(CharacterStates newState)
{
	character_state = newState;
}