#pragma once
namespace ASGE{
	
	/**
	* A font used to render text.
	* A font is used to store font related information.
	* All fonts need a name, size and line height. This can
	* be used by the renderer to ensure correct formatting.
	*/
	struct Font
	{
	public:

		/**
		* Default constructor.
		*/
		Font() = default;

		/**
		* Default destructor.
		*/
		virtual ~Font() = default;

		const char* font_name = ""; /**< Font Name.   The name of the font loaded. */
		int font_size = 0;          /**< Font Size.   The size of the font imported. */
		int line_height = 0;        /**< Line Height. The recommended height of each line. */
	};
}