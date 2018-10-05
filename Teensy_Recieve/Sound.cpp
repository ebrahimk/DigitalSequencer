#include "Sound.h"
#include<Arduino.h>

Sound::Sound(Note_set* note_set){
  this->current_key = 0;
  if(note_set->is_percussion){
    this->percussive_key = new Music_key(note_set, -1);
    Serial.println("SINGLE CHROMATIC SCALE FOR PERCUSSIVE INSTRUMENT CREATED!");
  }

  else{
    this->percussive_key = NULL;
    this->keys = new Music_key*[12];          //This is the pointer to an array of Music_key pointers
    for(int i = 0; i < 12; i++){
      this->keys[i] = new Music_key(note_set, i);
      Serial.println("NEW MELODIC KEY CREATED!");
    }
  }
}
