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
	void traverseNodes();

	void loadStateChildren(xml_node<> *stateNode);

	xml_document<> doc;
};