#pragma once

#include <sstream>
#include <fstream>
#include "../Libs/RapidXML/rapidxml.hpp"
#include "../Libs/RapidXML/rapidxml_utils.hpp"

class ReadXML {
public:
	//Handle all public interactions with the XML here.

private:
	void loadXML();
	void loadLevels();
	void loadZones();

	//xml_document<> doc;
};