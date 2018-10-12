#pragma once

/**
**   A loaded font. A font that's loaded in the game engine.
*/

struct Fonts
{
	Fonts(int idx, char* n, int ptm);

	int id = 0;             /**< Font ID. The ID assigned to the font from the graphics engine. */
	int size = 0;           /**< The font size. The size of the font that was loaded. */
	char* name = "";        /**< Name. The name of the font. */
	static Fonts*  fonts[5]; /**< Loaded Fonts. Cheap and nasty way of globalising five loaded fonts. */
};

