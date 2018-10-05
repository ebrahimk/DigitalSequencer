#include"test.h"

Test* test1 = new Test(5, 'h');

void setup() {
  Serial.begin(1200);
  //test1->initialize(5, 'h');
}

void loop() {
  Serial.print("This is the TEST objects information: ");
  Serial.print(test1->get_number());
  Serial.print(", " );
  Serial.println(test1->get_letter());
}
