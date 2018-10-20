#include "GameProgress.h"

int GameProgress::level = 0;
int GameProgress::zone = 0;
int GameProgress::state = 0;

string GameProgress::inventory[(int)GameConstants::MAX_INVENTORY_SPACE];

GameState GameProgress::gameState = GameState::LOADING;