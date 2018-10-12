#include "AngryLevels.h"

/* Load levels for class declaration. */
void LevelSetups::loadLevels()
{
	for (int i = 0; i < (int)GameVars::NUMBER_OF_LEVELS; i++)
	{
		//Load level file
		std::string line;
		std::ifstream level_read(".\\Resources\\LEVELS\\" + std::to_string(i) + ".level");

		//Split data into level array
		int x = 0;
		while (getline(level_read, line))
		{
			int v = 0;
			for (int p = 0; p < line.size(); p++)
			{
				if (line.at(p) != ',')
				{
					level_build[i][x][v] += line.at(p);
				}
				else
				{
					v++;
				}
			}
			x++;
		}

		//Close level file
		level_read.close();
	}
}

/* Return the name of a specific level. */
std::string LevelSetups::getLevelName(int level)
{
	return level_build[level][0][0];
}

/* Return the score threshold (1,2,3) for a level. */
float LevelSetups::getScoreThreshold(int level, int boundary)
{
	return std::stof(level_build[level][0][boundary]);
}

/* Generate levels when selected. */
void LevelSetups::GenerateLevel(int level) {
	for (int i = 1; i <= (int)GameVars::NUMBER_OF_LEVEL_ENTITIES; i++)
	{
		if (level_build[level][i][0] != "--") //"--" is level editor default for no entity.
		{
			placeComponent(level_build[level][i][0], level_build[level][i][1], level_build[level][i][2], level_build[level][i][3]);
		}
		else
		{
			break;
		}
	}
}

/* Reset all objects in the level. */
void LevelSetups::ResetLevel() 
{
	for (int i = 0; i < (int)GameVars::NUMBER_OF_BLOCKS_PER_VARIATION; i++)
	{
		/* Wood Blocks */
		sprites.wood_rectangle_long[i].despawn();
		sprites.wood_rectangle_tall[i].despawn();
		sprites.wood_square[i].despawn();

		/* Ice Blocks */
		sprites.ice_rectangle_long[i].despawn();
		sprites.ice_rectangle_tall[i].despawn();
		sprites.ice_square[i].despawn();

		/* Rock Blocks */
		sprites.rock_rectangle_long[i].despawn();
		sprites.rock_rectangle_tall[i].despawn();
		sprites.rock_square[i].despawn();
	}

	for (int i = 0; i < (int)GameVars::NUMBER_OF_PIGS; i++)
	{
		/* Pigs */
		sprites.pigs[i].despawn();
	}

	for (int i = 0; i < (((int)GameVars::NUMBER_OF_BLOCK_VARIATIONS * 3) + 1); i++)
	{
		/* Entity Count */
		entity_count[i] = 0;
	}
}

/* Get sprite for requested level component. */
void LevelSetups::placeComponent(std::string requested_sprite, std::string x_position, std::string y_position, std::string scale)
{
	if (requested_sprite == "PIG") 
	{
		placePig(getSpriteForCharacter(requested_sprite), std::stof(x_position), std::stof(y_position));
	}
	else
	{
		placeBlock(getSpriteForBlock(requested_sprite), std::stof(x_position), std::stof(y_position), std::stof(scale), DestructionStates::DEFAULT);
	}
}
EnvironmentBlock& LevelSetups::getSpriteForBlock(std::string requested_sprite) 
{
	/* Wood Blocks */
	if (requested_sprite == "WOOD_RECTANGLE_LONG")
	{
		entity_count[0]++;
		return sprites.wood_rectangle_long[entity_count[0]];
	}
	else if (requested_sprite == "WOOD_RECTANGLE_TALL")
	{
		entity_count[1]++;
		return sprites.wood_rectangle_tall[entity_count[1]];
	}
	else if (requested_sprite == "WOOD_SQUARE")
	{
		entity_count[2]++;
		return sprites.wood_square[entity_count[2]];
	}

	/* Ice Blocks */
	else if (requested_sprite == "ICE_RECTANGLE_LONG")
	{
		entity_count[3]++;
		return sprites.ice_rectangle_long[entity_count[3]];
	}
	else if (requested_sprite == "ICE_RECTANGLE_TALL")
	{
		entity_count[4]++;
		return sprites.ice_rectangle_tall[entity_count[4]];
	}
	else if (requested_sprite == "ICE_SQUARE")
	{
		entity_count[5]++;
		return sprites.ice_square[entity_count[5]];
	}

	/* Rock Blocks */
	else if (requested_sprite == "ROCK_RECTANGLE_LONG")
	{
		entity_count[6]++;
		return sprites.rock_rectangle_long[entity_count[6]];
	}
	else if (requested_sprite == "ROCK_RECTANGLE_TALL")
	{
		entity_count[7]++;
		return sprites.rock_rectangle_tall[entity_count[7]];
	}
	else // Must be ROCK_SQUARE
	{
		entity_count[8]++;
		return sprites.rock_square[entity_count[8]];
	}
}
Character& LevelSetups::getSpriteForCharacter(std::string requested_sprite)
{
	/* Pig */
	entity_count[9]++;
	return sprites.pigs[entity_count[9]];
}

/* Place objects in the level. */
void LevelSetups::placeBlock(EnvironmentBlock& item, float x_pos, float y_pos, float scale, DestructionStates destruction)
{
	item.setX(x_pos);
	item.setY(y_pos);
	item.setScale(scale);
	item.setDestruction(destruction);
	item.spawn();
}
void LevelSetups::placePig(Character& item, float x_pos, float y_pos)
{
	item.setX(x_pos);
	item.setY(y_pos);
	item.setInjuryLevel(CharacterInjuries::FEELIN_FINE);
	item.spawn();
}