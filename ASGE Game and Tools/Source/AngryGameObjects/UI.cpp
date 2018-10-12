#include <Engine\Renderer.h>
#include "UI.h"


/*
	-- ANIMATION --
*/

/* Fade Out Up */
bool UI::animateFadeOutUp(float frame_time)
{
	//Move up, lower opacity
	subtractFromY(frame_time * 10);
	setOpacity(getOpacity() - (frame_time / 2));

	//If opacity is 0, we've finished
	if (getOpacity() <= 0)
	{
		return true;
	}
	return false;
}

/* Fade In */
bool UI::animateFadeIn(float frame_time)
{
	//This function should be called when the element hasn't spawned (basically a spawn() replacement)
	if (!hasSpawned())
	{
		spawn();
		setOpacity(0);
	}

	if (getOpacity() >= 1)
	{
		//If opacity is 1, we've finished
		return true;
	}
	else
	{
		//Raise opacity
		setOpacity(getOpacity() + frame_time);
		return false;
	}
}

/* Fade In Up */
bool UI::animateFadeInUp(float frame_time)
{
	//This function should be called when the element hasn't spawned (basically a spawn() replacement)
	if (!hasSpawned())
	{
		spawn();
		setOpacity(0);
	}

	if (getOpacity() >= 1)
	{
		//If opacity is 1, we've finished
		return true;
	}
	else
	{
		//Move up, raise opacity
		subtractFromY(frame_time * 10);
		setOpacity(getOpacity() + frame_time);
		return false;
	}
}