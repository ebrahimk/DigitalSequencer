#include "Sound.h"
#include<Arduino.h>

Sound::Sound(Note_set* note_set){
  this->keys = new Music_key*[12];          //This is the pointer to an array of Music_key pointers
  this->current_key = 0;
  for(int i = 0; i < 12; i++){
    this->keys[i] = new Music_key(note_set, i);
    Serial.println("NEW KEY CREATED!");
  }
}
