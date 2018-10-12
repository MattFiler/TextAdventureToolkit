#pragma once
#include "GameObject.h"
#include "AngryEnums\AngryCharacterStates.h"
#include "AngryEnums\AngryCharacterInjury.h"

class Character : public GameObject<(int)GameVars::NUMBER_OF_CHARACTER_FRAMES>
{
public:
	Character();

	CharacterInjuries getInjuryLevel();
	void setInjuryLevel(CharacterInjuries injuryLevel);

	CharacterStates getState();
	void setState(CharacterStates newBirdState);

private:
	CharacterInjuries character_injuries;
	CharacterStates character_state;
};