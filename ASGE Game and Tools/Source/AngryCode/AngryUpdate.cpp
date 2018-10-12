#include "AngryUpdate.h"

//Create and destroy the sound engine when the class is called
UpdateStates::UpdateStates() {
	sound_engine = irrklang::createIrrKlangDevice();
	level.loadLevels();
}
UpdateStates::~UpdateStates() {
	sound_engine->drop();
}


/*
GAMESTATE_IN_MENU
*/
void UpdateStates::gstateInMenu(const ASGE::GameTime & us) {
	auto dt_sec = us.delta_time.count() / 1000.0;

	switch (gamestate.menu_screen)
	{
		//Splashscreen
		case MenuScreen::SPLASHSCREEN:
		{
			//Fade in
			if (sprites.backgrounds[(int)BackgroundSprites::CLOUDS_BACKGROUND].animateFadeIn(dt_sec))
			{
				if (sprites.menu_elements[(int)MenuElement::MAIN_LOGO].animateFadeInUp(dt_sec))
				{
					if (sprites.menu_elements[(int)MenuElement::PRESS_SPACE_TO_START].animateFadeInUp(dt_sec))
					{
						gamestate.should_allow_splashscreen_inputs = true;
					}
				}
			}

			break;
		}
		//Controls Screen
		case MenuScreen::CONTROL_PROMPT:
		{
			//Fade out
			if (sprites.menu_elements[(int)MenuElement::PRESS_SPACE_TO_START].animateFadeOutUp(dt_sec))
			{
				if (sprites.menu_elements[(int)MenuElement::LEVEL_SELECT_BACKGROUND].animateFadeIn(dt_sec))
				{
					if (sprites.menu_elements[(int)MenuElement::CONTROLS_TEXT].animateFadeIn(dt_sec))
					{
						gamestate.should_allow_controlscreen_inputs = true;
					}
				}
			}
			break;
		}
		//Main Menu (level select)
		case MenuScreen::MAIN_MENU: 
		{
			//Cycle level selection opacity
			switch (gamestate.level_select_menu_index)
			{
				case 0: {
					sprites.menu_elements[(int)MenuElement::LEVEL_ONE].setOpacity(1);
					sprites.menu_elements[(int)MenuElement::LEVEL_TWO].setOpacity(0.5);
					sprites.menu_elements[(int)MenuElement::LEVEL_THREE].setOpacity(0.5);
					sprites.menu_elements[(int)MenuElement::LEVEL_FOUR].setOpacity(0.5);
					break;
				}
				case 1: {
					sprites.menu_elements[(int)MenuElement::LEVEL_ONE].setOpacity(0.5);
					sprites.menu_elements[(int)MenuElement::LEVEL_TWO].setOpacity(1);
					sprites.menu_elements[(int)MenuElement::LEVEL_THREE].setOpacity(0.5);
					sprites.menu_elements[(int)MenuElement::LEVEL_FOUR].setOpacity(0.5);
					break;
				}
				case 2: {
					sprites.menu_elements[(int)MenuElement::LEVEL_ONE].setOpacity(0.5);
					sprites.menu_elements[(int)MenuElement::LEVEL_TWO].setOpacity(0.5);
					sprites.menu_elements[(int)MenuElement::LEVEL_THREE].setOpacity(1);
					sprites.menu_elements[(int)MenuElement::LEVEL_FOUR].setOpacity(0.5);
					break;
				}
				case 3: {
					sprites.menu_elements[(int)MenuElement::LEVEL_ONE].setOpacity(0.5);
					sprites.menu_elements[(int)MenuElement::LEVEL_TWO].setOpacity(0.5);
					sprites.menu_elements[(int)MenuElement::LEVEL_THREE].setOpacity(0.5);
					sprites.menu_elements[(int)MenuElement::LEVEL_FOUR].setOpacity(1);
					break;
				}
			}

			//Game has just been won or lost - reset everything here
			if (gamestate.win_state != Gamestate::NO_STATE) 
			{
				resetGame();
			}

			//Update scores if required
			if (!has_updated_score)
			{
				//Pull new scores
				score.loadScores();

				//Set stars for each level
				for (int i = 0; i < (int)GameVars::NUMBER_OF_LEVELS; i++)
				{
					if (gamestate.highscores[i] < (int)level.getScoreThreshold(i, 1))
					{
						//0 Stars
						sprites.menu_score_stars[i].setCurrentFrame(0);
					}
					else if (gamestate.highscores[i] >= (int)level.getScoreThreshold(i, 1) &&
							 gamestate.highscores[i] < (int)level.getScoreThreshold(i, 2))
					{
						//1 Star
						sprites.menu_score_stars[i].setCurrentFrame(1);
					}
					else if (gamestate.highscores[i] >= (int)level.getScoreThreshold(i, 2) &&
							 gamestate.highscores[i] < (int)level.getScoreThreshold(i, 3))
					{
						//2 Stars
						sprites.menu_score_stars[i].setCurrentFrame(2);
					}
					else if (gamestate.highscores[i] >= (int)level.getScoreThreshold(i, 3))
					{
						//3 Stars
						sprites.menu_score_stars[i].setCurrentFrame(3);
					}
				}

				has_updated_score = true;
			}

			break;
		}
		//Pause Menu
		case MenuScreen::PAUSE_MENU: 
		{
			//Cycle pause menu selection opacity
			switch (gamestate.pause_menu_index)
			{
				case 0:
				{
					sprites.menu_elements[(int)MenuElement::MENUOPT_CONTINUE].setOpacity(1);
					sprites.menu_elements[(int)MenuElement::MENUOPT_QUIT].setOpacity(0.5);
					break;
				}
				case 1: 
				{
					sprites.menu_elements[(int)MenuElement::MENUOPT_CONTINUE].setOpacity(0.5);
					sprites.menu_elements[(int)MenuElement::MENUOPT_QUIT].setOpacity(1);
					break;
				}
			}

			break;
		}
	}

	//If not already playing, play background music
	if (menu_music == NOT_PLAYING)
	{
		sound_engine->play2D("Resources\\UI\\MUSIC\\0.mp3", true);
		menu_music = PLAYING;
	}
}

/*
GAMESTATE_IS_PLAYING
*/
void UpdateStates::gstatePlaying(const ASGE::GameTime & us) {
	//Initialise rand() every frame
	srand(time(NULL));

	//Calculate frame time in seconds
	auto dt_sec = us.delta_time.count() / 1000.0;
	game_time += dt_sec; //update gametime

	//Ensure we get the victory/defeat track!
	game_over_music = NOT_PLAYING;
	gamestate.pause_menu_index = 0; //Also keep pause menu index reset.

	//Generate level if it hasn't already been
	if (level_spawn == NEEDS_TO_SPAWN) 
	{
		level.GenerateLevel(gamestate.current_level);
		level_spawn = HAS_SPAWNED;
	}

	//If not already playing, play background music and intro sfx
	if (game_music == NOT_PLAYING)
	{
		sound_engine->stopAllSounds();
		sound_engine->play2D("Resources\\ENVIRONMENT\\MUSIC\\0.mp3", false);
		sound_engine->play2D("Resources\\ENVIRONMENT\\SOUNDSCAPES\\0.mp3", true);
		game_music = PLAYING;
	}

	//Handle movement of the currently active bird
	handleBirdMovement(dt_sec, sprites.active_bird);

	//Handle block collision
	for (int i = 0; i < (int)GameVars::NUMBER_OF_BLOCKS_PER_VARIATION; i++)
	{
		//Wood
		detectBlockCollision(sprites.wood_rectangle_long[i]);
		detectBlockCollision(sprites.wood_rectangle_tall[i]);
		detectBlockCollision(sprites.wood_square[i]);

		//Ice
		detectBlockCollision(sprites.ice_rectangle_long[i]);
		detectBlockCollision(sprites.ice_rectangle_tall[i]);
		detectBlockCollision(sprites.ice_square[i]);

		//Rock
		detectBlockCollision(sprites.rock_rectangle_long[i]);
		detectBlockCollision(sprites.rock_rectangle_tall[i]);
		detectBlockCollision(sprites.rock_square[i]);
	}

	//Handle Pig Collision
	for (int i = 0; i < (int)GameVars::NUMBER_OF_PIGS; i++) 
	{
		detectPigCollision(sprites.pigs[i]);
	}

	//Work out the number of active pigs
	if (pig_count == 0)
	{
		for (int i = 0; i < (int)GameVars::NUMBER_OF_PIGS; i++)
		{
			if (sprites.pigs[i].hasSpawned())
			{
				pig_count += 1;
			}
		}
	}

	//Reload bird if we can
	if (sprites.active_bird.getState() == CharacterStates::DESPAWNED)
	{
		if (gamestate.lives != 0) 
		{
			//If bird has despawned, put it back in cannon
			sprites.active_bird.setState(CharacterStates::IN_CANNON);
		}
		else
		{
			//We're out of lives, can't put a bird in the cannon.
			gamestate.win_state = Gamestate::ON_HOLD;
			time_started_score_wrapup += dt_sec;
			if (time_started_score_wrapup > 2)
			{
				gamestate.current_gamestate = Gamestate::GAME_OVER;
				gamestate.win_state = Gamestate::HAS_LOST;
			}
		}
	}

	//If we're out of pigs, we've won - count birds
	if (pig_count == 0 && gamestate.lives != 0)
	{
		gamestate.win_state = Gamestate::ON_HOLD;
		time_started_score_wrapup += dt_sec;
		time_since_last_score_animation += dt_sec;

		//Animate score popup for every remaining bird
		if (time_since_last_score_animation > 1)
		{
			for (int i = 0; i < (int)GameVars::NUMBER_OF_STARTING_BIRDS - 1; i++)
			{
				if (sprites.waiting_birds[i].hasSpawned() && !animate_bird_scores[i])
				{
					animateScore((int)Score::HAS_BIRD_LEFT, sprites.waiting_birds[i].getX(), sprites.waiting_birds[i].getY());
					break;
				}
			}
		}

		//Animate score popup for active bird
		if (time_since_last_score_animation > 1) 
		{
			if (!animate_bird_scores[gamestate.lives-1])
			{
				animateScore((int)Score::HAS_BIRD_LEFT, sprites.active_bird.getX(), sprites.active_bird.getY());
			}
		}

		//Out of birds, and time has passed - flip to game over screen
		if (time_since_last_score_animation > 3)
		{
			gamestate.current_gamestate = Gamestate::GAME_OVER;
			gamestate.win_state = Gamestate::HAS_WON;
		}
	}

	//Animations
	performAnimations(dt_sec);
}

/*
HAS_WON HAS_LOST
*/
void UpdateStates::gstateGameOver(const ASGE::GameTime & us)
{
	//If not already playing, play background music
	if (game_over_music == NOT_PLAYING)
	{
		sound_engine->stopAllSounds();
		sound_engine->play2D("Resources\\UI\\MUSIC\\1.mp3", false);
		game_over_music = PLAYING;
	}

	//Check to see if we got a highscore
	if (!has_checked_for_highscore)
	{
		if (gamestate.current_score > gamestate.highscores[gamestate.current_level])
		{
			//We got a highscore, save it
			gamestate.highscores[gamestate.current_level] = gamestate.current_score;
			score.saveScores();
		}
		has_checked_for_highscore = true;
	}

	//Cycle selection opacity
	switch (gamestate.game_over_menu_index)
	{
		case 0: 
		{
			sprites.menu_elements[(int)MenuElement::MENUOPT_MENU].setOpacity(1);
			sprites.menu_elements[(int)MenuElement::MENUOPT_QUIT].setOpacity(0.5);
			break;
		}
		case 1: 
		{
			sprites.menu_elements[(int)MenuElement::MENUOPT_MENU].setOpacity(0.5);
			sprites.menu_elements[(int)MenuElement::MENUOPT_QUIT].setOpacity(1);
			break;
		}
	}

	//Set player star count if it hasn't already been done
	if (!has_set_stars) {
		if (gamestate.current_score < level.getScoreThreshold(gamestate.current_level, 1))
		{
			//0 Stars
			gamestate.awarded_stars = 0;
		}
		else if (gamestate.current_score >= level.getScoreThreshold(gamestate.current_level, 1) &&
				 gamestate.current_score < level.getScoreThreshold(gamestate.current_level, 2))
		{
			//1 Star
			gamestate.awarded_stars = 1;
		}
		else if (gamestate.current_score >= level.getScoreThreshold(gamestate.current_level, 2) &&
				 gamestate.current_score < level.getScoreThreshold(gamestate.current_level, 3))
		{
			//2 Stars
			gamestate.awarded_stars = 2;
		}
		else if (gamestate.current_score >= level.getScoreThreshold(gamestate.current_level, 3))
		{
			//3 Stars
			gamestate.awarded_stars = 3;
		}
	}

	//Animate stars
	auto dt_sec = us.delta_time.count() / 1000.0;
	animateStars(dt_sec);
}

/*
Level Builder
*/
void UpdateStates::gstateLevelBuilder(const ASGE::GameTime & us)
{
	//Editor mode doesn't need the player bird.
	if (sprites.active_bird.hasSpawned())
	{
		sprites.active_bird.despawn();
	}

	//Place block if requested.
	if (gamestate.debug_place_block) 
	{
		gamestate.debug_place_block = false;
		sprites.placeholder_marker[(int)mousedata.cursor - 2].setX(mousedata.mouse_x);
		sprites.placeholder_marker[(int)mousedata.cursor - 2].setY(mousedata.mouse_y - 10);
		if (mousedata.cursor != Cursors::PIG)
		{
			sprites.placeholder_marker[(int)mousedata.cursor - 2].setScale(gamestate.debug_block_scale);
		}
	}
}


/*
Perform any requested animations
*/
void UpdateStates::performAnimations(double dt_sec)
{
	//Animate Birds
	AnimateBird(sprites.active_bird);
	for (int i = 0; i < (int)GameVars::NUMBER_OF_STARTING_BIRDS - 1; i++)
	{
		AnimateBird(sprites.waiting_birds[i]);
	}

	//Animate pigs
	for (int i = 0; i < (int)GameVars::NUMBER_OF_PIGS; i++)
	{
		AnimatePig(sprites.pigs[i]);
	}

	//Animate explosion FX
	for (int i = 0; i < (int)GameVars::NUMBER_OF_FX_AVAILABLE; i++)
	{
		if (performing_explosion_fx[i])
		{
			//Perform animation if requested
			if (sprites.explosion[i].animate(dt_sec))
			{
				//Animation is done.
				performing_explosion_fx[i] = false;
				sprites.explosion[i].despawn();
				sprites.explosion[i].setCurrentFrame(0);
			}
		}
	}

	//Animate pig score
	for (int i = 0; i < (int)GameVars::NUMBER_OF_FX_AVAILABLE; i++)
	{
		if (animate_pig_scores[i])
		{
			//Perform animation if requested
			if (sprites.score_bonus_5000[i].animateFadeOutUp(dt_sec))
			{
				//Animation is done.
				animate_pig_scores[i] = false;
				sprites.score_bonus_5000[i].despawn();
			}
		}
	}

	//Animate bird score
	for (int i = 0; i < (int)GameVars::NUMBER_OF_STARTING_BIRDS; i++)
	{
		if (animate_bird_scores[i])
		{
			//Perform animation if requested
			if (sprites.score_bonus_10000[i].animateFadeOutUp(dt_sec))
			{
				//Animation is done.
				sprites.score_bonus_10000[i].despawn();
			}
		}
	}
}

/*
Find a free score popup animation slot
*/
void UpdateStates::animateScore(int value, float x, float y)
{
	int slot_id = 10;
	if (value == (int)Score::HAS_DESTROYED_PIG)
	{
		//Pig Score
		for (int i = 0; i < (int)GameVars::NUMBER_OF_FX_AVAILABLE; i++)
		{
			if (!animate_pig_scores[i]) 
			{
				slot_id = i;
				break;
			}
		}
		if (slot_id != 10) 
		{
			animate_pig_scores[slot_id] = true;
			sprites.score_bonus_5000[slot_id].spawn();
			sprites.score_bonus_5000[slot_id].setX(x);
			sprites.score_bonus_5000[slot_id].setY(y);
			sound_engine->play2D("Resources\\UI\\SCORE\\SCORE_BONUS\\SFX\\1.wav", false);
		}
		else
		{
			//Couldn't animate...
		}
	}
	else
	{
		//Bird Score
		for (int i = 0; i < (int)GameVars::NUMBER_OF_STARTING_BIRDS; i++)
		{
			if (!animate_bird_scores[i]) 
			{
				slot_id = i;
				break;
			}
		}
		if (slot_id != 10)
		{
			animate_bird_scores[slot_id] = true;
			sprites.score_bonus_10000[slot_id].spawn();
			sprites.score_bonus_10000[slot_id].setX(x);
			sprites.score_bonus_10000[slot_id].setY(y);
			sound_engine->play2D("Resources\\UI\\SCORE\\SCORE_BONUS\\SFX\\0.wav", false);
		}
		else
		{
			//Couldn't animate (should never get here)
		}
	}
	gamestate.current_score += value;
	time_since_last_score_animation = 0;
}


/*
Find a free explosion FX slot
*/
void UpdateStates::animateExplosion(float x, float y)
{
	int slot_id = 10;
	for (int i = 0; i < (int)GameVars::NUMBER_OF_FX_AVAILABLE; i++)
	{
		//Find a "slot" to request an explosion
		if (!performing_explosion_fx[i])
		{
			slot_id = i;
			break;
		}
	}
	if (slot_id != 10) 
	{
		performing_explosion_fx[slot_id] = true;
		sprites.explosion[slot_id].spawn();
		sprites.explosion[slot_id].setX(x);
		sprites.explosion[slot_id].setY(y);
		sound_engine->play2D("Resources\\UI\\FX\\EXPLOSION\\SFX\\0.mp3", false);
	}
	else
	{
		//Couldn't animate...
	}
}


/*
Animate stars on the game over screen
*/
void UpdateStates::animateStars(float frame_time)
{
	time_since_star_animation_start += frame_time;

	if (time_since_star_animation_start < 2) 
	{
		sprites.gameover_score_stars.setCurrentFrame(0);
		if (gamestate.awarded_stars == 0)
		{
			gamestate.should_show_gameover_options = true;
		}
	}
	else if (time_since_star_animation_start >= 2 &&
			 time_since_star_animation_start < 2.5)
	{
		if (gamestate.awarded_stars >= 1)
		{
			sprites.gameover_score_stars.setCurrentFrame(1);
			if (!has_played_star_sfx[0])
			{
				sound_engine->play2D("Resources\\UI\\SCORE\\STARS\\SFX\\0.mp3", false);
				has_played_star_sfx[0] = true;
			}
		}
	}
	else if (time_since_star_animation_start >= 2.5 &&
			 time_since_star_animation_start < 3)
	{
		if (gamestate.awarded_stars >= 2)
		{
			sprites.gameover_score_stars.setCurrentFrame(2);
			if (!has_played_star_sfx[1])
			{
				sound_engine->play2D("Resources\\UI\\SCORE\\STARS\\SFX\\1.mp3", false);
				has_played_star_sfx[1] = true;
			}
		}
		if (gamestate.awarded_stars == 1)
		{
			gamestate.should_show_gameover_options = true;
		}
	}
	else if (time_since_star_animation_start >= 3 &&
			 time_since_star_animation_start < 3.5)
	{
		if (gamestate.awarded_stars == 3)
		{
			sprites.gameover_score_stars.setCurrentFrame(3);
			if (!has_played_star_sfx[2])
			{
				sound_engine->play2D("Resources\\UI\\SCORE\\STARS\\SFX\\2.mp3", false);
				has_played_star_sfx[2] = true;
			}
		}
		if (gamestate.awarded_stars == 2)
		{
			gamestate.should_show_gameover_options = true;
		}
	}
	else if (time_since_star_animation_start >= 3.5 &&
			 time_since_star_animation_start < 4)
	{
		if (gamestate.awarded_stars == 3)
		{
			gamestate.should_show_gameover_options = true;
		}
	}
}


/*
Detect collision on spawned blocks
*/
void UpdateStates::detectBlockCollision(EnvironmentBlock& block)
{
	if (block.hasSpawned())
	{
		if (block.spriteComponent()->getBoundingBox().isInside(sprites.active_bird.spriteComponent()->getBoundingBox()))
		{
			if (!block.doDamage()) 
			{
				//Block has been destroyed
				gamestate.current_score += (int)Score::HAS_DESTROYED_BLOCK;
				animateExplosion(block.getX(), block.getY());
			}
			else
			{
				//Block has been damaged but not destroyed
				gamestate.current_score += (int)Score::HAS_HIT_BLOCK;
			}
			animateExplosion(sprites.active_bird.getX(), sprites.active_bird.getY());
			sprites.active_bird.setState(CharacterStates::DESPAWNED);
		}
	}
}


/*
Detect collision on spawned pigs
*/
void UpdateStates::detectPigCollision(Character& pig)
{
	if (pig.hasSpawned())
	{
		if (pig.spriteComponent()->getBoundingBox().isInside(sprites.active_bird.spriteComponent()->getBoundingBox()))
		{
			pig.setInjuryLevel((CharacterInjuries)((int)pig.getInjuryLevel() + 1));
			if (pig.getInjuryLevel() == CharacterInjuries::DEAD)
			{
				//Pig has been killed
				sound_engine->play2D("Resources\\CHARACTERS\\PIGS\\SFX\\4.mp3", false);
				pig.despawn();
				pig_count -= 1;
				animateScore((int)Score::HAS_DESTROYED_PIG, pig.getX(), pig.getY());
				animateExplosion(pig.getX(), pig.getY());
			}
			else
			{
				//Pig has been damaged but not killed
				gamestate.current_score += (int)Score::HAS_HIT_PIG;
			}
			animateExplosion(sprites.active_bird.getX(), sprites.active_bird.getY());
			sprites.active_bird.setState(CharacterStates::DESPAWNED);
		}
	}
}


/*
Handle movement of the currently active bird
*/
void UpdateStates::handleBirdMovement(double dt_sec, Character &bird)
{
	switch (bird.getState())
	{
		/* Bird is loaded in cannon and should spawn... */
		case (CharacterStates::IN_CANNON):
		{
			//Spawn
			bird.spawn();

			//Set Position to cannon
			bird.setX((float)GameVars::SLINGSHOT_X_ORIGIN);
			bird.setY((float)GameVars::SLINGSHOT_Y_ORIGIN);

			//Reset Slingshot SFX
			bird_pulled_back_sfx = NOT_PLAYING;
			bird_fired_sfx = NOT_PLAYING;

			//Reset vars
			flightdata.bird_flight_time = 0;
			flightdata.pullback_angle = 0;
			flightdata.pullback_force = 0;

			//Play SFX
			if (bird_sfx == NOT_PLAYING)
			{
				sound_engine->play2D("Resources\\CHARACTERS\\BIRDS\\RED\\SFX\\0.mp3", false);
				bird_sfx = PLAYING;
			}

			//Make sure animation has reset
			if (bird.getCurrentFrame() == 4) 
			{
				bird.setCurrentFrame(0, game_time);
			}

			break;
		}

		/* Bird is in cannon and about to be fired... */
		case (CharacterStates::ABOUT_TO_BE_FIRED):
		{
			//SFX
			if (bird_pulled_back_sfx == NOT_PLAYING)
			{
				sound_engine->play2D("Resources\\ENVIRONMENT\\SLINGSHOT\\SFX\\3.mp3", false);
				bird_pulled_back_sfx = PLAYING;
			}

			//Set position of bird to mouse position (up to set constraints)
			if (mousedata.mouse_x < (int)GameVars::SLINGSHOT_X_ORIGIN + (bird.getWidth() / 2) &&
				mousedata.mouse_x > (int)GameVars::SLINGSHOT_X_ORIGIN - (int)GameVars::BIRD_DRAG_RADIUS)
			{
				bird.setX(mousedata.mouse_x - (bird.getWidth() / 2));
			}
			if (mousedata.mouse_y < (int)GameVars::SLINGSHOT_Y_ORIGIN + (int)GameVars::BIRD_DRAG_RADIUS &&
				mousedata.mouse_y > (int)GameVars::SLINGSHOT_Y_ORIGIN + bird.getHeight() - (int)GameVars::BIRD_DRAG_RADIUS)
			{
				bird.setY(mousedata.mouse_y - (bird.getHeight() / 2));
			}

			//Stretch Slingshot String
			/*
			sprites.slingshot[2].spriteComponent()->getSprite()->width((int)GameVars::SLINGSHOT_X_ORIGIN - sprites.active_bird.getX());
			sprites.slingshot[2].spriteComponent()->getSprite()->height(bird.getHeight());
			sprites.slingshot[2].setRotation(((int)GameVars::SLINGSHOT_Y_ORIGIN - sprites.active_bird.getY()) / 4);
			sprites.slingshot[2].setX(bird.getX());
			sprites.slingshot[2].setY((int)GameVars::SLINGSHOT_Y_ORIGIN + (bird.getY() - (int)GameVars::SLINGSHOT_Y_ORIGIN));
			*/

			break;
		}

		/* Bird has been fired from cannon... */
		case (CharacterStates::HAS_BEEN_FIRED):
		{
			//SFX
			if (bird_fired_sfx == NOT_PLAYING)
			{
				random_slingshot_sfx = rand() % 3;
				if (random_slingshot_sfx == 0)
				{
					sound_engine->play2D("Resources\\ENVIRONMENT\\SLINGSHOT\\SFX\\0.mp3", false);
				}
				else if (random_slingshot_sfx == 1)
				{
					sound_engine->play2D("Resources\\ENVIRONMENT\\SLINGSHOT\\SFX\\1.mp3", false);
				}
				else if (random_slingshot_sfx == 2)
				{
					sound_engine->play2D("Resources\\ENVIRONMENT\\SLINGSHOT\\SFX\\2.mp3", false);
				}
				bird_fired_sfx = PLAYING;
			}

			//Calculate the time our bird has been in flight - this will act as our gravity
			flightdata.bird_flight_time += dt_sec;

			//Move bird based on how the user fired it
			bird.subtractFromY(flightdata.pullback_angle * (int)GameVars::FLIGHT_ANGLE_MODIFIER * dt_sec);
			bird.addToY(flightdata.bird_flight_time * (int)GameVars::FLIGHT_TIME_MODIFIER * dt_sec);
			bird.addToX(flightdata.pullback_force * (int)GameVars::FLIGHT_FORCE_MODIFIER * dt_sec);

			//Off window
			if (bird.getY() > (int)GameVars::GAME_HEIGHT ||
				//bird.getY() < -bird.spriteComponent()->getSprite()->height() ||
				bird.getX() > (int)GameVars::GAME_WIDTH ||
				bird.getX() < -bird.getWidth())
			{
				bird.setState(CharacterStates::SHOULD_DESPAWN);
			}

			//Place down a flight marker if enough time has elapsed
			flightdata.time_between_markers += dt_sec;
			if (flightdata.time_between_markers > 0.1)
			{
				sprites.flight_marker[flightdata.number_of_markers].spawn();
				sprites.flight_marker[flightdata.number_of_markers].setX(bird.getX() + (bird.getWidth() / 2));
				sprites.flight_marker[flightdata.number_of_markers].setY(bird.getY() + (bird.getHeight() / 2));

				flightdata.number_of_markers += 1;
				flightdata.time_between_markers = 0;
			}

			break;
		}

		/* Bird is off window and should despawn... */
		case (CharacterStates::SHOULD_DESPAWN):
		{
			//Reset position
			bird.setX((int)GameVars::DESPAWN_X_POS);
			bird.setY((int)GameVars::DESPAWN_Y_POS);

			//Despawn
			bird.despawn();
			bird.setState(CharacterStates::DESPAWNED);

			//Reset music trigger
			bird_sfx = NOT_PLAYING;

			//Update lives & bird spawns accordingly
			gamestate.lives -= 1;
			if (gamestate.lives != 0)
			{
				sprites.waiting_birds[gamestate.lives - 1].despawn();
			}

			break;
		}
	}
}


/*
Handle animations of birds
*/
void UpdateStates::AnimateBird(Character& bird)
{
	if (bird.getState() != CharacterStates::HAS_BEEN_FIRED)
	{
		/* In canon or lineup, alternate between expressions. */
		if (bird.hasSpawned())
		{
			eyes_open_time = rand() % 3 + 1;
			switch (bird.getCurrentFrame())
			{
				case 0: 
				{
					/* ANGRY */
					if ((game_time - bird.getLastFrameUpdateTime()) > eyes_open_time)
					{
						bird.setCurrentFrame(2, game_time);
					}
					break;
				}
				case 2:
				{
					/* NORMAL*/
					if ((game_time - bird.getLastFrameUpdateTime()) > eyes_closed_time)
					{
						bird.setCurrentFrame(0, game_time);
					}
					break;
				}
				default:
				{
					//Reset to normal if we get here.
					bird.setCurrentFrame(2, game_time);
					break;
				}
			}
		}
	}
	else
	{
		/* Fired, show dazed expression. */
		bird.setCurrentFrame(4, game_time);
	}
}

/*
Handle animations of pigs
*/
void UpdateStates::AnimatePig(Character& pig)
{
	if (pig.hasSpawned())
	{
		eyes_open_time = rand() % 3 + 1;
		switch (pig.getCurrentFrame())
		{
			case 0:
			{
				/* BLINKING - NORMAL*/
				if ((game_time - pig.getLastFrameUpdateTime()) > eyes_open_time)
				{
					pig.setCurrentFrame(1, game_time);
				}
				break;
			}
			case 1:
			{
				/* NORMAL */
				if ((game_time - pig.getLastFrameUpdateTime()) > eyes_closed_time)
				{
					pig.setCurrentFrame(0, game_time);
				}
				break;
			}
			case 2:
			{
				/* BLINKING - DAMAGED */
				if ((game_time - pig.getLastFrameUpdateTime()) > eyes_open_time)
				{
					pig.setCurrentFrame(3, game_time);
				}
				break;
			}
			case 3:
			{
				/* DAMAGED */
				if ((game_time - pig.getLastFrameUpdateTime()) > eyes_closed_time)
				{
					pig.setCurrentFrame(2, game_time);
				}
				break;
			}
			case 4:
			{
				/* BLINKING - HIGHLY DAMAGED */
				if ((game_time - pig.getLastFrameUpdateTime()) > eyes_open_time)
				{
					pig.setCurrentFrame(5, game_time);
				}
				break;
			}
			case 5:
			{
				/* HIGHLY DAMAGED */
				if ((game_time - pig.getLastFrameUpdateTime()) > eyes_closed_time)
				{
					pig.setCurrentFrame(4, game_time);
				}
				break;
			}
		}
	}
}


/* 
Reset Game
*/
void UpdateStates::resetGame()
{
	//Reset music
	menu_music = NOT_PLAYING;
	game_music = NOT_PLAYING;
	game_over_music = NOT_PLAYING;
	bird_sfx = NOT_PLAYING;
	sound_engine->stopAllSounds();

	//Reset gamestate & score
	gamestate.win_state = Gamestate::NO_STATE;
	gamestate.lives = (int)GameVars::NUMBER_OF_STARTING_BIRDS;
	for (int i = 0; i < (int)GameVars::NUMBER_OF_STARTING_BIRDS - 1; i++)
	{
		sprites.waiting_birds[i].spawn();
	}

	//Reset level build
	level_spawn = NEEDS_TO_SPAWN;
	level.ResetLevel();

	//Reset menu marker positions
	gamestate.level_select_menu_index = 0;
	gamestate.game_over_menu_index = 0;
	gamestate.pause_menu_index = 0;

	//Reset score & animations
	gamestate.current_score = 0;
	pig_count = 0;
	has_set_stars = false;
	time_started_score_wrapup = 0;
	time_since_last_score_animation = 0;
	time_since_star_animation_start = 0;
	gamestate.should_show_gameover_options = false;
	has_updated_score = false;
	has_checked_for_highscore = false;
	for (int i = 0; i < (int)GameVars::NUMBER_OF_STARTING_BIRDS; i++)
	{
		animate_bird_scores[i] = false;
		sprites.score_bonus_10000[i].despawn();
	}
	for (int i = 0; i < (int)GameVars::NUMBER_OF_FX_AVAILABLE; i++)
	{
		animate_pig_scores[i] = false;
		sprites.score_bonus_5000[i].despawn();
	}
	for (int i = 0; i < 3; i++)
	{
		has_played_star_sfx[i] = false;
	}

	//Reset flight marker dots
	for (int i = 0; i < (int)GameVars::NUMBER_OF_FLIGHT_MARKER_DOTS; i++)
	{
		sprites.flight_marker[i].despawn();
	}
}