#pragma once
#include <string>
#include <Engine/OGLGame.h>

/**
*  An OpenGL Game based on ASGE.
*/
class TextAdventureGame :
	public ASGE::OGLGame
{
public:
	TextAdventureGame();
	~TextAdventureGame();
	virtual bool init() override;

private:
	void keyHandler(const ASGE::SharedEventData data);
	void clickHandler(const ASGE::SharedEventData data);
	void setupResolution();

	virtual void update(const ASGE::GameTime &) override;
	virtual void render(const ASGE::GameTime &) override;

	//Input callbacks
	int key_callback_id = -1;
	int mouse_callback_id = -1;
};