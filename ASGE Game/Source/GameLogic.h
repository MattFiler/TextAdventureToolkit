#pragma once

#include "../Libs/nlohmann/json.hpp"
#include <fstream>
#include <string>

#include "GameProgress.h"
#include "GameConstants.h"
#include "GameScreenText.h"
#include "GameDataType.h"

using json = nlohmann::json;
using namespace std;

class TextAdventureLogic
{
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
	void parseInput(string input);

	string getZoneIntro();

	string interpretAction(string input);
	string interpretSubject(string input, string tempAction="");
	string checkForReferencedAction(string action, string tempSubject="");

	string getInvalidInputResponse();
	string getErrorResponse();
	int getNumberOfActionTypes();
	string getActionText(int index);

	void performCurrentAction();

	bool isCurrentActionValid();
	bool isCurrentSubjectValid();
	bool isItemInGameData(string item);

	void handleGameData(bool shouldAdd=true);
	gameDataType gameDataExistsForCurrentAction(gameDataType type);

	void moveToState(string name);
	void moveToZone(string name);
	void moveToLevel(string name);

	int findStateByName(string name);
	int findZoneByName(string name);
	int findLevelByName(string name);

	//Instances
	json logic;
	GameProgress progress;
	GameScreenText screenText;

	//Check for action referencing
	bool thisActionWasReferenced = false;
	string actionReferencedFrom = "";
	string referencedSubject = "";

	//Parsed Input
	string currentAction = "";
	string currentSubject = "";
};