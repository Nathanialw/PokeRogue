//
// Created by nathanial on 5/19/26.
//

#include "splash_animation.h"

#include "lib_decl.h"
#include "lib_types.h"
/************************************************************************************************************
 *  TODO: NOT IMPLEMENTED YET
 *  TITLE SCREEN WITH A CUSTOM ANIMATION
 ************************************************************************************************************/
SET_MEMORY(".splash")
void AnimationTitle(GraphicsInterface graphics, HardwareInterface hardware)
{
    FrameBuffer f = {50, 100, 64, 80, 0xd6fa};
    Rect_16 r = {5, 20, 10, 10};
    Color c;
    c.color = 0x001f;

    while (true)
    {
        graphics.TestAnimation(f, r, c);
        hardware.SleepMS(16);

        r.h += 1;
        if (r.h > 60)
            break;
    }
}

