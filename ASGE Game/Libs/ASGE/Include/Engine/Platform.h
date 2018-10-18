#pragma once

#ifdef OGL
#include "../../Source/Engine/OpenGL/GLSprite.h"
namespace ASGE
{
	using GameSprite = ASGE::GLSprite;
}
#elif D3D
namespace ASGE
{
	using GameSprite = ASGE::D3DSprite;
}

#elif OGLES
namespace ASGE
{
	using GameSprite = ASGE::GLEsSprite;
}
#endif
