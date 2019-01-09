//
// Created by huxy on 11/11/18.
//

#ifndef ASGE_SPRITEBOUNDS_H
#define ASGE_SPRITEBOUNDS_H
#include "Point2D.h"

/**
* @brief Four vertices defining a sprites bound.
*
* Used to conveniently store 4 points together. These 4 points
* typically define the for vertices defining the bounding rectangle
* of a sprite. Note:There is no guarantee that the bounds stored here
* are axis-aligned or ordered.
*/
struct SpriteBounds
{
    Point2D v1 = {0,0}; /**< the first vertex position.   */
    Point2D v2 = {0,0}; /**< the second vertex position   */
    Point2D v3 = {0,0}; /**< the third vertex position.   */
    Point2D v4 = {0,0}; /**< the fourth vertex position.  */

};

#endif //ASGE_SPRITEBOUNDS_H
