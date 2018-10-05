/********** FILE STRUCTURE HANDLING **************************/

//******** KEY STRUCT ************
/*struct  Key{
   char** notes;     //pointer to an array of string pointers which point to string literals hardcoded in the data section, allocate all of the memory to avoid dynamic variable creation
   int  key;            //key of a-> g starts
   int   len;
};

void key_constructor(struct Key* key, struct Note_set* sound_file_names, int set_key){
  int intervals[7] = {0, 2, 4, 5, 7, 9, 11};
  key->key = set_key;
  int starting_index = 0;

  if(set_key < sound_file_names->octave){    //find the note an octave up //should be at index 5
    starting_index = (11 - sound_file_names->octave) + set_key + 1;

  }
  else{
    starting_index = set_key - sound_file_names->octave;
  }

  int num_octaves = ((sound_file_names->len - starting_index)/7);
  int key_length = num_octaves * 7;


  key->notes = (char**) malloc(key_length * sizeof(char*));

 Serial.println("PRINTING");
  for(int j = 0; j < ((sound_file_names->len - starting_index)/7); j++){
    for(int i = 0; i < 7; i++){
      key->notes[i*j] = sound_file_names->data[starting_index+intervals[i]];
      Serial.println(sound_file_names->data[starting_index+intervals[i]]);
      key_length = (i+1)*(j+1);
      delay(50);
    }
    starting_index = starting_index + 12;
  }
  key->len = key_length;
}*/

//******** SOUNDS STRUCT ********
/*
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

  struct Note_set* RAW_SOUNDS[6] = {&violin_sounds, &bass_sounds, &piano_sounds, &snare_sounds, &hihat_sounds, &kick_sounds};

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
/*
struct Session {
  struct Pot* session_pots[6];       //An array of six potentiometers
  int    octave_location;           //integer representing the index of the lowest note loaded to the button pad (notes array of a Key object)
  int    location;                  //represents the lowest note loaded out onto the session
  struct Pad* button_pad;                       //Button pad
  //struct Arpeggiator* arpeggiator;
  //struct Chord* chord;
  int    current_effect;                     //int representing the mode for the session (arp, chord, off)
};

/*********** ARRANGEMENT OBJECTS **********************


//A single spot in the recorded grid 16th note resolution...
struct Recording_space{
  char* note;       //a pointer to a string of the file name which exists in the gien location
  int note_length;              //an integer stating the total number of space the given rocording consumes from its start, faster indexing.
  bool uninitialized;
};


 * he potentiometers must be configured to get the note length data, pitch, and octave information then find the exact corresponding note string to point to


struct Arrangement {
  struct Pot** config_pots;                 //An array of six potentiometers 6 potentiometers
  struct Track** tracks;       //64 An Array of note files played in sequence Differentiate between a sound or just along note playing the entire duration....
  bool add_mode;
  bool is_playing_locally;
  int grid_location;                       //An integer representing the first location displayed on the button pad, for referencing and scrolling through sounds...
};



/*********** CONFIGURATION OBJECTS ***********************
struct Track{
  struct Recorded_space** sequence;       //64 An Array of note files played in sequence Differentiate between a sound or just along note playing the entire duration....
  struct Pad* button_pad;                       //Button pad
};

struct Config {
  struct Pots** potentiometer;          //6 potentiometers
  struct Sound_files* sound_options;
  struct Sound*   current_sound;
  struct Pad* button_pad;                       //Button pad
  float  instrument_volume;
  bool is_on;
  int current_key;                  //This integer will contain the index of the current key within the Sound object
  int delay_milli;
  //For channel panning
  float right_gain;
  float left_gain;
};

/*********** UNIVERSAL CONFIGURATION *******************

struct Instrument_interface{
  struct Pot** universal_pots;    //Array of potentiometers which have universal priority
  struct Instruments** rack;      //Array of four instruments
  int current_instrument;           //An integer storing the index within the "rack" member of the currently loaded instrument
  float master_volume;          //COULD REMOVE  --> REPLACE WITH A TRACK STRUCT
  bool playing_all_recordings;
  int master_tempo;
};

/*
void Instrument_interface_constructor(){
  //Create new Pot pointer objects
  //create Instrument pointer objects configured within the instruments


}


s
//THINK ABOUT HOW WE WANT THE BUTTON PAD TO BEHAVE UNDER CONFIGURATION MODE, MAYBE THE BUTTON PAD SHOULD BE NESTED UNDER THE CONFIGURATION MODES??? <--- THIS SEEMS LIKE THE PREPER DESIGN
//Configure communication between mega and teensy for stateful button displays in the arrangement mode
struct Button{
  AudioPlaySdWav* push_button;          //The sound playing object
  int current_color[3];                 //The current color of the given button pad at this state
  bool is_down;
  char* button_down;
  char* button_up;
};

void button_constructor(struct Button* button, AudioPlaySdWav* player, char* set_up, char* set_down ){
  int i;

  //Set all of the buttons to red
  for(i = 0; i < 3; i++){
    button->current_color[i] = 255;
  }

  button->button_down = set_down;
  button->button_up = set_up;
  button->push_button = player;
  button->is_down = false;
  delay(50);
  Serial.println("Button initalized");
  Serial.print(button->button_up);
  Serial.print(" ");
  Serial.println(button->button_down);
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
  char* temp_button_state_up;
  char* temp_button_state_down;

  AudioPlaySdWav* playSdWavArray[16]={&playSdWav1, &playSdWav2, &playSdWav3, &playSdWav4, &playSdWav5, &playSdWav6, &playSdWav7, &playSdWav8,
                                      &playSdWav9, &playSdWav10, &playSdWav11, &playSdWav12, &playSdWav13, &playSdWav14, &playSdWav15, &playSdWav16};

  char button_ids[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' , 'k', 'k', 'm', 'n', 'o', 'p'};

  //Create a pointer to an array of 2 chas's, initialize the characters with the proper Id's
  for(int i = 0; i < 16; i++){
    temp_button_state_up = (char*) malloc(2* sizeof(char));
    temp_button_state_down = (char*) malloc(2* sizeof(char));

    temp_button_state_up[0] = button_ids[i];
    temp_button_state_up[1] = 'U';

    temp_button_state_down[0] = button_ids[i];
    temp_button_state_down[1] = 'D';

    button_constructor(&temp_array_structs[i], playSdWavArray[i], temp_button_state_up, temp_button_state_down);
  }
  Serial.println("PAD CONSTRUCTED");
}

struct Pad button_pad;
/*
struct Physical_interface{
  struct Instrument_interface* instrument_interface;    //config potentiometers
};

//COMPLETE THIS
void Physical_interface_constructor(struct Physical_interface* physical_interface){


}
*/

/*********** INSTRUMENTS ************************************/
/*
struct Instrument {
  int    current_mode;                //An integer representing the current mode of the Instrument (Session/Arrangement/Config)
  struct Session* session;            //pointer to a session object associated with the instrument
  struct Arrangement* arrangement;    //pointer to an arrangement object associated with the instrument
  struct Config* configuration;       //pointer t oa configuration object for the given instrument  --> volume/Current_sound
};

void instrument_constructor(){


}*/
