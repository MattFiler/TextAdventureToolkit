#include "Rect.h"

/**
*   @brief   Does a point reside within this rectangle?
*   @details Will check to see if the x and y coordinates
             provided reside within the area of the rectangle.
*   @return  True if they do.
*/
bool rect::isInside(float x, float y) const
{
	if (x >= this->x &&
		x <= this->x + (this->length * this->scale))
	{
		if (y >= this->y &&
			y <= this->y + (this->height * this->scale))
		{
			return true;
		}
	}

	return false;
}


/**
*   @brief   Does a another rectangle reside within this rectangle?
*   @details Will check to see if the two rectanges overlap.
*   @return  True if they do.
*/
bool rect::isInside(const rect& rhs) const
{
	auto& lhs = *this;

	bool xOverlap = isBetween(lhs.x, rhs.x, rhs.x + (rhs.length * rhs.scale)) ||
		isBetween(rhs.x, lhs.x, lhs.x + (lhs.length * lhs.scale));

	bool yOverlap = isBetween(lhs.y, rhs.y, rhs.y + (rhs.height * rhs.scale)) ||
		isBetween(rhs.y, lhs.y, lhs.y + (lhs.height * lhs.scale));

	return xOverlap && yOverlap;
}


/**
*   @brief   Checks to see if a value falls within a range.
*   @details Takes a value and uses a min and max to generate a 
             check to see if the value falls inside it's range.
*   @return  True if they do.
*/
bool rect::isBetween(float value, float min, float max) const
{
	return (value >= min) && (value <= max);
}