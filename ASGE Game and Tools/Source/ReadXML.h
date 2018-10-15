#pragma once

#include <sstream>
#include <fstream>
#include "../Libs/RapidXML/rapidxml.hpp"
#include "../Libs/RapidXML/rapidxml_utils.hpp"

using namespace rapidxml;
using namespace std;

class ReadXML {
public:
	void init();

private:
	void loadXML();
	void loadLevels();
	void loadZones(xml_node<> *levelNode);
	void loadStates(xml_node<> *zoneNode);
	void loadStateChildren(xml_node<> *stateNode);

	xml_document<> doc;
};