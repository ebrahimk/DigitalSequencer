char mystr[4]; //Initialized variable to store recieved data

void setup() {
  Serial6.begin(115200);
  Serial.begin(115200);
}

void loop() {
  Serial6.readBytes(mystr,4); 
  Serial.write(mystr,4); 
  Serial.write("\n");
  Serial6.flush();
}
