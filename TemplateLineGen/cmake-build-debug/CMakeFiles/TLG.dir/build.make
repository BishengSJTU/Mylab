# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /opt/clion-2019.1.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2019.1.3/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/bisheng/final paper/Mylab/TemplateLineGen"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/bisheng/final paper/Mylab/TemplateLineGen/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/TLG.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TLG.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TLG.dir/flags.make

CMakeFiles/TLG.dir/main.cpp.o: CMakeFiles/TLG.dir/flags.make
CMakeFiles/TLG.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/bisheng/final paper/Mylab/TemplateLineGen/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TLG.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TLG.dir/main.cpp.o -c "/home/bisheng/final paper/Mylab/TemplateLineGen/main.cpp"

CMakeFiles/TLG.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TLG.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/bisheng/final paper/Mylab/TemplateLineGen/main.cpp" > CMakeFiles/TLG.dir/main.cpp.i

CMakeFiles/TLG.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TLG.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/bisheng/final paper/Mylab/TemplateLineGen/main.cpp" -o CMakeFiles/TLG.dir/main.cpp.s

# Object files for target TLG
TLG_OBJECTS = \
"CMakeFiles/TLG.dir/main.cpp.o"

# External object files for target TLG
TLG_EXTERNAL_OBJECTS =

TLG: CMakeFiles/TLG.dir/main.cpp.o
TLG: CMakeFiles/TLG.dir/build.make
TLG: /usr/local/lib/libopencv_highgui.so.3.4.2
TLG: /usr/local/lib/libyaml-cpp.a
TLG: /usr/local/lib/libopencv_videoio.so.3.4.2
TLG: /usr/local/lib/libopencv_imgcodecs.so.3.4.2
TLG: /usr/local/lib/libopencv_imgproc.so.3.4.2
TLG: /usr/local/lib/libopencv_core.so.3.4.2
TLG: CMakeFiles/TLG.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/bisheng/final paper/Mylab/TemplateLineGen/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TLG"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TLG.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TLG.dir/build: TLG

.PHONY : CMakeFiles/TLG.dir/build

CMakeFiles/TLG.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TLG.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TLG.dir/clean

CMakeFiles/TLG.dir/depend:
	cd "/home/bisheng/final paper/Mylab/TemplateLineGen/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/bisheng/final paper/Mylab/TemplateLineGen" "/home/bisheng/final paper/Mylab/TemplateLineGen" "/home/bisheng/final paper/Mylab/TemplateLineGen/cmake-build-debug" "/home/bisheng/final paper/Mylab/TemplateLineGen/cmake-build-debug" "/home/bisheng/final paper/Mylab/TemplateLineGen/cmake-build-debug/CMakeFiles/TLG.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/TLG.dir/depend

