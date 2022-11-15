//star line function

#ifndef star_h
#define star_h
using namespace std;

//#include <iostream>
//using namespace std;

// bus[10];
void vline (char line)
{
  for (int starline = 80; starline > 0; starline--)
    std::cout<<  line;
};

#endif
