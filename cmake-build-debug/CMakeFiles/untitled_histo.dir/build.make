# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /home/tobi/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/202.6397.106/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/tobi/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/202.6397.106/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tobi/CLionProjects/MetricCalculator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tobi/CLionProjects/MetricCalculator/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/untitled_histo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/untitled_histo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/untitled_histo.dir/flags.make

CMakeFiles/untitled_histo.dir/main.cpp.o: CMakeFiles/untitled_histo.dir/flags.make
CMakeFiles/untitled_histo.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tobi/CLionProjects/MetricCalculator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/untitled_histo.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/untitled_histo.dir/main.cpp.o -c /home/tobi/CLionProjects/MetricCalculator/main.cpp

CMakeFiles/untitled_histo.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/untitled_histo.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tobi/CLionProjects/MetricCalculator/main.cpp > CMakeFiles/untitled_histo.dir/main.cpp.i

CMakeFiles/untitled_histo.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/untitled_histo.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tobi/CLionProjects/MetricCalculator/main.cpp -o CMakeFiles/untitled_histo.dir/main.cpp.s

CMakeFiles/untitled_histo.dir/MetricCalculator.cpp.o: CMakeFiles/untitled_histo.dir/flags.make
CMakeFiles/untitled_histo.dir/MetricCalculator.cpp.o: ../MetricCalculator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tobi/CLionProjects/MetricCalculator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/untitled_histo.dir/MetricCalculator.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/untitled_histo.dir/MetricCalculator.cpp.o -c /home/tobi/CLionProjects/MetricCalculator/MetricCalculator.cpp

CMakeFiles/untitled_histo.dir/MetricCalculator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/untitled_histo.dir/MetricCalculator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tobi/CLionProjects/MetricCalculator/MetricCalculator.cpp > CMakeFiles/untitled_histo.dir/MetricCalculator.cpp.i

CMakeFiles/untitled_histo.dir/MetricCalculator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/untitled_histo.dir/MetricCalculator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tobi/CLionProjects/MetricCalculator/MetricCalculator.cpp -o CMakeFiles/untitled_histo.dir/MetricCalculator.cpp.s

CMakeFiles/untitled_histo.dir/test.cpp.o: CMakeFiles/untitled_histo.dir/flags.make
CMakeFiles/untitled_histo.dir/test.cpp.o: ../test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tobi/CLionProjects/MetricCalculator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/untitled_histo.dir/test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/untitled_histo.dir/test.cpp.o -c /home/tobi/CLionProjects/MetricCalculator/test.cpp

CMakeFiles/untitled_histo.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/untitled_histo.dir/test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tobi/CLionProjects/MetricCalculator/test.cpp > CMakeFiles/untitled_histo.dir/test.cpp.i

CMakeFiles/untitled_histo.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/untitled_histo.dir/test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tobi/CLionProjects/MetricCalculator/test.cpp -o CMakeFiles/untitled_histo.dir/test.cpp.s

CMakeFiles/untitled_histo.dir/test-main.cpp.o: CMakeFiles/untitled_histo.dir/flags.make
CMakeFiles/untitled_histo.dir/test-main.cpp.o: ../test-main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tobi/CLionProjects/MetricCalculator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/untitled_histo.dir/test-main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/untitled_histo.dir/test-main.cpp.o -c /home/tobi/CLionProjects/MetricCalculator/test-main.cpp

CMakeFiles/untitled_histo.dir/test-main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/untitled_histo.dir/test-main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tobi/CLionProjects/MetricCalculator/test-main.cpp > CMakeFiles/untitled_histo.dir/test-main.cpp.i

CMakeFiles/untitled_histo.dir/test-main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/untitled_histo.dir/test-main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tobi/CLionProjects/MetricCalculator/test-main.cpp -o CMakeFiles/untitled_histo.dir/test-main.cpp.s

# Object files for target untitled_histo
untitled_histo_OBJECTS = \
"CMakeFiles/untitled_histo.dir/main.cpp.o" \
"CMakeFiles/untitled_histo.dir/MetricCalculator.cpp.o" \
"CMakeFiles/untitled_histo.dir/test.cpp.o" \
"CMakeFiles/untitled_histo.dir/test-main.cpp.o"

# External object files for target untitled_histo
untitled_histo_EXTERNAL_OBJECTS =

untitled_histo: CMakeFiles/untitled_histo.dir/main.cpp.o
untitled_histo: CMakeFiles/untitled_histo.dir/MetricCalculator.cpp.o
untitled_histo: CMakeFiles/untitled_histo.dir/test.cpp.o
untitled_histo: CMakeFiles/untitled_histo.dir/test-main.cpp.o
untitled_histo: CMakeFiles/untitled_histo.dir/build.make
untitled_histo: CMakeFiles/untitled_histo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tobi/CLionProjects/MetricCalculator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable untitled_histo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/untitled_histo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/untitled_histo.dir/build: untitled_histo

.PHONY : CMakeFiles/untitled_histo.dir/build

CMakeFiles/untitled_histo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/untitled_histo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/untitled_histo.dir/clean

CMakeFiles/untitled_histo.dir/depend:
	cd /home/tobi/CLionProjects/MetricCalculator/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tobi/CLionProjects/MetricCalculator /home/tobi/CLionProjects/MetricCalculator /home/tobi/CLionProjects/MetricCalculator/cmake-build-debug /home/tobi/CLionProjects/MetricCalculator/cmake-build-debug /home/tobi/CLionProjects/MetricCalculator/cmake-build-debug/CMakeFiles/untitled_histo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/untitled_histo.dir/depend
