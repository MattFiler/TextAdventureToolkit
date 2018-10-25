#include "GameScreenText.h"

string GameScreenText::gameTitle = "";
string GameScreenText::gameDeveloper = "";

//We have two variants of each game output - OnScreen is the visible output, and the original is the desired result.
//When animating the "typing effect", we may not see the desired result on screen, rather an unfinished half-typed version.
string GameScreenText::locationIntro = "";
string GameScreenText::locationIntroOnScreen = "";
string GameScreenText::inputResponse = "";
string GameScreenText::inputResponseOnScreen = "";

string GameScreenText::userInput = "";