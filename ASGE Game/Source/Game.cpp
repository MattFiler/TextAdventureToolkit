#include <string>

#include <Engine/Keys.h>
#include <Engine/Input.h>
#include <Engine/InputEvents.h>
#include <Engine/Sprite.h>

#include "Game.h"

/**
*   @brief   Default Constructor.
*   @details Consider setting the game's width and height
             and even seeding the random number generator.
*/
TextAdventureGame::TextAdventureGame()
{
	std::srand(time(NULL)); 
	sound_engine = irrklang::createIrrKlangDevice();
}

/**
*   @brief   Destructor.
*   @details Remove any non-managed memory and callbacks.
*/
TextAdventureGame::~TextAdventureGame()
{
	this->inputs->unregisterCallback(key_callback_id);
	sound_engine->drop();
}

/**
*   @brief   Initialises the game.
*   @details The game window is created and all assets required to
			 run the game are loaded. The keyHandler and clickHandler
			 callback should also be set in the initialise function.
*   @return  True if the game initialised correctly.
*/
bool TextAdventureGame::init()
{
	//Setup engine
	setupResolution();
	if (!initAPI())
	{
		return false;
	}

	//Core game settings
	renderer->setWindowTitle("Text Adventure Game");
	renderer->setWindowedMode(ASGE::Renderer::WindowMode::WINDOWED);
	renderer->setClearColour(ASGE::COLOURS::BLACK);

	//Input callbacks
	inputs->use_threads = false;
	key_callback_id = inputs->addCallbackFnc(ASGE::E_KEY, &TextAdventureGame::keyHandler, this);

	//sound_engine->play2D("Resources\\demo.mp3", false);

	//Load font
	renderer->setFont(renderer->loadFont("Resources\\font.ttf", 55));

	//Instanciate inventory
	for (int i = 0; i < (int)GameConstants::MAX_INVENTORY_SPACE; i++) 
	{
		progress.inventory[i] = "";
	}

	//Load sprites - loading
	loading_monitor_background_red.loadSprite(renderer.get(), "Resources\\loading_monitor_background_red.png");
	loading_monitor_background_blue.loadSprite(renderer.get(), "Resources\\loading_monitor_background_blue.png");
	loading_monitor_background_black.loadSprite(renderer.get(), "Resources\\loading_monitor_background_black.png");

	//Load sprites - main
	main_monitor_foreground.loadSprite(renderer.get(), "Resources\\main_monitor_foreground.png");
	main_monitor_background.loadSprite(renderer.get(), "Resources\\main_monitor_background.png");

	//Load game into logic
	GameLogic.loadTextAdventure();

	return true;
}

/**
*   @brief   Sets the game window resolution
*   @details This function is designed to create the window size, any 
             aspect ratio scaling factors and safe zones to ensure the 
			 game frames when resolutions are changed in size.
*   @return  void
*/
void TextAdventureGame::setupResolution()
{
	game_width = (int)GameConstants::WINDOW_WIDTH;
	game_height = (int)GameConstants::WINDOW_HEIGHT;
}

/**
*   @brief   Processes any key inputs
*   @details This function is added as a callback to handle the game's
			 keyboard input. For this game, calls to this function
			 are thread safe, so you may alter the game's state as you
			 see fit.
*   @param   data The event data relating to key input.
*   @see     KeyEvent
*   @return  void
*/
void TextAdventureGame::keyHandler(const ASGE::SharedEventData data)
{
	auto key = static_cast<const ASGE::KeyEvent*>(data.get());

	//Handle user input
	if (progress.gameState != GameState::ANIMATING) 
	{
		if (key->action == ASGE::KEYS::KEY_RELEASED && key->key == ASGE::KEYS::KEY_BACKSPACE) 
		{
			screenText.userInput = screenText.userInput.substr(0, screenText.userInput.size() - 1);
		}
		else if (key->action == ASGE::KEYS::KEY_RELEASED && key->key == ASGE::KEYS::KEY_ENTER)
		{
			GameLogic.handleUserInput(screenText.userInput);
			screenText.userInput = "";
		}
		else if (key->action == ASGE::KEYS::KEY_RELEASED) 
		{
			screenText.userInput += toupper((char)key->key);
		}
	}
}


/**
*   @brief   Updates the scene
*   @details Prepares the renderer subsystem before drawing the
		     current frame. Once the current frame is has finished
		     the buffers are swapped accordingly and the image shown.
*   @return  void
*/
void TextAdventureGame::update(const ASGE::GameTime& us)
{
	float dt_sec = us.delta_time.count() / 1000.0;

	if (progress.gameState == GameState::LOADING)
	{
		//Animate loading screen & progress when done
		bool loadingAnim = loadScreenAnim.animateLoadingScreen(us, loading_monitor_background_red, loading_monitor_background_blue, loading_monitor_background_black);

		if (loadingAnim) {
			progress.gameState = GameState::PLAYING;
		}
	}
	else
	{
		//Handle text animations & blocking of user input
		bool locationIntroAnim = zoneIntroAnim.animateText(us, screenText.locationIntro, screenText.locationIntroOnScreen);
		bool responseTextAnim = outputTextAnim.animateText(us, screenText.inputResponse, screenText.inputResponseOnScreen);

		if (locationIntroAnim || responseTextAnim) 
		{
			screenText.userInput = GameLogic.getInputDisabledText();
			progress.gameState = GameState::ANIMATING;
		}
		else
		{
			if (screenText.userInput == GameLogic.getInputDisabledText())
			{
				screenText.userInput = "";
			}
			progress.gameState = GameState::PLAYING;
		}
	}
}

/**
*   @brief   Renders the scene
*   @details Renders all the game objects to the current frame.
	         Once the current frame is has finished the buffers are
			 swapped accordingly and the image shown.
*   @return  void
*/
void TextAdventureGame::render(const ASGE::GameTime& us)
{
	if (progress.gameState == GameState::LOADING) 
	{
		//Loading background layers
		renderer->renderSprite(*loading_monitor_background_red.getSprite());
		renderer->renderSprite(*loading_monitor_background_blue.getSprite());
		renderer->renderSprite(*loading_monitor_background_black.getSprite());

		//Loading foreground layers
		//renderer->renderSprite(*loading_monitor_background_blue.getSprite());
	}
	else
	{
		//Game background
		renderer->renderSprite(*main_monitor_background.getSprite()); 
		
		//Game header text
		renderer->renderText(screenText.gameTitle, 50, 60, 0.5, ASGE::COLOURS::BLACK);
		renderer->renderText(screenText.gameDeveloper, game_width - 200, 60, 0.5, ASGE::COLOURS::BLACK);

		//Game response text
		renderer->renderText(screenText.locationIntroOnScreen, 50, 150, 0.5, ASGE::COLOURS::WHITE);
		renderer->renderText(screenText.inputResponseOnScreen, 50, 550, 0.5, ASGE::COLOURS::WHITE);

		//Game input text
		renderer->renderText(screenText.userInput, 50, game_height - 40, 0.8, ASGE::COLOURS::BLACK);
	}

	//Monitor Overlay
	renderer->renderSprite(*main_monitor_foreground.getSprite());
}
