# img-viewer

A small single image viewer with opencv

# Homework Assignment No. 1

First Homework Assignment of the CE-5201 Digital Images Processing and Analysis Course, on the First Semester of 2018.

## Getting Started

Clone this repository with git

```
$ git clone git@github.com:dcorderoch/img-viewer.git
```

### Prerequisites

This assignment was done on Ubuntu 16.04, using the default software repositories to install the g++ compiler, Cmake, and OpenCV.


#### OpenCV viewer

For the progam building process, CMake was used, so a CMakeLists.txt file was needed, and to keep the repository clean, I ran the command in the opencv subdirectory of this repository like so:

```
cmake -H./ -B./build && cd build && make
```

and in the same directory, to execute the program run

```
./image_viewer -f <image_file>
```

where `<image_file>` is a 2d graphical image (tested with png and jpg images)

or

```
./image_viewer [-h]
```

to view the progam usage

## Author

* **David Cordero Chavarría** - *Initial Work* - [dcorderoch](https://github.com/dcorderoch)
