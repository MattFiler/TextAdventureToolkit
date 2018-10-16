#pragma once

#include "../Libs/nlohmann/json.hpp"
#include <fstream>
#include <string>

using json = nlohmann::json;
using namespace std;

class ReadJSON {
public:
	void init();

private:
	void loadJSON();
};