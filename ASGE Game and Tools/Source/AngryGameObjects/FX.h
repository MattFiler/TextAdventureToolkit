#pragma once
#include "GameObject.h"
#include "../AngryEnums/AngryGameVars.h"

class FX : public GameObject<(int)GameVars::NUMBER_OF_FRAMES_IN_FX>
{
public:
	bool animate(float frame_time);

private:
	float runtime_count = 0;
};