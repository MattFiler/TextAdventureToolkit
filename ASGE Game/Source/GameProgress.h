#pragma once

#include <string>
#include "GameConstants.h"
using namespace std;

struct GameProgress
{
	static int level;
	static int zone;
	static int state;

	static string inventory[(int)GameConstants::MAX_INVENTORY_SPACE];
};