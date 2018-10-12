#include <Engine\Renderer.h>
#include "FX.h"


/*
	-- ANIMATION --
*/

/* Animate FX */
bool FX::animate(float frame_time)
{
	//Keep track of the animation time
	runtime_count += frame_time;

	//Cycle frames
	if (runtime_count < 0.1) 
	{
		setCurrentFrame(0);
		return false;
	}
	else if (runtime_count > 0.1 && 
		runtime_count < 0.2)
	{
		setCurrentFrame(1);
		return false;
	}
	else if (runtime_count > 0.2 &&
				runtime_count < 0.3)
	{
		setCurrentFrame(2);
		return false;
	}
	else if (runtime_count > 0.3 &&
				runtime_count < 0.4)
	{
		setCurrentFrame(3);
		return false;
	}

	//Animation finished
	runtime_count = 0;
	return true;
}