#pragma once
#include <string>
#include <irrklang.h>
#include "SpriteComponent.h"
#include "AngryEnums\AngryGameVars.h"

#include <Engine\Renderer.h>

template <size_t frame_count>
class GameObject
{
public:
	GameObject()
	{
		//Initialise the sound engine
		sound_engine = irrklang::createIrrKlangDevice();

		//Assign nullptr to every frame on initialisation
		for (int i = 0; i < frame_count; i++)
		{
			sprite_component[i] = nullptr;
		}
	}
	~GameObject()
	{
		//Destruct the sound engine
		sound_engine->drop();

		//De-assign the sprite from every frame
		for (int i = 0; i < frame_count; i++)
		{
			freeSpriteComponent(i);
		}
	}


	/* Add Sprite To Each Frame */
	bool addSpriteComponent(ASGE::Renderer* renderer, const std::string& texture_file_name, int frame = 0)
	{
		freeSpriteComponent(frame);

		sprite_component[frame] = new SpriteComponent();
		if (sprite_component[frame]->loadSprite(renderer, texture_file_name))
		{
			return true;
		}

		freeSpriteComponent(frame);
		return false;
	}

	/* Return Sprite For Current Frame */
	SpriteComponent* spriteComponent()
	{
		return sprite_component[getCurrentFrame()];
	}


	/* Set X/Y To Pre-Defined Value */
	void setX(float x)
	{
		for (int i = 0; i < frame_count; i++)
		{
			sprite_component[i]->getSprite()->xPos(x);
		}
	}
	void setY(float y)
	{
		for (int i = 0; i < frame_count; i++)
		{
			sprite_component[i]->getSprite()->yPos(y);
		}
	}

	/* Add To Existing X/Y Value */
	void addToX(float addX)
	{
		for (int i = 0; i < frame_count; i++)
		{
			sprite_component[i]->getSprite()->xPos(sprite_component[0]->getSprite()->xPos() + addX);
		}
	}
	void addToY(float addY)
	{
		for (int i = 0; i < frame_count; i++)
		{
			sprite_component[i]->getSprite()->yPos(sprite_component[0]->getSprite()->yPos() + addY);
		}
	}

	/* Subtract From Existing X/Y Value */
	void subtractFromX(float minusX)
	{
		for (int i = 0; i < frame_count; i++)
		{
			sprite_component[i]->getSprite()->xPos(sprite_component[0]->getSprite()->xPos() - minusX);
		}
	}
	void subtractFromY(float minusY)
	{
		for (int i = 0; i < frame_count; i++)
		{
			sprite_component[i]->getSprite()->yPos(sprite_component[0]->getSprite()->yPos() - minusY);
		}
	}

	/* Return X/Y Value */
	float getX()
	{
		return sprite_component[getCurrentFrame()]->getSprite()->xPos();
	}
	float getY()
	{
		return sprite_component[getCurrentFrame()]->getSprite()->yPos();
	}

	/* Return Sprite Height/Width Respectively */
	float getHeight()
	{
		return sprite_component[getCurrentFrame()]->getSprite()->height();
	}
	float getWidth()
	{
		return sprite_component[getCurrentFrame()]->getSprite()->width();
	}

	/* Get/Set Scale */
	float getScale()
	{
		return sprite_component[getCurrentFrame()]->getSprite()->scale();
	}
	void setScale(float scale)
	{
		for (int i = 0; i < frame_count; i++)
		{
			sprite_component[i]->getSprite()->scale(scale);
		}
	}

	/* Get/Set Opacity */
	float getOpacity()
	{
		return sprite_component[getCurrentFrame()]->getSprite()->opacity();
	}
	void setOpacity(float opacity)
	{
		for (int i = 0; i < frame_count; i++)
		{
			sprite_component[i]->getSprite()->opacity(opacity);
		}
	}

	/* Set Rotation Value (In Degrees) */
	void setRotation(float degrees)
	{
		for (int i = 0; i < frame_count; i++)
		{
			sprite_component[i]->getSprite()->rotationInRadians(degrees * (3.14159 / 180));
		}
	}


	/* Get/Set Current Frame */
	int getCurrentFrame()
	{
		return current_frame;
	}
	void setCurrentFrame(int frame, float game_time = 0)
	{
		current_frame = frame;
		frame_update_time = game_time; //Not every call needs to log game_time, so by default it is 0.
	}

	/* Return Last Frame Update Time */
	int getLastFrameUpdateTime()
	{
		return frame_update_time;
	}


	/* Despawn Entity */
	void despawn()
	{
		setOpacity(1);
		has_spawned = false;
	}

	/* Spawn Entity */
	void spawn()
	{
		setOpacity(1);
		has_spawned = true;
	}

	/* Return If Entity Has Spawned */
	bool hasSpawned()
	{
		return has_spawned;
	}

protected:
	irrklang::ISoundEngine* sound_engine;
	SpriteComponent* sprite_component[frame_count];

private:
	/* Deallocate Memory For Sprite In Each Frame */
	void freeSpriteComponent(int frame)
	{
		delete sprite_component[frame];
		sprite_component[frame] = nullptr;
	}

	bool has_spawned = false;
	int current_frame = 0;
	float frame_update_time = 0;
};