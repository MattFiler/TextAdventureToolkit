#pragma once

#include <string>
using namespace std;

struct GameProgress
{
	static int current_level;
	static int current_zone;
	static int current_state;

	static string inventory[];
};