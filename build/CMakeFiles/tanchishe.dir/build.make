# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /home/ls/cmake3.27/cmake-3.27.0-rc3-linux-x86_64/bin/cmake

# The command to remove a file.
RM = /home/ls/cmake3.27/cmake-3.27.0-rc3-linux-x86_64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ls/vscode/mycode/misson2/tanchishe

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ls/vscode/mycode/misson2/tanchishe/build

# Include any dependencies generated for this target.
include CMakeFiles/tanchishe.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/tanchishe.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/tanchishe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tanchishe.dir/flags.make

CMakeFiles/tanchishe.dir/tanchishe.cpp.o: CMakeFiles/tanchishe.dir/flags.make
CMakeFiles/tanchishe.dir/tanchishe.cpp.o: /home/ls/vscode/mycode/misson2/tanchishe/tanchishe.cpp
CMakeFiles/tanchishe.dir/tanchishe.cpp.o: CMakeFiles/tanchishe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ls/vscode/mycode/misson2/tanchishe/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tanchishe.dir/tanchishe.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tanchishe.dir/tanchishe.cpp.o -MF CMakeFiles/tanchishe.dir/tanchishe.cpp.o.d -o CMakeFiles/tanchishe.dir/tanchishe.cpp.o -c /home/ls/vscode/mycode/misson2/tanchishe/tanchishe.cpp

CMakeFiles/tanchishe.dir/tanchishe.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tanchishe.dir/tanchishe.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ls/vscode/mycode/misson2/tanchishe/tanchishe.cpp > CMakeFiles/tanchishe.dir/tanchishe.cpp.i

CMakeFiles/tanchishe.dir/tanchishe.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tanchishe.dir/tanchishe.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ls/vscode/mycode/misson2/tanchishe/tanchishe.cpp -o CMakeFiles/tanchishe.dir/tanchishe.cpp.s

# Object files for target tanchishe
tanchishe_OBJECTS = \
"CMakeFiles/tanchishe.dir/tanchishe.cpp.o"

# External object files for target tanchishe
tanchishe_EXTERNAL_OBJECTS =

tanchishe: CMakeFiles/tanchishe.dir/tanchishe.cpp.o
tanchishe: CMakeFiles/tanchishe.dir/build.make
tanchishe: CMakeFiles/tanchishe.dir/compiler_depend.ts
tanchishe: /usr/local/lib/libopencv_gapi.so.4.7.0
tanchishe: /usr/local/lib/libopencv_highgui.so.4.7.0
tanchishe: /usr/local/lib/libopencv_ml.so.4.7.0
tanchishe: /usr/local/lib/libopencv_objdetect.so.4.7.0
tanchishe: /usr/local/lib/libopencv_photo.so.4.7.0
tanchishe: /usr/local/lib/libopencv_stitching.so.4.7.0
tanchishe: /usr/local/lib/libopencv_video.so.4.7.0
tanchishe: /usr/local/lib/libopencv_videoio.so.4.7.0
tanchishe: /usr/local/lib/libopencv_imgcodecs.so.4.7.0
tanchishe: /usr/local/lib/libopencv_dnn.so.4.7.0
tanchishe: /usr/local/lib/libopencv_calib3d.so.4.7.0
tanchishe: /usr/local/lib/libopencv_features2d.so.4.7.0
tanchishe: /usr/local/lib/libopencv_flann.so.4.7.0
tanchishe: /usr/local/lib/libopencv_imgproc.so.4.7.0
tanchishe: /usr/local/lib/libopencv_core.so.4.7.0
tanchishe: CMakeFiles/tanchishe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/ls/vscode/mycode/misson2/tanchishe/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tanchishe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tanchishe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tanchishe.dir/build: tanchishe
.PHONY : CMakeFiles/tanchishe.dir/build

CMakeFiles/tanchishe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tanchishe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tanchishe.dir/clean

CMakeFiles/tanchishe.dir/depend:
	cd /home/ls/vscode/mycode/misson2/tanchishe/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ls/vscode/mycode/misson2/tanchishe /home/ls/vscode/mycode/misson2/tanchishe /home/ls/vscode/mycode/misson2/tanchishe/build /home/ls/vscode/mycode/misson2/tanchishe/build /home/ls/vscode/mycode/misson2/tanchishe/build/CMakeFiles/tanchishe.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/tanchishe.dir/depend

