#pragma once
#pragma comment(lib, "irrKlang.lib")

#include <string>
#include <Engine/OGLGame.h>
#include <irrklang.h>

#include "SpriteComponent.h"
#include "GameLogic.h"
#include "GameProgress.h"
#include "GameScreenText.h"
#include "Animations.h"
#include "GameStates.h"

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
	void setupResolution();

	virtual void update(const ASGE::GameTime &) override;
	virtual void render(const ASGE::GameTime &) override;

	void keyboardSFX();

	//Input callbacks
	int key_callback_id = -1;
	int mouse_callback_id = -1;

	//Sound engine
	irrklang::ISoundEngine* sound_engine;

	//Misc Instances
	TextAdventureLogic GameLogic;
	GameProgress progress;
	GameScreenText screenText;

	//Animation Instances
	Animations loadScreenAnim;
	Animations zoneIntroAnim;
	Animations outputTextAnim;

	//Sprites - Loading
	SpriteComponent loading_monitor_background_red;
	SpriteComponent loading_monitor_background_blue;
	SpriteComponent loading_monitor_background_black;

	//Sprites - Main
	SpriteComponent main_monitor_foreground;
	SpriteComponent main_monitor_background;

	bool isPlayingTheme = false;
};