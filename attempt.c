
//config variables
#define NUM_LED_COLUMNS (4)
#define NUM_LED_ROWS (4)
#define NUM_BTN_COLUMNS (4)
#define NUM_BTN_ROWS (4)
#define NUM_COLORS (3)
#define NUM_COM_BITS (4)

#define MAX_DEBOUNCE (3)

// Global variables
static uint8_t LED_outputs[NUM_LED_COLUMNS][NUM_LED_ROWS];
static int32_t next_scan;

//SWT-GND
static const uint8_t btnselpins[4]   = {26,22,25,29};

//Switch
static const uint8_t btnreadpins[4] = {32,33,30,31};

//LED-GND (Good)
static const uint8_t ledselpins[4]   = {28, 24, 23, 27};



// RGB pins for each of 4 rows
static const uint8_t colorpins[4][3] = {{13,11,12}, {10,8,9},{7,5,6},{4,2,3}};

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



static int8_t debounce_count[NUM_BTN_COLUMNS][NUM_BTN_ROWS];

static void setuppins()
{
    uint8_t i;

    // initialize
    // select lines
    for(i = 0; i < NUM_LED_COLUMNS; i++)
    {
        pinMode(ledselpins[i], OUTPUT);

        // with nothing selected by default
        digitalWrite(ledselpins[i], HIGH);
    }

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


          uint8_t value = (current * NUM_BTN_ROWS) + j;
          //Transmit code on serial3

           Serial.println("1");

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
            uint8_t value = (current * NUM_BTN_ROWS) + j;
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

  //Info transfer baudrate
  Serial3.begin(115200);

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
