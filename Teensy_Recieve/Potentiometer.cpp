#include "Potentiometer.h"
#include <Arduino.h>

Potentiometer::Potentiometer(int pin_num, int min_value){
  this->pin_num = pin_num;
  this->min_value = min_value;
}

void Potentiometer::set_range(int range){
  this->range = range;
}

int Potentiometer::read(){
      return map(analogRead(this->pin_num), this->min_value, 1023, 0, this->range);
}
