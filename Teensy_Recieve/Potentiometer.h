#ifndef POTENTIOMETER_H
#define POTENTIOMETER_H

class Potentiometer{
  public:
    int pin_num;
    int min_value;
    int range;
    int is_reversed;
    Potentiometer(int pin_num, int min_value, int is_reversed);
    void set_range(int range);
    int read();
};

#endif
