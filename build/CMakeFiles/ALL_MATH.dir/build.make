# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_SOURCE_DIR = /home/v_s2/Desktop/ComputerGraphicsProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/v_s2/Desktop/ComputerGraphicsProject/build

# Include any dependencies generated for this target.
include CMakeFiles/ALL_MATH.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ALL_MATH.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ALL_MATH.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ALL_MATH.dir/flags.make

CMakeFiles/ALL_MATH.dir/lib/Math/AllMath/AllMath.cpp.o: CMakeFiles/ALL_MATH.dir/flags.make
CMakeFiles/ALL_MATH.dir/lib/Math/AllMath/AllMath.cpp.o: /home/v_s2/Desktop/ComputerGraphicsProject/lib/Math/AllMath/AllMath.cpp
CMakeFiles/ALL_MATH.dir/lib/Math/AllMath/AllMath.cpp.o: CMakeFiles/ALL_MATH.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/v_s2/Desktop/ComputerGraphicsProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ALL_MATH.dir/lib/Math/AllMath/AllMath.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ALL_MATH.dir/lib/Math/AllMath/AllMath.cpp.o -MF CMakeFiles/ALL_MATH.dir/lib/Math/AllMath/AllMath.cpp.o.d -o CMakeFiles/ALL_MATH.dir/lib/Math/AllMath/AllMath.cpp.o -c /home/v_s2/Desktop/ComputerGraphicsProject/lib/Math/AllMath/AllMath.cpp

CMakeFiles/ALL_MATH.dir/lib/Math/AllMath/AllMath.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ALL_MATH.dir/lib/Math/AllMath/AllMath.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/v_s2/Desktop/ComputerGraphicsProject/lib/Math/AllMath/AllMath.cpp > CMakeFiles/ALL_MATH.dir/lib/Math/AllMath/AllMath.cpp.i

CMakeFiles/ALL_MATH.dir/lib/Math/AllMath/AllMath.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ALL_MATH.dir/lib/Math/AllMath/AllMath.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/v_s2/Desktop/ComputerGraphicsProject/lib/Math/AllMath/AllMath.cpp -o CMakeFiles/ALL_MATH.dir/lib/Math/AllMath/AllMath.cpp.s

# Object files for target ALL_MATH
ALL_MATH_OBJECTS = \
"CMakeFiles/ALL_MATH.dir/lib/Math/AllMath/AllMath.cpp.o"

# External object files for target ALL_MATH
ALL_MATH_EXTERNAL_OBJECTS =

libALL_MATH.a: CMakeFiles/ALL_MATH.dir/lib/Math/AllMath/AllMath.cpp.o
libALL_MATH.a: CMakeFiles/ALL_MATH.dir/build.make
libALL_MATH.a: CMakeFiles/ALL_MATH.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/v_s2/Desktop/ComputerGraphicsProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libALL_MATH.a"
	$(CMAKE_COMMAND) -P CMakeFiles/ALL_MATH.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ALL_MATH.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ALL_MATH.dir/build: libALL_MATH.a
.PHONY : CMakeFiles/ALL_MATH.dir/build

CMakeFiles/ALL_MATH.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ALL_MATH.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ALL_MATH.dir/clean

CMakeFiles/ALL_MATH.dir/depend:
	cd /home/v_s2/Desktop/ComputerGraphicsProject/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/v_s2/Desktop/ComputerGraphicsProject /home/v_s2/Desktop/ComputerGraphicsProject /home/v_s2/Desktop/ComputerGraphicsProject/build /home/v_s2/Desktop/ComputerGraphicsProject/build /home/v_s2/Desktop/ComputerGraphicsProject/build/CMakeFiles/ALL_MATH.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ALL_MATH.dir/depend

