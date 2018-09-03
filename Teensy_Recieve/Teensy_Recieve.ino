char mystr[2]; //Initialized variable to store recieved data

void setup() {
  Serial6.begin(115200);
  Serial.begin(115200);
  Serial.println("Teensy Com Port");
}

void loop() {
  Serial6.readBytes(mystr,2); 
  Serial.write(mystr,2); 
  Serial.write("\n");
  Serial6.flush();
}
