#include "../AngryStructs/AngryGamestateData.h"
#include "../AngryEnums/AngryGameVars.h"

/* GAMESTATE DATA */
Gamestate GamestateData::current_gamestate = Gamestate::IN_MENU; //By default, gamestate is IN_MENU 
Gamestate GamestateData::win_state = Gamestate::NO_STATE; //This is set at runtime when we win or lose. Reset on return to menu

/* GAME DATA */
int GamestateData::lives = (int)GameVars::NUMBER_OF_STARTING_BIRDS; //Lives defaults are preset in AngryGameVars
int GamestateData::current_level = 0; //Set from Main Menu at runtime
float GamestateData::current_score = 0; //Incremented at runtime
int GamestateData::awarded_stars = 0; //Set at the end of a level

/* MENU DATA */
MenuScreen GamestateData::menu_screen = MenuScreen::SPLASHSCREEN; //By default we land on the splashscreen, unless in editor mode
int GamestateData::level_select_menu_index = 0; //Set as 0 for default
int GamestateData::pause_menu_index = 0; //Set as 0 for default
int GamestateData::game_over_menu_index = 0; //Set as 0 for default
bool GamestateData::should_show_gameover_options = false; //False = shouldn't show yet
bool GamestateData::should_allow_splashscreen_inputs = false; //False = shouldn't yet
bool GamestateData::should_allow_controlscreen_inputs = false; //False = shouldn't yet

/* LEVEL EDITOR DATA */
bool GamestateData::debug_place_block = false; //True = should place
float GamestateData::debug_block_scale = 1; //1 is default

/* SCORE DATA */
int GamestateData::highscores[(int)GameVars::NUMBER_OF_LEVELS]; //Set by Scores::loadScores()