#include "GameLogic.h"

/* 
------
PUBLIC 
------
*/

/* Read in the text adventure from a JSON file */
void TextAdventureLogic::loadTextAdventure() {
	ifstream ReadXML("F:\\demo.json");
	ReadXML >> logic;

	screenText.gameTitle = getGameTitle();
	screenText.gameDeveloper = getGameDeveloper();
	screenText.locationIntro = getZoneIntro();
}

/* Return the number of levels */
int TextAdventureLogic::levelsInThisGame() {
	return logic.size()-1; //-1 to account for game_core
}
/* Return the number of zones per level */
int TextAdventureLogic::zonesInThisLevel(int level_id) {
	return logic[to_string(level_id)].size();
}
/* Return the number of states per zone */
int TextAdventureLogic::statesInThisZone(int level_id, int zone_id) {
	return logic[to_string(level_id)][to_string(zone_id)].size() - 1;
}

/* Get the game's title */
string TextAdventureLogic::getGameTitle() {
	return logic["game_core"]["title"];
}
/* Get the game's developer */
string TextAdventureLogic::getGameDeveloper() {
	return logic["game_core"]["developer"];
}

/* Handle response of action */
void TextAdventureLogic::handleUserInput(string input) {
	string action = interpretAction(input);
	string subject = interpretSubject(input);

	if (isActionPermitted(action) && isSubjectValid(action, subject)) {
		if (requiredItemsAreInInventory(action)) {
			string response = logic[to_string(progress.level)][to_string(progress.zone)][to_string(progress.state)][action]["system_reply"];
			performAction(action, subject);
			screenText.inputResponse = response;
		}
		else
		{
			screenText.inputResponse = getInvalidInventoryResponse();
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

/* Show the game intro text */
string TextAdventureLogic::getZoneIntro() {
	return logic[to_string(progress.level)][to_string(progress.zone)][to_string(progress.state)]["zone_intro"];
}

/* Interpret the user's input action */
string TextAdventureLogic::interpretAction(string input) {
	string action = "";
	for (int i = 0; i < (int)GameConstants::NUMBER_OF_COMMANDS; i++) {
		if (input.substr(0, gameAction.input[i].length()) == gameAction.input[i]) {
			action = checkForReferencedAction(gameAction.command[i]);
		}
	}
	if (action == "") {
		action == "BAD_COMMAND";
	}
	return action;
}

/* Check for a referenced action */
string TextAdventureLogic::checkForReferencedAction(string action) {
	if (!logic[to_string(progress.level)][to_string(progress.zone)][to_string(progress.state)][action]["referenced"].is_null()) {
		thisActionWasReferenced = true;
		actionReferencedFrom = action;
		return logic[to_string(progress.level)][to_string(progress.zone)][to_string(progress.state)][action]["referenced"];
	}
	else
	{
		thisActionWasReferenced = false;
		return action;
	}
}

/* Get the text to respond to an invalid input with */
string TextAdventureLogic::getInvalidInputResponse() {
	return logic["game_core"]["invalid_input"];
}

/* Get the text to respond to an invalid input with */
string TextAdventureLogic::getInvalidInventoryResponse() {
	return logic["game_core"]["items_are_required"];
}

/* Verify if an action is permitted in this location */
bool TextAdventureLogic::isActionPermitted(string action) {
	return !logic[to_string(progress.level)][to_string(progress.zone)][to_string(progress.state)][action].is_null();
}

/* Perform action */
void TextAdventureLogic::performAction(string action, string subject) {
	handleInventory(action);
	if (action == "GET_OUT" || action == "EXIT") {
		progress.zone++;
		screenText.locationIntro = getZoneIntro();
	}
	else if (action == "GO_TO") {
		progress.zone = 0; //will want to grab zone id here from name (move_to)
		screenText.locationIntro = getZoneIntro();
	}
}

/* Interpret the user's input subject */
string TextAdventureLogic::interpretSubject(string input) {
	string action = interpretAction(input);
	if (thisActionWasReferenced) {
		action = actionReferencedFrom;
	}
	if (isActionPermitted(action)) {
		try {
			for (int i = 0; i < (int)GameConstants::NUMBER_OF_COMMANDS; i++) {
				if (action == gameAction.command[i]) {
					return input.substr(gameAction.input[i].length() + 1);
				}
			}
		}
		catch (out_of_range& exception) {
			return ""; //No valid subject provided. This might still be ok.
		}
	}
	else
	{
		return "";
	}
}

/* Verify if an subject is permitted on this action */
bool TextAdventureLogic::isSubjectValid(string action, string subject) {
	auto requiredSubject = logic[to_string(progress.level)][to_string(progress.zone)][to_string(progress.state)][action]["subject"];

	if (requiredSubject.is_string()) {
		if (requiredSubject == subject) {
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return true;
	}
}

/* Check if an item is in the inventory */
bool TextAdventureLogic::isItemInInventory(string item) {
	for (int i = 0; i < (int)GameConstants::MAX_INVENTORY_SPACE; i++) {
		if (item == progress.inventory[i]) {
			return true;
		}
	}
	return false;
}

/* Add items to inventory when requested */
void TextAdventureLogic::handleInventory(string action) {
	auto inventoryAdd = logic[to_string(progress.level)][to_string(progress.zone)][to_string(progress.state)][action]["add_to_inventory"];
	if (inventoryAdd.is_array()) {
		for (int i = 0; i < inventoryAdd.size(); i++) {
			if (!isItemInInventory(inventoryAdd[i])) {
				for (int x = 0; x < (int)GameConstants::MAX_INVENTORY_SPACE; x++) {
					if (progress.inventory[x] == "") {
						progress.inventory[x] = inventoryAdd[i];
						break;
					}
				}
			}
		}
	}
}

/* Check required items for action are in the inventory */
bool TextAdventureLogic::requiredItemsAreInInventory(string action) {
	auto inventoryRequired = logic[to_string(progress.level)][to_string(progress.zone)][to_string(progress.state)][action]["required_inventory"];
	bool hasRequiredInventory = false;
	if (inventoryRequired.is_array()) {
		for (int x = 0; x < inventoryRequired.size(); x++) {
			hasRequiredInventory = isItemInInventory(inventoryRequired[x]);
			if (!hasRequiredInventory) {
				return false;
			}
		}
	}
	return true;
}