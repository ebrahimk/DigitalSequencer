//QUESTION: DIFFFERENTIATE BETWEEN THE VALUE AND THE POTENTIOMETER

#define NUM_SOUNDS   6

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

/****AUDIO CONNECTIONS*****/

#define SDCARD_CS_PIN    10
#define SDCARD_MOSI_PIN  7
#define SDCARD_SCK_PIN   14

AudioControlSGTL5000     sgtl5000_1;     //audio control object

AudioOutputI2S           i2s1;           //xy=690.0056686401367,592.460223197937

AudioPlaySdWav           playSdWav4;     //xy=144.00571060180664,407.4602851867676
AudioPlaySdWav           playSdWav1;     //xy=145.0057029724121,289.46025562286377
AudioPlaySdWav           playSdWav8;     //xy=144.0056915283203,565.4601669311523
AudioPlaySdWav           playSdWav7;     //xy=145.00569915771484,523.4602127075195
AudioPlaySdWav           playSdWav3;     //xy=146.00568771362305,365.4602699279785
AudioPlaySdWav           playSdWav5;     //xy=146.00568771362305,446.4602336883545
AudioPlaySdWav           playSdWav6;     //xy=146.0056872367859,481.46027755737305
AudioPlaySdWav           playSdWav12;    //xy=151.0057144165039,723.5511236190796
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
AudioConnection          patchCord17(playSdWav2, 0, mixer1, 1);
AudioConnection          patchCord18(playSdWav2, 1, mixer2, 1);
AudioConnection          patchCord19(playSdWav10, 0, mixer3, 1);
AudioConnection          patchCord20(playSdWav10, 1, mixer4, 1);
AudioConnection          patchCord21(playSdWav11, 0, mixer3, 2);
AudioConnection          patchCord22(playSdWav11, 1, mixer4, 2);
AudioConnection          patchCord23(playSdWav15, 0, mixer7, 2);
AudioConnection          patchCord24(playSdWav15, 1, mixer8, 2);
AudioConnection          patchCord25(playSdWav14, 0, mixer7, 1);
AudioConnection          patchCord26(playSdWav14, 1, mixer8, 1);
AudioConnection          patchCord27(playSdWav13, 0, mixer7, 0);
AudioConnection          patchCord28(playSdWav13, 1, mixer8, 0);
AudioConnection          patchCord29(playSdWav9, 0, mixer3, 0);
AudioConnection          patchCord30(playSdWav9, 1, mixer4, 0);
AudioConnection          patchCord31(mixer1, 0, mixer9, 0);
AudioConnection          patchCord32(mixer4, 0, mixer10, 2);
AudioConnection          patchCord33(mixer3, 0, mixer9, 2);
AudioConnection          patchCord34(mixer2, 0, mixer10, 0);
AudioConnection          patchCord35(mixer6, 0, mixer10, 1);
AudioConnection          patchCord36(mixer5, 0, mixer9, 1);
AudioConnection          patchCord37(mixer8, 0, mixer10, 3);
AudioConnection          patchCord38(mixer7, 0, mixer9, 3);
AudioConnection          patchCord39(mixer9, 0, i2s1, 0);
AudioConnection          patchCord40(mixer10, 0, i2s1, 1);

/**********ANALOG POTENTIOMETER INPUTS**********/
//Macros
#define NUM_UNIVERSAL_POTENTIOMETERS 5
#define NUM_CONFIG_POTENTIOMETERS 6

struct Pot{
   int pin_num;
   int min_val;
   int range;               //The number of different states the given potentiometer can exist in at the given moment dependant upon the session/Arrangement mode the file exists in.
};

//Hardcode these
struct Pot pot1 = { .pin_num = 65, .min_val = 502};
struct Pot pot2 = { .pin_num = 50, .min_val = 500};
struct Pot pot3 = { .pin_num = 64, .min_val = 530};
struct Pot pot4 = { .pin_num = 67, .min_val = 523};
struct Pot pot5 = { .pin_num = 49, .min_val = 500};
struct Pot pot6 = { .pin_num = 34, .min_val = 530};
struct Pot pot7 = { .pin_num = 33, .min_val = 515};
struct Pot pot8 = { .pin_num = 39, .min_val = 520};
struct Pot pot9 = { .pin_num = 66, .min_val = 473};
struct Pot pot10 = {.pin_num = 31, .min_val = 520};
struct Pot pot11 = { .pin_num = 32, .min_val = 515};

struct Pot* universal_pins[NUM_UNIVERSAL_POTENTIOMETERS] = {&pot1, &pot2, &pot3, &pot4, &pot5};
struct Pot* config_pins[NUM_CONFIG_POTENTIOMETERS] = {&pot6, &pot7, &pot8, &pot9, &pot10, &pot11};

//int led_pins[6] ={16 ,17, 18, 19, 29, 30};

void pot_read_pin(struct Pot* pot, int* num){
      *num=map(analogRead(pot->pin_num), pot->min_val, 1023, 0, pot->range);
}

/********** FILE STRUCTURE HANDLING **************************/

char* violin[] = {"violin_g2.wav", "violin_g#2.wav", "violin_a2.wav", "violin_a#2.wav", "violin_b2.wav",
                        "violin_c3.wav", "violin_c#3.wav", "violin_d3.wav", "violin_d#3.wav", "violin_e3.wav", "violin_f3.wav", "violin_f#3.wav", "violin_g3.wav", "violin_g#3.wav", "violin_a3.wav", "violin_a#3.wav", "violin_b3.wav",
                        "violin_c4.wav", "violin_c#4.wav", "violin_d4.wav", "violin_d#4.wav", "violin_e4.wav", "violin_f4.wav", "violin_f#4.wav", "violin_g4.wav", "violin_g#4.wav", "violin_a4.wav", "violin_a#4.wav", "violin_b4.wav",
                        "violin_c5.wav", "violin_c#5.wav", "violin_d5.wav", "violin_d#5.wav", "violin_e5.wav", "violin_f5.wav", "violin_f#5.wav", "violin_g5.wav", "violin_g#5.wav", "violin_a5.wav", "violin_a#5.wav", "violin_b5.wav",
                        "violin_c6.wav"};

char* bass[] ={"808_g2.wav", "808_g#2.wav", "808_a2.wav", "808_a#2.wav", "808_b2.wav",
                     "808_c3.wav", "808_c#3.wav", "808_d3.wav", "808_d#3.wav", "808_e3.wav", "808_f3.wav", "808_f#3.wav", "808_g3.wav", "808_g#3.wav", "808_a3.wav", "808_a#3.wav", "808_b3.wav",
                     "808_c4.wav", "808_c#4.wav", "808_d4.wav", "808_d#4.wav", "808_e4.wav", "808_f4.wav", "808_f#4.wav", "808_g4.wav", "808_g#4.wav", "808_a4.wav", "808_a#4.wav", "808_b4.wav",
                     "808_c5.wav", "808_c#5.wav", "808_d5.wav", "808_d#5.wav", "808_e5.wav", "808_f5.wav", "808_f#5.wav", "808_g5.wav", "808_g#5.wav", "808_a5.wav", "808_a#5.wav", "808_b5.wav",
                     "808_c6.wav"};

char* flute[] ={"flute_g2.wav", "flute_g#2.wav", "flute_a2.wav", "flute_a#2.wav", "flute_b2.wav",
                      "flute_c3.wav", "flute_c#3.wav", "flute_d3.wav", "flute_d#3.wav", "flute_e3.wav", "flute_f3.wav", "flute_f#3.wav", "flute_g3.wav", "flute_g#3.wav", "flute_a3.wav", "flute_a#3.wav", "flute_b3.wav",
                      "flute_c4.wav", "flute_c#4.wav", "flute_d4.wav", "flute_d#4.wav", "flute_e4.wav", "flute_f4.wav", "flute_f#4.wav", "flute_g4.wav", "flute_g#4.wav", "flute_a4.wav", "flute_a#4.wav", "flute_b4.wav",
                      "flute_c5.wav", "flute_c#5.wav", "flute_d5.wav", "flute_d#5.wav", "flute_e5.wav", "flute_f5.wav", "flute_f#5.wav", "flute_g5.wav", "flute_g#5.wav", "flute_a5.wav", "flute_a#5.wav", "flute_b5.wav",
                      "flute_c6.wav"};

char* kick[] ={"kick_c2.wav", "kick_c#2.wav", "kick_d2.wav", "kick_d#2.wav", "kick_e2.wav", "kick_f2.wav", "kick_f#2.wav", "kick_g2.wav", "kick_g#2.wav", "kick_a2.wav", "kick_a#2.wav", "kick_b2.wav",
                     "kick_c3.wav", "kick_c#3.wav", "kick_d3.wav", "kick_d#3.wav", "kick_e3.wav", "kick_f3.wav", "kick_f#3.wav", "kick_g3.wav", "kick_g#3.wav", "kick_a3.wav", "kick_a#3.wav", "kick_b3.wav",
                     "kick_c4.wav"};

char* snare[] ={"snare_g2.wav", "snare_g#2.wav", "snare_a2.wav", "snare_a#2.wav", "snare_b2.wav",
                      "snare_c3.wav", "snare_c#3.wav", "snare_d3.wav", "snare_d#3.wav", "snare_e3.wav", "snare_f3.wav", "snare_f#3.wav", "snare_g3.wav", "snare_g#3.wav", "snare_a3.wav", "snare_a#3.wav", "snare_b3.wav",
                      "snare_c4.wav"};

char* hihat[] ={"hat_c2.wav", "hat_c#2.wav", "hat_d2.wav", "hat_d#2.wav", "hat_e2.wav", "hat_f2.wav", "hat_f#2.wav", "hat_g2.wav", "hat_g#2.wav", "hat_a2.wav", "hat_a#2.wav", "hat_b2.wav",
                      "hat_c3.wav"};


//******** ARRAY STRUCT ***********
//An array of strings of file names, we need an associated length
struct Note_set{
  char** data;
  int len;
  int lowest_note;          //integer from 0 to 11 where 0 represents the note "A" and 11 represents the note "G#"
};

struct Note_set violin_sounds = {.data = violin, .len = 42, .lowest_note = 10};
struct Note_set bass_sounds = {.data = bass, .len = 42, .lowest_note = 10};
struct Note_set flute_sounds = {.data = flute, .len = 42, .lowest_note = 10};
struct Note_set kick_sounds = {.data = kick, .len = 25, .lowest_note = 3};
struct Note_set snare_sounds = {.data = snare, .len = 18, .lowest_note = 10};
struct Note_set hihat_sounds = {.data = hihat, .len = 13, .lowest_note = 3};

//******** KEY STRUCT ************
struct  Key{
   char** notes;     //pointer to an array of string pointers which point to string literals hardcoded in the data section, llocate all of the memory to avoid dynamic variable creation
   int  key;            //key of a-> g starts
   int   len;
};

void key_constructor(struct Key* key, struct Note_set* sound_file_names, int set_key){
  int intervals[7] = {0, 2, 4, 5, 7, 9, 11};
  key->key = set_key;
  int starting_index = 0;

  if(set_key < sound_file_names->lowest_note){    //find the note an octave up //should be at index 5
    starting_index = (11 - sound_file_names->lowest_note) + set_key + 1;

  }
  else{
    starting_index = set_key - sound_file_names->lowest_note;
  }

  int num_octaves = ((sound_file_names->len - starting_index)/7);
  int key_length = num_octaves * 7;


  key->notes = (char**) malloc(key_length * sizeof(char*));


 Serial.println("PRINTING");
  for(int j = 0; j < ((sound_file_names->len - starting_index)/7); j++){
    for(int i = 0; i < 7; i++){
      key->notes[i*j] = sound_file_names->data[starting_index+intervals[i]];
      //Serial.println(sound_file_names->data[starting_index+intervals[i]]);
      key_length = (i+1)*(j+1);
      //delay(300);
    }
    starting_index = starting_index + 12;
  }

 // Serial.print("This is the length = " );
  //Serial.println(key_length);
  key->len = key_length;
}


void key_destructor(struct Key* key){

  for(int i = 0; i < key->len; i++){
      free(key->notes[i]);
      Serial.println("KEY DESTRUCTOR FREEING MEMORY");

  }
  free(key->notes);
}


//******** SOUNDS STRUCT ********
struct Sound{
   struct Key** keys;          //12 member long array      a pointer to an array of pointers
   int current_key;            //The current key we are playing in
};

//we want a pointer to an array of key pointers
//initialize they Keys structs, then initialize an array of Key pointers which are dynamically set to point to the new key objects


void sound_constructor(struct Sound* sound, struct Note_set* sound_file_names){
  struct Key* array_new_structs = (struct Key*) malloc(12 * sizeof(struct Key));
  sound->keys = (struct Key**) malloc(12 * sizeof(struct Key*));

  for(int i = 0; i < 12; i++){
    key_constructor(&array_new_structs[i], sound_file_names, i);
    sound->keys[i] = &array_new_structs[i];
    Serial.println("KEY CREATED");
  }
}

void sound_destructor(struct Sound* sound){

  for(int i = 0; i < 12; i++){
      key_destructor(sound->keys[i]);
      free(sound->keys[i]);
      Serial.println("SOUND DESTRUCTOR FREEING MEMORY");
  }
  free(sound->keys);
}

struct Sound VIOLIN;


//******** SOUND_FILES STRUCT *******
struct Sound_files{
   struct Sound** sounds;
   int number_of_sounds;
   int current_sound;
};

void sound_files_constructor(struct Sound_files* sound_files){

  //initialize all of the pointers
  //struct Note_set

  struct Note_set* RAW_SOUNDS[6] = {&violin_sounds, &bass_sounds, &flute_sounds, &snare_sounds, &hihat_sounds, &kick_sounds};

  struct Sound* array_of_structs = (struct Sound*) malloc(NUM_SOUNDS * sizeof(struct Sound));
  sound_files->sounds = (struct Sound**) malloc(NUM_SOUNDS * sizeof(struct Sound*));

  for(int i = 0; i < NUM_SOUNDS; i++){
    sound_constructor(&array_of_structs[i], RAW_SOUNDS[i] );
    sound_files->sounds[i] = &array_of_structs[i];
    Serial.println("NEW SOUND CREATED**********");
  }
  sound_files->current_sound = 0;
  sound_files->number_of_sounds = NUM_SOUNDS;
}

struct Sound_files file_structure;

/*********** ADD DRUM INSTRUMENT SEPERATELY

/*********** SESSION OBJECTS ***********************/

struct Session {
  struct Pot* session_pots[6];       //An array of six potentiometers
  int    octave_location;           //integer representing the index of the lowest note loaded to the button pad (notes array of a Key object)
  int    location;                  //represents the lowest note loaded out onto the session
  //struct Arpeggiator* arpeggiator;
  //struct Chord* chord;
  int    current_effect;                     //int representing the mode for the session (arp, chord, off)
};

/*********** ARRANGEMENT OBJECTS ***********************/


//A single spot in the recorded grid 16th note resolution...
struct Recording_space{
  char* note;       //a pointer to a string of the file name which exists in the gien location
  int note_length;              //an integer stating the total number of space the given rocording consumes from its start, faster indexing.
  bool uninitialized;
};

/*NOTE
 * The potentiometers must be configured to get the note length data, pitch, and octave information then find the exact corresponding note string to point to
 */

struct Arrangement {
  struct Pot* config_pots[6];                 //An array of six potentiometers
  struct Recorded_space* sequence[64];       //An Array of note files played in sequence Differentiate between a sound or just along note playing the entire duration....
  bool add_mode;
  bool is_playing_locally;
  int grid_location;                       //An integer representing the first location displayed on the button pad, for referencing and scrolling through sounds...
};

/*********** CONFIGURATION OBJECTS ***********************/

struct Config {
  struct Pots* potentiometer[6];
  struct Sound_files* sound_options;
  struct Sound*   current_sound;
  float  instrument_volume;
  bool is_on;
  int current_key;                  //This integer will contain the index of the current key within the Sound object
  int delay_milli;                  //the number of milliseconds to delay the sound

  //For channel panning
  float right_gain;
  float left_gain;
};

/*********** UNIVERSAL CONFIGURATION *******************/

struct Universal_config{
  struct Pot* universal_pots[5];    //Array of potentiometers which have universal priority
  struct Instruments* rack[6];      //Array of four instruments
  int current_instrument;           //An integer storing the index within the "rack" member of the currently loaded instrument
  float master_volume;
  bool playing_all_recordings;
  int master_tempo;
};

/*********** INTERFACE OBJECTS *******************/

struct Button{
  AudioPlaySdWav* push_button;          //The sound playing object
  int current_color[3];                 //The current color of the given button pad at this state
};


//NEW
void button_constructor(struct Button* button, int num){
  int i;
  for(i = 0; i < 3; i++){
    button->current_color[i] = 255;
  }
  button->push_button = playSdWavArray[num];
}

struct Pad{
  struct Button** button_array;
  int columns;
  int rows;
};

void pad_constructor(struct Pad* pad){
  pad->columns = 4;
  pad->rows = 4;
  pad->button_array = (struct Button**) malloc(16 * sizeof(Button*));
  struct Button* temp_array_structs = (struct Button*) malloc(16 * sizeof(Button));

  AudioPlaySdWav* playSdWavArray[16]={&playSdWav1, &playSdWav2, &playSdWav3, &playSdWav4, &playSdWav5, &playSdWav6, &playSdWav7, &playSdWav8,
                                   &playSdWav9, &playSdWav10, &playSdWav11, &playSdWav12, &playSdWav13, &playSdWav14, &playSdWav15,  };

  for(int i = 0; i < 16; i++){
    button_constructor(&temp_array_structs[i], )
  }
}


struct Interface{
  struct Pad* button_pad;                       //Button pad
  struct Universal_config* universal_config;    //config potentiometers
};

/************ INSTRUMENTS ************************************/

struct Instrument {
  int    current_mode;                //An integer representing the current mode of the Instrument (Session/Arrangement/Config)
  struct Session* session;            //pointer to a session object associated with the instrument
  struct Arrangement* arrangement;    //pointer to an arrangement object associated with the instrument
  struct Config* configuration;       //pointer t oa configuration object for the given instrument  --> volume/Current_sound
};

/**********COMMUNICATION BETWEEN TEENSY AND MEGA2560**********/

const char code_map_D[16][2] ={{'a','D'},{'b','D'},{'c','D'},{'d','D'},{'e','D'},{'f','D'},{'g','D'},{'h','D'},{'i','D'},{'j','D'},{'k','D'},{'l','D'},{'m','D'},{'n','D'},{'o','D'},{'p','D'}};
const char code_map_U[16][2] ={{'a','U'},{'b','U'},{'c','U'},{'d','U'},{'e','U'},{'f','U'},{'g','U'},{'h','U'},{'i','U'},{'j','U'},{'k','U'},{'l','U'},{'m','U'},{'n','U'},{'o','U'},{'p','U'}};

char mystr[2]; //recieve buffer from mega 2560
int replay[15];

//INCLUDE STRUCTURES FOR COMMUNCATING FROM THE TEENSY TO THE ARDUINO

/********** EXECUTABLE PROGRAM **************/

void setup() {

  Serial.begin(1200);

  sound_files_constructor(&file_structure);


  /*
  //ENABLE SERIAL COMMUNICATION
  Serial6.begin(115200);
  Serial.begin(1200);
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

  //CONFIGURE REPLAY ARRAY
  for(int i =0; i< 15; i++){
     replay[i] = 0;
  }
  */

}


void loop() {

/*
  for(int i = 0; i < violin_keyC.len; i++){
    Serial.println(violin_keyC.notes[i]);
    delay(200);
  }

*/
  //Serial.println("Done");

  /*
  //READ IN STATE CHANGES FROM POTENTIOMETERS
  Serial.write(mystr, 2);
  Serial6.readBytes(mystr,2);
  Serial.write(mystr,2);
  Serial.write("\n");
  Serial6.flush();

  for(int i = 0; i < 15; i++){
    if (((code_map_D[i][0] == mystr[0] )&&(code_map_D[i][1] == mystr[1])) || (replay[i] == 1)){
          replay[i] = 1;
          playSdWavArray[i]->play(code_mapStr[i]);
    }

    if ((code_map_U[i][0] == mystr[0] )&&(code_map_U[i][1] == mystr[1])){
          replay[i] = 0;
          playSdWavArray[i]->stop();
    }
  }
  */
}














/*
A switch statement looking at the input of the mode pin... If it is in this mode execute these potentiometer reading functions....
Funcitons:
 *
 * State_Wrapper():     This function will call a switch statement which will look at the mode potentiometer (pot 5). It will then call a series of update pin functions for which ever mode the synth exists in
 * Grab_Input():        This function will grab serial input data and do whatever it needs to do
 *
 */

/*
     TESTING ANALOG PINS
  int num;
  read_pin(analog_pins[0], &num);
    Serial.print("A");
  Serial.println( num);
  read_pin(analog_pins[1], &num);
    Serial.print("B");
  Serial.println(num);
  read_pin(analog_pins[2], &num);
    Serial.print("C");
  Serial.println(num);
  read_pin(analog_pins[3], &num);
    Serial.print("D");
  Serial.println(num);
  read_pin(analog_pins[4], &num);
    Serial.print("E");
  Serial.println(num);
  read_pin(analog_pins[5], &num);
    Serial.print("F");
  Serial.println(num);
  read_pin(analog_pins[6], &num);
    Serial.print("G");
  Serial.println(num);
  read_pin(analog_pins[7], &num);
    Serial.print("H");
  Serial.println(num);
  read_pin(analog_pins[8], &num);
    Serial.print("i");
  Serial.println(num);
  read_pin(analog_pins[9], &num);
    Serial.print("j");
  Serial.println(num);
  read_pin(analog_pins[10], &num);
    Serial.print("k");
  Serial.println(num);
    Serial.println("---------------------");
  delay(1000);

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
 */
