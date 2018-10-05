#ifndef SOUND_LIB_H
#define SOUND_LIB_H
#include "Sound.h"

class Sound_lib{
  public:
    Sound_lib(Note_set** note_sets, int num_sounds);
    Sound** sounds;
    int num_sounds;
    int current_sound;
};

#endif
