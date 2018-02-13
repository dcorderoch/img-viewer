#include <cstdlib>
#include <iostream>
#include <string>

#include "open_image.h"
#include "parse_param_file_name.h"

int main (int argc, char** argv)
{
  std::string file_name;

  parse_param_filename (argc, argv, file_name);

  open_image (file_name);

  exit (EXIT_SUCCESS);
}
