#include<Arduino.h>
#include"test.h"

Test::Test(int number, char letter){
  this->number = number;
  this->letter = letter;
}

void Test::initialize(int number, char letter){
  this->number = number;
  this->letter = letter; 
}

int Test::get_number(){
  return this->number;
}

char Test::get_letter(){
  return this->letter;
}
