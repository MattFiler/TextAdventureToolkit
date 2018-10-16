#pragma once

#include "../Libs/nlohmann/json.hpp"
#include <fstream>
#include <string>

using json = nlohmann::json;
using namespace std;

class ReadJSON {
public:
	void loadTextAdventure();
	
	int levelsInThisGame();
	int zonesInThisLevel(int level_id);
	int statesInThisZone(int level_id, int zone_id);

	string interpretAction(string input);

	bool isActionPermitted(string action, int level_id, int zone_id, int state_id);

private:
	void testing();

	json TextAdventure;
};