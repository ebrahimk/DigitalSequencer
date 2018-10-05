#ifndef SOUND_H
#define SOUND_H
#include "Music_key.h"

class Sound{
  public:
    Sound(Note_set* note_set);
    Music_key** keys;
    int current_key;
};

#endif
