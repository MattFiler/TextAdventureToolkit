#pragma once

#include <string>
#include "GameConstants.h"

using namespace std;

class Animations {
public:
	bool animateText(float dt_sec, string originalText, string &outputText);

private:
	float timePreviouslyAnimated = 0;
	float totalGameTime = 0;
	string previousGoalText = "";
};