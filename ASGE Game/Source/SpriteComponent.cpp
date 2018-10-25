#include <Engine\Renderer.h>
#include "SpriteComponent.h"

SpriteComponent::~SpriteComponent()
{
	freeSprite();
}

/* Load sprite to the component */
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

/* Free sprite from memory */
void SpriteComponent::freeSprite()
{
	if (sprite)
	{
		delete sprite;
		sprite = nullptr;
	}
}

/* Get the sprite in this component */
ASGE::Sprite* SpriteComponent::getSprite()
{
	return sprite;
}

/* Get texture of the sprite */
const ASGE::Texture2D* SpriteComponent::getTexture() 
{
	return sprite->getTexture();
}

/* Set the sprite's opacity */
void SpriteComponent::setSpriteOpacity(float opacity)
{
	sprite->opacity(opacity);
}

/* Set the sprite's position (X) */
void SpriteComponent::setSpritePositionX(float x, bool subtract, bool add)
{
	if (subtract)
	{
		x = getSpritePositionX() - x;
	}
	else if (add)
	{
		x += getSpritePositionX();
	}
	sprite->xPos(x);
}

/* Set the sprite's position (Y) */
void SpriteComponent::setSpritePositionY(float y, bool subtract, bool add)
{
	if (subtract)
	{
		y = getSpritePositionY() - y;
	}
	else if (add)
	{
		y += getSpritePositionY();
	}
	sprite->yPos(y);
}

/* Set sprite colour */
void SpriteComponent::setSpriteColour(float r, float g, float b) {
	float rgb[3] = { r,g,b };
	ASGE::Colour colour = ASGE::Colour::Colour(rgb);
	sprite->colour(colour);
}

/* Get the bounding box of this sprite */
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

/* Get the sprite's position (X) */
float SpriteComponent::getSpritePositionX()
{
	return sprite->xPos();
}

/* Get the sprite's position (Y) */
float SpriteComponent::getSpritePositionY()
{
	return sprite->yPos();
}

/* Crop the render rectangle */
void SpriteComponent::cropSprite(int x, int y)
{
	//Bit of a work in progress
	sprite->setSrcRect(x, y, sprite->width(), sprite->height());
	sprite->width(x);
	sprite->height(y);
}