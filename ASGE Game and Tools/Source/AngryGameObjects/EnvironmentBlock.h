#pragma once
#include "GameObject.h"
#include "../AngryEnums/AngryDestructionStates.h"
#include "../AngryEnums/AngryBlockTypes.h"

class EnvironmentBlock : public GameObject<(int)DestructionStates::DESTRUCTION_COUNT>
{
public:
	DestructionStates getDestruction();
	void setDestruction(DestructionStates state);
	bool doDamage();

	BlockTypes getBlockType();
	void setBlockType(BlockTypes blocktype);

private:
	bool blockDamage(std::string block_name, DestructionStates add_damage);

	DestructionStates destruction_state = DestructionStates::DEFAULT;
	BlockTypes block_type;
};