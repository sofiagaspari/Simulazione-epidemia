# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.24.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.24.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/giovanniguidocapano/Desktop/progetto

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/giovanniguidocapano/Desktop/progetto/build

# Include any dependencies generated for this target.
include simulation/CMakeFiles/window.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include simulation/CMakeFiles/window.dir/compiler_depend.make

# Include the progress variables for this target.
include simulation/CMakeFiles/window.dir/progress.make

# Include the compile flags for this target's objects.
include simulation/CMakeFiles/window.dir/flags.make

simulation/CMakeFiles/window.dir/board.cpp.o: simulation/CMakeFiles/window.dir/flags.make
simulation/CMakeFiles/window.dir/board.cpp.o: /Users/giovanniguidocapano/Desktop/progetto/simulation/board.cpp
simulation/CMakeFiles/window.dir/board.cpp.o: simulation/CMakeFiles/window.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/giovanniguidocapano/Desktop/progetto/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object simulation/CMakeFiles/window.dir/board.cpp.o"
	cd /Users/giovanniguidocapano/Desktop/progetto/build/simulation && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT simulation/CMakeFiles/window.dir/board.cpp.o -MF CMakeFiles/window.dir/board.cpp.o.d -o CMakeFiles/window.dir/board.cpp.o -c /Users/giovanniguidocapano/Desktop/progetto/simulation/board.cpp

simulation/CMakeFiles/window.dir/board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/window.dir/board.cpp.i"
	cd /Users/giovanniguidocapano/Desktop/progetto/build/simulation && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/giovanniguidocapano/Desktop/progetto/simulation/board.cpp > CMakeFiles/window.dir/board.cpp.i

simulation/CMakeFiles/window.dir/board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/window.dir/board.cpp.s"
	cd /Users/giovanniguidocapano/Desktop/progetto/build/simulation && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/giovanniguidocapano/Desktop/progetto/simulation/board.cpp -o CMakeFiles/window.dir/board.cpp.s

simulation/CMakeFiles/window.dir/epidemic.cpp.o: simulation/CMakeFiles/window.dir/flags.make
simulation/CMakeFiles/window.dir/epidemic.cpp.o: /Users/giovanniguidocapano/Desktop/progetto/simulation/epidemic.cpp
simulation/CMakeFiles/window.dir/epidemic.cpp.o: simulation/CMakeFiles/window.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/giovanniguidocapano/Desktop/progetto/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object simulation/CMakeFiles/window.dir/epidemic.cpp.o"
	cd /Users/giovanniguidocapano/Desktop/progetto/build/simulation && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT simulation/CMakeFiles/window.dir/epidemic.cpp.o -MF CMakeFiles/window.dir/epidemic.cpp.o.d -o CMakeFiles/window.dir/epidemic.cpp.o -c /Users/giovanniguidocapano/Desktop/progetto/simulation/epidemic.cpp

simulation/CMakeFiles/window.dir/epidemic.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/window.dir/epidemic.cpp.i"
	cd /Users/giovanniguidocapano/Desktop/progetto/build/simulation && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/giovanniguidocapano/Desktop/progetto/simulation/epidemic.cpp > CMakeFiles/window.dir/epidemic.cpp.i

simulation/CMakeFiles/window.dir/epidemic.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/window.dir/epidemic.cpp.s"
	cd /Users/giovanniguidocapano/Desktop/progetto/build/simulation && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/giovanniguidocapano/Desktop/progetto/simulation/epidemic.cpp -o CMakeFiles/window.dir/epidemic.cpp.s

# Object files for target window
window_OBJECTS = \
"CMakeFiles/window.dir/board.cpp.o" \
"CMakeFiles/window.dir/epidemic.cpp.o"

# External object files for target window
window_EXTERNAL_OBJECTS =

simulation/libwindow.a: simulation/CMakeFiles/window.dir/board.cpp.o
simulation/libwindow.a: simulation/CMakeFiles/window.dir/epidemic.cpp.o
simulation/libwindow.a: simulation/CMakeFiles/window.dir/build.make
simulation/libwindow.a: simulation/CMakeFiles/window.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/giovanniguidocapano/Desktop/progetto/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libwindow.a"
	cd /Users/giovanniguidocapano/Desktop/progetto/build/simulation && $(CMAKE_COMMAND) -P CMakeFiles/window.dir/cmake_clean_target.cmake
	cd /Users/giovanniguidocapano/Desktop/progetto/build/simulation && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/window.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
simulation/CMakeFiles/window.dir/build: simulation/libwindow.a
.PHONY : simulation/CMakeFiles/window.dir/build

simulation/CMakeFiles/window.dir/clean:
	cd /Users/giovanniguidocapano/Desktop/progetto/build/simulation && $(CMAKE_COMMAND) -P CMakeFiles/window.dir/cmake_clean.cmake
.PHONY : simulation/CMakeFiles/window.dir/clean

simulation/CMakeFiles/window.dir/depend:
	cd /Users/giovanniguidocapano/Desktop/progetto/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/giovanniguidocapano/Desktop/progetto /Users/giovanniguidocapano/Desktop/progetto/simulation /Users/giovanniguidocapano/Desktop/progetto/build /Users/giovanniguidocapano/Desktop/progetto/build/simulation /Users/giovanniguidocapano/Desktop/progetto/build/simulation/CMakeFiles/window.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : simulation/CMakeFiles/window.dir/depend

