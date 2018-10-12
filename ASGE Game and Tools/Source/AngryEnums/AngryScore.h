#pragma once

/*
Define scores for consistancy through the game.
*/
enum class Score : int
{
	/* BLOCK DAMAGE */
	HAS_HIT_BLOCK = 100,
	HAS_DESTROYED_BLOCK = 500,

	/* PIG DAMAGE */
	HAS_HIT_PIG = 1000,
	HAS_DESTROYED_PIG = 5000,

	/* LIVES LEFT REWARD */
	HAS_BIRD_LEFT = 10000
};