#include "Animations.h"

bool Animations::animateText(float dt_sec, string originalText, string &outputText) {
	totalGameTime += dt_sec;
	if (originalText != outputText && totalGameTime - timePreviouslyAnimated > ((int)GameConstants::GAME_TYPING_SPEED * dt_sec)) {
		int newTextLength = 0;
		if (previousGoalText == originalText) {
			newTextLength = outputText.length() + 1;
		}
		outputText = originalText.substr(0, newTextLength);
		timePreviouslyAnimated = totalGameTime;
		previousGoalText = originalText;
		return true;
	}
	else
	{
		if (originalText == outputText) {
			return false;
		}
	}
}