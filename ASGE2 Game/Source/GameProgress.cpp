#include "GameProgress.h"

int GameProgress::level = 0;
int GameProgress::zone = 0;
int GameProgress::state = 0;

string GameProgress::gameData[(int)GameConstants::MAX_GAMEDATA_SPACE];

GameState GameProgress::gameState = GameState::LOADING;