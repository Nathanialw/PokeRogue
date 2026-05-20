//
// Created by nathanial on 5/20/26.
//

#include "audio.h"

#include "lib_decl.h"


// TODO:
void PlaySoundEffect(void)
{

}


AudioInterface AudioInterfaceInit()
{
    AudioInterface audioInterface = {
        .PlaySoundEffect = PlaySoundEffect,
    };
    return audioInterface;
}
