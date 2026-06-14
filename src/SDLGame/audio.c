//
// Created by nathanial on 5/20/26.
//

#include "audio.h"

#include "lib_decl.h"
#include <SDL3/SDL.h>
#include <SDL3_mixer/SDL_mixer.h>
#include <string.h>

#include "lib_debugging.h"
#include "ram.h"

AudioInterface AudioInterfaceInit()
{
    AudioInterface audioInterface = {
        .PlaySoundEffect = RequestSound,
        .PlayMusic = NULL,
    };
    return audioInterface;
}


#define SOUND_QUEUE_SIZE 64

typedef struct
{
    uint16_t sound_id;
} SoundCmd;

static struct
{
    SoundCmd commands[SOUND_QUEUE_SIZE];
    int head, tail;
    SDL_Mutex* mutex;
    SDL_Condition* cond;
} g_sound_queue;

void InitSoundQueue(void)
{
    g_sound_queue.head = 0;
    g_sound_queue.tail = 0;
    g_sound_queue.mutex = SDL_CreateMutex();
    g_sound_queue.cond = SDL_CreateCondition();
}

// Called from main thread to request a sound
void RequestSound(uint16_t sound_id)
{
    SDL_LockMutex(g_sound_queue.mutex);
    int next = (g_sound_queue.head + 1) % SOUND_QUEUE_SIZE;
    if (next == g_sound_queue.tail)
    {
        // Queue full – you can either drop the sound or grow the buffer
        SDL_Log("Sound queue overflow, dropping sound");
        SDL_UnlockMutex(g_sound_queue.mutex);
        return;
    }
    g_sound_queue.commands[g_sound_queue.head] = (SoundCmd){sound_id};
    g_sound_queue.head = next;
    SDL_SignalCondition(g_sound_queue.cond); // wake up worker
    SDL_UnlockMutex(g_sound_queue.mutex);
}


// Global audio stream, accessible to all threads
static SDL_AudioStream* g_audio_stream = NULL;
static SDL_AudioSpec g_audio_spec; // the format we'll be using

void LoadSoundEffects()
{
    if (!SDL_Init(SDL_INIT_AUDIO))
    {
        SDL_Log("SDL_Init failed: %s", SDL_GetError());
        return;
    }

    InitSoundQueue();

    const char* asset_file = "bin/effects.bin";

    void* bin_data = SDL_LoadFile(asset_file, &g_ramState.effects_size);

    if (!bin_data)
    {
        SDL_Log("Load error: %s", SDL_GetError());
        return;
    }

    if (memcmp(bin_data, "ASST", 4) != 0)
    {
        SDL_Log("Invalid magic");
        SDL_free(bin_data);
        return;
    }

    g_ramState.effects_bytes = bin_data;
    g_audio_spec.freq = 44100;
    g_audio_spec.channels = 2;
    g_audio_spec.format = SDL_AUDIO_S16LE;

    // Now open a persistent stream with that spec
    g_audio_stream = SDL_OpenAudioDeviceStream(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, &g_audio_spec, NULL, NULL);
    if (!g_audio_stream)
    {
        SDL_Log("Failed to open global audio stream: %s", SDL_GetError());
        return;
    }
    SDL_ResumeAudioStreamDevice(g_audio_stream); // start it
}

void ShutdownAudio()
{
    SDL_DestroyAudioStream(g_audio_stream);
    SDL_free(g_ramState.effects_bytes);
}


int PlaySoundByID(uint16_t sound_id)
{
    // 2. Parse header and extract entry (same as before)
    const uint8_t* bin_data = (const uint8_t*)g_ramState.effects_bytes;

    uint32_t entry_addr = 7 + sound_id * 10;
    const uint8_t* entry = (const uint8_t*)bin_data + entry_addr;
    uint32_t offset = entry[2] | (entry[3] << 8) | ((uint32_t)entry[4] << 16) | ((uint32_t)entry[5] << 24);
    uint32_t size = entry[6] | (entry[7] << 8) | ((uint32_t)entry[8] << 16) | ((uint32_t)entry[9] << 24);

    // 3. Load WAV from memory
    SDL_IOStream* io = SDL_IOFromConstMem((const Uint8*)bin_data + offset, size);
    if (!io)
    {
        /* error */
    }

    SDL_AudioSpec spec;
    Uint8* pcm_data = NULL;
    Uint32 pcm_len = 0;
    if (!SDL_LoadWAV_IO(io, true, &spec, &pcm_data, &pcm_len))
    {
        SDL_Log("WAV load error: %s", SDL_GetError());
        return 1;
    }

    // 4. (Optional) Check that the WAV's format matches the global stream
    if (spec.freq != g_audio_spec.freq ||
        spec.channels != g_audio_spec.channels ||
        spec.format != g_audio_spec.format)
    {
        SDL_Log("WAV format mismatch – not playing");
        SDL_free(pcm_data);
        return 1;
    }

    // 5. Queue the audio data – THIS IS THREAD‑SAFE
    if (!SDL_PutAudioStreamData(g_audio_stream, pcm_data, pcm_len))
    {
        SDL_Log("Failed to queue audio: %s", SDL_GetError());
    }

    // 6. Clean up
    SDL_free(pcm_data);
    return 0;
}

int SoundThreadFunc(void* data)
{
    (void)data;

    while (g_ramState.running)
    {
        // global quit flag
        SDL_LockMutex(g_sound_queue.mutex);
        while (g_sound_queue.head == g_sound_queue.tail && g_ramState.running)
        {
            SDL_WaitCondition(g_sound_queue.cond, g_sound_queue.mutex);
        }
        if (!g_ramState.running)
        {
            SDL_UnlockMutex(g_sound_queue.mutex);
            break;
        }
        SoundCmd cmd = g_sound_queue.commands[g_sound_queue.tail];
        g_sound_queue.tail = (g_sound_queue.tail + 1) % SOUND_QUEUE_SIZE;
        SDL_UnlockMutex(g_sound_queue.mutex);

        // Play the sound using your existing function
        PlaySoundByID(cmd.sound_id);
    }
    return 0;
}


#define MUSIC_QUEUE_SIZE 8    // music changes are rare

typedef struct {
    uint16_t music_id;
} MusicCmd;

static struct {
    MusicCmd commands[MUSIC_QUEUE_SIZE];
    int head, tail;
    SDL_Mutex *mutex;
    SDL_Condition *cond;
} g_music_queue;

void InitMusicQueue(void) {
    g_music_queue.head = 0;
    g_music_queue.tail = 0;
    g_music_queue.mutex = SDL_CreateMutex();
    g_music_queue.cond  = SDL_CreateCondition();
}

void RequestMusic(uint16_t music_id) {
    SDL_LockMutex(g_music_queue.mutex);
    int next = (g_music_queue.head + 1) % MUSIC_QUEUE_SIZE;
    if (next == g_music_queue.tail) {
        SDL_Log("Music queue overflow, dropping request");
        SDL_UnlockMutex(g_music_queue.mutex);
        return;
    }
    g_music_queue.commands[g_music_queue.head] = (MusicCmd){ music_id };
    g_music_queue.head = next;
    SDL_SignalCondition(g_music_queue.cond);
    SDL_UnlockMutex(g_music_queue.mutex);
}




static MIX_Mixer *g_music_mixer = NULL;
static MIX_Track *g_music_track = NULL;
static MIX_Audio *g_current_music_audio = NULL;  // optional, f


bool InitMusicSystem(void)
{
    if (!MIX_Init()) {
        SDL_Log("MIX_Init failed: %s", SDL_GetError());
        return false;
    }

    InitMusicQueue();

    // Create a mixer that plays to the default audio device.
    // Spec can be NULL; it will convert automatically.
    g_music_mixer = MIX_CreateMixerDevice(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, NULL);
    if (!g_music_mixer) {
        SDL_Log("MIX_CreateMixerDevice failed: %s", SDL_GetError());
        return false;
    }

    // Create a single track to hold the music.
    g_music_track = MIX_CreateTrack(g_music_mixer);
    if (!g_music_track) {
        SDL_Log("MIX_CreateTrack failed: %s", SDL_GetError());
        return false;
    }

    return true;
}


void PlayMusicFromPack(uint16_t music_id)
{
    // Stop whatever is currently playing on the track
    MIX_StopTrack(g_music_track, 0);

    // Unref old audio (if any) so resources can be freed
    if (g_current_music_audio) {
        MIX_DestroyAudio(g_current_music_audio);
        g_current_music_audio = NULL;
    }

    // ----- load the new music from the pack -----
    // Assume music_bin and music_size are already loaded globally
    const uint8_t *ptr = (const uint8_t *)g_ramState.music_bytes;
    uint16_t count = ptr[5] | (ptr[6] << 8);
    if (music_id >= count) return;

    uint32_t entry_addr = 7 + music_id * 10;
    const uint8_t *entry = ptr + entry_addr;
    uint32_t offset = entry[2] | (entry[3] << 8) | ((uint32_t)entry[4] << 16) | ((uint32_t)entry[5] << 24);
    uint32_t size   = entry[6] | (entry[7] << 8) | ((uint32_t)entry[8] << 16) | ((uint32_t)entry[9] << 24);

    // Create an IOStream over the music file data
    SDL_IOStream *io = SDL_IOFromConstMem((const Uint8 *)g_ramState.music_bytes + offset, size);
    if (!io) return;

    // Load it as a MIX_Audio. No predecode, and let SDL_mixer close the IOStream.
    g_current_music_audio = MIX_LoadAudio_IO(g_music_mixer, io, false, true);
    if (!g_current_music_audio) {
        SDL_Log("MIX_LoadAudio_IO failed: %s", SDL_GetError());
        return;
    }

    // Assign it to our track
    if (!MIX_SetTrackAudio(g_music_track, g_current_music_audio)) {
        SDL_Log("MIX_SetTrackAudio failed: %s", SDL_GetError());
        return;
    }

    // Play the track, looping forever (-1)
    SDL_PropertiesID props = SDL_CreateProperties();
    SDL_SetNumberProperty(props, MIX_PROP_PLAY_LOOPS_NUMBER, -1);
    if (!MIX_PlayTrack(g_music_track, props)) {
        SDL_Log("MIX_PlayTrack failed: %s", SDL_GetError());
    }
    SDL_DestroyProperties(props);
}





int MusicThreadFunc(void *data)
{
    (void)data;

    // Load the whole music pack into memory once
    g_ramState.music_bytes = SDL_LoadFile("bin/music.bin", &g_ramState.music_size);
    if (!g_ramState.music_bytes) {
        SDL_Log("Failed to load music.bin: %s", SDL_GetError());
        return 1;
    }

    while (g_ramState.running) {
        SDL_LockMutex(g_music_queue.mutex);
        while (g_music_queue.head == g_music_queue.tail && g_ramState.running) {
            SDL_WaitCondition(g_music_queue.cond, g_music_queue.mutex);
        }
        if (!g_ramState.running) {
            SDL_UnlockMutex(g_music_queue.mutex);
            break;
        }
        MusicCmd cmd = g_music_queue.commands[g_music_queue.tail];
        g_music_queue.tail = (g_music_queue.tail + 1) % MUSIC_QUEUE_SIZE;
        SDL_UnlockMutex(g_music_queue.mutex);

        PlayMusicFromPack(cmd.music_id);
    }

    // Cleanup music
    MIX_StopTrack(g_music_track, 0);
    if (g_current_music_audio) MIX_DestroyAudio(g_current_music_audio);
    SDL_free(g_ramState.music_bytes);
    return 0;
}



void ShutdownMusicSystem(void)
{
    if (g_music_track) MIX_DestroyTrack(g_music_track);
    if (g_music_mixer) MIX_DestroyMixer(g_music_mixer);
    MIX_Quit();
}