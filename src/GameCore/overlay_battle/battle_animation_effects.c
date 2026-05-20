//
// Created by nathanial on 5/19/26.
//

#include "battle_animation_effects.h"

#include "lib_decl.h"
#include "lib_types.h"
#include "constants.h"

#include "core_entities.h"
#include "core_graphics.h"
#include "core_memory_access.h"
#include "core_ram.h"

#include "battle_memory_access.h"


/************************************************************************************************************
 *  Utility functions
 ************************************************************************************************************/


SET_MEMORY(".battle")
Rect_16 GetBattlerRect(bool onAttacker)
{
    Rect_16 r = {0, 0, BATTLER_TILES_W * TILE_W, BATTLER_TILES_H * TILE_H};

    if (onAttacker)
    {
        r.x = PLAYER_BATTLER_FRAME.x + BATTLER_OFFSET;
        r.y = PLAYER_BATTLER_FRAME.y;
        return r;
    }

    r.x = ENEMY_BATTLER_FRAME.x + BATTLER_OFFSET;
    r.y = ENEMY_BATTLER_FRAME.y;
    return r;
}

SET_MEMORY(".battle")
const uint8_t* GetBattlerSprite(MemoryInterface memory, bool onAttacker)
{
    if (onAttacker)
        return Flash_GetBattlerArray(memory, false);
    return Flash_GetBattlerArray(memory, true);
}

SET_MEMORY(".battle")
SpriteLayout GetBattlerLayout(MemoryInterface memory, bool onAttacker)
{
    if (onAttacker)
        return Flash_GetBattlerLayout(memory, GetCreatureType(g_core.battleMode.enemyMonsterID), false);
    return Flash_GetBattlerLayout(memory, GetCreatureType(g_core.battleMode.enemyMonsterID), true);
}

SET_MEMORY(".battle")
void RefreshBattler(GraphicsInterface graphics, MemoryInterface memory, bool onAttacker, Rect_16 r)
{
    SpriteLayout layout = GetBattlerLayout(memory, onAttacker);
    DrawBattlerToBuffer(graphics, memory, r.x, r.y, layout, CREATURE, onAttacker);
}


SET_MEMORY(".battle")
void ReDrawBattler(GraphicsInterface graphics, MemoryInterface memory, bool onAttacker, Rect_16 r)
{
    SpriteLayout layout = GetBattlerLayout(memory, onAttacker);
    DrawBattler(graphics, memory, r.x, r.y, layout, CREATURE, onAttacker);
}


/************************************************************************************************************
 *
 *      BATTLER MOVEMENT FUNCTIONS *
 *
 ************************************************************************************************************/

/************************************************************************************************************
 *  Redraws the framebuffer contents from the center to the left d pixels
 *  Updates every frameLength ms
 ************************************************************************************************************/
SET_MEMORY(".battle")
void MoveCenterToLeft(GraphicsInterface graphics, HardwareInterface hardware, Rect_16 r, uint16_t d, uint8_t frameLength)
{
    FrameBuffer f = {r.x, r.y, r.w, r.h};
    uint16_t end_pos = f.x - d;

    while (f.x > end_pos)
    {
        f.x -= 1;

        graphics.DrawBuffer(f);
        hardware.SleepMS(frameLength);
    }
}

/************************************************************************************************************
 *  Redraws the framebuffer contents right from the center - d pixels to the center
 *  Updates every frameLength ms
 ************************************************************************************************************/
SET_MEMORY(".battle")
void MoveLeftToCenter(GraphicsInterface graphics, HardwareInterface hardware, Rect_16 r, uint16_t d, uint8_t frameLength)
{
    FrameBuffer f = {r.x - d, r.y, r.w, r.h};
    uint16_t end_pos = r.x;

    while (f.x < end_pos)
    {
        f.x += 1;
        graphics.DrawBuffer(f);
        hardware.SleepMS(frameLength);
    }
}

/************************************************************************************************************
 *  Redraws the framebuffer contents from the center to the right d pixels
 *  Updates every frameLength ms
 ************************************************************************************************************/
SET_MEMORY(".battle")
void MoveCenterToRight(GraphicsInterface graphics, HardwareInterface hardware, Rect_16 r, uint16_t d, uint8_t frameLength)
{
    FrameBuffer f = {r.x, r.y, r.w, r.h};
    uint16_t end_pos = f.x + d;

    while (f.x < end_pos)
    {
        f.x += 1;
        graphics.DrawBuffer(f);
        hardware.SleepMS(frameLength);
    }
}

/************************************************************************************************************
 *  Redraws the framebuffer contents left from the center + d pixels to the center
 *  Updates every frameLength ms
 ************************************************************************************************************/
SET_MEMORY(".battle")
void MoveRightToCenter(GraphicsInterface graphics, HardwareInterface hardware, Rect_16 r, uint16_t d, uint8_t frameLength)
{
    FrameBuffer f = {r.x + d, r.y, r.w, r.h};
    uint16_t end_pos = r.x;

    while (f.x > end_pos)
    {
        f.x -= 1;
        graphics.DrawBuffer(f);
        hardware.SleepMS(frameLength);
    }
}

/************************************************************************************************************
 *  Redraws the framebuffer contents down from the center to the center + d pixels
 *  Updates every frameLength ms
 ************************************************************************************************************/
SET_MEMORY(".battle")
void MoveCenterToDown(GraphicsInterface graphics, HardwareInterface hardware, Rect_16 r, uint16_t d, uint8_t frameLength)
{
    FrameBuffer f = {r.x, r.y, r.w, r.h};
    uint16_t end_pos = r.y + d;

    while (f.y < end_pos)
    {
        f.y += 1;
        f.h -= 1; // ensures the sprite does not draw beyond the bounds of the battler area
        graphics.DrawBuffer(f);
        hardware.SleepMS(frameLength);
    }
}

/************************************************************************************************************
 *  Redraws the framebuffer contents up from the center to the center + d pixels
 *  Updates every frameLength ms
 ************************************************************************************************************/
SET_MEMORY(".battle")
void MoveCenterToTop(GraphicsInterface graphics, HardwareInterface hardware, Rect_16 r, uint16_t d, uint8_t frameLength)
{
    const uint8_t* sprite = graphics.GetFrameBuffer1byte();

    FrameBuffer f = {r.x, r.y, r.w, r.h};
    uint16_t end_pos = r.h - d;

    while (f.h > end_pos)
    {
        sprite += (f.w * sizeof(Pixel)); // increments the pixel array by 1 row of pixels
        f.h -= 1; // shrinks the height draw frame by 1 row
        graphics.DrawSprite(f, sprite);
        hardware.SleepMS(frameLength);
    }
}

/************************************************************************************************************
 *
 *  BATTLER DRAW WARPING FUNCTIONS
 *
 ************************************************************************************************************/

/************************************************************************************************************
 *  Distorts the battler, displaying 3 of the sprite horizontally across the battle area
 *  while shifting the sprite upward pixels
 *  Advances source by partial row for distortion
 ************************************************************************************************************/
SET_MEMORY(".battle")
void AnimationMirrorImageFloatingUp(GraphicsInterface graphics, HardwareInterface hardware, Rect_16 r, uint16_t d, uint8_t frameLength)
{
    const uint8_t* sprite = graphics.GetFrameBuffer1byte();

    FrameBuffer f = {r.x + BATTLER_OFFSET, r.y, r.w, r.h};
    uint16_t end_pos = r.h - d;

    while (f.h > end_pos)
    {
        sprite += f.w;
        f.h -= 1;
        graphics.DrawSprite(f, sprite);
        hardware.SleepMS(frameLength);
    }
}


/************************************************************************************************************
 *
 ************************************************************************************************************/
SET_MEMORY(".battle")
void AnimationSpooky(GraphicsInterface graphics, HardwareInterface hardware, Rect_16 r, uint16_t d, uint8_t frameLength)
{
    const uint8_t* sprite = graphics.GetFrameBuffer1byte();

    FrameBuffer f = {r.x, r.y, r.w, r.h};
    uint16_t end_pos = r.w * 2;

    uint16_t j = 0;
    while (j < end_pos)
    {
        sprite++;
        j++;
        graphics.DrawSprite(f, sprite);
        hardware.SleepMS(frameLength);
    }
}

/************************************************************************************************************
 *
 ************************************************************************************************************/
SET_MEMORY(".battle")
void AnimationSpookyMoveCenterToLeft(GraphicsInterface graphics, HardwareInterface hardware, Rect_16 r, uint16_t d, uint8_t frameLength)
{
    const uint8_t* sprite = graphics.GetFrameBuffer1byte();

    FrameBuffer f = {r.x, r.y, r.w, r.h};
    uint16_t end_pos = r.w / 2;

    uint16_t j = 0;
    while (j < end_pos)
    {
        sprite++;
        j++;
        graphics.DrawSprite(f, sprite);
        hardware.SleepMS(frameLength);
    }
}


/************************************************************************************************************
 *
 ************************************************************************************************************/
SET_MEMORY(".battle")
void AnimationSpookyMoveLeftToCenter(GraphicsInterface graphics, HardwareInterface hardware, Rect_16 r, uint16_t d, uint8_t frameLength)
{
    const uint8_t* sprite = graphics.GetFrameBuffer1byte();

    sprite += r.w / 2;
    FrameBuffer f = {r.x, r.y, r.w, r.h};
    uint16_t end_pos = 0;

    uint16_t j = r.w / 2;
    while (j > end_pos)
    {
        sprite--;
        j--;
        graphics.DrawSprite(f, sprite);
        hardware.SleepMS(frameLength);
    }
}


/************************************************************************************************************
 *
 ************************************************************************************************************/
SET_MEMORY(".battle")
void AnimationMirrorImage2(GraphicsInterface graphics, HardwareInterface hardware, Rect_16 r, uint16_t d, uint8_t frameLength)
{
    const uint8_t* sprite = graphics.GetFrameBuffer1byte();


    FrameBuffer f = {r.x + BATTLER_OFFSET, r.y, r.w, r.h};
    uint16_t end_pos = r.h - d;

    while (f.h > end_pos)
    {
        sprite += f.w;
        f.h--;
        graphics.DrawSprite(f, sprite);
        hardware.SleepMS(frameLength);
    }
}

/************************************************************************************************************
 *  draws an ice shard graphic at a random screen position in the battler draw area
 ************************************************************************************************************/
SET_MEMORY(".battle")
void AnimationIceShards(GraphicsInterface graphics, HardwareInterface hardware, Rect_16 r, uint16_t d, uint8_t frameLength)
{
    const uint8_t* sprite = graphics.GetFrameBuffer1byte();

    FrameBuffer f = {r.x + BATTLER_OFFSET, r.y, r.w, r.h};
    uint16_t end_pos = r.h - d;

    while (f.h > end_pos)
    {
        sprite += f.w;
        f.h--;
        graphics.DrawSprite(f, sprite);
        hardware.SleepMS(frameLength);
    }
}


/************************************************************************************************************
 *
 ************************************************************************************************************/
SET_MEMORY(".battle")
void AnimationBeam(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, Rect_16 r, uint16_t d, uint8_t frameLength, uint8_t palletIndex)
{
    ;
    graphics.SetFrameBuffer(Flash_GetColor(memory, palletIndex));
    
    const uint8_t* sprite = graphics.GetFrameBuffer1byte();

    uint16_t end_pos = r.x + r.w;
    FrameBuffer f = {r.x + r.w - 64, r.y + 64, 4, 4};

    uint16_t j = 0;
    while (f.y > r.y && f.x < end_pos)
    {
        j++;
        f.y -= j % 2;
        f.x++;
        graphics.DrawSprite(f, sprite);
        hardware.SleepMS(frameLength);
    }
}


/************************************************************************************************************
 *
 ************************************************************************************************************/
SET_MEMORY(".battle")
void AnimationRandomParticles(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, Rect_16 r, uint16_t d, uint8_t frameLength, uint8_t palletIndex, uint8_t particleCount)
{
    graphics.SetFrameBuffer(Flash_GetColor(memory, palletIndex));
    const uint8_t* sprite = graphics.GetFrameBuffer1byte();

    uint16_t end_pos = particleCount;
    uint16_t size = 4;
    FrameBuffer f = {r.x + r.w - 64, r.y + 64, size, size};

    uint16_t j = 0;
    while (j < end_pos)
    {
        j++;
        f.y = r.y + hardware.GetRandom_uint8_t(0, r.h - size);
        f.x = r.x + hardware.GetRandom_uint8_t(0, r.w - size);
        graphics.DrawSprite(f, sprite);
        hardware.SleepMS(frameLength);
    }
}


/************************************************************************************************************/
/*  Draws a line of pixels of the given colour for each long in the battler sprite
************************************************************************************************************/
SET_MEMORY(".battle")
void AnimationLineEffect(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, Rect_16 r, uint16_t d, uint8_t frameLength, uint8_t palletIndex)
{
    //Cache the line of pixels
    //replace the linx of pixels with given colour
    //display
    //replace pixels with cached
    //move to the next line
    //cycle through the frame buffer
    uint16_t n = r.w;
    const uint16_t* sprite = graphics.GetFrameBuffer2bytes();

    uint16_t buffer[n];
    graphics.SetBuffer(n, buffer, Flash_GetColor(memory, palletIndex));

    FrameBuffer f = {r.x, r.y, n, 1};
    uint16_t start_pos = 0;
    uint16_t end_pos = r.h;

    while (start_pos < end_pos)
    {
        graphics.DrawSprite(f, (uint8_t*)buffer);
        hardware.SleepMS(frameLength);
        const uint16_t* b = sprite + (n * start_pos);
        graphics.DrawSprite(f, (uint8_t*)b);
        start_pos++;
        f.y++;
    }
}

/************************************************************************************************************/
/*  Draws a line of pixels of the given colour for each long in the battler sprite
************************************************************************************************************/
SET_MEMORY(".battle")
void AnimationRainbowEffects(Rect_16 r, uint16_t d, uint8_t frameLength, uint8_t palletIndex)
{
}
