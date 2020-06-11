# cmake version to be used
cmake_minimum_required( VERSION 3.0 )

# project name
project( vision )

# flags

# files

# include
include_directories( ./include ./src )

# target
add_executable( binary ./src/image_utils.cpp )

# external libs
find_package (Eigen3 REQUIRED)

#add_subdirectory( ./libs/eigen-3.3.7 )
target_link_libraries( binary  Eigen3::Eigen)

# add_subdirectory( ./libs/Randomize )
# target_link_libraries( binary randomize )

#add_library(randomize STATIC IMPORTED)
#set_property(TARGET randomize PROPERTY IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libs/Randomize/librandomize.a)
#target_link_libraries( binary randomize )
