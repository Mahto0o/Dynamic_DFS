# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mahtashafieesabet/Desktop/codes/CLion

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mahtashafieesabet/Desktop/codes/CLion/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CLion.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CLion.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CLion.dir/flags.make

CMakeFiles/CLion.dir/main.cpp.o: CMakeFiles/CLion.dir/flags.make
CMakeFiles/CLion.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mahtashafieesabet/Desktop/codes/CLion/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CLion.dir/main.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CLion.dir/main.cpp.o -c /Users/mahtashafieesabet/Desktop/codes/CLion/main.cpp

CMakeFiles/CLion.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CLion.dir/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mahtashafieesabet/Desktop/codes/CLion/main.cpp > CMakeFiles/CLion.dir/main.cpp.i

CMakeFiles/CLion.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CLion.dir/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mahtashafieesabet/Desktop/codes/CLion/main.cpp -o CMakeFiles/CLion.dir/main.cpp.s

CMakeFiles/CLion.dir/graph.cpp.o: CMakeFiles/CLion.dir/flags.make
CMakeFiles/CLion.dir/graph.cpp.o: ../graph.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mahtashafieesabet/Desktop/codes/CLion/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CLion.dir/graph.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CLion.dir/graph.cpp.o -c /Users/mahtashafieesabet/Desktop/codes/CLion/graph.cpp

CMakeFiles/CLion.dir/graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CLion.dir/graph.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mahtashafieesabet/Desktop/codes/CLion/graph.cpp > CMakeFiles/CLion.dir/graph.cpp.i

CMakeFiles/CLion.dir/graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CLion.dir/graph.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mahtashafieesabet/Desktop/codes/CLion/graph.cpp -o CMakeFiles/CLion.dir/graph.cpp.s

CMakeFiles/CLion.dir/node.cpp.o: CMakeFiles/CLion.dir/flags.make
CMakeFiles/CLion.dir/node.cpp.o: ../node.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mahtashafieesabet/Desktop/codes/CLion/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/CLion.dir/node.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CLion.dir/node.cpp.o -c /Users/mahtashafieesabet/Desktop/codes/CLion/node.cpp

CMakeFiles/CLion.dir/node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CLion.dir/node.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mahtashafieesabet/Desktop/codes/CLion/node.cpp > CMakeFiles/CLion.dir/node.cpp.i

CMakeFiles/CLion.dir/node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CLion.dir/node.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mahtashafieesabet/Desktop/codes/CLion/node.cpp -o CMakeFiles/CLion.dir/node.cpp.s

CMakeFiles/CLion.dir/tree.cpp.o: CMakeFiles/CLion.dir/flags.make
CMakeFiles/CLion.dir/tree.cpp.o: ../tree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mahtashafieesabet/Desktop/codes/CLion/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/CLion.dir/tree.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CLion.dir/tree.cpp.o -c /Users/mahtashafieesabet/Desktop/codes/CLion/tree.cpp

CMakeFiles/CLion.dir/tree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CLion.dir/tree.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mahtashafieesabet/Desktop/codes/CLion/tree.cpp > CMakeFiles/CLion.dir/tree.cpp.i

CMakeFiles/CLion.dir/tree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CLion.dir/tree.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mahtashafieesabet/Desktop/codes/CLion/tree.cpp -o CMakeFiles/CLion.dir/tree.cpp.s

CMakeFiles/CLion.dir/SegmentTree.cpp.o: CMakeFiles/CLion.dir/flags.make
CMakeFiles/CLion.dir/SegmentTree.cpp.o: ../SegmentTree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mahtashafieesabet/Desktop/codes/CLion/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/CLion.dir/SegmentTree.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CLion.dir/SegmentTree.cpp.o -c /Users/mahtashafieesabet/Desktop/codes/CLion/SegmentTree.cpp

CMakeFiles/CLion.dir/SegmentTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CLion.dir/SegmentTree.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mahtashafieesabet/Desktop/codes/CLion/SegmentTree.cpp > CMakeFiles/CLion.dir/SegmentTree.cpp.i

CMakeFiles/CLion.dir/SegmentTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CLion.dir/SegmentTree.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mahtashafieesabet/Desktop/codes/CLion/SegmentTree.cpp -o CMakeFiles/CLion.dir/SegmentTree.cpp.s

CMakeFiles/CLion.dir/path.cpp.o: CMakeFiles/CLion.dir/flags.make
CMakeFiles/CLion.dir/path.cpp.o: ../path.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mahtashafieesabet/Desktop/codes/CLion/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/CLion.dir/path.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CLion.dir/path.cpp.o -c /Users/mahtashafieesabet/Desktop/codes/CLion/path.cpp

CMakeFiles/CLion.dir/path.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CLion.dir/path.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mahtashafieesabet/Desktop/codes/CLion/path.cpp > CMakeFiles/CLion.dir/path.cpp.i

CMakeFiles/CLion.dir/path.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CLion.dir/path.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mahtashafieesabet/Desktop/codes/CLion/path.cpp -o CMakeFiles/CLion.dir/path.cpp.s

CMakeFiles/CLion.dir/shallowTree.cpp.o: CMakeFiles/CLion.dir/flags.make
CMakeFiles/CLion.dir/shallowTree.cpp.o: ../shallowTree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mahtashafieesabet/Desktop/codes/CLion/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/CLion.dir/shallowTree.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CLion.dir/shallowTree.cpp.o -c /Users/mahtashafieesabet/Desktop/codes/CLion/shallowTree.cpp

CMakeFiles/CLion.dir/shallowTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CLion.dir/shallowTree.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mahtashafieesabet/Desktop/codes/CLion/shallowTree.cpp > CMakeFiles/CLion.dir/shallowTree.cpp.i

CMakeFiles/CLion.dir/shallowTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CLion.dir/shallowTree.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mahtashafieesabet/Desktop/codes/CLion/shallowTree.cpp -o CMakeFiles/CLion.dir/shallowTree.cpp.s

CMakeFiles/CLion.dir/dataStructure.cpp.o: CMakeFiles/CLion.dir/flags.make
CMakeFiles/CLion.dir/dataStructure.cpp.o: ../dataStructure.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mahtashafieesabet/Desktop/codes/CLion/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/CLion.dir/dataStructure.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CLion.dir/dataStructure.cpp.o -c /Users/mahtashafieesabet/Desktop/codes/CLion/dataStructure.cpp

CMakeFiles/CLion.dir/dataStructure.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CLion.dir/dataStructure.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mahtashafieesabet/Desktop/codes/CLion/dataStructure.cpp > CMakeFiles/CLion.dir/dataStructure.cpp.i

CMakeFiles/CLion.dir/dataStructure.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CLion.dir/dataStructure.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mahtashafieesabet/Desktop/codes/CLion/dataStructure.cpp -o CMakeFiles/CLion.dir/dataStructure.cpp.s

CMakeFiles/CLion.dir/DynamicDFS.cpp.o: CMakeFiles/CLion.dir/flags.make
CMakeFiles/CLion.dir/DynamicDFS.cpp.o: ../DynamicDFS.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mahtashafieesabet/Desktop/codes/CLion/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/CLion.dir/DynamicDFS.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CLion.dir/DynamicDFS.cpp.o -c /Users/mahtashafieesabet/Desktop/codes/CLion/DynamicDFS.cpp

CMakeFiles/CLion.dir/DynamicDFS.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CLion.dir/DynamicDFS.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mahtashafieesabet/Desktop/codes/CLion/DynamicDFS.cpp > CMakeFiles/CLion.dir/DynamicDFS.cpp.i

CMakeFiles/CLion.dir/DynamicDFS.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CLion.dir/DynamicDFS.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mahtashafieesabet/Desktop/codes/CLion/DynamicDFS.cpp -o CMakeFiles/CLion.dir/DynamicDFS.cpp.s

# Object files for target CLion
CLion_OBJECTS = \
"CMakeFiles/CLion.dir/main.cpp.o" \
"CMakeFiles/CLion.dir/graph.cpp.o" \
"CMakeFiles/CLion.dir/node.cpp.o" \
"CMakeFiles/CLion.dir/tree.cpp.o" \
"CMakeFiles/CLion.dir/SegmentTree.cpp.o" \
"CMakeFiles/CLion.dir/path.cpp.o" \
"CMakeFiles/CLion.dir/shallowTree.cpp.o" \
"CMakeFiles/CLion.dir/dataStructure.cpp.o" \
"CMakeFiles/CLion.dir/DynamicDFS.cpp.o"

# External object files for target CLion
CLion_EXTERNAL_OBJECTS =

CLion: CMakeFiles/CLion.dir/main.cpp.o
CLion: CMakeFiles/CLion.dir/graph.cpp.o
CLion: CMakeFiles/CLion.dir/node.cpp.o
CLion: CMakeFiles/CLion.dir/tree.cpp.o
CLion: CMakeFiles/CLion.dir/SegmentTree.cpp.o
CLion: CMakeFiles/CLion.dir/path.cpp.o
CLion: CMakeFiles/CLion.dir/shallowTree.cpp.o
CLion: CMakeFiles/CLion.dir/dataStructure.cpp.o
CLion: CMakeFiles/CLion.dir/DynamicDFS.cpp.o
CLion: CMakeFiles/CLion.dir/build.make
CLion: CMakeFiles/CLion.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mahtashafieesabet/Desktop/codes/CLion/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable CLion"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CLion.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CLion.dir/build: CLion

.PHONY : CMakeFiles/CLion.dir/build

CMakeFiles/CLion.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CLion.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CLion.dir/clean

CMakeFiles/CLion.dir/depend:
	cd /Users/mahtashafieesabet/Desktop/codes/CLion/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mahtashafieesabet/Desktop/codes/CLion /Users/mahtashafieesabet/Desktop/codes/CLion /Users/mahtashafieesabet/Desktop/codes/CLion/cmake-build-debug /Users/mahtashafieesabet/Desktop/codes/CLion/cmake-build-debug /Users/mahtashafieesabet/Desktop/codes/CLion/cmake-build-debug/CMakeFiles/CLion.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CLion.dir/depend

