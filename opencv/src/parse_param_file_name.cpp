#include "parse_param_file_name.h"

#define SUCCESS                   0
#define ERROR_IN_CLI              1
#define ERROR_UNHANDLED_EXCEPTION 2

void parse_param_filename ( int argc, char** argv, std::string& file_name)
{
  char* program_name = argv[0]; //this should never be null
  try
  {
    // start command line parsing
    boost::program_options::options_description desc ("Options");
    // add program options
    desc.add_options ()
      ("help,h", "Show help")
      ("file,f", boost::program_options::value<std::string>(&file_name), "img file name");

    // initialize options storage
    boost::program_options::variables_map vm;
    try
    {
      // parse options
      boost::program_options::store (boost::program_options::parse_command_line (argc, argv, desc), vm);

      // if help option was passed, print help (and exit)
      if (vm.count ("help") || argc == 1)
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
      std::cerr << "ERROR: " << e.what () << std::endl << std::endl;
      std::cerr << desc << std::endl;
      exit (ERROR_IN_CLI);
    }

    if ( file_name.size() < 0 )
    {
      show_help (program_name, desc);
      exit (SUCCESS);
    }
  }
  catch(std::exception& e)
  {
    std::cerr << "Unhandled Exception reached the top of main: "
              << e.what() << ", application will now exit" << std::endl;
    exit (ERROR_UNHANDLED_EXCEPTION);
  }
}
