#pragma once
#include <memory>
#include <string>
#include <Engine\Colours.h>

namespace ASGE {
	class Renderer;
	class Texture2D;

	/**
	*  An ASGE supported sprite.
	*  Used to render and load textures. Includes the ability to resize,
	*  scale, flip, recolour etc. 2D games are made up of these. 
	*/
	class Sprite
	{
	public:

		/**
		* FlipFlags.
		* Used to flip the texture's UV coordinates. 
		* The flip is performed on the CPU when calculating the UVs.
		*/
		enum FlipFlags
		{
			NORMAL = 0x00,					/**< texture is not flipped. */
			FLIP_X = 0x01,					/**< texture is flipped on the x axis. */
			FLIP_Y = 0x02,					/**< texture is flipped on the y axis. */
			FLIP_BOTH = FLIP_X | FLIP_Y		/**< texture is flipped on both axis.  */
		};

		/**
		* Default destructor.
		* The destructor does not free the memory used on the GPU.
		* **This is handled inside the platform's specific 
		  implementation.**
		*/
		virtual ~Sprite() = default;
		
		/**
		* Pure virtual function for loading texture on to the GPU.
		  **This is handled inside the platform's specific 
		  implementation.**
		* @return The result of the load operation.
		*/
		virtual bool loadTexture(const std::string&) = 0;

		/**
		* Pure virtual function for retrieving the loaded texture.
		  **This is handled inside the platform's specific 
		  implementation.**
		* @return The result of the load operation.
		*/
		virtual const Texture2D* getTexture() const = 0;
		
		/**
		* Returns the sprite's position on the X axis.
		* Sprite positions are described using Cartesian 
		* Coordinates. The horizontal position in this engine 
		* is labelled **X** and runs from left to right. 
		* It is mapped directly to screen 
		* space. 
		* @return The position on the x axis */
		float xPos() const noexcept;
		
		/**
		* Updates the sprite's position on the X axis.
		* Sprite positions are described using Cartesian
		* Coordinates. The horizontal position in this engine
		* is labelled **X** and runs from left to right.
		* It is mapped directly to screen
		* @param x The position on the x axis */
		void xPos(float x) noexcept;
		
		/**
		* Returns the sprite's position on the Y axis.
		* Sprite positions are described using Cartesian 
		* Coordinates. The vertical position in this engine 
		* is labelled **y** and runs from top to bottom. 
		* It is mapped directly to screen space.
		* @return The new position on the y axis */
		float yPos() const noexcept;

		/**
		* Returns the sprite's position on the Y axis.
		* Sprite positions are described using Cartesian 
		* Coordinates. The vertical position in this engine 
		* is labelled **y** and runs from top to bottom. 
		* It is mapped directly to screen space.
		* @param y The new position on the y axis */
		void yPos(float y) noexcept;
		
		/**
		* Gets the width of the sprite.
		* Width is used to determine how wide/long a sprite 
		* will be when it's rendered to the screen. It is 
		* mapped using pixels.
		* @return The sprites width. */
		float width() const noexcept;

		/**
		* Sets the width of the sprite.
		* Width is used to determine how wide/long a sprite
		* will be when it's rendered to the screen. It is
		* mapped using pixels.
		* @param [in] width The sprites width. */
		void width(float width) noexcept;

		/**
		* Gets the height of the sprite.
		* Height is used to determine how tall a sprite
		* will be when it's rendered to the screen. It is
		* mapped using pixels.
		* @return The sprites height. */
		float height() const noexcept;

		/**
		* Sets the height of the sprite.
		* Height is used to determine how tall a sprite
		* will be when it's rendered to the screen. It is
		* mapped using pixels.
		* @param [in] height The sprites height. */
		void height(float height) noexcept;

		/**
		* Gets the height and the width of the sprite.
		* Updates the width and the height of two parameters 
		* passed in to the function. It does **not** return a 
		* value. The width and height is found in the resultant
		* parameters. 
		* @param width The sprites width.
		* @param height The sprites height. */
		void  dimensions(float& width, float& height) const noexcept;

		/**
		* Gets the rotation of the sprite in radians.
		* The angle of rotation is used to rotate the sprite
		* around it's origin. The origin defaults to the mid-point
		* of the sprite. The angle of rotation is expressed 
		* in radians.
		* @return The sprites angle of rotation in radians. */
		float rotationInRadians() const noexcept;

		/**
		* Sets the rotation of the sprite in radians.
		* The angle of rotation is used to rotate the sprite
		* around it's origin. The origin defaults to the mid-point
		* of the sprite. The angle of rotation is expressed
		* in radians.
		* @param rotation_radians The angle of rotation in radians. */
		void  rotationInRadians(float rotation_radians);
		
		/**
		* Gets the scale of the sprite.
		* The scale can be adjusted to automatically make the sprite
		* bigger or smaller than it's original size, allowing for on
		* the fly alterations withouth having to edit the sprite's true
		* size. The scaling operation is performed in both axis. 
		* @return The scale factor. */
		float scale() const noexcept;

		/**
		* Sets the scale of the sprite.
		* The scale can be adjusted to automatically make the sprite
		* bigger or smaller than it's original size, allowing for on
		* the fly alterations withouth having to edit the sprite's true
		* size. The scaling operation is performed in both axis.
		* @param scale_value The scale factor. */
		void scale(float scale_value) noexcept;
		
		/**
		* Gets the colour of the sprite.
		* The colour of the sprite can be influenced by providing 
		* a tint.
		* @return The sprite's colour. */
		Colour colour() const noexcept;

		/**
		* Sets the colour of the sprite.
		* The colour of the sprite can be influenced by providing 
		* a tint.
		* @param sprite_colour The sprite's colour. */
		void colour(ASGE::Colour sprite_colour) noexcept;

		/**
		* Checks to see if the texture is flipped on the X axis.
		* It is possible to flip the UV coordinates used on the sprite's
		* texture. This will check to see if the X axis is flipped. 
		* @return If the texture is flipped on the X axis. */
		bool isFlippedOnX() const noexcept;

		/**
		* Checks to see if the texture is flipped on the Y axis.
		* It is possible to flip the UV coordinates used on the sprite's
		* texture. This will check to see if the Y axis is flipped.
		* @return If the texture is flipped on the Y axis. */
		bool isFlippedOnY() const noexcept;

		/**
		* Sets the flip state of the texture.
		* It is possible to flip the UV coordinates used on the sprite's
		* texture. This function allows setting of the flip flags. These
		* are then used to control shader's UV mappings. 
		* @param flags The flip flags to apply to the texture. */
		void setFlipFlags(FlipFlags flags) noexcept;

		/**
		* Sets the opacity of the sprite.
		* This function let's you control the opacity of the sprite by 
		* modifying the alpha channel during the render cycle. 1.0f is 
		* opaque and 0.0f is completely transparent. 
		* @param [in] alpha The new value for the alpha channel. */
		void opacity(float alpha) noexcept;

		/**
		* Retrieves the opacity of the sprite.
		* This function let's you obtain the opacity of the sprite.
		* The opacity is controlled by using the alpha channel. 
		* 1.0f is opaque and 0.0f is completely transparent.
		* @return The value for the alpha channel. */
		float opacity() const noexcept;

		/**
		* Gets the source rectangle used for rendering. 
		* It is possible to render a subset of a sprite using a rectangle.
		* The rectangle will use [0] and [1] for the beginning x and y 
		* position in the texture and [2] and [3] for the width and height.
		* This is useful when the texture is a sprite sheet. 
		* @return The rectangle used for the UV source. */
		float* srcRect() noexcept;

		/**
		* Gets a read-only source rectangle used for rendering.
		* It is possible to render a subset of a sprite using a rectangle.
		* The rectangle will use [0] and [1] for the beginning x and y
		* position in the texture and [2] and [3] for the width and height.
		* This is useful when the texture is a sprite sheet.
		* @return The rectangle (as a constant) used for the UV source. */
		const float* srcRect() const noexcept;
		
	protected:
		float dims[2]{ 0,0 };         /**< Sprite Dimensions. The dimensions of the sprite. */
		float src_rect[4]{ 0,0,0,0 }; /**< Sprite Rectangle. The source rectangle used for drawing. */
		float position[2] { 0,0 };    /**< Sprite Position. The sprites position on the screen. */
		float angle = 0.0f;           /**< Sprite Rotation. Rotation around the sprite's origin. */
		float scale_factor = 1.0f;    /**< Sprite Scale. Scales the sprite equally in both dims. */
		float alpha = 1.0f;			  /**< Sprite Opacity. Controls the sprite's opacity via alpha */
		FlipFlags flip_flags;         /**< Sprite Texture Flip. Flags to control UV mappings. */
		Colour tint = COLOURS::WHITE; /**< Sprite Colour. Sets the colour of the sprite. */
	};
}