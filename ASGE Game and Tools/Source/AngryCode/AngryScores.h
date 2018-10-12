#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <Engine/OGLGame.h>

#include "../AngryStructs/AngryGamestateData.h"
#include "../AngryEnums/AngryGameVars.h"

class Scores {
public:
	void saveScores();
	void loadScores();

private:
	GamestateData gamestate;
};