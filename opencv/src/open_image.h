#ifndef OPEN_IMAGE_H
#define OPEN_IMAGE_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <cstddef>
#include <opencv2/opencv.hpp>

// if the file name is not valid, the progam will exit with exit code 1
// otherwise opencv's cv::Mat limitations apply
void open_image (std::string valid_image_file_name);

#endif // OPEN_IMAGE_H
