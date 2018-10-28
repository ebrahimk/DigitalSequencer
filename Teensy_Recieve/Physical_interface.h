#ifndef PHYSICAL_INTERFACE_H
#define PHYSICAL_INTERFACE_H

#include "Potentiometer.h"
#include "Led.h"

#define NUM_INSTRUMENTS 4

class Physical_interface{
  public:
    Instruments* instruments[NUM_INSTRUMENTS];
    Potentiometer* universal_pots[5];
    Led* leds[2];
    short master_volume;
    int tempo;
    int current_instruments;
    bool is_playing;
    AudioPlaySdWav* track_player[NUM_INSTRUMENTS];

    Physical_interface(Instrument** instruments, Ptentiometer** universal_pots, Led* leds, short master_volume, int tempo, int current_instrument, AudioPlaySdWav** track_player);
    
}
