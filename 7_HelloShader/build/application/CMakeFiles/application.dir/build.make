# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.22.1/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.22.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/fengxuegt/GitHubCode/LwLearnOpenGL/HelloShader

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/fengxuegt/GitHubCode/LwLearnOpenGL/HelloShader/build

# Include any dependencies generated for this target.
include application/CMakeFiles/application.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include application/CMakeFiles/application.dir/compiler_depend.make

# Include the progress variables for this target.
include application/CMakeFiles/application.dir/progress.make

# Include the compile flags for this target's objects.
include application/CMakeFiles/application.dir/flags.make

application/CMakeFiles/application.dir/application.cpp.o: application/CMakeFiles/application.dir/flags.make
application/CMakeFiles/application.dir/application.cpp.o: ../application/application.cpp
application/CMakeFiles/application.dir/application.cpp.o: application/CMakeFiles/application.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/fengxuegt/GitHubCode/LwLearnOpenGL/HelloShader/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object application/CMakeFiles/application.dir/application.cpp.o"
	cd /Users/fengxuegt/GitHubCode/LwLearnOpenGL/HelloShader/build/application && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT application/CMakeFiles/application.dir/application.cpp.o -MF CMakeFiles/application.dir/application.cpp.o.d -o CMakeFiles/application.dir/application.cpp.o -c /Users/fengxuegt/GitHubCode/LwLearnOpenGL/HelloShader/application/application.cpp

application/CMakeFiles/application.dir/application.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/application.dir/application.cpp.i"
	cd /Users/fengxuegt/GitHubCode/LwLearnOpenGL/HelloShader/build/application && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/fengxuegt/GitHubCode/LwLearnOpenGL/HelloShader/application/application.cpp > CMakeFiles/application.dir/application.cpp.i

application/CMakeFiles/application.dir/application.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/application.dir/application.cpp.s"
	cd /Users/fengxuegt/GitHubCode/LwLearnOpenGL/HelloShader/build/application && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/fengxuegt/GitHubCode/LwLearnOpenGL/HelloShader/application/application.cpp -o CMakeFiles/application.dir/application.cpp.s

# Object files for target application
application_OBJECTS = \
"CMakeFiles/application.dir/application.cpp.o"

# External object files for target application
application_EXTERNAL_OBJECTS =

application/libapplication.a: application/CMakeFiles/application.dir/application.cpp.o
application/libapplication.a: application/CMakeFiles/application.dir/build.make
application/libapplication.a: application/CMakeFiles/application.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/fengxuegt/GitHubCode/LwLearnOpenGL/HelloShader/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libapplication.a"
	cd /Users/fengxuegt/GitHubCode/LwLearnOpenGL/HelloShader/build/application && $(CMAKE_COMMAND) -P CMakeFiles/application.dir/cmake_clean_target.cmake
	cd /Users/fengxuegt/GitHubCode/LwLearnOpenGL/HelloShader/build/application && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/application.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
application/CMakeFiles/application.dir/build: application/libapplication.a
.PHONY : application/CMakeFiles/application.dir/build

application/CMakeFiles/application.dir/clean:
	cd /Users/fengxuegt/GitHubCode/LwLearnOpenGL/HelloShader/build/application && $(CMAKE_COMMAND) -P CMakeFiles/application.dir/cmake_clean.cmake
.PHONY : application/CMakeFiles/application.dir/clean

application/CMakeFiles/application.dir/depend:
	cd /Users/fengxuegt/GitHubCode/LwLearnOpenGL/HelloShader/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/fengxuegt/GitHubCode/LwLearnOpenGL/HelloShader /Users/fengxuegt/GitHubCode/LwLearnOpenGL/HelloShader/application /Users/fengxuegt/GitHubCode/LwLearnOpenGL/HelloShader/build /Users/fengxuegt/GitHubCode/LwLearnOpenGL/HelloShader/build/application /Users/fengxuegt/GitHubCode/LwLearnOpenGL/HelloShader/build/application/CMakeFiles/application.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : application/CMakeFiles/application.dir/depend

