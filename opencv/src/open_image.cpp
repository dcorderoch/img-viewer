#include "open_image.h"

using namespace std;

#define ANY_KEY 0

void open_image (std::string file_name)
{
  cv::Mat imagen = cv::imread (file_name.c_str());
  if (imagen.data)
  {
    cv::namedWindow ("image_viewer", CV_WINDOW_AUTOSIZE);
    cv::imshow ("image_viewer", imagen);
    cv::waitKey (ANY_KEY);
    imagen.release ();
    exit (EXIT_SUCCESS);
  }
  exit (EXIT_FAILURE);
}
