#ifndef USAGE_H
#define USAGE_H

#include <iostream>
#include <string>

#include "boost/program_options.hpp"

// this function gets called if the program gets called with no arguments
// or if it gets called with the -h [ --help ] flag
void show_help (char* program_name, boost::program_options::options_description desc);

#endif //USAGE_H
