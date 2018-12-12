#pragma once

enum class GameState : int
{
	LOADING,
	PLAYING,
	ANIMATING,
	DID_WIN,
	DID_LOSE
};