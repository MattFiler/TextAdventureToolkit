#pragma once
//#pragma comment(lib, "irrKlang.lib")

#include <Engine/OGLGame.h>
//#include <irrklang.h>
#include <string>

#include "GameConstants.h"
#include "SpriteComponent.h"

using namespace std;

class Animations 
{
public:
	Animations();
	~Animations();

	bool animateText(const ASGE::GameTime &time, string originalText, string &outputText);
	bool animateLoadingScreen(const ASGE::GameTime &time, SpriteComponent &red, SpriteComponent &blue, SpriteComponent &black);

private:
	float getCurrentGameTime(const ASGE::GameTime &time);
	float getCurrentDeltaTime(const ASGE::GameTime &time);

	//Animation data - won't all be used by some instances.
	float timePreviouslyAnimated = 0;
	float timeAnimationStarted = 0;
	string previousGoalText = "";

	//Sound engine
	//irrklang::ISoundEngine* sound_engine;
};