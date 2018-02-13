#ifndef PARSE_PARAM_FILENAME_H
#define PARSE_PARAM_FILENAME_H

#include <cstdlib>
#include <iostream>
#include <string>

#include "boost/program_options.hpp"

#include "usage.h"

void parse_param_filename ( int argc, char** argv, std::string& file_name);

#endif // PARSE_PARAM_FILENAME_H
