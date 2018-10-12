#include "AngryInput.h"

InputStates::InputStates() {
	sound_engine = irrklang::createIrrKlangDevice();
}
InputStates::~InputStates() {
	sound_engine->drop();
}


/*
	GAMESTATE_IN_MENU
*/
void InputStates::gstateInMenu(ASGE::SharedEventData data) 
{
	//Get key
	auto key = static_cast<const ASGE::KeyEvent*>(data.get());

	switch (gamestate.menu_screen) 
	{
		//Splashscreen
		case MenuScreen::SPLASHSCREEN: 
		{
			//Start game
			if (key->key == ASGE::KEYS::KEY_SPACE &&
				key->action == ASGE::KEYS::KEY_RELEASED &&
				gamestate.should_allow_splashscreen_inputs)
			{
				gamestate.menu_screen = MenuScreen::CONTROL_PROMPT;
				sound_engine->play2D("Resources\\UI\\SFX\\0.mp3", false);
			}

			//Quit
			if (key->key == ASGE::KEYS::KEY_ESCAPE &&
				key->action == ASGE::KEYS::KEY_RELEASED)
			{
				gamestate.current_gamestate = Gamestate::REQUESTED_QUIT;
			}

			break;
		}
		//Controls Screen
		case MenuScreen::CONTROL_PROMPT:
		{
			//Continue
			if (key->key == ASGE::KEYS::KEY_SPACE &&
				key->action == ASGE::KEYS::KEY_RELEASED &&
				gamestate.should_allow_controlscreen_inputs)
			{
				gamestate.menu_screen = MenuScreen::MAIN_MENU;
				sound_engine->play2D("Resources\\UI\\SFX\\0.mp3", false);
			}

			//Quit
			if (key->key == ASGE::KEYS::KEY_ESCAPE &&
				key->action == ASGE::KEYS::KEY_RELEASED)
			{
				gamestate.current_gamestate = Gamestate::REQUESTED_QUIT;
			}

			break;
		}
		//Main Menu (level select)
		case MenuScreen::MAIN_MENU: 
		{
			//User has selected a level
			if (key->key == ASGE::KEYS::KEY_ENTER &&
				key->action == ASGE::KEYS::KEY_RELEASED)
			{
				gamestate.current_level = gamestate.level_select_menu_index;
				gamestate.current_gamestate = Gamestate::IS_PLAYING;
				sound_engine->play2D("Resources\\UI\\SFX\\0.mp3", false);
			}

			//Handle left/right
			else if (gamestate.level_select_menu_index != 0 &&
				key->key == ASGE::KEYS::KEY_LEFT &&
				key->action == ASGE::KEYS::KEY_RELEASED)
			{
				gamestate.level_select_menu_index -= 1;
				sound_engine->play2D("Resources\\UI\\SFX\\1.mp3", false);
			}
			else if (gamestate.level_select_menu_index != ((int)GameVars::NUMBER_OF_LEVELS - 1) &&
				key->key == ASGE::KEYS::KEY_RIGHT &&
				key->action == ASGE::KEYS::KEY_RELEASED)
			{
				gamestate.level_select_menu_index += 1;
				sound_engine->play2D("Resources\\UI\\SFX\\1.mp3", false);
			}

			//Quit
			if (key->key == ASGE::KEYS::KEY_ESCAPE &&
				key->action == ASGE::KEYS::KEY_RELEASED)
			{
				gamestate.current_gamestate = Gamestate::REQUESTED_QUIT;
			}

			break;
		}
		//Pause Menu
		case MenuScreen::PAUSE_MENU: 
		{
			//User has chosen to continue game
			if (gamestate.pause_menu_index == 0 &&
				key->key == ASGE::KEYS::KEY_ENTER &&
				key->action == ASGE::KEYS::KEY_RELEASED)
			{
				gamestate.current_gamestate = Gamestate::IS_PLAYING;
				sound_engine->play2D("Resources\\UI\\SFX\\0.mp3", false);
			}

			//User has chosen to exit
			else if (gamestate.pause_menu_index == 1 &&
					key->key == ASGE::KEYS::KEY_ENTER &&
					key->action == ASGE::KEYS::KEY_RELEASED)
			{
				gamestate.current_gamestate = Gamestate::REQUESTED_QUIT;
				sound_engine->play2D("Resources\\UI\\SFX\\0.mp3", false);
			}

			//Handle up/down
			else if (gamestate.pause_menu_index != 0 &&
					key->key == ASGE::KEYS::KEY_UP &&
					key->action == ASGE::KEYS::KEY_RELEASED)
			{
				gamestate.pause_menu_index -= 1;
				sound_engine->play2D("Resources\\UI\\SFX\\1.mp3", false);
			}
			else if (gamestate.pause_menu_index != 1 &&
					key->key == ASGE::KEYS::KEY_DOWN &&
					key->action == ASGE::KEYS::KEY_RELEASED)
			{
				gamestate.pause_menu_index += 1;
				sound_engine->play2D("Resources\\UI\\SFX\\1.mp3", false);
			}

			break;
		}
	}
}

/*
	GAMESTATE_IS_PLAYING
*/
void InputStates::gstatePlaying(ASGE::SharedEventData data) 
{
	//Get key
	auto key = static_cast<const ASGE::KeyEvent*>(data.get());

	//Pause the game when ESC is pressed
	if (key->key == ASGE::KEYS::KEY_ESCAPE &&
		key->action == ASGE::KEYS::KEY_RELEASED)
	{
		gamestate.current_gamestate = Gamestate::IN_MENU;
		gamestate.menu_screen = MenuScreen::PAUSE_MENU;
	}
}

/*
HAS_WON, HAS_LOST
*/
void InputStates::gstateGameOver(ASGE::SharedEventData data)
{
	//Get key
	auto key = static_cast<const ASGE::KeyEvent*>(data.get());

	//Only allow input if options are shown
	if (gamestate.should_show_gameover_options)
	{
		//User has chosen to return to menu
		if (gamestate.game_over_menu_index == 0 &&
			key->key == ASGE::KEYS::KEY_ENTER &&
			key->action == ASGE::KEYS::KEY_RELEASED)
		{
			gamestate.menu_screen = MenuScreen::MAIN_MENU;
			gamestate.current_gamestate = Gamestate::IN_MENU;
			sound_engine->play2D("Resources\\UI\\SFX\\0.mp3", false);
		}

		//User has chosen to exit
		else if (gamestate.game_over_menu_index == 1 &&
			key->key == ASGE::KEYS::KEY_ENTER &&
			key->action == ASGE::KEYS::KEY_RELEASED)
		{
			gamestate.current_gamestate = Gamestate::REQUESTED_QUIT;
			sound_engine->play2D("Resources\\UI\\SFX\\0.mp3", false);
		}

		//Handle up/down
		else if (gamestate.game_over_menu_index != 0 &&
			key->key == ASGE::KEYS::KEY_UP &&
			key->action == ASGE::KEYS::KEY_RELEASED)
		{
			gamestate.game_over_menu_index -= 1;
			sound_engine->play2D("Resources\\UI\\SFX\\1.mp3", false);
		}
		else if (gamestate.game_over_menu_index != 1 &&
			key->key == ASGE::KEYS::KEY_DOWN &&
			key->action == ASGE::KEYS::KEY_RELEASED)
		{
			gamestate.game_over_menu_index += 1;
			sound_engine->play2D("Resources\\UI\\SFX\\1.mp3", false);
		}
	}
}

/*
Level Builder
*/
void InputStates::gstateLevelBuilder(ASGE::SharedEventData data)
{
	//Get key
	auto key = static_cast<const ASGE::KeyEvent*>(data.get());

	//Modify placeholder block scale up/down
	if (key->key == ASGE::KEYS::KEY_UP && key->action == ASGE::KEYS::KEY_RELEASED)
	{
		gamestate.debug_block_scale += 0.1;
	}
	else if (key->key == ASGE::KEYS::KEY_DOWN && key->action == ASGE::KEYS::KEY_RELEASED)
	{
		gamestate.debug_block_scale -= 0.1;
	}
}