# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/bjt/Documents/research/vision/libs/eigen-3.3.7

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bjt/Documents/research/vision/libs/eigen-3.3.7/build

# Include any dependencies generated for this target.
include test/CMakeFiles/mapstaticmethods_2.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/mapstaticmethods_2.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/mapstaticmethods_2.dir/flags.make

test/CMakeFiles/mapstaticmethods_2.dir/mapstaticmethods.cpp.o: test/CMakeFiles/mapstaticmethods_2.dir/flags.make
test/CMakeFiles/mapstaticmethods_2.dir/mapstaticmethods.cpp.o: ../test/mapstaticmethods.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bjt/Documents/research/vision/libs/eigen-3.3.7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/mapstaticmethods_2.dir/mapstaticmethods.cpp.o"
	cd /home/bjt/Documents/research/vision/libs/eigen-3.3.7/build/test && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mapstaticmethods_2.dir/mapstaticmethods.cpp.o -c /home/bjt/Documents/research/vision/libs/eigen-3.3.7/test/mapstaticmethods.cpp

test/CMakeFiles/mapstaticmethods_2.dir/mapstaticmethods.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mapstaticmethods_2.dir/mapstaticmethods.cpp.i"
	cd /home/bjt/Documents/research/vision/libs/eigen-3.3.7/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bjt/Documents/research/vision/libs/eigen-3.3.7/test/mapstaticmethods.cpp > CMakeFiles/mapstaticmethods_2.dir/mapstaticmethods.cpp.i

test/CMakeFiles/mapstaticmethods_2.dir/mapstaticmethods.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mapstaticmethods_2.dir/mapstaticmethods.cpp.s"
	cd /home/bjt/Documents/research/vision/libs/eigen-3.3.7/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bjt/Documents/research/vision/libs/eigen-3.3.7/test/mapstaticmethods.cpp -o CMakeFiles/mapstaticmethods_2.dir/mapstaticmethods.cpp.s

test/CMakeFiles/mapstaticmethods_2.dir/mapstaticmethods.cpp.o.requires:

.PHONY : test/CMakeFiles/mapstaticmethods_2.dir/mapstaticmethods.cpp.o.requires

test/CMakeFiles/mapstaticmethods_2.dir/mapstaticmethods.cpp.o.provides: test/CMakeFiles/mapstaticmethods_2.dir/mapstaticmethods.cpp.o.requires
	$(MAKE) -f test/CMakeFiles/mapstaticmethods_2.dir/build.make test/CMakeFiles/mapstaticmethods_2.dir/mapstaticmethods.cpp.o.provides.build
.PHONY : test/CMakeFiles/mapstaticmethods_2.dir/mapstaticmethods.cpp.o.provides

test/CMakeFiles/mapstaticmethods_2.dir/mapstaticmethods.cpp.o.provides.build: test/CMakeFiles/mapstaticmethods_2.dir/mapstaticmethods.cpp.o


# Object files for target mapstaticmethods_2
mapstaticmethods_2_OBJECTS = \
"CMakeFiles/mapstaticmethods_2.dir/mapstaticmethods.cpp.o"

# External object files for target mapstaticmethods_2
mapstaticmethods_2_EXTERNAL_OBJECTS =

test/mapstaticmethods_2: test/CMakeFiles/mapstaticmethods_2.dir/mapstaticmethods.cpp.o
test/mapstaticmethods_2: test/CMakeFiles/mapstaticmethods_2.dir/build.make
test/mapstaticmethods_2: test/CMakeFiles/mapstaticmethods_2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bjt/Documents/research/vision/libs/eigen-3.3.7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable mapstaticmethods_2"
	cd /home/bjt/Documents/research/vision/libs/eigen-3.3.7/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mapstaticmethods_2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/mapstaticmethods_2.dir/build: test/mapstaticmethods_2

.PHONY : test/CMakeFiles/mapstaticmethods_2.dir/build

test/CMakeFiles/mapstaticmethods_2.dir/requires: test/CMakeFiles/mapstaticmethods_2.dir/mapstaticmethods.cpp.o.requires

.PHONY : test/CMakeFiles/mapstaticmethods_2.dir/requires

test/CMakeFiles/mapstaticmethods_2.dir/clean:
	cd /home/bjt/Documents/research/vision/libs/eigen-3.3.7/build/test && $(CMAKE_COMMAND) -P CMakeFiles/mapstaticmethods_2.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/mapstaticmethods_2.dir/clean

test/CMakeFiles/mapstaticmethods_2.dir/depend:
	cd /home/bjt/Documents/research/vision/libs/eigen-3.3.7/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bjt/Documents/research/vision/libs/eigen-3.3.7 /home/bjt/Documents/research/vision/libs/eigen-3.3.7/test /home/bjt/Documents/research/vision/libs/eigen-3.3.7/build /home/bjt/Documents/research/vision/libs/eigen-3.3.7/build/test /home/bjt/Documents/research/vision/libs/eigen-3.3.7/build/test/CMakeFiles/mapstaticmethods_2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/mapstaticmethods_2.dir/depend

