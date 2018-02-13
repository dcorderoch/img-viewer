#ifndef PARSE_PARAM_FILENAME_H
#define PARSE_PARAM_FILENAME_H

#include <cstdlib>
#include <iostream>
#include <string>

#include "boost/program_options.hpp"

#include "usage.h"

// initiates file_name to the filename passed to the program after the -f [ --file ] flag
// if no filename is passed, program will exit with exit code 1
void parse_param_filename ( int argc, char** argv, std::string& file_name);

#endif // PARSE_PARAM_FILENAME_H
