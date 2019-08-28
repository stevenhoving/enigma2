#pragma once

typedef struct audio_mixer {
    unsigned int volume_left;
    unsigned int volume_right;
    // what else do we need? bass, pass-through, ...
} audio_mixer_t;

