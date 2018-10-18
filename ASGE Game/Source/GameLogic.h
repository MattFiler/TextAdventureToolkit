#pragma once

#include "../Libs/nlohmann/json.hpp"
#include <fstream>
#include <string>

#include "GameProgress.h"
#include "GameConstants.h"
#include "GameActions.h"
#include "GameScreenText.h"

using json = nlohmann::json;
using namespace std;

class TextAdventureLogic {
public:
	void loadTextAdventure();
	
	int levelsInThisGame();
	int zonesInThisLevel(int level_id);
	int statesInThisZone(int level_id, int zone_id);

	string getGameTitle();
	string getGameDeveloper();
	string getInputDisabledText();

	void handleUserInput(string input);

private:
	string getZoneIntro();

	string interpretAction(string input);
	string interpretSubject(string input);
	string checkForReferencedAction(string action);

	string getInvalidInputResponse();
	string getInvalidInventoryResponse();

	void performAction(string action, string subject);

	bool isActionPermitted(string action);
	bool isSubjectValid(string action, string subject);
	bool isItemInInventory(string item);

	void handleInventory(string action);
	bool requiredItemsAreInInventory(string action);

	void moveToZone(string name);

	json logic;
	GameProgress progress;
	GameActions gameAction;
	GameScreenText screenText;

	bool thisActionWasReferenced = false;
	string actionReferencedFrom = "";
};