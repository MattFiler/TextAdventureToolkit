#include "ReadJSON.h"

/* 
------
PUBLIC 
------
*/

/* Read in the text adventure from a JSON file */
string ReadJSON::loadTextAdventure() {
	ifstream ReadXML("C:\\Users\\mattf\\OneDrive\\Github Repos\\TextAdventure\\ASGE Game and Tools\\Builds\\Debug (x86)\\Resources\\demo.json");
	ReadXML >> TextAdventure;

	return zoneIntro();
}

/* Return the number of levels */
int ReadJSON::levelsInThisGame() {
	return TextAdventure.size();
}
/* Return the number of zones per level */
int ReadJSON::zonesInThisLevel(int level_id) {
	return TextAdventure[to_string(level_id)].size();
}
/* Return the number of states per zone */
int ReadJSON::statesInThisZone(int level_id, int zone_id) {
	return TextAdventure[to_string(level_id)][to_string(zone_id)].size() - 1;
}

/* Handle response of action */
string ReadJSON::handleUserInput(string input) {
	string action = interpretAction(input);
	string subject = interpretSubject(input);

	if (isActionPermitted(action) && isSubjectValid(action, subject)) {
		string response = TextAdventure[to_string(TextAdventure_Progress.current_level)][to_string(TextAdventure_Progress.current_zone)][to_string(TextAdventure_Progress.current_state)][action]["system_reply"];
		performAction(action, subject);
		return response;
	}
	else
	{
		return "I'm sorry, I don't understand.";
	}
}

/*
-------
PRIVATE
-------
*/

/* Show the game intro text */
string ReadJSON::zoneIntro() {
	return TextAdventure[to_string(TextAdventure_Progress.current_level)][to_string(TextAdventure_Progress.current_zone)][to_string(TextAdventure_Progress.current_state)]["zone_intro"];
}

/* Interpret the user's input action */
string ReadJSON::interpretAction(string input) {
	string action = "";
	if (input.substr(0, 11) == "LOOK AROUND") {
		action = checkForReferencedAction("LOOK_AROUND");
	}
	else if (input.substr(0, 7) == "LOOK AT") {
		action = checkForReferencedAction("LOOK_AT");
	}
	else if (input.substr(0, 5) == "GO TO") {
		action = checkForReferencedAction("GO_TO");
	}
	else if (input.substr(0, 7) == "GET OUT") {
		action = checkForReferencedAction("GET_OUT");
	}
	else if (input.substr(0, 4) == "EXIT") {
		action = checkForReferencedAction("EXIT");
	}
	else if (input.substr(0, 3) == "USE") {
		action = checkForReferencedAction("USE");
	}
	else if (input.substr(0, 4) == "OPEN") {
		action = checkForReferencedAction("OPEN");
	}
	else if (input.substr(0, 4) == "READ") {
		action = checkForReferencedAction("READ");
	}
	else {
		return "BAD_COMMAND";
	}
	return action;
}

/* Check for a referenced action */
string ReadJSON::checkForReferencedAction(string action) {
	if (!TextAdventure[to_string(TextAdventure_Progress.current_level)][to_string(TextAdventure_Progress.current_zone)][to_string(TextAdventure_Progress.current_state)][action]["referenced"].is_null()) {
		thisActionWasReferenced = true;
		actionReferencedFrom = action;
		return TextAdventure[to_string(TextAdventure_Progress.current_level)][to_string(TextAdventure_Progress.current_zone)][to_string(TextAdventure_Progress.current_state)][action]["referenced"];
	}
	else
	{
		thisActionWasReferenced = false;
		return action;
	}
}

/* Verify if an action is permitted in this location */
bool ReadJSON::isActionPermitted(string action) {
	return !TextAdventure[to_string(TextAdventure_Progress.current_level)][to_string(TextAdventure_Progress.current_zone)][to_string(TextAdventure_Progress.current_state)][action].is_null();
}

/* Perform action */
void ReadJSON::performAction(string action, string subject) {
	if (action == "GET_OUT" || action == "EXIT") {
		TextAdventure_Progress.current_zone++;
	}
	else if (action == "GO_TO") {
		TextAdventure_Progress.current_zone = 0; //will want to grab zone id here from name (move_to)
	}
}

/* Interpret the user's input subject */
string ReadJSON::interpretSubject(string input) {
	string action = interpretAction(input);
	if (thisActionWasReferenced) {
		action = actionReferencedFrom;
	}
	if (isActionPermitted(action)) {
		try {
			if (action == "LOOK_AROUND") {
				return input.substr(12);
			}
			else if (action == "LOOK_AT") {
				return input.substr(8);
			}
			else if (action == "GO_TO") {
				return input.substr(6);
			}
			else if (action == "GET_OUT") {
				return input.substr(8);
			}
			else if (action == "EXIT") {
				return input.substr(5);
			}
			else if (action == "USE") {
				return input.substr(4);
			}
			else if (action == "OPEN") {
				return input.substr(5);
			}
			else if (action == "READ") {
				return input.substr(5);
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
bool ReadJSON::isSubjectValid(string action, string subject) {
	auto requiredSubject = TextAdventure[to_string(TextAdventure_Progress.current_level)][to_string(TextAdventure_Progress.current_zone)][to_string(TextAdventure_Progress.current_state)][action]["subject"];

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

/////////////////////////////////////////////////////////////////////////

/* Misc tests (PRIVATE) */
void ReadJSON::testing() {
	/*
	auto testing = j.size();
	string test = j["0"]["0"]["0"]["LOOK_AT"]["system_reply"];
	string sdfsdf;

	for (int i = 0; i < j.size(); i++) {
		//LEVEL
		for (int x = 0; x < j[to_string(i)].size(); x++) {
			//ZONE
			for (int y = 0; y < j[to_string(x)].size(); y++) {
				//STATE
			}
		}
	}
	*/
}