#include "AngryRender.h"

RenderStates::RenderStates() {
	levels.loadLevels();
}
RenderStates::~RenderStates() {

}


/*
GAMESTATE_IN_MENU
*/
void RenderStates::gstateInMenu(const ASGE::GameTime & us, ASGE::Renderer* renderer)
{
	switch (gamestate.menu_screen) 
	{
		//Splashscreen
		case MenuScreen::SPLASHSCREEN: 
		{
			//Background
			renderer->renderSprite(*sprites.backgrounds[(int)BackgroundSprites::CLOUDS_BACKGROUND].spriteComponent()->getSprite());

			//Logo & Input Prompt
			renderer->renderSprite(*sprites.menu_elements[(int)MenuElement::MAIN_LOGO].spriteComponent()->getSprite());
			renderer->renderSprite(*sprites.menu_elements[(int)MenuElement::PRESS_SPACE_TO_START].spriteComponent()->getSprite());

			break;
		}
		//Controls Screen
		case MenuScreen::CONTROL_PROMPT:
		{
			//Background
			renderer->renderSprite(*sprites.backgrounds[(int)BackgroundSprites::CLOUDS_BACKGROUND].spriteComponent()->getSprite());

			//Logo & Input Prompt
			renderer->renderSprite(*sprites.menu_elements[(int)MenuElement::MAIN_LOGO].spriteComponent()->getSprite());
			renderer->renderSprite(*sprites.menu_elements[(int)MenuElement::PRESS_SPACE_TO_START].spriteComponent()->getSprite());

			//Controls list & Background
			renderer->renderSprite(*sprites.menu_elements[(int)MenuElement::LEVEL_SELECT_BACKGROUND].spriteComponent()->getSprite());
			renderer->renderSprite(*sprites.menu_elements[(int)MenuElement::CONTROLS_TEXT].spriteComponent()->getSprite());

			break;
		}
		//Main menu
		case MenuScreen::MAIN_MENU: 
		{
			//Background
			renderer->renderSprite(*sprites.backgrounds[(int)BackgroundSprites::CLOUDS_BACKGROUND].spriteComponent()->getSprite());

			//Logo & Level Icons
			renderer->renderSprite(*sprites.menu_elements[(int)MenuElement::MAIN_LOGO].spriteComponent()->getSprite());
			renderer->renderSprite(*sprites.menu_elements[(int)MenuElement::LEVEL_SELECT_BACKGROUND].spriteComponent()->getSprite());
			renderer->renderSprite(*sprites.menu_elements[(int)MenuElement::LEVEL_ONE].spriteComponent()->getSprite());
			renderer->renderSprite(*sprites.menu_elements[(int)MenuElement::LEVEL_TWO].spriteComponent()->getSprite());
			renderer->renderSprite(*sprites.menu_elements[(int)MenuElement::LEVEL_THREE].spriteComponent()->getSprite());
			renderer->renderSprite(*sprites.menu_elements[(int)MenuElement::LEVEL_FOUR].spriteComponent()->getSprite());

			//Level Highscores
			renderer->renderText(std::to_string(gamestate.highscores[0]), 528, 891, 0.5, ASGE::COLOURS::WHITE);
			renderer->renderText(std::to_string(gamestate.highscores[1]), 756, 891, 0.5, ASGE::COLOURS::WHITE);
			renderer->renderText(std::to_string(gamestate.highscores[2]), 982, 891, 0.5, ASGE::COLOURS::WHITE);
			renderer->renderText(std::to_string(gamestate.highscores[3]), 1208, 891, 0.5, ASGE::COLOURS::WHITE);

			//Level Stars
			for (int i = 0; i < (int)GameVars::NUMBER_OF_LEVELS; i++)
			{
				renderer->renderSprite(*sprites.menu_score_stars[i].spriteComponent()->getSprite());
			}

			break;
		}
		//Pause menu
		case MenuScreen::PAUSE_MENU: 
		{
			//Background
			renderer->renderSprite(*sprites.backgrounds[(int)BackgroundSprites::CLOUDS_BACKGROUND].spriteComponent()->getSprite());

			//Text
			renderer->renderSprite(*sprites.menu_elements[(int)MenuElement::TITLE_PAUSE].spriteComponent()->getSprite());
			renderer->renderSprite(*sprites.menu_elements[(int)MenuElement::MENUOPT_CONTINUE].spriteComponent()->getSprite());
			renderer->renderSprite(*sprites.menu_elements[(int)MenuElement::MENUOPT_QUIT].spriteComponent()->getSprite());

			break;
		}
	}
}

/*
GAMESTATE_IS_PLAYING
*/
void RenderStates::gstatePlaying(const ASGE::GameTime & us, ASGE::Renderer* renderer)
{
	//In-game background
	renderer->renderSprite(*sprites.backgrounds[(int)BackgroundSprites::LEVEL_BACKGROUND].spriteComponent()->getSprite());

	//Render Spawned Flight Marker Dots 
	for (int i = 0; i < (int)GameVars::NUMBER_OF_FLIGHT_MARKER_DOTS; i++)
	{
		if (sprites.flight_marker[i].hasSpawned())
		{
			renderer->renderSprite(*sprites.flight_marker[i].spriteComponent()->getSprite());
		}
	}

	//Slingshot background
	renderer->renderSprite(*sprites.slingshot[0].spriteComponent()->getSprite());

	//Blocks
	for (int i = 0; i < (int)GameVars::NUMBER_OF_BLOCKS_PER_VARIATION; i++)
	{
		//Wood
		if (sprites.wood_rectangle_long[i].hasSpawned())
			renderer->renderSprite(*sprites.wood_rectangle_long[i].spriteComponent()->getSprite());
		if (sprites.wood_rectangle_tall[i].hasSpawned())
			renderer->renderSprite(*sprites.wood_rectangle_tall[i].spriteComponent()->getSprite());
		if (sprites.wood_square[i].hasSpawned())
			renderer->renderSprite(*sprites.wood_square[i].spriteComponent()->getSprite());

		//Ice
		if (sprites.ice_rectangle_long[i].hasSpawned())
			renderer->renderSprite(*sprites.ice_rectangle_long[i].spriteComponent()->getSprite());
		if (sprites.ice_rectangle_tall[i].hasSpawned())
			renderer->renderSprite(*sprites.ice_rectangle_tall[i].spriteComponent()->getSprite());
		if (sprites.ice_square[i].hasSpawned())
			renderer->renderSprite(*sprites.ice_square[i].spriteComponent()->getSprite());

		//Rock
		if (sprites.rock_rectangle_long[i].hasSpawned())
			renderer->renderSprite(*sprites.rock_rectangle_long[i].spriteComponent()->getSprite());
		if (sprites.rock_rectangle_tall[i].hasSpawned())
			renderer->renderSprite(*sprites.rock_rectangle_tall[i].spriteComponent()->getSprite());
		if (sprites.rock_square[i].hasSpawned())
			renderer->renderSprite(*sprites.rock_square[i].spriteComponent()->getSprite());
	}

	//Pigs
	for (int i = 0; i < (int)GameVars::NUMBER_OF_PIGS; i++)
	{
		if (sprites.pigs[i].hasSpawned())
		{
			renderer->renderSprite(*sprites.pigs[i].spriteComponent()->getSprite());
		}
	}

	//Active player controlled bird
	if (sprites.active_bird.hasSpawned())
	{
		renderer->renderSprite(*sprites.active_bird.spriteComponent()->getSprite());
	}

	//Slingshot foreground
	renderer->renderSprite(*sprites.slingshot[1].spriteComponent()->getSprite());

	//Inactive birds 
	for (int i = 0; i < (int)GameVars::NUMBER_OF_STARTING_BIRDS - 1; i++)
	{
		if (sprites.waiting_birds[i].hasSpawned())
		{
			renderer->renderSprite(*sprites.waiting_birds[i].spriteComponent()->getSprite());
		}
	}

	//Explosion FX
	for (int i = 0; i < (int)GameVars::NUMBER_OF_FX_AVAILABLE; i++)
	{
		if (sprites.explosion[i].hasSpawned()) 
		{
			renderer->renderSprite(*sprites.explosion[i].spriteComponent()->getSprite());
		}
	}

	//Score Bonuses
	for (int i = 0; i < (int)GameVars::NUMBER_OF_STARTING_BIRDS; i++)
	{
		if (sprites.score_bonus_10000[i].hasSpawned())
		{
			renderer->renderSprite(*sprites.score_bonus_10000[i].spriteComponent()->getSprite());
		}
	}
	for (int i = 0; i < (int)GameVars::NUMBER_OF_FX_AVAILABLE; i++)
	{
		if (sprites.score_bonus_5000[i].hasSpawned())
		{
			renderer->renderSprite(*sprites.score_bonus_5000[i].spriteComponent()->getSprite());
		}
	}

	//Cursor
	renderer->renderSprite(*sprites.cursor[(int)mousedata.cursor].spriteComponent()->getSprite());

	//Show Score
	renderer->renderText("Highscore: " + std::to_string((int)gamestate.highscores[gamestate.current_level]), (int)GameVars::GAME_WIDTH - 350, 70, 0.7, ASGE::COLOURS::WHITE);
	renderer->renderText("Score: " + std::to_string((int)gamestate.current_score), (int)GameVars::GAME_WIDTH - 280, 120, 0.7, ASGE::COLOURS::WHITE);
}

/*
HAS_WON, HAS_LOST
*/
void RenderStates::gstateGameOver(const ASGE::GameTime & us, ASGE::Renderer* renderer) 
{
	//Background
	renderer->renderSprite(*sprites.backgrounds[(int)BackgroundSprites::CLOUDS_BACKGROUND].spriteComponent()->getSprite());

	//Title
	switch (gamestate.win_state) 
	{
		case Gamestate::HAS_LOST: 
		{
			renderer->renderSprite(*sprites.menu_elements[(int)MenuElement::TITLE_LEVEL_OVER].spriteComponent()->getSprite());
			break;
		}
		case Gamestate::HAS_WON: 
		{
			renderer->renderSprite(*sprites.menu_elements[(int)MenuElement::TITLE_VICTORY].spriteComponent()->getSprite());
			break;
		}
	}

	//Options
	if (gamestate.should_show_gameover_options)
	{
		renderer->renderSprite(*sprites.menu_elements[(int)MenuElement::MENUOPT_MENU].spriteComponent()->getSprite());
		renderer->renderSprite(*sprites.menu_elements[(int)MenuElement::MENUOPT_QUIT].spriteComponent()->getSprite());
	}

	//Render stars
	renderer->renderSprite(*sprites.gameover_score_stars.spriteComponent()->getSprite());
}

/*
Level Builder
*/
void RenderStates::gstateLevelBuilder(const ASGE::GameTime & us, ASGE::Renderer* renderer)
{
	//Background
	renderer->renderSprite(*sprites.backgrounds[(int)BackgroundSprites::EDITOR_BACKGROUND].spriteComponent()->getSprite());

	//Slingshot
	renderer->renderSprite(*sprites.slingshot[0].spriteComponent()->getSprite());
	renderer->renderSprite(*sprites.slingshot[1].spriteComponent()->getSprite());

	//Set default font
	renderer->setFont(0);

	//Render builder overlay
	renderer->renderText("LEVEL EDITOR MODE ACTIVE", 50, 75, 2, ASGE::COLOURS::RED);
	renderer->renderText("CURRENT X: " + std::to_string(mousedata.mouse_x), 50, 100, 1, ASGE::COLOURS::RED);
	renderer->renderText("CURRENT Y: " + std::to_string(mousedata.mouse_y - 10), 50, 125, 1, ASGE::COLOURS::RED);
	renderer->renderText("CURRENT SCALE: " + std::to_string(gamestate.debug_block_scale), 50, 150, 1, ASGE::COLOURS::RED);
	renderer->renderText("SCALE DOES NOT APPLY TO CHARACTERS!", 50, 175, 1, ASGE::COLOURS::RED);
	renderer->renderText("LMB: PLACE ENTITY", 50, 265, 1, ASGE::COLOURS::RED);
	renderer->renderText("RMB: SWAP ENTITY TYPE", 50, 290, 1, ASGE::COLOURS::RED);
	renderer->renderText("UP/DOWN ARROW: SCALE BLOCK", 50, 315, 1, ASGE::COLOURS::RED);

	//Render placeholders
	if (gamestate.current_gamestate == Gamestate::LEVEL_BUILDER_MODE)
	{
		for (int i = 0; i < ((int)GameVars::NUMBER_OF_BLOCK_VARIATIONS + 1); i++)
		{
			renderer->renderSprite(*sprites.placeholder_marker[i].spriteComponent()->getSprite());
		}
	}

	//Cursor
	renderer->renderSprite(*sprites.cursor[(int)mousedata.cursor].spriteComponent()->getSprite());
}