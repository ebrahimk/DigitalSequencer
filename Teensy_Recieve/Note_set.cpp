#include"Note_set.h"
#include<Arduino.h>

Note_set::Note_set(char** data, int length, int octaves, bool is_percussion){
  Serial.println("CONSTRUCTING NOTE_SET");
  this->data = data;
  this->length = length;
  this->octaves = octaves;
  this->is_percussion = is_percussion;
}
