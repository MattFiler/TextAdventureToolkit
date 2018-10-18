#include <Engine\Renderer.h>
#include "SpriteComponent.h"

SpriteComponent::~SpriteComponent()
{
	freeSprite();
}

bool SpriteComponent::loadSprite(
	ASGE::Renderer* renderer, const std::string& texture_file_name)
{
	freeSprite();
	sprite = renderer->createRawSprite();
	if (sprite->loadTexture(texture_file_name))
	{
		return true;
	}

	freeSprite();
	return false;
}

void SpriteComponent::freeSprite()
{
	if (sprite)
	{
		delete sprite;
		sprite = nullptr;
	}
}


ASGE::Sprite* SpriteComponent::getSprite()
{
	return sprite;
}


rect SpriteComponent::getBoundingBox() const
{
	rect bounding_box;
	bounding_box.x = sprite->xPos();
	bounding_box.y = sprite->yPos();
	bounding_box.length = sprite->width();
	bounding_box.height = sprite->height();
	bounding_box.scale = sprite->scale();

	return bounding_box;
}