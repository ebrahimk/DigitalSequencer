#include "Sound_lib.h"
#include <Arduino.h>

Sound_lib::Sound_lib(Note_set** note_sets, int num_sounds){
  this->num_sounds = num_sounds;
  this->current_sound = 0;
  this->sounds = new Sound*[this->num_sounds];

  for(int i = 0; i < this->num_sounds; i++){
    this->sounds[i] = new Sound(note_sets[i]);
    Serial.println("******************NEW SOUND CREATED**************");
  }
}
