#pragma once
#include <Engine\Sprite.h>
#include "Rect.h"
/**
*  Sprite Components are used by GameObjects
*  A component based approach allows GameObjects to decide
*  on whether they want to have specific functionality. This
*  is a better approach than using multiple inheritance to
*  construct an object using classes as traits.
*  @see GameObject
*/
class SpriteComponent
{
public:

	/**
	*  Default constructor.
	*/
	SpriteComponent() = default;

	/**
	*  Destructor. Frees dynamic memory.
	*/
	~SpriteComponent();

	/**
	*  Allocates and loads the sprite.
	*  Part of this process will attempt to load a texture file.
	*  If this fails this function will return false and the memory
	*  allocated, freed.
	*  @param [in] renderer The renderer used to perform the allocations
	*  @param [in] texture_file_name The file path to the the texture to load
	*  @return true if the sprite was successfully loaded
	*/
	bool  loadSprite(ASGE::Renderer* renderer, const std::string& texture_file_name);

	/**
	*  Returns a pointer to the sprite residing in this component.
	*  As this is a pointer, you will need to check its contents before 
	*  attempting to read from it. A simple nullptr will be solve this.
	*  @return a pointer to the objects sprite (if any)
	*/
	ASGE::Sprite* getSprite();

	/**
	*  Grabs a bounding box for the sprite.
	*  Will create a bounding box as a rectangle. This can be used to check
	*  for collisions with other rects.
	*  @return a rectangle represent the sprite's position and bounds.
	*/
	rect  getBoundingBox() const;


private:
	void freeSprite();
	ASGE::Sprite* sprite = nullptr;
};