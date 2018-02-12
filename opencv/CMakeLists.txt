CMAKE_MINIMUM_REQUIRED( VERSION 3.5.1 )

PROJECT( hw_1_opencv )

FIND_PACKAGE( Boost 1.58 COMPONENTS program_options REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

FIND_PACKAGE( OpenCV REQUIRED )

ADD_EXECUTABle( hw_1_opencv src/main.cpp src/open_image.cpp )
TARGET_LINK_libraries( hw_1_opencv ${OpenCV_LIBS} ${Boost_LIBRARIES} )
