#pragma once
#include "GameObject.h"

class UI : public GameObject<1>
{
public:
	bool animateFadeOutUp(float frame_time);
	bool animateFadeIn(float frame_time);
	bool animateFadeInUp(float frame_time);
};