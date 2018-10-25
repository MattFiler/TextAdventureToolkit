#pragma once

#include <string>
using namespace std;

struct GameScreenText
{
	//Top screen
	static string gameTitle;
	static string gameDeveloper;

	//Main dynamic scripted content
	static string locationIntro;
	static string locationIntroOnScreen;
	static string inputResponse;
	static string inputResponseOnScreen;

	//User's input
	static string userInput;
};