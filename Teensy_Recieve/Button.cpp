#include "Button.h"
#include<Arduino.h>

Button::Button(AudioPlaySdWav* player, char code){
  this->player = player;
  this->is_pressed = false;
  this->RGB[0] = 15;
  this->RGB[1] = 167;
  this->RGB[2] = 253;
  this->code = code;
}
