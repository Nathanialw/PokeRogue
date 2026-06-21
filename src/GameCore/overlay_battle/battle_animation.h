//
// Created by nathanial on 4/10/26.
//
#pragma once
#include "lib_decl.h"


void AnimationUpdatePlayerMana(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory);
void AnimationUpdateEnemyMana(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory);
void AnimationUpdatePlayerHealth(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory);
void AnimationUpdateEnemyHealth(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory);
void BattlerAnimationAttack(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool player);
void BattlerAnimationStruck(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool player);
void AnimationBattlerStart(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface);
void AnimationBattlerDie(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface, bool onAttacker);
void AnimationScreenClearRandom(GraphicsInterface graphics, MemoryInterface memory, HardwareInterface hardware);
void AnimationUpdateXP(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory);
void EffectAnimation(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory);