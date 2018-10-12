#pragma once
#pragma comment(lib, "irrKlang.lib")

#include <string>
#include <Engine/OGLGame.h>
#include <irrklang.h>

#include "../AngryCode/AngryLevels.h"
#include "../AngryCode/AngryScores.h"

#include "../AngryStructs/AngryGamestateData.h"
#include "../AngryStructs/AngrySprites.h"
#include "../AngryStructs/AngryFlightVars.h"
#include "../AngryStructs/AngryMouseData.h"

#include "../AngryEnums/AngryCharacterStates.h"
#include "../AngryEnums/AngryGameVars.h"
#include "../AngryEnums/AngryCharacterInjury.h"
#include "../AngryEnums/AngryScore.h"

class UpdateStates {
	public:
		UpdateStates();
		~UpdateStates();

		//Update Handlers
		void gstateInMenu(const ASGE::GameTime & us);
		void gstatePlaying(const ASGE::GameTime & us);
		void gstateGameOver(const ASGE::GameTime & us);
		void gstateLevelBuilder(const ASGE::GameTime & us);

	private:
		//Define music states (to avoid multiple tracks playing)
		enum music_state { PLAYING, NOT_PLAYING };
		int menu_music = NOT_PLAYING;
		int game_music = NOT_PLAYING;
		int bird_sfx = NOT_PLAYING;
		int bird_pulled_back_sfx = NOT_PLAYING;
		int bird_fired_sfx = NOT_PLAYING;
		int game_over_music = NOT_PLAYING;
		float random_slingshot_sfx = 0;

		//Our class' sound engine
		irrklang::ISoundEngine* sound_engine;

		//Level generation
		enum level_state { NEEDS_TO_SPAWN, HAS_SPAWNED };
		int level_spawn = NEEDS_TO_SPAWN;
		LevelSetups level;

		//Collision handlers
		void detectBlockCollision(EnvironmentBlock& block);
		void detectPigCollision(Character& pig);

		//Handle Bird Movement
		void handleBirdMovement(double dt_sec, Character &bird);

		//Character Animations
		void performAnimations(double dt_sec);
		void AnimateBird(Character& bird);
		void AnimatePig(Character& pig);
		float eyes_open_time = 0; //This time randomly generated every frame when playing.
		float eyes_closed_time = 0.5;

		//Score sanity check
		int pig_count = 0;
		bool has_set_stars = false;

		//Post-game score "wrap-up" & stars
		float time_started_score_wrapup = 0;
		float time_since_last_score_animation = 0;
		float time_since_star_animation_start = 0;
		bool animate_bird_scores[(int)GameVars::NUMBER_OF_STARTING_BIRDS];
		bool animate_pig_scores[(int)GameVars::NUMBER_OF_FX_AVAILABLE];
		bool has_played_star_sfx[3];
		void animateScore(int value, float x, float y);
		void animateStars(float frame_time);

		//Update/load scores
		Scores score;
		bool has_checked_for_highscore = false;
		bool has_updated_score = false;

		//Game timer
		float game_time = 0;

		//Explosion FX slot register
		void animateExplosion(float x, float y);
		bool performing_explosion_fx[(int)GameVars::NUMBER_OF_FX_AVAILABLE];

		//Reset
		void resetGame();

		/* AngryStructs */
		GamestateData gamestate;
		MouseData mousedata;
		Sprites sprites;
		FlightVars flightdata;
};