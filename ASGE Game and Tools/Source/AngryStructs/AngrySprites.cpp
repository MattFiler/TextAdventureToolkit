#include "../AngryStructs/AngrySprites.h"

//UI Elements
UI Sprites::backgrounds[(int)BackgroundSprites::NUMBER_OF_BACKGROUNDS];
UI Sprites::flight_marker[(int)GameVars::NUMBER_OF_FLIGHT_MARKER_DOTS];
UI Sprites::cursor[(int)GameVars::NUMBER_OF_CURSOR_STATES];
UI Sprites::menu_elements[(int)MenuElement::MENU_ELEMENT_COUNT];
FX Sprites::gameover_score_stars;
UI Sprites::score_bonus_10000[(int)GameVars::NUMBER_OF_STARTING_BIRDS];
UI Sprites::score_bonus_5000[(int)GameVars::NUMBER_OF_FX_AVAILABLE];
FX Sprites::menu_score_stars[(int)GameVars::NUMBER_OF_LEVELS];

//Slingshot
UI Sprites::slingshot[2];

//Birds
Character Sprites::active_bird;
Character Sprites::waiting_birds[(int)GameVars::NUMBER_OF_STARTING_BIRDS - 1];

//Pigs
Character Sprites::pigs[(int)GameVars::NUMBER_OF_PIGS];

//Wood Blocks
EnvironmentBlock Sprites::wood_rectangle_long[(int)GameVars::NUMBER_OF_BLOCKS_PER_VARIATION];
EnvironmentBlock Sprites::wood_rectangle_tall[(int)GameVars::NUMBER_OF_BLOCKS_PER_VARIATION];
EnvironmentBlock Sprites::wood_square[(int)GameVars::NUMBER_OF_BLOCKS_PER_VARIATION];

//Ice Blocks
EnvironmentBlock Sprites::ice_rectangle_long[(int)GameVars::NUMBER_OF_BLOCKS_PER_VARIATION];
EnvironmentBlock Sprites::ice_rectangle_tall[(int)GameVars::NUMBER_OF_BLOCKS_PER_VARIATION];
EnvironmentBlock Sprites::ice_square[(int)GameVars::NUMBER_OF_BLOCKS_PER_VARIATION];

//Rock Blocks
EnvironmentBlock Sprites::rock_rectangle_long[(int)GameVars::NUMBER_OF_BLOCKS_PER_VARIATION];
EnvironmentBlock Sprites::rock_rectangle_tall[(int)GameVars::NUMBER_OF_BLOCKS_PER_VARIATION];
EnvironmentBlock Sprites::rock_square[(int)GameVars::NUMBER_OF_BLOCKS_PER_VARIATION];

//Level Editor Resources
EnvironmentBlock Sprites::placeholder_marker[(int)GameVars::NUMBER_OF_BLOCK_VARIATIONS + 1]; //+1 for pigs!

//All FX
FX Sprites::explosion[(int)GameVars::NUMBER_OF_FX_AVAILABLE];