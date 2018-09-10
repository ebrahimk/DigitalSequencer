#include <Audio.h>
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

const char code_map[16][2] ={{'a','D'},{'b','D'},{'c','D'},{'d','D'},{'e','D'},{'f','D'},{'g','D'},{'h','D'},{'i','D'},{'j','D'},{'k','D'},{'l','D'},{'m','D'},{'n','D'},{'o','D'},{'p','D'}};

void setup() {
  Serial6.begin(115200);
  Serial.begin(115200);
  Serial.println("Teensy Com Port");
  AudioMemory(8);
  sgtl5000_1.enable();
  sgtl5000_1.volume(.4);
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

  const char* code_mapStr[] =
  { "c3.wav", "d3.wav", "e3.wav", "f3.wav", "g3.wav", "a3.wav", "b3.wav", "c4.wav", "d4.wav", 
    "e4.wav", "f4.wav", "g4.wav", "a4.wav", "b4.wav", "c5.wav", "d5.wav"
  };
  char mystr[2]; //Initialized variable to store recieved data


void loop() {
  Serial.write(mystr, 2);
  Serial6.readBytes(mystr,2); 
  Serial.write(mystr,2); 
  Serial.write("\n");
  Serial6.flush();

 
 
   for(int i = 0; i < 16; i++){ 
    if ((code_map[i][0] == mystr[0] )&&(code_map[i][1] == mystr[1])){       
          playSdWav1.play(code_mapStr[i]); 
    }
  }
    
}
