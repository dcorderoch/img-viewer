#include <cstdlib>
#include <iostream>
#include <string>

#include "boost/program_options.hpp"

#include "open_image.h"

using namespace std;

const size_t SUCCESS                   = 0;
const size_t ERROR_IN_CLI              = 1;
const size_t ERROR_UNHANDLED_EXCEPTION = 2;

void show_help (char* name, boost::program_options::options_description desc);

int main (int argc, char** argv)
{
  char* program_name = argv[0]; // this should never be null
  string file_name;

  try
  {
    // start command line parsing
    boost::program_options::options_description desc ("Options");
    // add program options
    desc.add_options ()
      (",h", "Show help")
      (",f", boost::program_options::value<string>(&file_name), "img file name");

    // initialize options storage
    boost::program_options::variables_map vm;
    try
    {
      // parse options
      boost::program_options::store (boost::program_options::parse_command_line (argc, argv, desc), vm);

      // if help option was passed, print help (and exit)
      if (vm.count ("help"))
      {
        show_help ( program_name, desc );
        exit (SUCCESS);
      }
      // throws on error
      boost::program_options::notify (vm);
    }
    // error handling on program options
    // print error and exit with unsuccessful exit code
    catch (boost::program_options::error& e)
    {
      cerr << "ERROR: " << e.what () << endl << endl;
      cerr << desc << endl;
      exit (ERROR_IN_CLI);
    }

    // actual program logic starts here
    if ( file_name.size() > 0 )
    {
      open_image (file_name);
    }
    else
    {
      show_help (program_name, desc);
      exit (SUCCESS);
    }
  }
  catch(exception& e)
  {
    cerr << "Unhandled Exception reached the top of main: "
              << e.what() << ", application will now exit" << endl;
    exit (ERROR_UNHANDLED_EXCEPTION);

  }
  exit (SUCCESS);
}

void show_help (char* name, boost::program_options::options_description desc)
{
  cout << name << endl;
  cout << desc << endl;
}
