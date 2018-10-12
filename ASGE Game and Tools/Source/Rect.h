#pragma once
struct rect
{
	float x = 0;
	float y = 0;
	float length = 0;
	float height = 0;
	float scale = 0;
	bool  isInside(float x, float y) const;
	bool  isInside(const rect& rhs) const;
	bool  isBetween(float value, float min, float max) const;
};