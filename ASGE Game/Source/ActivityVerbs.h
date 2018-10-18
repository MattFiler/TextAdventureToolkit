#pragma once

#include <string>
using namespace std;

struct ActionList
{
	const string actionInput[8] = { "LOOK AROUND", "LOOK AT", "GO TO", "GET OUT", "EXIT", "USE", "OPEN", "READ" };
	const string actionCommand[8] = { "LOOK_AROUND", "LOOK_AT", "GO_TO", "GET_OUT", "EXIT", "USE", "OPEN", "READ" };
};