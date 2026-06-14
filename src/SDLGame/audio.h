//
// Created by nathanial on 5/20/26.
//

#pragma once
#include "lib_decl.h"


AudioInterface AudioInterfaceInit();
void LoadSoundEffects();

int PlaySoundByID(uint16_t sound_id);
int SoundThreadFunc(void *data);
void RequestSound(uint16_t id);


bool InitMusicSystem(void);
void RequestMusic(uint16_t music_id);
int MusicThreadFunc(void *data);
