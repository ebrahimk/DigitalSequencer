//Number of potentiometer analog pin inputs
#define NUM_PINS_IN 9

  // analog_pins[NUM_PINS_IN] = {"A14", "A15", "A16", "A17", "A18", "A19", "A20", "A21", "A22"};
static const uint8_t    color_mappings[12][3] = {
                      {255,0,0}, //Red
                      {255,125,0}, //Orange
                      {255,255,0}, //Yellow
                      {125,255,0}, //Spring Green
                      {0,255,0},  //Green
                      {0,255,125}, //Turquiose
                      {0,255,255}, //Cyan
                      {0,125,255}, //Ocean
                      {0,0,255},  //Blue
                      {125,0,255}, //Violet
                      {255,0,255}, //Magenta
                      {255,0,125}};  //Rasberry
                      
void setup() {
  // put your setup code here, to run once:
  Serial.begin(300); 
  for(int i = 2; i < 8; i++){
    pinMode(i, OUTPUT);
  }
  
}
//19,18, 17 
void loop() {

            analogWrite(2, color_mappings[9][0]);
            analogWrite(3, color_mappings[9][1]);
            analogWrite(4, color_mappings[9][2]);  


            analogWrite(5, color_mappings[11][0]);
            analogWrite(6, color_mappings[11][1]);
            analogWrite(7, color_mappings[11][2]); 

            
}
