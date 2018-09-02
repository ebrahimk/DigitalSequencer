//Number of potentiometer analog pin inputs
#define NUM_PINS_IN 9

  // analog_pins[NUM_PINS_IN] = {"A14", "A15", "A16", "A17", "A18", "A19", "A20", "A21", "A22"};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(300); 
  //for(int i = 0; i < (sizeof(analog_pins)/sizeof(analog_pins[0])); i++){
   //   pinMode(analog_pins[i], INPUT);    
//  }
  
}
//19,18, 17 
void loop() {
  // put your main code here, to run repeatedly:
  
  /*for(int i = 0; i < (sizeof(analog_pins)/sizeof(analog_pins[0])); i++){
    
    last_state[i] = analogRead(analog_pins[i]);
    if
  
  Serial.print("PIN ");
  Serial.print(analog_pins[i]);
  Serial.print("  ");
  Serial.print(analogRead(analog_pins[i])); 
  Serial.print("\n");
  }*/
  //uint8_t pin = analog_pins[1];
  //19, 18,17, 16,14 
  //15 IS FUCKED SO IS 18
  Serial.print("PIN A20");

  Serial.print("  ");
  Serial.print(analogRead(A20)); 
  Serial.print("\n");
  //six side -- top to bottum (leds top) 1, 
}
