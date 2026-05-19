//
// Created by nathanial on 3/15/26.
//
#pragma once
#include "common/types.h"


MusicData InitMusicData();
void GenerateDungeonMelody(HardwareInterface hardware, Note *melody);


/**********************************************************************************************************************/
/**  IMPLEMENTATION DEFINED
**********************************************************************************************************************/
void AudioPlayVoices(const MusicData* music_data, const Note* music);
void CheckVolume();
void CheckDimmer();







