#include "GameLogic.h"

/* 
------
PUBLIC 
------
*/

/* Read in the text adventure from a JSON file */
void TextAdventureLogic::loadTextAdventure() 
{
	auto file = ASGE::FILEIO::File();
	file.open("/data/story.json");
	auto buffer = file.read();
	stringstream(string(buffer.as_char(), buffer.length)) >> logic;

	screenText.gameTitle = getGameTitle();
	screenText.gameDeveloper = getGameDeveloper();
	screenText.locationIntro = getZoneIntro();
}

/* Return the number of levels */
int TextAdventureLogic::levelsInThisGame() 
{
	return logic.size() - 1; //-1 to account for game_core
}
/* Return the number of zones per level */
int TextAdventureLogic::zonesInThisLevel(int level_id)
{
	return logic[to_string(level_id)].size() - 1; //-1 to account for level_name
}
/* Return the number of states per zone */
int TextAdventureLogic::statesInThisZone(int level_id, int zone_id) 
{
	return logic[to_string(level_id)][to_string(zone_id)].size() - 1; //-1 to account for zone_name
}

/* Get the game's title */
string TextAdventureLogic::getGameTitle()
{
	return logic["game_core"]["title"];
}
/* Get the game's developer */
string TextAdventureLogic::getGameDeveloper() 
{
	return logic["game_core"]["developer"];
}
/* Get the game's disabled input text */
string TextAdventureLogic::getInputDisabledText()
{
	return logic["game_core"]["input_disabled"];
}

/* Handle response of action */
void TextAdventureLogic::handleUserInput(string input) 
{
	parseInput(input);

	if (isCurrentActionValid() && isCurrentSubjectValid())
	{
		auto actionGroup = logic[to_string(progress.level)][to_string(progress.zone)][to_string(progress.state)][currentAction][currentSubject];
		gameDataType requiredData = gameDataExistsForCurrentAction(gameDataType::REQUIRED_DATA);
		gameDataType optionalData = gameDataExistsForCurrentAction(gameDataType::OPTIONAL_DATA);

		if (requiredData != gameDataType::DATA_DOES_NOT_EXIST && optionalData != gameDataType::DATA_DOES_NOT_EXIST)
		{
			if (actionGroup["system_reply_ok"].is_string()) 
			{
				screenText.inputResponse = actionGroup["system_reply_ok"];
			}
			else
			{
				screenText.inputResponse = getErrorResponse();
			}
		}
		else
		{
			if (actionGroup["system_reply_issue"].is_string())
			{
				screenText.inputResponse = actionGroup["system_reply_issue"];
			}
			else
			{
				screenText.inputResponse = getErrorResponse();
			}
		}

		if (requiredData != gameDataType::DATA_DOES_NOT_EXIST)
		{
			performCurrentAction();
			handleGameData();
		}
	}
	else
	{
		screenText.inputResponse = getInvalidInputResponse();
	}
}

/*
-------
PRIVATE
-------
*/

void TextAdventureLogic::parseInput(string input) {
	currentAction = "";
	currentSubject = "";
	thisActionWasReferenced = false;

	currentAction = interpretAction(input);
	currentSubject = interpretSubject(input);
}

/* Show the game intro text */
string TextAdventureLogic::getZoneIntro() 
{
	return logic[to_string(progress.level)][to_string(progress.zone)][to_string(progress.state)]["zone_intro"];
}

/* Interpret the user's input action */
string TextAdventureLogic::interpretAction(string input)
{
	string actionProcessing = "";
	string actionToReturn = "";
	int actionLength = 0;
	for (int i = 0; i < getNumberOfActionTypes(); i++)
	{
		if (input.substr(0, getActionText(i).length()) == getActionText(i))
		{
			actionProcessing = checkForReferencedAction(getActionText(i), interpretSubject(input, getActionText(i)));
			actionLength = actionProcessing.length();
			if (actionToReturn.length() < actionLength) {
				actionToReturn = actionProcessing;
			}
		}
	}
	if (actionToReturn == "")
	{
		actionToReturn == "BAD_COMMAND";
	}
	return actionToReturn;
}

/* Check for a referenced action */
string TextAdventureLogic::checkForReferencedAction(string action, string tempSubject)
{
	if (currentSubject != "") 
	{
		tempSubject = currentSubject;
	}
	auto referencedScript = logic[to_string(progress.level)][to_string(progress.zone)][to_string(progress.state)][action][tempSubject]["referenced"];

	if (referencedScript.is_array())
	{
		thisActionWasReferenced = true;
		actionReferencedFrom = action;
		referencedSubject = referencedScript[1];
		return referencedScript[0];
	}
	else
	{
		thisActionWasReferenced = false;
		return action;
	}
}

/* Get the text to respond to an invalid input with */
string TextAdventureLogic::getInvalidInputResponse() 
{
	return logic["game_core"]["invalid_input"];
}

/* Get the text to respond to an invalid input with */
string TextAdventureLogic::getErrorResponse()
{
	return logic["game_core"]["fatal_error"];
}

/* Get the number of prefixes available in the game */
int TextAdventureLogic::getNumberOfActionTypes()
{
	return logic["game_core"]["prefixes"].size();
}

/* Get the input text for an action */
string TextAdventureLogic::getActionText(int index)
{
	return logic["game_core"]["prefixes"][index];
}

/* Verify if an action is permitted in this location */
bool TextAdventureLogic::isCurrentActionValid()
{
	if (logic[to_string(progress.level)][to_string(progress.zone)][to_string(progress.state)][currentAction].size() > 0) 
	{
		return true;
	}
	else
	{
		return false;
	}
}

/* Verify if a subject is permitted for this action */
bool TextAdventureLogic::isCurrentSubjectValid()
{
	if (logic[to_string(progress.level)][to_string(progress.zone)][to_string(progress.state)][currentAction][currentSubject].size() > 1) 
	{
		return true;
	}
	else
	{
		return false;
	}
}

/* Perform action when we are permitted to do so */
void TextAdventureLogic::performCurrentAction()
{
	auto actionLogic = logic[to_string(progress.level)][to_string(progress.zone)][to_string(progress.state)][currentAction][currentSubject];

	if (actionLogic["new_state"].is_string())
	{
		moveToState(actionLogic["new_state"]);
	}
	if (actionLogic["new_zone"].is_string())
	{
		moveToZone(actionLogic["new_zone"]);
	}
	if (actionLogic["new_level"].is_string())
	{
		moveToLevel(actionLogic["new_level"]);
	}
	if (actionLogic["game_over"].is_string())
	{
		gameOver(actionLogic["game_over"]);
	}
}

/* Interpret the user's input subject */
string TextAdventureLogic::interpretSubject(string input, string tempAction)
{
	if (currentAction != "") 
	{
		tempAction = currentAction;
	}
	if (thisActionWasReferenced) 
	{
		return referencedSubject;
	}
	if (tempAction == "") 
	{
		return "";
	}
	try {
		for (int i = 0; i < getNumberOfActionTypes(); i++)
		{
			if (tempAction == getActionText(i))
			{
				return input.substr(getActionText(i).length() + 1);
			}
		}
	}
	catch (...) {
		return ""; //No subject specified, might not be a big deal... we'll check that next.
	}
	return "";
}

/* Add items to game memory when requested */
void TextAdventureLogic::handleGameData(bool shouldAdd)
{
	string jsonString = "add_gamedata";
	if (!shouldAdd) 
	{
		jsonString = "remove_gamedata";
	}
	auto gameData = logic[to_string(progress.level)][to_string(progress.zone)][to_string(progress.state)][currentAction][currentSubject][jsonString];

	if (gameData.is_array())
	{
		for (int i = 0; i < gameData.size(); i++)
		{
			if (!isItemInGameData(gameData[i]))
			{
				for (int x = 0; x < (int)GameConstants::MAX_GAMEDATA_SPACE; x++)
				{
					if (progress.gameData[x] == "")
					{
						progress.gameData[x] = gameData[i];
						break;
					}
				}
			}
			else
			{
				if (!shouldAdd) 
				{
					for (int x = 0; x < (int)GameConstants::MAX_GAMEDATA_SPACE; x++)
					{
						if (progress.gameData[x] == gameData[i])
						{
							progress.gameData[x] = "";
							break;
						}
					}
				}
			}
		}
	}
}

/* Check if an item is in the game memory */
bool TextAdventureLogic::isItemInGameData(string item)
{
	for (int i = 0; i < (int)GameConstants::MAX_GAMEDATA_SPACE; i++)
	{
		if (item == progress.gameData[i])
		{
			return true;
		}
	}
	return false;
}

/* Check required/optional items for action are in memory */
gameDataType TextAdventureLogic::gameDataExistsForCurrentAction(gameDataType type)
{
	auto requestedData = logic[to_string(progress.level)][to_string(progress.zone)][to_string(progress.state)][currentAction][currentSubject]["optional_gamedata"];
	if (type == gameDataType::REQUIRED_DATA) {
		requestedData = logic[to_string(progress.level)][to_string(progress.zone)][to_string(progress.state)][currentAction][currentSubject]["required_gamedata"];
	}

	if (requestedData.is_array()) 
	{
		for (int i = 0; i < requestedData.size(); i++)
		{
			if (!isItemInGameData(requestedData[i]))
			{
				return gameDataType::DATA_DOES_NOT_EXIST;
			}
		}
	}
	else
	{
		return gameDataType::DATA_IS_NOT_SPECIFIED;
	}
	return gameDataType::DATA_EXISTS;
}

/* Find zone by name and move to it */
void TextAdventureLogic::moveToState(string name)
{
	progress.state = findStateByName(name);
	screenText.locationIntro = getZoneIntro();
}

/* Find zone by name and move to it */
void TextAdventureLogic::moveToZone(string name)
{
	progress.zone = findZoneByName(name);
	progress.state = 0;
	screenText.locationIntro = getZoneIntro();
}

/* Find zone by name and move to it */
void TextAdventureLogic::moveToLevel(string name)
{
	progress.level = findLevelByName(name);
	progress.zone = 0;
	progress.state = 0;
	screenText.locationIntro = getZoneIntro();
}

/* Game over (won/lost?) */
void TextAdventureLogic::gameOver(string winState)
{
	if (winState == "WIN")
	{
		progress.gameState = GameState::DID_WIN;
	}
	else if (winState == "LOSE")
	{
		progress.gameState = GameState::DID_LOSE;
	}
}

/* Find state ID by name in current zone */
int TextAdventureLogic::findStateByName(string name) {
	for (int i = 0; i < statesInThisZone(progress.level, progress.zone); i++)
	{
		if (logic[to_string(progress.level)][to_string(progress.zone)][to_string(i)]["state_name"] == name)
		{
			return i;
		}
	}
	return 99;
}

/* Find zone ID by name in current level */
int TextAdventureLogic::findZoneByName(string name) {
	for (int i = 0; i < zonesInThisLevel(progress.level); i++)
	{
		if (logic[to_string(progress.level)][to_string(i)]["zone_name"] == name)
		{
			return i;
		}
	}
    return 99;
}

/* Find level ID by name */
int TextAdventureLogic::findLevelByName(string name) {
	for (int i = 0; i < levelsInThisGame(); i++)
	{
		if (logic[to_string(i)]["level_name"] == name)
		{
			return i;
		}
	}
    return 99;
}