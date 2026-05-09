//
// Created by nathanial on 4/8/26.
//
#pragma once

#include "lib_decl.h"
#include "types.h"

/************************************************************************************************************
 *  Utility functions
 ************************************************************************************************************/
void RefreshBattler(GraphicsInterface graphics, bool onAttacker, Rect_16 r);
void ReDrawBattler(GraphicsInterface graphics, bool onAttacker, Rect_16 r);
Rect_16 GetBattlerRect(bool onAttacker);
void AnimationsBasicAssert();

/******************************************************************************************************
 *  MOVE BATTLER
/******************************************************************************************************/
void MoveRightToCenter(GraphicsInterface graphics, HardwareInterface hardware, Rect_16 r, uint16_t d, uint8_t frameLength);
void MoveCenterToRight(GraphicsInterface graphics, HardwareInterface hardware, Rect_16 r, uint16_t d, uint8_t frameLength);
void MoveLeftToCenter(GraphicsInterface graphics, HardwareInterface hardware, Rect_16 r, uint16_t d, uint8_t frameLength);
void MoveCenterToLeft(GraphicsInterface graphics, HardwareInterface hardware, Rect_16 r, uint16_t d, uint8_t frameLength);
void MoveCenterToDown(GraphicsInterface graphics, HardwareInterface hardware, Rect_16 r, uint16_t d, uint8_t frameLength);

/******************************************************************************************************
 *  BATTLER EFFECTS
/******************************************************************************************************/
void MoveCenterToTop(GraphicsInterface graphics, HardwareInterface hardware, Rect_16 r, uint16_t d, uint8_t frameLength);
void AnimationSpooky(GraphicsInterface graphics, HardwareInterface hardware, Rect_16 r, uint16_t d, uint8_t frameLength);
void AnimationSpookyMoveLeftToCenter(GraphicsInterface graphics, HardwareInterface hardware, Rect_16 r, uint16_t d, uint8_t frameLength);
void AnimationSpookyMoveCenterToLeft(GraphicsInterface graphics, HardwareInterface hardware, Rect_16 r, uint16_t d, uint8_t frameLength);
void AnimationMirrorImage2(GraphicsInterface graphics, HardwareInterface hardware, Rect_16 r, uint16_t d, uint8_t frameLength);
void AnimationMirrorImageFloatingUp(GraphicsInterface graphics, HardwareInterface hardware, Rect_16 r, uint16_t d, uint8_t frameLength);
void AnimationIceShards(GraphicsInterface graphics, HardwareInterface hardware, Rect_16 r, uint16_t d, uint8_t frameLength);
void AnimationBeam(GraphicsInterface graphics, HardwareInterface hardware, Rect_16 r, uint16_t d, uint8_t frameLength, uint8_t palletIndex);
void AnimationRandomParticles(GraphicsInterface graphics, HardwareInterface hardware, Rect_16 r, uint16_t d, uint8_t frameLength, uint8_t palletIndex, uint8_t particleCount);
void AnimationLineEffect(GraphicsInterface graphics, HardwareInterface hardware, Rect_16 r, uint16_t d, uint8_t frameLength, uint8_t palletIndex);
void AnimationRainbowEffects(Rect_16 r, uint16_t d, uint8_t frameLength, uint8_t palletIndex);