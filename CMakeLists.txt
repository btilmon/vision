set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# cmake version to be used
cmake_minimum_required( VERSION 3.1 )

# project name
project( vision )

# include
include_directories( ./include ./src )

#add_library(

# target
add_executable( binary ./src/main.cpp ./src/stitching.cpp ./src/filtering.cpp ./src/basic_utils.cpp ./src/matrix.cpp ./tests/unit_tests.cpp )


########################
# Maybe add Eigen later?
########################
find_package (Eigen3 REQUIRED)
add_subdirectory( ./libs/eigen-3.3.7 )
target_link_libraries( binary  Eigen3::Eigen)
