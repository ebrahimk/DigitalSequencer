#include"Music_key.h"
#include<Arduino.h>

Music_key::Music_key(Note_set* note_set, int key){
    int intervals[7] = {0, 2, 4, 5, 7, 9, 11};
    int i, j, index = 0;

    //All sound files to be used within this code have "A" as the lowest note.
    //Implementation, all note_set objects are recorded as having one less octave than what is actually stored on the SD card
    //Each key must contain at most 32 notes (2*16) Thus the lowest note A will span 4 octaves and 4 notes of the 5th octave. This is the standard I am setting
    //The violin sound array contains 3 full octaves but in order for Ab to have the same range as A (4 notes into the 5th octave), we say the range is two octaves.
    this->octaves = note_set->octaves;

    if(note_set->is_percussion){

    //  Serial.println("PERCUSSIVE INSTRUMENT BEING INTIALIZED");
      this->length = (note_set->octaves+1)*8;
      this->key = -1;
      this->notes = new char*[this->length];

        for(i = 0; i < this->length; i++){
          this->notes[i] = note_set->data[i];
        //  Serial.print(i);
        //  Serial.print(": ");
        //  Serial.println(this->notes[i]);
        //  delay(20);
        }
    }

    else{
      this->length = (note_set->octaves * 8);
      this->key = key;
      this->notes = new char*[this->length];

/*
      Serial.print("THIS IS THE LENGTH, OCTAVES, INDEX: ");
      Serial.print(this->length);
      Serial.print(", ");
      Serial.print(this->octaves);
      Serial.print(", ");
      Serial.println(index);
*/

  //    Serial.print("MELODIC INSTRUMENT BEING INTIALIZED IN THE KEY OF: ");
  //    Serial.println(this->key);


      for(i = 0; i < (note_set->octaves + 1); i++){
        for(j = 0; j < 7; j++){
          this->notes[index] = note_set->data[(key+12*i+intervals[j])];
      //    Serial.print(index);
      //    Serial.print(": ");
      //    Serial.println(this->notes[index]);
          index++;
          if(index == (this->octaves * 8))
            break;
      //    delay(20);
        }
      }
    }
}
