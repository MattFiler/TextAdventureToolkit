#pragma once
#include "NonCopyable.h"
namespace ASGE
{
	/**
	* SpriteSortMode.
	* Used to control the sprite batching techniques
	* that renderers may support. 
	*/
	enum class SpriteSortMode
	{
		IMMEDIATE,     /**< Renders the sprite immediately. 
					        Invokes a state change, uploads to the gpu and draws the 
							primitives. This can be an expensive operation. */
		DEFERRED,      /**< Defers (batches) the rendering to end of the render cycle or
					        until the texture being drawn is changed It will automatically 
					        Will generate the vertices and then batch upload them at the
							batch renders that use the same texture as long as they are 
							drawn in the correct order, saving on memory transfers and
							primitive draws. */
		TEXTURE,       /**< Prepares the render data but does not populate the shared buffers
					        nor does it render immediately. Instead it queues all the draw calls
							and then sorts them by their texture id. This reduces texture and 
							GPU state changes, but breaks the original draw order and is slightly
							more intensive on the CPU and memory systems. */
		BACK_TO_FRONT, /**< Works identically to texture, but also uses the z-order to control the
					        order of draw calls. All draw calls will be first sorted by their z-order 
							and then sorted by their texture id. This mode will render the sprites with
							the lowest z-order first. */
		FRONT_TO_BACK, /**< Works identically to texture, but also uses the z-order to control the
					        order of draw calls. All draw calls will be first sorted by their z-order 
							and then sorted by their texture id. This mode will render the sprites with
							the highest z-order first. */
	};

	/**
	* A simple 2D non-renderable texture.
	* A texture is used to load images into the GPU.
	* They retain a handle or link to it and the 
	* renderers are free to implement any caching systems
	* they see fit. 
	*/
	class Texture2D
	{
	public:

		/**
		* Default constructor.
		* @param width The width of the texture.
		* @param height the height of the texture. 
		*/
		Texture2D(int width, int height) noexcept
		{
			dims[0] = width;
			dims[1] = height;
		}
			
		/**
		* Default destructor.
		* The destructor does not free the memory used on the GPU.
		* **This is handled inside the platform's specific implementation.**
		*/
		virtual ~Texture2D() = default;

		/**
		* The format of the texture
		*/
		enum Format
		{
			MONOCHROME = 1, /**< The texture is monochromatic.*/
			MONOCHROME_ALPHA = 2, /**< The texture is monochromatic and has an alpha channel.*/
			RGB = 3, /**< There are Red, Green & Blue channels present.*/
			RGBA = 4 /**< There are RGB plus alpha chanels present .*/
		};

		/**
		* Sets the format of the texture. 
		* @param f The format of the stored texture.
		* @see Format
		*/
		void setFormat(Format f) noexcept {	format = f; } 

		/**
		* Retrieves the format of the stored texture. 
		* @return The format of the texture. 
		* @see Format
		*/
		Format getFormat() const { return format;}

		/**
		* Loads the texture into GPU memory.
		* @param data The binary file loaded in memory.
		*/
		virtual void  setData(void* data) = 0;

		/**
		* Retrieves the texture from GPU memory.
		* Retrieving memory from the GPU like this is a 
		* slow process. It is best to do this infrequently.
		* @return The binary file loaded in memory.
		*/
		virtual void* getData() = 0;

		/**
		* Retrieves the width of the loaded texture.
		* @return The width of the texture.
		*/
		unsigned int getWidth()  const noexcept { return dims[0]; }
		
		/**
		* Retrieves the width of the loaded texture.
		* @return The height of the texture.
		*/
		unsigned int getHeight() const noexcept { return dims[1]; }

	protected:
		Format format = RGB;			/**< Texture2D Format. The pixel format used when loading the texture file. */
		unsigned int dims[2]{ 0,0 };	/**< Texture2D Dimensions. The dimensions of the loaded texture file. */
	};
}