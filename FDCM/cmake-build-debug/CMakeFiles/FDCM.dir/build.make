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
CMAKE_SOURCE_DIR = /home/bisheng/final_paper/FDCM

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bisheng/final_paper/FDCM/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/FDCM.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/FDCM.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FDCM.dir/flags.make

CMakeFiles/FDCM.dir/main.cpp.o: CMakeFiles/FDCM.dir/flags.make
CMakeFiles/FDCM.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bisheng/final_paper/FDCM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/FDCM.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FDCM.dir/main.cpp.o -c /home/bisheng/final_paper/FDCM/main.cpp

CMakeFiles/FDCM.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FDCM.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bisheng/final_paper/FDCM/main.cpp > CMakeFiles/FDCM.dir/main.cpp.i

CMakeFiles/FDCM.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FDCM.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bisheng/final_paper/FDCM/main.cpp -o CMakeFiles/FDCM.dir/main.cpp.s

CMakeFiles/FDCM.dir/IprovedFDCM.cpp.o: CMakeFiles/FDCM.dir/flags.make
CMakeFiles/FDCM.dir/IprovedFDCM.cpp.o: ../IprovedFDCM.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bisheng/final_paper/FDCM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/FDCM.dir/IprovedFDCM.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FDCM.dir/IprovedFDCM.cpp.o -c /home/bisheng/final_paper/FDCM/IprovedFDCM.cpp

CMakeFiles/FDCM.dir/IprovedFDCM.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FDCM.dir/IprovedFDCM.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bisheng/final_paper/FDCM/IprovedFDCM.cpp > CMakeFiles/FDCM.dir/IprovedFDCM.cpp.i

CMakeFiles/FDCM.dir/IprovedFDCM.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FDCM.dir/IprovedFDCM.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bisheng/final_paper/FDCM/IprovedFDCM.cpp -o CMakeFiles/FDCM.dir/IprovedFDCM.cpp.s

# Object files for target FDCM
FDCM_OBJECTS = \
"CMakeFiles/FDCM.dir/main.cpp.o" \
"CMakeFiles/FDCM.dir/IprovedFDCM.cpp.o"

# External object files for target FDCM
FDCM_EXTERNAL_OBJECTS =

FDCM: CMakeFiles/FDCM.dir/main.cpp.o
FDCM: CMakeFiles/FDCM.dir/IprovedFDCM.cpp.o
FDCM: CMakeFiles/FDCM.dir/build.make
FDCM: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_highgui3.so.3.3.1
FDCM: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_videoio3.so.3.3.1
FDCM: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_imgcodecs3.so.3.3.1
FDCM: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_imgproc3.so.3.3.1
FDCM: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_core3.so.3.3.1
FDCM: CMakeFiles/FDCM.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bisheng/final_paper/FDCM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable FDCM"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FDCM.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FDCM.dir/build: FDCM

.PHONY : CMakeFiles/FDCM.dir/build

CMakeFiles/FDCM.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FDCM.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FDCM.dir/clean

CMakeFiles/FDCM.dir/depend:
	cd /home/bisheng/final_paper/FDCM/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bisheng/final_paper/FDCM /home/bisheng/final_paper/FDCM /home/bisheng/final_paper/FDCM/cmake-build-debug /home/bisheng/final_paper/FDCM/cmake-build-debug /home/bisheng/final_paper/FDCM/cmake-build-debug/CMakeFiles/FDCM.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/FDCM.dir/depend

