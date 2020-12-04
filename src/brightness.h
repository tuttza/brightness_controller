#ifndef brightness_h_INCLUDED
#define brightness_h_INCLUDED

#include <iostream>
#include <fstream>
#include <string>

class Brightness {
public:
  const std::string intel_max_value_path = "/sys/class/backlight/intel_backlight/max_brightness";
  const std::string intel_current_value_path = "/sys/class/backlight/intel_backlight/brightness";

 int current_value;
 int max_value;

 int get_current_value();
 int set_current_value(int value); 
 int set_max_value();

 Brightness();
};
#endif // brightness_h_INCLUDED

