#include "usage.h"

void show_help (char* program_name, boost::program_options::options_description desc)
{
  std::cout << program_name << std::endl;
  std::cout << desc << std::endl;
}
