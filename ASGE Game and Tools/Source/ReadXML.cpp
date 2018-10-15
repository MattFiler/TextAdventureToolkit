#include "ReadXML.h"

using namespace rapidxml;
using namespace std;

/* Load the XML file into "doc" */
void ReadXML::loadXML() {
	xml_document<> doc;
	ifstream file("..\\..\\Resources\\Builds\\Debug (x86)\\Resources\\demo.xml"); //might need full filepath, not sure why active directory is wrong. debugging?

	stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	string content(buffer.str());
	string CONTENT = &content[0];
	doc.parse<parse_full>(&content[0]);
}

/* Load levels into array */
void ReadXML::loadLevels() {

}

/* Load zones into array */
void ReadXML::loadZones() {
	/*
	xml_node<> *node = doc.first_node("Behavior")->first_node("Node")->first_node("Connector")->first_node("Node")->first_node("Connector");
	for (xml_node<> *child = node->first_node(); child; child = child->next_sibling()) {
		string TEST = child->first_attribute()->value();
		string TEST2 = child->first_attribute("ZoneName")->value();
		string breakpoint;
	}
	*/
}
