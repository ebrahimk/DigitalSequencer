#ifndef Test_h_
#define Test_h_

#include <stdint.h>

class Test{
  public:
    Test(int number, char letter); //Constructor for the Test class
    void initialize(int number, char letter);
    int number;
    char letter;
    int get_number();
    char get_letter();
};

#endif
