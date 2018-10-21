#pragma once

#include <string>
#include "GameConstants.h"
#include "GameStates.h"
using namespace std;

struct GameProgress
{
	//Game Location Tracking
	static int level;
	static int zone;
	static int state;

	//Player Progress Tracking
	static string gameData[(int)GameConstants::MAX_GAMEDATA_SPACE];

	//Game System Progress Tracking
	static GameState gameState;
};