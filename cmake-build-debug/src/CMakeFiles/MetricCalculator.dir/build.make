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
CMAKE_COMMAND = /home/sarosi/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/201.7846.88/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/sarosi/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/201.7846.88/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sarosi/CLionProjects/MetricCalculator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sarosi/CLionProjects/MetricCalculator/cmake-build-debug

# Include any dependencies generated for this target.
include src/CMakeFiles/MetricCalculator.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/MetricCalculator.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/MetricCalculator.dir/flags.make

src/CMakeFiles/MetricCalculator.dir/main.cpp.o: src/CMakeFiles/MetricCalculator.dir/flags.make
src/CMakeFiles/MetricCalculator.dir/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sarosi/CLionProjects/MetricCalculator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/MetricCalculator.dir/main.cpp.o"
	cd /home/sarosi/CLionProjects/MetricCalculator/cmake-build-debug/src && /bin/g++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MetricCalculator.dir/main.cpp.o -c /home/sarosi/CLionProjects/MetricCalculator/src/main.cpp

src/CMakeFiles/MetricCalculator.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MetricCalculator.dir/main.cpp.i"
	cd /home/sarosi/CLionProjects/MetricCalculator/cmake-build-debug/src && /bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sarosi/CLionProjects/MetricCalculator/src/main.cpp > CMakeFiles/MetricCalculator.dir/main.cpp.i

src/CMakeFiles/MetricCalculator.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MetricCalculator.dir/main.cpp.s"
	cd /home/sarosi/CLionProjects/MetricCalculator/cmake-build-debug/src && /bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sarosi/CLionProjects/MetricCalculator/src/main.cpp -o CMakeFiles/MetricCalculator.dir/main.cpp.s

src/CMakeFiles/MetricCalculator.dir/MetricCalculator.cpp.o: src/CMakeFiles/MetricCalculator.dir/flags.make
src/CMakeFiles/MetricCalculator.dir/MetricCalculator.cpp.o: ../src/MetricCalculator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sarosi/CLionProjects/MetricCalculator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/MetricCalculator.dir/MetricCalculator.cpp.o"
	cd /home/sarosi/CLionProjects/MetricCalculator/cmake-build-debug/src && /bin/g++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MetricCalculator.dir/MetricCalculator.cpp.o -c /home/sarosi/CLionProjects/MetricCalculator/src/MetricCalculator.cpp

src/CMakeFiles/MetricCalculator.dir/MetricCalculator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MetricCalculator.dir/MetricCalculator.cpp.i"
	cd /home/sarosi/CLionProjects/MetricCalculator/cmake-build-debug/src && /bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sarosi/CLionProjects/MetricCalculator/src/MetricCalculator.cpp > CMakeFiles/MetricCalculator.dir/MetricCalculator.cpp.i

src/CMakeFiles/MetricCalculator.dir/MetricCalculator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MetricCalculator.dir/MetricCalculator.cpp.s"
	cd /home/sarosi/CLionProjects/MetricCalculator/cmake-build-debug/src && /bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sarosi/CLionProjects/MetricCalculator/src/MetricCalculator.cpp -o CMakeFiles/MetricCalculator.dir/MetricCalculator.cpp.s

# Object files for target MetricCalculator
MetricCalculator_OBJECTS = \
"CMakeFiles/MetricCalculator.dir/main.cpp.o" \
"CMakeFiles/MetricCalculator.dir/MetricCalculator.cpp.o"

# External object files for target MetricCalculator
MetricCalculator_EXTERNAL_OBJECTS =

src/MetricCalculator: src/CMakeFiles/MetricCalculator.dir/main.cpp.o
src/MetricCalculator: src/CMakeFiles/MetricCalculator.dir/MetricCalculator.cpp.o
src/MetricCalculator: src/CMakeFiles/MetricCalculator.dir/build.make
src/MetricCalculator: src/CMakeFiles/MetricCalculator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sarosi/CLionProjects/MetricCalculator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable MetricCalculator"
	cd /home/sarosi/CLionProjects/MetricCalculator/cmake-build-debug/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MetricCalculator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/MetricCalculator.dir/build: src/MetricCalculator

.PHONY : src/CMakeFiles/MetricCalculator.dir/build

src/CMakeFiles/MetricCalculator.dir/clean:
	cd /home/sarosi/CLionProjects/MetricCalculator/cmake-build-debug/src && $(CMAKE_COMMAND) -P CMakeFiles/MetricCalculator.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/MetricCalculator.dir/clean

src/CMakeFiles/MetricCalculator.dir/depend:
	cd /home/sarosi/CLionProjects/MetricCalculator/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sarosi/CLionProjects/MetricCalculator /home/sarosi/CLionProjects/MetricCalculator/src /home/sarosi/CLionProjects/MetricCalculator/cmake-build-debug /home/sarosi/CLionProjects/MetricCalculator/cmake-build-debug/src /home/sarosi/CLionProjects/MetricCalculator/cmake-build-debug/src/CMakeFiles/MetricCalculator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/MetricCalculator.dir/depend

