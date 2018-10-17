#include "ReadJSON.h"

/* Read in the text adventure from a JSON file */
void ReadJSON::loadTextAdventure() {
	ifstream ReadXML("C:\\Users\\mattf\\OneDrive\\Github Repos\\TextAdventure\\ASGE Game and Tools\\Builds\\Debug (x86)\\Resources\\demo.json");
	ReadXML >> TextAdventure;
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

/* Interpret the user's input action */
string ReadJSON::interpretAction(string input) {
	if (input.substr(0, 11) == "LOOK AROUND") {
		return "LOOK_AROUND";
	}
	else if (input.substr(0, 4) == "LOOK") {
		return "LOOK_AT";
	}
	else if (input.substr(0, 2) == "GO") {
		return "GO_TO";
	}
	else if (input.substr(0, 7) == "GET OUT" || input.substr(0, 4) == "EXIT") {
		return "GET_OUT";
	}
	else if (input.substr(0, 3) == "USE") {
		return "USE";
	}
	else if (input.substr(0, 4) == "OPEN") {
		return "OPEN";
	}
	else if (input.substr(0, 4) == "READ") {
		return "READ";
	}
}

/* Verify if an action is permitted in this location */
bool ReadJSON::isActionPermitted(string action, int level_id, int zone_id, int state_id) {
	return !TextAdventure[to_string(level_id)][to_string(zone_id)][to_string(state_id)][action].is_null();
}

/* Handle response of action */
string ReadJSON::handleActionResponse(string action, int level_id, int zone_id, int state_id) {
	//VERY BASIC FOR NOW AND WILL ERROR ON SOME, BUT JUST TO TEST...
	return TextAdventure[to_string(level_id)][to_string(zone_id)][to_string(state_id)][action]["system_reply"];
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