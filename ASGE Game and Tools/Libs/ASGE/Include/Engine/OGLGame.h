#pragma once
#include <Engine/Game.h>

namespace ASGE {
	/**
	*  OGLGame. An OPENGL implementation of the Game engine.
	*  Supporting modern OpenGL this class allows the update and
	*  rendering of game objects, sprites and textures. It makes 
	*  use of simple shaders and manages the creation and destruction
	*  of the OpenGL window subsystem. Currently it does not support
	*  resizing of windows on the fly, or focus loss. 
	*/
	class OGLGame: public Game
	{
	public:
		
		virtual ~OGLGame() = default;

		/**
		* Initialises the OpenGL subsystem.
		* @return True if successful.
		*/
		virtual bool initAPI(Renderer::WindowMode mode = 
			Renderer::WindowMode::WINDOWED) override final;
		
		/**
		* Terminates the OpenGL subsystem.
		* @return True if managed gracefully.
		*/
		virtual bool exitAPI() noexcept override final;
		
		/**
		* Prepares the OpenGL subsystem for the next frame.
		*/
		virtual void beginFrame() override final;
		
		/**
		* Clean-up the OpenGL subsystem at the end of the frame.
		* This also includes the updating and rendering of FPS,
		* dynamic_batch rendering, queue management and swapping of
		* buffers. 
		*/
		virtual void endFrame() override final;
	};
}