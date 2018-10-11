#include "Potentiometer.h"
#include <Arduino.h>

Potentiometer::Potentiometer(int pin_num, int min_value, int is_reversed){
  this->pin_num = pin_num;
  this->min_value = min_value;
  this->is_reversed = is_reversed;
}

void Potentiometer::set_range(int range){
  this->range = range;
}

int Potentiometer::read(){
    if(is_reversed)
      return map(analogRead(this->pin_num), this->min_value, 1023, this->range, 0);
    else
      return map(analogRead(this->pin_num), this->min_value, 1023, 0, this->range);
}
