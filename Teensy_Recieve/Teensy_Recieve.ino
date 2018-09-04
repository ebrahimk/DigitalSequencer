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

char mystr[2]; //Initialized variable to store recieved data

void setup() {
  Serial6.begin(115200);
  Serial.begin(115200);
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
  Serial6.readBytes(mystr,2); 
  Serial.write(mystr,2); 
  Serial.write("\n");
  Serial6.flush();

  char c3[2] = {'a','D'};
  if ((c3[0] == mystr[0] )&&(c3[1] == mystr[1])){
        playSdWav1.isPlaying() == false;
        playSdWav1.play("c3.wav"); 
    
  }
  else if ((c3[0] == mystr[0] )&&(c3[1] == mystr[1])){
        playSdWav1.isPlaying() == false;
        playSdWav1.play("c3.wav"); 
    
  }


  
}
