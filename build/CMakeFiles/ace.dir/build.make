# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/scutech/code/ace

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/scutech/code/ace/build

# Include any dependencies generated for this target.
include CMakeFiles/ace.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ace.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ace.dir/flags.make

CMakeFiles/ace.dir/main.cpp.o: CMakeFiles/ace.dir/flags.make
CMakeFiles/ace.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/scutech/code/ace/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ace.dir/main.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ace.dir/main.cpp.o -c /home/scutech/code/ace/main.cpp

CMakeFiles/ace.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ace.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scutech/code/ace/main.cpp > CMakeFiles/ace.dir/main.cpp.i

CMakeFiles/ace.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ace.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scutech/code/ace/main.cpp -o CMakeFiles/ace.dir/main.cpp.s

# Object files for target ace
ace_OBJECTS = \
"CMakeFiles/ace.dir/main.cpp.o"

# External object files for target ace
ace_EXTERNAL_OBJECTS =

ace: CMakeFiles/ace.dir/main.cpp.o
ace: CMakeFiles/ace.dir/build.make
ace: CMakeFiles/ace.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/scutech/code/ace/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ace"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ace.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ace.dir/build: ace

.PHONY : CMakeFiles/ace.dir/build

CMakeFiles/ace.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ace.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ace.dir/clean

CMakeFiles/ace.dir/depend:
	cd /home/scutech/code/ace/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/scutech/code/ace /home/scutech/code/ace /home/scutech/code/ace/build /home/scutech/code/ace/build /home/scutech/code/ace/build/CMakeFiles/ace.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ace.dir/depend
