#include "AngryFonts.h"

/**
*   @brief   Constructor.
*   @details Sets the font index, it's size and description. 
*            Make sure the IDX is valid otherwise the font will 
*            fail to render. 
*	@param   idx is The font index in the Graphics Engine
*   @param   n is the name or description of the font
*   @param   ptm is the size of the loaded font
*   @return  void
*/
Fonts::Fonts(int idx, char* n, int ptm)
	: id(idx), name(n), size(ptm)
{

}

// static variables for fonts
Fonts* Fonts::fonts[5] = { nullptr };

