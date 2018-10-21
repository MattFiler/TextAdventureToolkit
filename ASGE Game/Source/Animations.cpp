#include "Animations.h"

/*
------
PUBLIC
------
*/

Animations::Animations() {
	sound_engine = irrklang::createIrrKlangDevice();
}

Animations::~Animations() {
	sound_engine->drop();
}

/* Animate text with a typing effect */
bool Animations::animateText(const ASGE::GameTime &time, string originalText, string &outputText)
{
	float currentGameTime = getCurrentGameTime(time);
	float currentDeltaTime = getCurrentDeltaTime(time);
	if (originalText != outputText && currentGameTime - timePreviouslyAnimated > (int)GameConstants::GAME_TYPING_SPEED * currentDeltaTime)
	{
		//Should animate
		int newTextLength = 0;
		if (previousGoalText == originalText) 
		{
			newTextLength = outputText.length() + 1;
			sound_engine->play2D("Resources\\blip_2.mp3", false);
		}
		outputText = originalText.substr(0, newTextLength);
		timePreviouslyAnimated = currentGameTime;
		previousGoalText = originalText;
		return true;
	}
	else
	{
		//Don't need to animate
		if (originalText == outputText) 
		{
			return false;
		}
	}
}

/* Animate loading screen */
bool Animations::animateLoadingScreen(const ASGE::GameTime &time, SpriteComponent &red, SpriteComponent &blue, SpriteComponent &black) 
{
	float currentGameTime = getCurrentGameTime(time);
	float currentDeltaTime = getCurrentDeltaTime(time);
	if (timeAnimationStarted == 0) 
	{
		//This function is single use, so time started only needs to be set once.
		timeAnimationStarted = currentGameTime;
	}
	float timeSinceStart = currentGameTime - timeAnimationStarted;
	//float loadSpeed = (float)currentDeltaTime / (float)GameConstants::GAME_LOADING_ANIM_SPEED;
	float loadSpeed = 1;

	//Animate visibility
	if (timeSinceStart < 0.5 * loadSpeed)
	{
		red.setSpriteOpacity(0);
		blue.setSpriteOpacity(0);
		black.setSpriteOpacity(0);
	}
	else if (timeSinceStart > 0.5 * loadSpeed && timeSinceStart < 1 * loadSpeed)
	{
		red.setSpriteOpacity(1);
		blue.setSpriteOpacity(1);
		black.setSpriteOpacity(1);
	}
	else if (timeSinceStart > 1 * loadSpeed && timeSinceStart < 1.5 * loadSpeed)
	{
		blue.setSpriteOpacity(0);
	}
	else if (timeSinceStart > 1.5 * loadSpeed && timeSinceStart < 2 * loadSpeed)
	{
		blue.setSpriteOpacity(1);
		red.setSpriteOpacity(0);
	}
	else if (timeSinceStart > 2 * loadSpeed && timeSinceStart < 2.5 * loadSpeed)
	{
		red.setSpriteOpacity(1);
	}
	else if (timeSinceStart > 3.5 * loadSpeed && timeSinceStart < 4 * loadSpeed)
	{
		red.setSpriteOpacity(0);
	}
	else if (timeSinceStart > 4 * loadSpeed && timeSinceStart < 4.5 * loadSpeed)
	{
		red.setSpriteOpacity(1);
		blue.setSpriteOpacity(0);
	}
	else if (timeSinceStart > 4.5 * loadSpeed && timeSinceStart < 5 * loadSpeed)
	{
		red.setSpriteOpacity(0);
		blue.setSpriteOpacity(1);
	}
	else
	{
		red.setSpriteOpacity(1);
	}

	//Animate position
	if (currentGameTime - timePreviouslyAnimated > 1 * loadSpeed)
	{
		red.setSpritePositionY(20, true);
		blue.setSpritePositionY(20, true);
		timePreviouslyAnimated = currentGameTime;
	}

	//Work out if the animation should finish
	if (currentGameTime - timeAnimationStarted > 6 * loadSpeed)
	{
		return true; //End it, this will trigger the game to start
	}
	else
	{
		return false;
	}
}

/*
-------
PRIVATE
-------
*/

/* Calculate current game time */
float Animations::getCurrentGameTime(const ASGE::GameTime &time)
{
	return time.game_time.count() / 1000.0;
}

/* Calculate current delta time */
float Animations::getCurrentDeltaTime(const ASGE::GameTime &time)
{
	return time.delta_time.count() / 1000.0;
}