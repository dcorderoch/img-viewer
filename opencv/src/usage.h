#ifndef USAGE_H
#define USAGE_H

#include <iostream>
#include <string>

#include "boost/program_options.hpp"

void show_help (char* program_name, boost::program_options::options_description desc);

#endif //USAGE_H
