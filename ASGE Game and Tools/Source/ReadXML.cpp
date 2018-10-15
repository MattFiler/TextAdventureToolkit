#include "ReadXML.h"

/*
	This all needs a big 'ol refactor... but it's a work in progress :)
*/

/* Public init */
void ReadXML::init() {
	loadXML();
}

/* Load the XML file */
void ReadXML::loadXML() {
	ifstream file("H:\\Personal\\GITHUB\\TextAdventure\\ASGE Game and Tools\\Builds\\Debug (x86)\\Resources\\deom2.xml"); //might need full filepath, not sure why active directory is wrong. debugging?

	stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	string content(buffer.str());
	string CONTENT = &content[0];
	doc.parse<parse_full>(&content[0]);

	loadLevels();
}

/* Load levels */
void ReadXML::loadLevels() {
	xml_node<> *node = doc.first_node("Behavior")->first_node("Node")->first_node("Connector");
	for (xml_node<> *levelNode = node->first_node(); levelNode; levelNode = levelNode->next_sibling()) {
		loadZones(levelNode);
	}
}

/* Load zones */
void ReadXML::loadZones(xml_node<> *levelNode) {
	levelNode = levelNode->first_node("Connector");
	for (xml_node<> *zoneNode = levelNode->first_node(); zoneNode; zoneNode = zoneNode->next_sibling()) {
		loadStates(zoneNode);
	}
}

/* Load states */
void ReadXML::loadStates(xml_node<> *zoneNode) {
	zoneNode = zoneNode->first_node("Connector");
	for (xml_node<> *stateNode = zoneNode->first_node(); stateNode; stateNode = stateNode->next_sibling()) {
		loadStateChildren(stateNode);
	}
}

/* Load zone responses */
void ReadXML::loadStateChildren(xml_node<> *stateNode) {
	stateNode = stateNode->first_node("Connector");
	for (xml_node<> *stateChildNode = stateNode->first_node(); stateChildNode; stateChildNode = stateChildNode->next_sibling()) {
		string nodeType = stateChildNode->first_attribute("Class")->value();
		if (nodeType == "TextAdventure.Nodes.UserInput") {
			//Handle user input
			string nodeType = stateChildNode->first_attribute("InputCommand")->value();
			string breakpoint_here_pls;
		}
		else if (nodeType == "TextAdventure.Nodes.ZoneIntro") {
			//Handle zone intro text
		}
	}
}