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
CMAKE_COMMAND = "C:/Program Files/CMake/bin/cmake.exe"

# The command to remove a file.
RM = "C:/Program Files/CMake/bin/cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:/Users/Vs2/Desktop/ComputerGraphicsProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:/Users/Vs2/Desktop/ComputerGraphicsProject/build

# Include any dependencies generated for this target.
include CMakeFiles/GameTests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/GameTests.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/GameTests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GameTests.dir/flags.make

CMakeFiles/GameTests.dir/tests/UnitTests/GameTests.cpp.obj: CMakeFiles/GameTests.dir/flags.make
CMakeFiles/GameTests.dir/tests/UnitTests/GameTests.cpp.obj: CMakeFiles/GameTests.dir/includes_CXX.rsp
CMakeFiles/GameTests.dir/tests/UnitTests/GameTests.cpp.obj: C:/Users/Vs2/Desktop/ComputerGraphicsProject/tests/UnitTests/GameTests.cpp
CMakeFiles/GameTests.dir/tests/UnitTests/GameTests.cpp.obj: CMakeFiles/GameTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/Users/Vs2/Desktop/ComputerGraphicsProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GameTests.dir/tests/UnitTests/GameTests.cpp.obj"
	C:/MinGW/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GameTests.dir/tests/UnitTests/GameTests.cpp.obj -MF CMakeFiles/GameTests.dir/tests/UnitTests/GameTests.cpp.obj.d -o CMakeFiles/GameTests.dir/tests/UnitTests/GameTests.cpp.obj -c C:/Users/Vs2/Desktop/ComputerGraphicsProject/tests/UnitTests/GameTests.cpp

CMakeFiles/GameTests.dir/tests/UnitTests/GameTests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameTests.dir/tests/UnitTests/GameTests.cpp.i"
	C:/MinGW/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:/Users/Vs2/Desktop/ComputerGraphicsProject/tests/UnitTests/GameTests.cpp > CMakeFiles/GameTests.dir/tests/UnitTests/GameTests.cpp.i

CMakeFiles/GameTests.dir/tests/UnitTests/GameTests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameTests.dir/tests/UnitTests/GameTests.cpp.s"
	C:/MinGW/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:/Users/Vs2/Desktop/ComputerGraphicsProject/tests/UnitTests/GameTests.cpp -o CMakeFiles/GameTests.dir/tests/UnitTests/GameTests.cpp.s

# Object files for target GameTests
GameTests_OBJECTS = \
"CMakeFiles/GameTests.dir/tests/UnitTests/GameTests.cpp.obj"

# External object files for target GameTests
GameTests_EXTERNAL_OBJECTS =

GameTests.exe: CMakeFiles/GameTests.dir/tests/UnitTests/GameTests.cpp.obj
GameTests.exe: CMakeFiles/GameTests.dir/build.make
GameTests.exe: libENGINE_BASIC_CLASSES.a
GameTests.exe: libGAME_CAMERA.a
GameTests.exe: libGAME_OBJECT.a
GameTests.exe: libGAME.a
GameTests.exe: libRAY.a
GameTests.exe: libENTITIES_LIST.a
GameTests.exe: libENTITY.a
GameTests.exe: libIDENTIFIER.a
GameTests.exe: libCOORDINATE_SYSTEM.a
GameTests.exe: libVECTOR_SPACE.a
GameTests.exe: libPOINT.a
GameTests.exe: libFUNCTIONS.a
GameTests.exe: libVECTOR.a
GameTests.exe: libMATRIX.a
GameTests.exe: libMATH_EXCEPTION.a
GameTests.exe: libACCURACY.a
GameTests.exe: CMakeFiles/GameTests.dir/linkLibs.rsp
GameTests.exe: CMakeFiles/GameTests.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:/Users/Vs2/Desktop/ComputerGraphicsProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable GameTests.exe"
	"C:/Program Files/CMake/bin/cmake.exe" -E rm -f CMakeFiles/GameTests.dir/objects.a
	C:/MinGW/bin/ar.exe qc CMakeFiles/GameTests.dir/objects.a @CMakeFiles/GameTests.dir/objects1.rsp
	C:/MinGW/bin/g++.exe -g -Wl,--whole-archive CMakeFiles/GameTests.dir/objects.a -Wl,--no-whole-archive -o GameTests.exe -Wl,--out-implib,libGameTests.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/GameTests.dir/linkLibs.rsp

# Rule to build all files generated by this target.
CMakeFiles/GameTests.dir/build: GameTests.exe
.PHONY : CMakeFiles/GameTests.dir/build

CMakeFiles/GameTests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GameTests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GameTests.dir/clean

CMakeFiles/GameTests.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" C:/Users/Vs2/Desktop/ComputerGraphicsProject C:/Users/Vs2/Desktop/ComputerGraphicsProject C:/Users/Vs2/Desktop/ComputerGraphicsProject/build C:/Users/Vs2/Desktop/ComputerGraphicsProject/build C:/Users/Vs2/Desktop/ComputerGraphicsProject/build/CMakeFiles/GameTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/GameTests.dir/depend

