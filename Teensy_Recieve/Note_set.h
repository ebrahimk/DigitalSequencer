#ifndef NOTE_SET_H
#define NOTE_SET_H

class Note_set{
  public:
    Note_set(char** data, int length, int octaves, bool is_percussion);
    char** data;
    int octaves;
    int length;
    bool is_percussion;
};

#endif
