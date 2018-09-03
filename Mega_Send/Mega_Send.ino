
void setup() {
  Serial1.begin(115200);
  Serial.begin(115200);
}

void loop() {
 char mystr[4] =  {'m', 'o', '#','\0'};
  for(int i = 33; i < 133; i++){
    mystr[2] = i;
    Serial1.write(mystr, 4); 
    Serial.write(mystr);
    Serial.write("\n");
    Serial1.flush(); 
  }
}


