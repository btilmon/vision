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
include libs/eigen-3.3.7/doc/examples/CMakeFiles/function_taking_ref.dir/depend.make

# Include the progress variables for this target.
include libs/eigen-3.3.7/doc/examples/CMakeFiles/function_taking_ref.dir/progress.make

# Include the compile flags for this target's objects.
include libs/eigen-3.3.7/doc/examples/CMakeFiles/function_taking_ref.dir/flags.make

libs/eigen-3.3.7/doc/examples/CMakeFiles/function_taking_ref.dir/function_taking_ref.cpp.o: libs/eigen-3.3.7/doc/examples/CMakeFiles/function_taking_ref.dir/flags.make
libs/eigen-3.3.7/doc/examples/CMakeFiles/function_taking_ref.dir/function_taking_ref.cpp.o: ../libs/eigen-3.3.7/doc/examples/function_taking_ref.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bjt/Documents/research/vision/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object libs/eigen-3.3.7/doc/examples/CMakeFiles/function_taking_ref.dir/function_taking_ref.cpp.o"
	cd /home/bjt/Documents/research/vision/build/libs/eigen-3.3.7/doc/examples && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/function_taking_ref.dir/function_taking_ref.cpp.o -c /home/bjt/Documents/research/vision/libs/eigen-3.3.7/doc/examples/function_taking_ref.cpp

libs/eigen-3.3.7/doc/examples/CMakeFiles/function_taking_ref.dir/function_taking_ref.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/function_taking_ref.dir/function_taking_ref.cpp.i"
	cd /home/bjt/Documents/research/vision/build/libs/eigen-3.3.7/doc/examples && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bjt/Documents/research/vision/libs/eigen-3.3.7/doc/examples/function_taking_ref.cpp > CMakeFiles/function_taking_ref.dir/function_taking_ref.cpp.i

libs/eigen-3.3.7/doc/examples/CMakeFiles/function_taking_ref.dir/function_taking_ref.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/function_taking_ref.dir/function_taking_ref.cpp.s"
	cd /home/bjt/Documents/research/vision/build/libs/eigen-3.3.7/doc/examples && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bjt/Documents/research/vision/libs/eigen-3.3.7/doc/examples/function_taking_ref.cpp -o CMakeFiles/function_taking_ref.dir/function_taking_ref.cpp.s

libs/eigen-3.3.7/doc/examples/CMakeFiles/function_taking_ref.dir/function_taking_ref.cpp.o.requires:

.PHONY : libs/eigen-3.3.7/doc/examples/CMakeFiles/function_taking_ref.dir/function_taking_ref.cpp.o.requires

libs/eigen-3.3.7/doc/examples/CMakeFiles/function_taking_ref.dir/function_taking_ref.cpp.o.provides: libs/eigen-3.3.7/doc/examples/CMakeFiles/function_taking_ref.dir/function_taking_ref.cpp.o.requires
	$(MAKE) -f libs/eigen-3.3.7/doc/examples/CMakeFiles/function_taking_ref.dir/build.make libs/eigen-3.3.7/doc/examples/CMakeFiles/function_taking_ref.dir/function_taking_ref.cpp.o.provides.build
.PHONY : libs/eigen-3.3.7/doc/examples/CMakeFiles/function_taking_ref.dir/function_taking_ref.cpp.o.provides

libs/eigen-3.3.7/doc/examples/CMakeFiles/function_taking_ref.dir/function_taking_ref.cpp.o.provides.build: libs/eigen-3.3.7/doc/examples/CMakeFiles/function_taking_ref.dir/function_taking_ref.cpp.o


# Object files for target function_taking_ref
function_taking_ref_OBJECTS = \
"CMakeFiles/function_taking_ref.dir/function_taking_ref.cpp.o"

# External object files for target function_taking_ref
function_taking_ref_EXTERNAL_OBJECTS =

libs/eigen-3.3.7/doc/examples/function_taking_ref: libs/eigen-3.3.7/doc/examples/CMakeFiles/function_taking_ref.dir/function_taking_ref.cpp.o
libs/eigen-3.3.7/doc/examples/function_taking_ref: libs/eigen-3.3.7/doc/examples/CMakeFiles/function_taking_ref.dir/build.make
libs/eigen-3.3.7/doc/examples/function_taking_ref: libs/eigen-3.3.7/doc/examples/CMakeFiles/function_taking_ref.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bjt/Documents/research/vision/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable function_taking_ref"
	cd /home/bjt/Documents/research/vision/build/libs/eigen-3.3.7/doc/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/function_taking_ref.dir/link.txt --verbose=$(VERBOSE)
	cd /home/bjt/Documents/research/vision/build/libs/eigen-3.3.7/doc/examples && ./function_taking_ref >/home/bjt/Documents/research/vision/build/libs/eigen-3.3.7/doc/examples/function_taking_ref.out

# Rule to build all files generated by this target.
libs/eigen-3.3.7/doc/examples/CMakeFiles/function_taking_ref.dir/build: libs/eigen-3.3.7/doc/examples/function_taking_ref

.PHONY : libs/eigen-3.3.7/doc/examples/CMakeFiles/function_taking_ref.dir/build

libs/eigen-3.3.7/doc/examples/CMakeFiles/function_taking_ref.dir/requires: libs/eigen-3.3.7/doc/examples/CMakeFiles/function_taking_ref.dir/function_taking_ref.cpp.o.requires

.PHONY : libs/eigen-3.3.7/doc/examples/CMakeFiles/function_taking_ref.dir/requires

libs/eigen-3.3.7/doc/examples/CMakeFiles/function_taking_ref.dir/clean:
	cd /home/bjt/Documents/research/vision/build/libs/eigen-3.3.7/doc/examples && $(CMAKE_COMMAND) -P CMakeFiles/function_taking_ref.dir/cmake_clean.cmake
.PHONY : libs/eigen-3.3.7/doc/examples/CMakeFiles/function_taking_ref.dir/clean

libs/eigen-3.3.7/doc/examples/CMakeFiles/function_taking_ref.dir/depend:
	cd /home/bjt/Documents/research/vision/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bjt/Documents/research/vision /home/bjt/Documents/research/vision/libs/eigen-3.3.7/doc/examples /home/bjt/Documents/research/vision/build /home/bjt/Documents/research/vision/build/libs/eigen-3.3.7/doc/examples /home/bjt/Documents/research/vision/build/libs/eigen-3.3.7/doc/examples/CMakeFiles/function_taking_ref.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libs/eigen-3.3.7/doc/examples/CMakeFiles/function_taking_ref.dir/depend

