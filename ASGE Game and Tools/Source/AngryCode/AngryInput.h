#pragma once
#include <string>
#include <Engine/OGLGame.h>
#include <irrklang.h>

#include "../AngryStructs/AngryGamestateData.h"
#include "../AngryEnums/AngryMenuScreens.h"
#include "../AngryEnums/AngryGameVars.h"

#include "../AngryCode/AngryLevels.h"

class InputStates {
	public:
		InputStates();
		~InputStates();

		//Input Handlers
		void gstateInMenu(ASGE::SharedEventData data);
		void gstatePlaying(ASGE::SharedEventData data);
		void gstateGameOver(ASGE::SharedEventData data);
		void gstateLevelBuilder(ASGE::SharedEventData data);

	private:
		//Our class' sound engine
		irrklang::ISoundEngine* sound_engine;

		/* AngryStructs */
		GamestateData gamestate;

		//Level data
		LevelSetups levels;
};