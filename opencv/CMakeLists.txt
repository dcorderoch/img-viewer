CMAKE_MINIMUM_REQUIRED( VERSION 3.5.1 )

PROJECT( image_viewer )

FIND_PACKAGE( Boost 1.58 COMPONENTS program_options REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

FIND_PACKAGE( OpenCV REQUIRED )

ADD_EXECUTABle( image_viewer src/main.cpp src/open_image.cpp src/parse_param_file_name.cpp src/usage.cpp )
TARGET_LINK_libraries( image_viewer ${OpenCV_LIBS} ${Boost_LIBRARIES} )
