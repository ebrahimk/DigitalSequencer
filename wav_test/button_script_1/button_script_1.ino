//config variables
#define NUM_LED_COLUMNS (4)
#define NUM_LED_ROWS (4)
#define NUM_BTN_COLUMNS (4)
#define NUM_BTN_ROWS (4)
#define NUM_COM_BITS (4)
#define NUM_COLORS (3) //Based off the color wheel http://instant-eyedropper.com/info/the_color_wheel/


#define MAX_DEBOUNCE (3) //We want less  delay Will need to play around with this and perhaps look into clock cycles
char buffer [50];

// Global variables
//tracks which RGB led to toggle on next, alwayts increasing, then the bitwise and Isolate which of the fours states it is in
static uint8_t LED_outputs[NUM_LED_COLUMNS][NUM_LED_ROWS];
static int32_t next_scan;

static const uint8_t btnselpins[4]   = {50,51,52,53};
static const uint8_t btnreadpins[4] = {46,47,48,49};
static const uint8_t ledselpins[4]   = {42,43,44,45};

// RGB pins for each of 4 rows 
static const uint8_t colorpins[4][3] = {{13,12,11}, {10,9,8},{7,6,5},{4,3,2}};
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
/*
static const uint8_t    color_mappings[14][3] = {
                      //{255,255,255},  //none1
                      {255,0,0}, //Red2
                      {255,125,0}, //Orange3
                      {255,255,0}, //Yellow4
                      {125,255,0}, //Spring Green5
                      {0,255,0},  //Green6
                      {0,255,125}, //Turquiose7
                      {0,255,255}, //Cyan8
                      {0,125,255}, //Ocean9
                      {0,0,255},  //Blue10
                      {138,43,226}, //Dark violet11
                      {125,0,255}, //Violet12
                      {255,0,255}, //Magenta13
                      {255,0,125}};  //Rasberry14
*/

static int8_t debounce_count[NUM_BTN_COLUMNS][NUM_BTN_ROWS];

//Pin communication The set of pins used to communicate to the teensy
static int8_t com_pins[4] = {31,33,35,37};   


static void setuppins()
{
    uint8_t i;
    //initialize the color mappings

    for(i = 0; i < NUM_LED_ROWS; i++)
    {
        for(uint8_t j = 0; j < NUM_COLORS; j++)
        {
            pinMode(colorpins[i][j], OUTPUT);
            digitalWrite(colorpins[i][j], LOW);
        }
    }

    // initialize
    for(i = 0; i < NUM_BTN_COLUMNS; i++)
    {
        pinMode(btnselpins[i], OUTPUT);

        // with nothing selected by default
        digitalWrite(btnselpins[i], HIGH);
    }

    // key return lines
    for(i = 0; i < 4; i++)
    {
        pinMode(btnreadpins[i], INPUT_PULLUP);
    }

    // LED drive lines
    for(i = 0; i < NUM_LED_ROWS; i++)
    {
        for(uint8_t j = 0; j < NUM_COLORS; j++)
        {
            pinMode(colorpins[i][j], OUTPUT);
            digitalWrite(colorpins[i][j], LOW);
        }
    }

    
    for(uint8_t i = 0; i < NUM_BTN_COLUMNS; i++)
    {
        for(uint8_t j = 0; j < NUM_BTN_ROWS; j++)
        {
            debounce_count[i][j] = 0;
        }
    }
}


static void scan()
{
  static uint8_t current = 0;
  uint8_t val;
  uint8_t i, j;

    //run
    digitalWrite(btnselpins[current], LOW);
    digitalWrite(ledselpins[current], LOW);

    //At the beginning of each scan refresh the row we are currently working on
    for(i = 0; i < NUM_LED_ROWS; i++)
    {

        uint8_t val = (LED_outputs[current][i] % 13);

            analogWrite(colorpins[i][0], color_mappings[val][0]);
            analogWrite(colorpins[i][1], color_mappings[val][1]);
            analogWrite(colorpins[i][2], color_mappings[val][2]);  
  }


  delay(1);

  for( j = 0; j < NUM_BTN_ROWS; j++)
  {
    val = digitalRead(btnreadpins[j]);

    if(val == LOW)
    {
      // active low: val is low when btn is pressed
      if( debounce_count[current][j] < MAX_DEBOUNCE)
      {
        debounce_count[current][j]++;
        if( debounce_count[current][j] == MAX_DEBOUNCE )
        {
          Serial.print("Key Down ");
          Serial.println((current * NUM_BTN_ROWS) + j);

          LED_outputs[current][j]++;
              //Button is pushed send encoded button in 4 bits
              //write 4 digital pins high 
              for(int k = 0; k < 4; k++){
                  
              }
              
        }
      }
    }
    else
    {
      // otherwise, button is released
      if( debounce_count[current][j] > 0)
      {
        debounce_count[current][j]--;
        if( debounce_count[current][j] == 0 )
        {
          Serial.print("Key Up ");
          Serial.println((current * NUM_BTN_ROWS) + j);
        }
      }
    }
  }// for j = 0 to 3;

  delay(1);

  digitalWrite(btnselpins[current], HIGH);
  digitalWrite(ledselpins[current], HIGH);

  for(i = 0; i < NUM_LED_ROWS; i++)
  {
    for(j = 0; j < NUM_COLORS; j++)
    {
      digitalWrite(colorpins[i][j], LOW);
    }
  }

  current++;
  if (current >= NUM_BTN_COLUMNS)
  {
    current = 0;
  }
}

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(115200);

  Serial.print("Starting Setup...");

  // setup hardware
  setuppins();

  // init global variables
  next_scan = millis() + 1;

  for(uint8_t i = 0; i < NUM_LED_ROWS; i++)
  {
    for(uint8_t j = 0; j < NUM_LED_COLUMNS; j++)
    {
      LED_outputs[i][j] = 0;
    }
  }

  Serial.println("Setup Complete.");
}

void loop() {
  // put your main code here, to run repeatedly:

  if(millis() >= next_scan)
  {
    next_scan = millis()+1;
    scan();
  }
}

