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
CMAKE_SOURCE_DIR = /home/bjt/Documents/research/vision

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bjt/Documents/research/vision/build

# Include any dependencies generated for this target.
include libs/eigen-3.3.7/test/CMakeFiles/smallvectors.dir/depend.make

# Include the progress variables for this target.
include libs/eigen-3.3.7/test/CMakeFiles/smallvectors.dir/progress.make

# Include the compile flags for this target's objects.
include libs/eigen-3.3.7/test/CMakeFiles/smallvectors.dir/flags.make

libs/eigen-3.3.7/test/CMakeFiles/smallvectors.dir/smallvectors.cpp.o: libs/eigen-3.3.7/test/CMakeFiles/smallvectors.dir/flags.make
libs/eigen-3.3.7/test/CMakeFiles/smallvectors.dir/smallvectors.cpp.o: ../libs/eigen-3.3.7/test/smallvectors.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bjt/Documents/research/vision/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object libs/eigen-3.3.7/test/CMakeFiles/smallvectors.dir/smallvectors.cpp.o"
	cd /home/bjt/Documents/research/vision/build/libs/eigen-3.3.7/test && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/smallvectors.dir/smallvectors.cpp.o -c /home/bjt/Documents/research/vision/libs/eigen-3.3.7/test/smallvectors.cpp

libs/eigen-3.3.7/test/CMakeFiles/smallvectors.dir/smallvectors.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/smallvectors.dir/smallvectors.cpp.i"
	cd /home/bjt/Documents/research/vision/build/libs/eigen-3.3.7/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bjt/Documents/research/vision/libs/eigen-3.3.7/test/smallvectors.cpp > CMakeFiles/smallvectors.dir/smallvectors.cpp.i

libs/eigen-3.3.7/test/CMakeFiles/smallvectors.dir/smallvectors.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/smallvectors.dir/smallvectors.cpp.s"
	cd /home/bjt/Documents/research/vision/build/libs/eigen-3.3.7/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bjt/Documents/research/vision/libs/eigen-3.3.7/test/smallvectors.cpp -o CMakeFiles/smallvectors.dir/smallvectors.cpp.s

libs/eigen-3.3.7/test/CMakeFiles/smallvectors.dir/smallvectors.cpp.o.requires:

.PHONY : libs/eigen-3.3.7/test/CMakeFiles/smallvectors.dir/smallvectors.cpp.o.requires

libs/eigen-3.3.7/test/CMakeFiles/smallvectors.dir/smallvectors.cpp.o.provides: libs/eigen-3.3.7/test/CMakeFiles/smallvectors.dir/smallvectors.cpp.o.requires
	$(MAKE) -f libs/eigen-3.3.7/test/CMakeFiles/smallvectors.dir/build.make libs/eigen-3.3.7/test/CMakeFiles/smallvectors.dir/smallvectors.cpp.o.provides.build
.PHONY : libs/eigen-3.3.7/test/CMakeFiles/smallvectors.dir/smallvectors.cpp.o.provides

libs/eigen-3.3.7/test/CMakeFiles/smallvectors.dir/smallvectors.cpp.o.provides.build: libs/eigen-3.3.7/test/CMakeFiles/smallvectors.dir/smallvectors.cpp.o


# Object files for target smallvectors
smallvectors_OBJECTS = \
"CMakeFiles/smallvectors.dir/smallvectors.cpp.o"

# External object files for target smallvectors
smallvectors_EXTERNAL_OBJECTS =

libs/eigen-3.3.7/test/smallvectors: libs/eigen-3.3.7/test/CMakeFiles/smallvectors.dir/smallvectors.cpp.o
libs/eigen-3.3.7/test/smallvectors: libs/eigen-3.3.7/test/CMakeFiles/smallvectors.dir/build.make
libs/eigen-3.3.7/test/smallvectors: libs/eigen-3.3.7/test/CMakeFiles/smallvectors.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bjt/Documents/research/vision/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable smallvectors"
	cd /home/bjt/Documents/research/vision/build/libs/eigen-3.3.7/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/smallvectors.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libs/eigen-3.3.7/test/CMakeFiles/smallvectors.dir/build: libs/eigen-3.3.7/test/smallvectors

.PHONY : libs/eigen-3.3.7/test/CMakeFiles/smallvectors.dir/build

libs/eigen-3.3.7/test/CMakeFiles/smallvectors.dir/requires: libs/eigen-3.3.7/test/CMakeFiles/smallvectors.dir/smallvectors.cpp.o.requires

.PHONY : libs/eigen-3.3.7/test/CMakeFiles/smallvectors.dir/requires

libs/eigen-3.3.7/test/CMakeFiles/smallvectors.dir/clean:
	cd /home/bjt/Documents/research/vision/build/libs/eigen-3.3.7/test && $(CMAKE_COMMAND) -P CMakeFiles/smallvectors.dir/cmake_clean.cmake
.PHONY : libs/eigen-3.3.7/test/CMakeFiles/smallvectors.dir/clean

libs/eigen-3.3.7/test/CMakeFiles/smallvectors.dir/depend:
	cd /home/bjt/Documents/research/vision/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bjt/Documents/research/vision /home/bjt/Documents/research/vision/libs/eigen-3.3.7/test /home/bjt/Documents/research/vision/build /home/bjt/Documents/research/vision/build/libs/eigen-3.3.7/test /home/bjt/Documents/research/vision/build/libs/eigen-3.3.7/test/CMakeFiles/smallvectors.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libs/eigen-3.3.7/test/CMakeFiles/smallvectors.dir/depend

