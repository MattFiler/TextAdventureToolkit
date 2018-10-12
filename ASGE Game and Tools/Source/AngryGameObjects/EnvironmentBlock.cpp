#include <Engine\Renderer.h>
#include "EnvironmentBlock.h"


/*
	-- DESTRUCTION --
*/

/* Get/Set Destruction State */
DestructionStates EnvironmentBlock::getDestruction()
{
	return destruction_state;
}
void EnvironmentBlock::setDestruction(DestructionStates state)
{
	destruction_state = state;
	setCurrentFrame((int)destruction_state);
}

/* Deal Damage To Block */
bool EnvironmentBlock::doDamage()
{
	switch (block_type) 
	{
		case BlockTypes::ICE: 
		{
			return blockDamage("ICE", DestructionStates::ICE_DAMAGE_PER_HIT);
			break;
		}
		case BlockTypes::ROCK: 
		{
			return blockDamage("ROCK", DestructionStates::ROCK_DAMAGE_PER_HIT);
			break;
		}
		case BlockTypes::WOOD: 
		{
			return blockDamage("WOOD", DestructionStates::WOOD_DAMAGE_PER_HIT);
			break;
		}
	}
}
bool EnvironmentBlock::blockDamage(std::string block_name, DestructionStates add_damage)
{
	if (((int)destruction_state + (int)add_damage) > (int)DestructionStates::DESTRUCTION_COUNT - 1)
	{
		//Block is destroyed
		sound_engine->play2D(("Resources\\ENVIRONMENT\\BLOCKS\\" + block_name + "\\SFX\\1.mp3").c_str(), false);
		despawn();
		return false;
	}
	else
	{
		//Deal damage
		sound_engine->play2D(("Resources\\ENVIRONMENT\\BLOCKS\\" + block_name + "\\SFX\\0.mp3").c_str(), false);
		setDestruction((DestructionStates)((int)destruction_state + (int)add_damage));
		return true;
	}
}


/*
	-- BLOCK TYPE --
*/

/* Get/Set Block Type */
BlockTypes EnvironmentBlock::getBlockType()
{
	return block_type;
}
void EnvironmentBlock::setBlockType(BlockTypes blocktype)
{
	block_type = blocktype;
}