#include "ReadJSON.h"

void ReadJSON::init() {
	loadJSON();
}

void ReadJSON::loadJSON() {
	ifstream i("H:\\Personal\\GITHUB\\TextAdventure\\ASGE Game and Tools\\Builds\\Debug (x86)\\Resources\\demo.json");
	json j;
	i >> j;
	int test = j["test"];
	string sdfsdf;
}