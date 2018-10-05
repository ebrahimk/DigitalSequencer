#ifndef MUSIC_KEY_H
#define MUSIC_KEY_H

#include"Note_set.h"

class Music_key{
  public:
    Music_key(Note_set* note_set, int key);
    char** notes;
    int  key;
    int  length;
    int octaves;
};

#endif
