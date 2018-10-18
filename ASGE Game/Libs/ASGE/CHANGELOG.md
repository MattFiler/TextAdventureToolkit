# Changelog:

## 0.1.3 - 15/02/2018

**Enhancements:**

*Mouse cursor:*
- Added the ability to hide the mouse cursor
- Added the ability to lock the mouse cursor to the window


## 0.1.2 - 18/12/2017

**Bug Fixes:**
- Resolved issue with string destruction after storing the texture in the cache  


## 0.1.1 - 06/12/2017

**Bug Fixes:**
- Fixed issue when applying a scale to rotated sprites
- Fixed issue where it was not possible to obtain the sprite's dimensions
- Fixed issue where the texture cache would not empty when the game exits but the textures would be unloaded from GPU
- Fixed issue where FPS counter could be rendered behind other sprites 

**Enhancements:**

*Sprites:*
- Sprites now use appropriate getters and setters
- Sprites can now be flipped in the x or y axis. 
- Sprites can now use a source rectangle to make use of sprite sheets
- Sprites now support for opacity using the alpha channel

*Render modes:*
- Batching modes for texture, front to back and back to front mode added
- Borderless window support added
- Deferred rendering support added
- Fullscreen support added
- Implemented a new sprite batch class that manages rendering of both text and sprites
- Rendering the FPS also shows some additional debug info
- Replaced dynamic text buffers with a larger static buffer
- Replaced sprite shader with an instancing version

*Documentation:*
- Doxygen comments have been added to all public facing API classes and functions.

*Misc:*
- Added a new demo browser to the game engine
- Huge performance increases when rendering large numbers of sprites
- Huge performance increases when rendering large amounts of text
- Ordering renders by their texture and colour hugely benefits the sprite batch system


**Upgrades:**
- Updated GLEW to 2.1.0


**Known Issues:**
- Mouse coordinates are in screen space when using bordless mode and not orthogonal 