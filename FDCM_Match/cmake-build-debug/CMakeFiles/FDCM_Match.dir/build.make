# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /opt/clion-2018.3.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2018.3.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/bisheng/final_paper/FDCM_Match

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bisheng/final_paper/FDCM_Match/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/FDCM_Match.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/FDCM_Match.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FDCM_Match.dir/flags.make

CMakeFiles/FDCM_Match.dir/main.cpp.o: CMakeFiles/FDCM_Match.dir/flags.make
CMakeFiles/FDCM_Match.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bisheng/final_paper/FDCM_Match/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/FDCM_Match.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FDCM_Match.dir/main.cpp.o -c /home/bisheng/final_paper/FDCM_Match/main.cpp

CMakeFiles/FDCM_Match.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FDCM_Match.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bisheng/final_paper/FDCM_Match/main.cpp > CMakeFiles/FDCM_Match.dir/main.cpp.i

CMakeFiles/FDCM_Match.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FDCM_Match.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bisheng/final_paper/FDCM_Match/main.cpp -o CMakeFiles/FDCM_Match.dir/main.cpp.s

# Object files for target FDCM_Match
FDCM_Match_OBJECTS = \
"CMakeFiles/FDCM_Match.dir/main.cpp.o"

# External object files for target FDCM_Match
FDCM_Match_EXTERNAL_OBJECTS =

FDCM_Match: CMakeFiles/FDCM_Match.dir/main.cpp.o
FDCM_Match: CMakeFiles/FDCM_Match.dir/build.make
FDCM_Match: CMakeFiles/FDCM_Match.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bisheng/final_paper/FDCM_Match/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable FDCM_Match"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FDCM_Match.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FDCM_Match.dir/build: FDCM_Match

.PHONY : CMakeFiles/FDCM_Match.dir/build

CMakeFiles/FDCM_Match.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FDCM_Match.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FDCM_Match.dir/clean

CMakeFiles/FDCM_Match.dir/depend:
	cd /home/bisheng/final_paper/FDCM_Match/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bisheng/final_paper/FDCM_Match /home/bisheng/final_paper/FDCM_Match /home/bisheng/final_paper/FDCM_Match/cmake-build-debug /home/bisheng/final_paper/FDCM_Match/cmake-build-debug /home/bisheng/final_paper/FDCM_Match/cmake-build-debug/CMakeFiles/FDCM_Match.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/FDCM_Match.dir/depend

