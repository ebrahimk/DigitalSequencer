#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

#include "Led.h"
#include "Sound_lib.h"
#include "Potentiometer.h"
#include "Button.h"

/****AUDIO CONNECTIONS*****/

#define SDCARD_CS_PIN    10
#define SDCARD_MOSI_PIN  7
#define SDCARD_SCK_PIN   14

#define NUM_SOUNDS   6

#define NUM_UNIVERSAL_POTENTIOMETERS 5
#define NUM_CONFIG_POTENTIOMETERS 6

// GUItool: begin automatically generated code
AudioPlaySdWav           playSdWav4;     //xy=144.00571060180664,407.4602851867676
AudioPlaySdWav           playSdWav1;     //xy=145.0057029724121,289.46025562286377
AudioPlaySdWav           playSdWav8;     //xy=144.0056915283203,565.4601669311523
AudioPlaySdWav           playSdWav7;     //xy=145.00569915771484,523.4602127075195
AudioPlaySdWav           playSdWav3;     //xy=146.00568771362305,365.4602699279785
AudioPlaySdWav           playSdWav5;     //xy=146.00568771362305,446.4602336883545
AudioPlaySdWav           playSdWav6;     //xy=146.0056872367859,481.46027755737305
AudioPlaySdWav           playSdWav12;    //xy=151.0057144165039,723.5511236190796
AudioPlaySdWav           playSdWav16;    //xy=150.55113983154297,884.3693437576294
AudioPlaySdWav           playSdWav2;     //xy=153.0057144165039,327.4602222442627
AudioPlaySdWav           playSdWav10;    //xy=153.0056915283203,653.5511260032654
AudioPlaySdWav           playSdWav11;    //xy=154.00569915771484,687.5511469841003
AudioPlaySdWav           playSdWav15;    //xy=157.0056915283203,849.551157951355
AudioPlaySdWav           playSdWav14;    //xy=158.0056915283203,815.5511817932129
AudioPlaySdWav           playSdWav13;    //xy=160.0056915283203,780.5511379241943
AudioPlaySdWav           playSdWav9;     //xy=161.00569915771484,619.5511603355408

AudioMixer4              mixer1;         //xy=329.00560760498047,283.460205078125
AudioMixer4              mixer4;         //xy=328.0056838989258,688.4602403640747
AudioMixer4              mixer3;         //xy=329.00569915771484,614.4602317810059
AudioMixer4              mixer2;         //xy=330.00561141967773,382.46015548706055
AudioMixer4              mixer6;         //xy=331.00569915771484,539.4601898193359
AudioMixer4              mixer5;         //xy=332.0056915283203,467.4602394104004
AudioMixer4              mixer8;         //xy=349.0056915283203,835.9148044586182
AudioMixer4              mixer7;         //xy=353.00572967529297,760.6419811248779
AudioMixer4              mixer9;         //xy=532.0056686401367,549.6420440673828
AudioMixer4              mixer10;        //xy=536.0056686401367,648.732988357544
AudioEffectDelay         delay1;         //xy=624.5511589050293,803.7330093383789
AudioOutputI2S           i2s1;           //xy=690.0056686401367,592.460223197937
AudioConnection          patchCord1(playSdWav4, 0, mixer1, 3);
AudioConnection          patchCord2(playSdWav4, 1, mixer2, 3);
AudioConnection          patchCord3(playSdWav1, 0, mixer1, 0);
AudioConnection          patchCord4(playSdWav1, 1, mixer2, 0);
AudioConnection          patchCord5(playSdWav8, 0, mixer5, 3);
AudioConnection          patchCord6(playSdWav8, 1, mixer6, 3);
AudioConnection          patchCord7(playSdWav7, 0, mixer5, 2);
AudioConnection          patchCord8(playSdWav7, 1, mixer6, 2);
AudioConnection          patchCord9(playSdWav3, 0, mixer1, 0);
AudioConnection          patchCord10(playSdWav3, 1, mixer2, 2);
AudioConnection          patchCord11(playSdWav5, 0, mixer5, 0);
AudioConnection          patchCord12(playSdWav5, 1, mixer6, 0);
AudioConnection          patchCord13(playSdWav6, 0, mixer5, 1);
AudioConnection          patchCord14(playSdWav6, 1, mixer6, 1);
AudioConnection          patchCord15(playSdWav12, 0, mixer3, 3);
AudioConnection          patchCord16(playSdWav12, 1, mixer4, 3);
AudioConnection          patchCord17(playSdWav16, 0, mixer7, 3);
AudioConnection          patchCord18(playSdWav16, 1, mixer8, 3);
AudioConnection          patchCord19(playSdWav2, 0, mixer1, 1);
AudioConnection          patchCord20(playSdWav2, 1, mixer2, 1);
AudioConnection          patchCord21(playSdWav10, 0, mixer3, 1);
AudioConnection          patchCord22(playSdWav10, 1, mixer4, 1);
AudioConnection          patchCord23(playSdWav11, 0, mixer3, 2);
AudioConnection          patchCord24(playSdWav11, 1, mixer4, 2);
AudioConnection          patchCord25(playSdWav15, 0, mixer7, 2);
AudioConnection          patchCord26(playSdWav15, 1, mixer8, 2);
AudioConnection          patchCord27(playSdWav14, 0, mixer7, 1);
AudioConnection          patchCord28(playSdWav14, 1, mixer8, 1);
AudioConnection          patchCord29(playSdWav13, 0, mixer7, 0);
AudioConnection          patchCord30(playSdWav13, 1, mixer8, 0);
AudioConnection          patchCord31(playSdWav9, 0, mixer3, 0);
AudioConnection          patchCord32(playSdWav9, 1, mixer4, 0);
AudioConnection          patchCord33(mixer1, 0, mixer9, 0);
AudioConnection          patchCord34(mixer4, 0, mixer10, 2);
AudioConnection          patchCord35(mixer3, 0, mixer9, 2);
AudioConnection          patchCord36(mixer2, 0, mixer10, 0);
AudioConnection          patchCord37(mixer6, 0, mixer10, 1);
AudioConnection          patchCord38(mixer5, 0, mixer9, 1);
AudioConnection          patchCord39(mixer8, 0, mixer10, 3);
AudioConnection          patchCord40(mixer7, 0, mixer9, 3);
AudioConnection          patchCord41(mixer9, 0, i2s1, 0);
AudioConnection          patchCord42(mixer10, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;

char* violin[] = {"violin_a1.wav", "violin_a#1.wav", "violin_b1.wav", "violin_c1.wav", "violin_c#1.wav", "violin_d1.wav", "violin_d#1.wav", "violin_e1.wav", "violin_f1.wav", "violin_f#1.wav", "violin_g1.wav", "violin_g#1.wav",
	"violin_a2.wav", "violin_a#2.wav", "violin_b2.wav", "violin_c2.wav", "violin_c#2.wav", "violin_d2.wav", "violin_d#2.wav", "violin_e2.wav", "violin_f2.wav", "violin_f#2.wav", "violin_g2.wav", "violin_g#2.wav",
	"violin_a3.wav", "violin_a#3.wav", "violin_b3.wav", "violin_c3.wav", "violin_c#3.wav", "violin_d3.wav", "violin_d#3.wav", "violin_e3.wav", "violin_f3.wav", "violin_f#3.wav", "violin_g3.wav", "violin_g#3.wav",
	"violin_a4.wav", "violin_a#4.wav", "violin_b4.wav", "violin_c4.wav", "violin_c#4.wav"};
//NOTE: the last file in this array "violin_c#4.wav" does not actually exist on the SD card

char* bass[] ={ "808_a1.wav", "808_a#1.wav", "808_b1.wav", "808_c1.wav", "808_c#1.wav", "808_d1.wav", "808_d#1.wav", "808_e1.wav", "808_f1.wav", "808_f#1.wav", "808_g1.wav", "808_g#1.wav",
	"808_a2.wav", "808_a#2.wav", "808_b2.wav","808_c2.wav", "808_c#2.wav", "808_d2.wav", "808_d#2.wav", "808_e2.wav", "808_f2.wav", "808_f#2.wav", "808_g2.wav", "808_g#2.wav",
	"808_a3.wav", "808_a#3.wav", "808_b3.wav", "808_c3.wav", "808_c#3.wav", "808_d3.wav", "808_d#3.wav", "808_e3.wav", "808_f3.wav", "808_f#3.wav", "808_g3.wav", "808_g#3.wav",
	"808_a4.wav", "808_a#4.wav", "808_b4.wav","808_c4.wav", "808_c#4.wav", "808_d4.wav", "808_d#4.wav", "808_e4.wav", "808_f4.wav", "808_f#4.wav", "808_g4.wav", "808_g#4.wav",
	"808_a5.wav", "808_a#5.wav", "808_b5.wav", "808_c5.wav", "808_c#5.wav", "808_d5.wav", "808_d#5.wav", "808_e5.wav", "808_f5.wav", "808_f#5.wav", "808_g5.wav", "808_g#5.wav",
	"808_a6.wav", "808_a#6.wav", "808_b6.wav", "808_c6.wav", "808_c#6.wav"};

char* piano[] =   {"piano_a1.wav", "piano_a#1.wav", "piano_b1.wav", "piano_c1.wav", "piano_c#1.wav", "piano_d1.wav", "piano_d#1.wav", "piano_e1.wav", "piano_f1.wav", "piano_f#1.wav", "piano_g1.wav", "piano_g#1.wav",
	"piano_a2.wav", "piano_a#2.wav", "piano_b2.wav", "piano_c2.wav", "piano_c#2.wav", "piano_d2.wav", "piano_d#2.wav", "piano_e2.wav", "piano_f2.wav", "piano_f#2.wav", "piano_g2.wav", "piano_g#2.wav",
	"piano_a3.wav", "piano_a#3.wav", "piano_b3.wav", "piano_c3.wav", "piano_c#3.wav", "piano_d3.wav", "piano_d#3.wav", "piano_e3.wav", "piano_f3.wav", "piano_f#3.wav", "piano_g3.wav", "piano_g#3.wav",
	"piano_a4.wav", "piano_a#4.wav", "piano_b4.wav", "piano_c4.wav", "piano_c#4.wav", "piano_d4.wav", "piano_d#4.wav", "piano_e4.wav", "piano_f4.wav", "piano_f#4.wav", "piano_g4.wav", "piano_g#4.wav",
	"piano_a5.wav", "piano_a#5.wav", "piano_b5.wav", "piano_c5.wav", "piano_c#5.wav", "piano_d5.wav", "piano_d#5.wav", "piano_e5.wav", "piano_f5.wav", "piano_f#5.wav", "piano_g5.wav", "piano_g#5.wav",
	"piano_a6.wav", "piano_a#6.wav", "piano_b6.wav", "piano_c6.wav", "piano_c#6.wav"};

char* kick[] ={ "kick_a1.wav", "kick_a#1.wav", "kick_b1.wav", "kick_c1.wav", "kick_c#1.wav", "kick_d1.wav", "kick_d#1.wav", "kick_e1.wav", "kick_f1.wav", "kick_f#1.wav", "kick_g1.wav", "kick_g#1.wav",
	"kick_a2.wav", "kick_a#2.wav", "kick_b2.wav", "kick_c2.wav", "kick_c#2.wav", "kick_d2.wav", "kick_d#2.wav", "kick_e2.wav", "kick_f2.wav", "kick_f#2.wav", "kick_g2.wav", "kick_g#2.wav",
	"kick_a3.wav", "kick_a#3.wav", "kick_b3.wav", "kick_c3.wav", "kick_c#3.wav", "kick_d3.wav", "kick_d#3.wav", "kick_e3.wav", "kick_f3.wav", "kick_f#3.wav", "kick_g3.wav", "kick_g#3.wav"};

char* snare[] ={"snare_a1.wav", "snare_a#1.wav", "snare_b1.wav", "snare_c1.wav", "snare_c#1.wav", "snare_d1.wav", "snare_d#1.wav", "snare_e1.wav", "snare_f1.wav", "snare_f#1.wav", "snare_g1.wav", "snare_g#1.wav",
	"snare_a2.wav", "snare_a#2.wav", "snare_b2.wav", "snare_c2.wav", "snare_c#2.wav", "snare_d2.wav", "snare_d#2.wav", "snare_e2.wav", "snare_f2.wav", "snare_f#2.wav", "snare_g2.wav", "snare_g#2.wav",
	"snare_a3.wav", "snare_a#3.wav", "snare_b3.wav", "snare_c3.wav", "snare_c#3.wav", "snare_d3.wav", "snare_d#3.wav", "snare_e3.wav", "snare_f3.wav", "snare_f#3.wav", "snare_g3.wav", "snare_g#3.wav"};

char* hihat[] ={"hat_a1.wav", "hat_a#1.wav", "hat_b1.wav", "hat_c1.wav", "hat_c#1.wav", "hat_d1.wav", "hat_d#1.wav", "hat_e1.wav", "hat_f1.wav", "hat_f#1.wav", "hat_g1.wav", "hat_g#1.wav",
	"hat_a2.wav", "hat_a#2.wav", "hat_b2.wav", "hat_c2.wav", "hat_c#2.wav", "hat_d2.wav", "hat_d#2.wav", "hat_e2.wav", "hat_f2.wav", "hat_f#2.wav", "hat_g2.wav", "hat_g#2.wav",
	"hat_a3.wav", "hat_a#3.wav", "hat_b3.wav", "hat_c3.wav", "hat_c#3.wav", "hat_d3.wav", "hat_d#3.wav", "hat_e3.wav", "hat_f3.wav", "hat_f#3.wav", "hat_g3.wav", "hat_g#3.wav"};



Potentiometer universal_pot0(65, 502, 0);
Potentiometer universal_pot1(50, 500, 1);
Potentiometer universal_pot2(64, 530, 0);
Potentiometer universal_pot3(67, 523, 1);
Potentiometer universal_pot4(49, 500, 1);

Potentiometer view_pot0(34, 530, 1);
Potentiometer view_pot1(33, 515, 1);	//view_pot1 above behaves finiky, hardware issue!
Potentiometer view_pot2(39, 520, 1);
Potentiometer view_pot3(66, 473, 1);
Potentiometer view_pot4(31, 520, 1);
Potentiometer view_pot5(32, 515, 1);

Potentiometer* universal_pots[NUM_UNIVERSAL_POTENTIOMETERS] = {&universal_pot0, &universal_pot1, &universal_pot2, &universal_pot3, &universal_pot4};
Potentiometer* view_pots[NUM_CONFIG_POTENTIOMETERS] = {&view_pot0, &view_pot1, &view_pot2, &view_pot3, &view_pot4, &view_pot5};

/************LED_CONTROL_STRUCTURES***************************/

//one LED does the battery life and the other LED will do the mode
int battery_leds[3] ={35, 36, 37};
int mode_leds[3] = {38, 29, 30};
//initialize LED objects
Led battery_led(battery_leds);
Led mode_led(mode_leds);
//int led_pins[6] ={16 ,17, 18, 19, 29, 30};

/************BUTTONS *******************************************/
static const uint8_t    color_mappings[14][3] = {
                      {0,255,255}, //Cyan8
                      {0,125,255}, //Ocean9
                      {0,0,255},  //Blue10
                      {138,43,226}, //Darek violet11
                      {125,0,255}, //Violet12
                      {255,0,255}, //Magenta13
                      {255,0,125},  //Rasberry14
                      {255,0,0}, //Red2
                      {255,125,0}, //Orange3
                      {255,255,0}, //Yellow4
                      {125,255,0}, //Spring Green5
                      {0,255,0},  //Green6
                      {0,255,125}, //Turquiose7
};

Button button_A(&playSdWav1, 'A');
Button button_B(&playSdWav2, 'B');
Button button_C(&playSdWav3, 'C');
Button button_D(&playSdWav4, 'D');
Button button_E(&playSdWav5, 'E');
Button button_F(&playSdWav6, 'F');
Button button_G(&playSdWav7, 'G');
Button button_H(&playSdWav8, 'H');
Button button_I(&playSdWav9, 'I');
Button button_J(&playSdWav10, 'J');
Button button_K(&playSdWav11, 'K');
Button button_L(&playSdWav12, 'L');
Button button_M(&playSdWav13, 'M');
Button button_N(&playSdWav14, 'N');
Button button_O(&playSdWav15, 'O');
Button button_P(&playSdWav16, 'P');

Button* buttons[16] = {&button_A, &button_B, &button_C, &button_D, &button_E, &button_F, &button_G, &button_H, &button_I, &button_J, &button_K, &button_L, &button_M, &button_N, &button_O, &button_P};
/**********COMMUNICATION BETWEEN TEENSY AND MEGA2560**********/

const char code_map_D[16][2] ={{'a','D'},{'b','D'},{'c','D'},{'d','D'},{'e','D'},{'f','D'},{'g','D'},{'h','D'},{'i','D'},{'j','D'},{'k','D'},{'l','D'},{'m','D'},{'n','D'},{'o','D'},{'p','D'}};
const char code_map_U[16][2] ={{'a','U'},{'b','U'},{'c','U'},{'d','U'},{'e','U'},{'f','U'},{'g','U'},{'h','U'},{'i','U'},{'j','U'},{'k','U'},{'l','U'},{'m','U'},{'n','U'},{'o','U'},{'p','U'}};

char state_str[16];

char mystr[2];

uint8_t button_states1[48] ={0, 255, 255, 0, 125, 255, 0, 0, 255, 138, 43, 226, 125, 0, 255, 255, 0, 255, 255, 0, 125, 255, 0, 0, 255, 125, 0, 255, 255, 0, 125, 255, 0, 0, 255, 0, 0, 255, 125, 255, 255, 255, 255, 255, 255, 255, 255, 255 };
uint8_t button_states2[48] = {255, 0, 255, 255, 255, 0, 255, 0, 255, 255, 255, 0, 255, 0, 255, 255, 255, 0, 255, 0, 255, 255, 255, 0, 255, 0, 255, 255, 255, 0, 255, 0, 255, 255, 255, 0, 255, 0, 255, 255, 255, 0, 255, 0, 255, 255, 255, 0};
uint8_t button_states3[48];

int sustain[16];

//SPISettings settingsA(8000000, MSBFIRST, SPI_MODE0);

/********** EXECUTABLE PROGRAM **************/

void setup() {
	//ENABLE SERIAL COMMUNICATION
	Serial6.begin(115200);


/*
	pinMode(20, OUTPUT); //this is the slave select pin, make sure it is always an output
	SPI2.begin();
	pinMode(43, OUTPUT);	//digital pin 43 on Teensy will be used to enable the slave device.
  digitalWrite(43, HIGH); // because we only have two devices, we will continuoulsy enable the Arduino Mega
*/


	Serial.begin(1200);
	while (!Serial) ;

 //***************************************************************
	//configure buttons state arrays for testing, how responsive can we make this with USART
	uint8_t i;
	Serial.println("\n");
	for(i = 0; i < 48; i++){
		button_states3[i] = 0;
	}
 //***************************************************************



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


	//SET THE RANGE FOR THE UNIVERSAL POTENTIOMETERS
	for(int i = 0; i < 5; i++){
		universal_pots[i]->set_range(25);
	}

	//SET THE RANGE FOR THE CONFIG POTENTIOMETERS
	for(int i = 0; i < 6; i++){
		view_pots[i]->set_range(25);
	}

	//CONFIGURE sustain ARRAY
	for(int i =0; i< 16; i++){
		sustain[i] = 0;
	}
}


void loop() {
	Serial.println("Constructing sound library...");
	Note_set* violin_sounds = new Note_set(violin, 40, 2, false);
	Note_set* bass_sounds = new Note_set(bass, 65, 4, false);
	Note_set* piano_sounds = new Note_set(piano, 65, 4, false);
	Note_set* kick_sounds = new Note_set(kick, 36, 3, true);
	Note_set* snare_sounds = new Note_set(snare, 36, 3, true);
	Note_set* hihat_sounds = new Note_set(hihat, 36, 3, true);

	Note_set* note_sets[NUM_SOUNDS] = {kick_sounds, snare_sounds, hihat_sounds, violin_sounds, bass_sounds, piano_sounds,};

	Sound_lib* new_sound_lib = new Sound_lib(note_sets, NUM_SOUNDS);
	while(1){
			//POLL THE POTENTIOMETERS UNIVERSAL THEN VIEW
			//CREATE A SIMPLE POTENTIOMETER REEADING, DO THE UNIVERSAL POTS FIRST.


	//		Serial.write(mystr, 2);   //Write to console for Debugging
			Serial6.readBytes(mystr,2);
			Serial.write(mystr,2);    //Write to console for Debugging
			Serial.write("\n");       //Write to console for Debugging
			Serial6.flush();

			mystr[0] = 'x';
			mystr[1] = 'x';



			if(universal_pots[0]->read() > 10){
				Serial.println("BUTTON STATE CHANGED 1");
				Serial6.write(button_states1, 48);
				Serial6.flush();
			}
			else if(universal_pots[1]->read() > 10){
				Serial.println("BUTTON STATE CHANGED 2");
				Serial6.write(button_states2, 48);
				Serial6.flush();
			}
			else{
				Serial.println("no color: ");
				Serial6.write(button_states3, 48);
				Serial6.flush();
			}



/*
		int i, j, count = 0;
		digitalWrite(43, LOW);
		SPI2.beginTransaction(settingsA);
		//16 buttons and for each button we have unique RGB values
		for(i = 0; i < 16; i++){
			for(j = 0; j < 3; j++){
				SPI2.transfer(buttons[count]->RGB[j]);
				Serial.print("Data transferred: ");
				Serial.println(buttons[count]->RGB[j]);
			}
			count++;
		}
		SPI2.endTransaction();
		digitalWrite(43, HIGH);
*/








/*
	int i;
	for(i = 0; i < 15; i++){
	   if (((code_map_D[i][0] == mystr[0] )&&(code_map_D[i][1] == mystr[1])) || (sustain[i] == 1)){
	   		sustain[i] = 1;
	   		playSdWavArray[i]->play();
	   }

	   if ((code_map_U[i][0] == mystr[0] )&&(code_map_U[i][1] == mystr[1])){
	   		sustain[i] = 0;
	   		playSdWavArray[i]->stop();
	   }
	 }
	*/



	/*
		 int num;
		 num = universal_pots[0]->read();
		 Serial.print("A");
		 Serial.println( num);
		 num = universal_pots[1]->read();
		 Serial.print("B");
		 Serial.println(num);
		 */

	 //		Serial.println(new_sound_lib->sounds[0]->keys[0]->notes[0]);
	//		Serial.println("moose");

	 //Write the color out to the LEDS
	  	int color_battery[3] = {0, 255, 255};
	  	int color_mode[3] = {255, 51, 255};
	  	battery_led.set_color(color_battery);
	 		mode_led.set_color(color_mode);
	}
}

/*
   HIGH LEVEL FLOW OF CONTROL:
   TEENSY 3.6

   1) Poll Universal Pots and make stateful changes
   2) Poll View_pots and make stateful changes
   3) Send serial data out for button display changes
   4) Poll for serial button input
   5) Execute command for given input

	 int num;
	 num = universal_pots[0]->read();
	 Serial.print("A");
	 Serial.println( num);
	 num = universal_pots[1]->read();
	 Serial.print("B");
	 Serial.println(num);
	 num = universal_pots[2]->read();
	 Serial.print("C");
	 Serial.println(num);
	 num = universal_pots[3]->read();
	 Serial.print("D");
	 Serial.println(num);
	 num = universal_pots[4]->read();
	 Serial.print("E");
	 Serial.println(num);
	 num = view_pots[0]->read();
	 Serial.print("F");
	 Serial.println(num);
	 num = view_pots[1]->read();
	 Serial.print("G");
	 Serial.println(num);
	 num = view_pots[2]->read();
	 Serial.print("H");
	 Serial.println(num);
	 num = view_pots[3]->read();
	 Serial.print("i");
	 Serial.println(num);
	 num = view_pots[4]->read();
	 Serial.print("j");
	 Serial.println(num);
	 num = view_pots[5]->read();
	 Serial.print("k");
	 Serial.println(num);
	 Serial.println("---------------------");
	 delay(1000);
 */



/*
   mapping _ min_val
 * 1: 11 ----- 502    65
 * 2: 24 ----- 500    (Normal pin: 50)  50
 * 3: 10 ----- 530    64
 * 4: 22 ----- 523   NO NORMAL PIN
 * 5: 23 ----- 500 (Normal pin: 49) 49
 * 6: 15 ----- 530  (Normal pin: 34)  34
 * 7: 14   ----- 515 (Normal pin: 33) 33
 * 8: 20 ----- 520  (NOrmal pin: 39) 39
 * 9: 21 ----- 473   66
 * 10: 12  ----- 520  31
 * 11: 13  ----- 515   32



 //SWT-GND
 static const uint8_t btnselpins[4]   = {46,42,47,43};

 //Switch
 static const uint8_t btnreadpins[4] = {22,23,24,25};

 //LED-GND (Good)
 static const uint8_t ledselpins[4]   = {48,44,49,45};


 /*
 //Convert pin numbers to their respective port mappings for faster I/O C-style functions
 //SWT-GND
 static const uint8_t btnselpins[4]   = {PL3,PL7,PL2,PL6};

 //Switch
 static const uint8_t btnreadpins[4] = {PA0,PA1,PA2,PA3};

 //LED-GND (Good)
 static const uint8_t ledselpins[4]   = {PL1,PL5,PL0,PL4};


    Serial.println("Recieved Data:");   //Write to console for Debugging
     Serial1.readBytes(mystr,2);
     Serial.write(mystr,2);    //Write to console for Debugging
     Serial.write("\n");       //Write to console for Debugging
     Serial1.flush();*/
