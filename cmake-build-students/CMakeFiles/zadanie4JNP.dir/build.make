# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /tmp/tmp.dIjovpnUdW

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /tmp/tmp.dIjovpnUdW/cmake-build-students

# Include any dependencies generated for this target.
include CMakeFiles/zadanie4JNP.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/zadanie4JNP.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/zadanie4JNP.dir/flags.make

CMakeFiles/zadanie4JNP.dir/main.cpp.o: CMakeFiles/zadanie4JNP.dir/flags.make
CMakeFiles/zadanie4JNP.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.dIjovpnUdW/cmake-build-students/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/zadanie4JNP.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zadanie4JNP.dir/main.cpp.o -c /tmp/tmp.dIjovpnUdW/main.cpp

CMakeFiles/zadanie4JNP.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zadanie4JNP.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.dIjovpnUdW/main.cpp > CMakeFiles/zadanie4JNP.dir/main.cpp.i

CMakeFiles/zadanie4JNP.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zadanie4JNP.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.dIjovpnUdW/main.cpp -o CMakeFiles/zadanie4JNP.dir/main.cpp.s

CMakeFiles/zadanie4JNP.dir/hunt_examples.cpp.o: CMakeFiles/zadanie4JNP.dir/flags.make
CMakeFiles/zadanie4JNP.dir/hunt_examples.cpp.o: ../hunt_examples.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.dIjovpnUdW/cmake-build-students/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/zadanie4JNP.dir/hunt_examples.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zadanie4JNP.dir/hunt_examples.cpp.o -c /tmp/tmp.dIjovpnUdW/hunt_examples.cpp

CMakeFiles/zadanie4JNP.dir/hunt_examples.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zadanie4JNP.dir/hunt_examples.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.dIjovpnUdW/hunt_examples.cpp > CMakeFiles/zadanie4JNP.dir/hunt_examples.cpp.i

CMakeFiles/zadanie4JNP.dir/hunt_examples.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zadanie4JNP.dir/hunt_examples.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.dIjovpnUdW/hunt_examples.cpp -o CMakeFiles/zadanie4JNP.dir/hunt_examples.cpp.s

# Object files for target zadanie4JNP
zadanie4JNP_OBJECTS = \
"CMakeFiles/zadanie4JNP.dir/main.cpp.o" \
"CMakeFiles/zadanie4JNP.dir/hunt_examples.cpp.o"

# External object files for target zadanie4JNP
zadanie4JNP_EXTERNAL_OBJECTS =

zadanie4JNP: CMakeFiles/zadanie4JNP.dir/main.cpp.o
zadanie4JNP: CMakeFiles/zadanie4JNP.dir/hunt_examples.cpp.o
zadanie4JNP: CMakeFiles/zadanie4JNP.dir/build.make
zadanie4JNP: CMakeFiles/zadanie4JNP.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/tmp/tmp.dIjovpnUdW/cmake-build-students/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable zadanie4JNP"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/zadanie4JNP.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/zadanie4JNP.dir/build: zadanie4JNP

.PHONY : CMakeFiles/zadanie4JNP.dir/build

CMakeFiles/zadanie4JNP.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/zadanie4JNP.dir/cmake_clean.cmake
.PHONY : CMakeFiles/zadanie4JNP.dir/clean

CMakeFiles/zadanie4JNP.dir/depend:
	cd /tmp/tmp.dIjovpnUdW/cmake-build-students && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /tmp/tmp.dIjovpnUdW /tmp/tmp.dIjovpnUdW /tmp/tmp.dIjovpnUdW/cmake-build-students /tmp/tmp.dIjovpnUdW/cmake-build-students /tmp/tmp.dIjovpnUdW/cmake-build-students/CMakeFiles/zadanie4JNP.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/zadanie4JNP.dir/depend

