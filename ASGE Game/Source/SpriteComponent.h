#pragma once
#include <Engine\Sprite.h>
#include "Rect.h"

class SpriteComponent
{
public:
	SpriteComponent() = default;
	~SpriteComponent();

	bool loadSprite(ASGE::Renderer* renderer, const std::string& texture_file_name);
	ASGE::Sprite* getSprite();

	void setSpriteOpacity(float opacity);
	void setSpritePositionX(float x, bool subtract = false, bool add = false);
	void setSpritePositionY(float y, bool subtract = false, bool add = false);

	rect getBoundingBox() const;
	float getSpritePositionX();
	float getSpritePositionY();

private:
	void freeSprite();

	ASGE::Sprite* sprite = nullptr;
};