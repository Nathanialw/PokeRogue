//
// Created by nathanial on 4/8/26.
//
#pragma once

#include "types.h"

/************************************************************************************************************
 *  Utility functions
 ************************************************************************************************************/
void RefreshBattler(bool onAttacker, Rect_16 r);
void ReDrawBattler(bool onAttacker, Rect_16 r);
Rect_16 GetBattlerRect(bool onAttacker);
void AnimationsBasicAssert();

/******************************************************************************************************
 *  MOVE BATTLER
/******************************************************************************************************/
void MoveRightToCenter(Rect_16 r, uint16_t d, uint8_t frameLength);
void MoveCenterToRight(Rect_16 r, uint16_t d, uint8_t frameLength);
void MoveLeftToCenter(Rect_16 r, uint16_t d, uint8_t frameLength);
void MoveCenterToLeft(Rect_16 r, uint16_t d, uint8_t frameLength);
void MoveCenterToDown(Rect_16 r, uint16_t d, uint8_t frameLength);

/******************************************************************************************************
 *  BATTLER EFFECTS
/******************************************************************************************************/
void MoveCenterToTop(Rect_16 r, uint16_t d, uint8_t frameLength);
void AnimationSpooky(Rect_16 r, uint16_t d, uint8_t frameLength);
void AnimationSpookyMoveLeftToCenter(Rect_16 r, uint16_t d, uint8_t frameLength);
void AnimationSpookyMoveCenterToLeft(Rect_16 r, uint16_t d, uint8_t frameLength);
void AnimationMirrorImage2(Rect_16 r, uint16_t d, uint8_t frameLength);
void AnimationMirrorImageFloatingUp(Rect_16 r, uint16_t d, uint8_t frameLength);
void AnimationIceShards(Rect_16 r, uint16_t d, uint8_t frameLength);
void AnimationBeam(Rect_16 r, uint16_t d, uint8_t frameLength, uint8_t palletIndex);
void AnimationRandomParticles(Rect_16 r, uint16_t d, uint8_t frameLength, uint8_t palletIndex, uint8_t particleCount);
void AnimationLineEffect(Rect_16 r, uint16_t d, uint8_t frameLength, uint8_t palletIndex);
void AnimationRainbowEffects(Rect_16 r, uint16_t d, uint8_t frameLength, uint8_t palletIndex);