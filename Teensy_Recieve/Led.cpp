#include"Led.h"
#include<Arduino.h>

Led::Led(int pin_nums[]){
  for(int i = 0; i < 3; i++){
    this->color[i] = 255; //initialized to white
    this->pin_nums[i] = pin_nums[i];
  }
}

//Takes an array of three integers [R, G, B] and writes
//the values out to the three pins associated with the Red, Green and Blue
//terminals of the LED
void Led::set_color(int color[]){
  for(int i = 0; i < 3; i++){
    this->color[i] = color[i];
    analogWrite(this->pin_nums[i], this->color[i]);
  }
}
