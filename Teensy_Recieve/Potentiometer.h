#ifndef POTENTIOMETER_H
#define POTENTIOMETER_H

class Potentiometer{
  public:
    int pin_num;
    int min_value;
    int range;
    Potentiometer(int pin_num, int min_value);
    void set_range(int range);
    int read();
};

#endif
