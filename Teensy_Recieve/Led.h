#ifndef LED_H
#define LED_H

class Led{
  public:
    int pin_nums[3];
    int color[3];
    Led(int pin_nums[]);
    void set_color(int* color);
};

#endif
