#ifndef BUTTON_H
#define BUTTON_H
#include <Audio.h>
#include <SD.h>

class Button{
  public:
    Button(AudioPlaySdWav* player, char code);
    AudioPlaySdWav* player;
    char code;
    int RGB[3];
    bool is_pressed;
};

#endif
