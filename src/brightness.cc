#include "brightness.h"

Brightness::Brightness(void) 
{
  Brightness::set_max_value();
  Brightness::get_current_value();
}

int Brightness::set_current_value(int value)
{
 if (value <= 0)
   return this->current_value;

 if (value >= this->max_value)
   return this->max_value;

 std::fstream sys_brightness_file(intel_current_value_path, std::ios_base::out);

 sys_brightness_file << value << std::endl;

 sys_brightness_file.close();

 this->current_value = value;

 return value;
}

int Brightness::get_current_value()
{
	std::fstream sys_brightness_file(intel_current_value_path, std::ios_base::in);

	std::string b_value;

	sys_brightness_file >> b_value;

	this->current_value = std::stoi(b_value);

	return this->current_value;
}

int Brightness::set_max_value()
{
  std::fstream sys_max_brightness_file(intel_max_value_path, std::ios_base::in);

  std::string local_max_value;

  sys_max_brightness_file >> local_max_value;

  this->max_value = std::stoi(local_max_value);

  return this->max_value;
}
