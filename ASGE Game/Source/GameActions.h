#pragma once

#include <string>
#include "GameConstants.h"
using namespace std;

struct GameActions
{
	const string input[(int)GameConstants::NUMBER_OF_COMMANDS] = { "LOOK AROUND", "LOOK AT", "GO TO", "GET OUT", "EXIT", "USE", "OPEN", "READ" };
	const string command[(int)GameConstants::NUMBER_OF_COMMANDS] = { "LOOK_AROUND", "LOOK_AT", "GO_TO", "GET_OUT", "EXIT", "USE", "OPEN", "READ" };
};