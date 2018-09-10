i#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

AudioPlaySdWav           playSdWav1;
AudioOutputI2S           audioOutput;
AudioConnection          patchCord1(playSdWav1, 0, audioOutput, 0);
AudioConnection          patchCord2(playSdWav1, 1, audioOutput, 1);
AudioControlSGTL5000     sgtl5000_1;

#define SDCARD_CS_PIN    10
#define SDCARD_MOSI_PIN  7
#define SDCARD_SCK_PIN   14

char* code_mapStr[16] ={"aD.wav","bD.wav","cD.wav","dD.wav","eD.wav","fD.wav","gD.wav","hD.wav","iD.wav","jD.wav","kD.wav","lD.wav","mD.wav","nD.wav","oD.wav","pD.wav"};
char code_map[16][2] ={{'a','D'},{'b','D'},{'c','D'},{'d','D'},{'e','D'},{'f','D'},{'g','D'},{'h','D'},{'i','D'},{'j','D'},{'l','D'},{'m','D'},{'n','D'},{'o','D'},{'p','D'}};
  char mystr[2] ;

void setup() {
  Serial6.begin(115200);
  Serial.begin(9600);
  Serial.println("Teensy Com Port");
  AudioMemory(8);
  sgtl5000_1.enable();
  sgtl5000_1.volume(.8);
  SPI.setMOSI(SDCARD_MOSI_PIN);
  SPI.setSCK(SDCARD_SCK_PIN);
  if (!(SD.begin(SDCARD_CS_PIN))) {
    while (1) {
      Serial.println("Unable to access the SD card");
      delay(500);
    }
  }
  pinMode(13, OUTPUT); // LED on pin 13
  delay(1000);
}


void loop() {
  mystr[0] ='\0';
  mystr[1] ='\0'; 
  Serial6.flush();
  Serial6.readBytes(mystr,2); 
  Serial.write(mystr,2); 
  Serial.write("\n");
  
    


  for(int i = 0; i < 16; i++){
       if ((code_map[i][0] == mystr[0] )&&(code_map[i][1] == mystr[1])){ 
        Serial.println(code_mapStr[i]);
        playSdWav1.play(code_mapStr[i]); 
   } 
 }
}
