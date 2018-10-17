#pragma once

#include "../Libs/nlohmann/json.hpp"
#include <fstream>
#include <string>

#include "GameProgress.h"

using json = nlohmann::json;
using namespace std;

class ReadJSON {
public:
	string loadTextAdventure();
	
	int levelsInThisGame();
	int zonesInThisLevel(int level_id);
	int statesInThisZone(int level_id, int zone_id);

	string handleUserInput(string input);

private:
	string gameIntroText();

	string interpretAction(string input);
	string interpretSubject(string input);
	string checkForReferencedAction(string action);

	bool isActionPermitted(string action);
	bool isSubjectValid(string action, string subject);

	void testing();

	json TextAdventure;
	GameProgress TextAdventure_Progress;

	bool thisActionWasReferenced = false;
	string actionReferencedFrom = "";
};