#pragma once

#include <string>
#include "GameConstants.h"
using namespace std;

struct GameProgress
{
	//Game Location Tracking
	static int level;
	static int zone;
	static int state;

	//Player Progress Tracking
	static string inventory[(int)GameConstants::MAX_INVENTORY_SPACE];

	//Game System Progress Tracking
	static bool textIsAnimating;
};