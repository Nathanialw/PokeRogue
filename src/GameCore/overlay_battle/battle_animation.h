//
// Created by nathanial on 4/10/26.
//
#pragma once
#include "lib_decl.h"


void AnimationUpdateHealth(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool attackersTurn);
void BattlerAnimationAttack(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool player);
void BattlerAnimationStruck(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool player);
void AnimationBattlerStart(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface);
void AnimationBattlerDie(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface, bool onAttacker);
void AnimationScreenClearRandom(GraphicsInterface graphics, HardwareInterface hardware);
void AnimationUpdateXP(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory);
void AnimationUpdateMana(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool attackersTurn);
void EffectAnimation(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory);