# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_SOURCE_DIR = /home/noerlol/C-Projects/tuiplusplus

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/noerlol/C-Projects/tuiplusplus

# Include any dependencies generated for this target.
include CMakeFiles/tuiplusplus.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/tuiplusplus.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/tuiplusplus.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tuiplusplus.dir/flags.make

CMakeFiles/tuiplusplus.dir/src/cmake.cpp.o: CMakeFiles/tuiplusplus.dir/flags.make
CMakeFiles/tuiplusplus.dir/src/cmake.cpp.o: src/cmake.cpp
CMakeFiles/tuiplusplus.dir/src/cmake.cpp.o: CMakeFiles/tuiplusplus.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/noerlol/C-Projects/tuiplusplus/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tuiplusplus.dir/src/cmake.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tuiplusplus.dir/src/cmake.cpp.o -MF CMakeFiles/tuiplusplus.dir/src/cmake.cpp.o.d -o CMakeFiles/tuiplusplus.dir/src/cmake.cpp.o -c /home/noerlol/C-Projects/tuiplusplus/src/cmake.cpp

CMakeFiles/tuiplusplus.dir/src/cmake.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tuiplusplus.dir/src/cmake.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/noerlol/C-Projects/tuiplusplus/src/cmake.cpp > CMakeFiles/tuiplusplus.dir/src/cmake.cpp.i

CMakeFiles/tuiplusplus.dir/src/cmake.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tuiplusplus.dir/src/cmake.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/noerlol/C-Projects/tuiplusplus/src/cmake.cpp -o CMakeFiles/tuiplusplus.dir/src/cmake.cpp.s

# Object files for target tuiplusplus
tuiplusplus_OBJECTS = \
"CMakeFiles/tuiplusplus.dir/src/cmake.cpp.o"

# External object files for target tuiplusplus
tuiplusplus_EXTERNAL_OBJECTS =

libtuiplusplus.a: CMakeFiles/tuiplusplus.dir/src/cmake.cpp.o
libtuiplusplus.a: CMakeFiles/tuiplusplus.dir/build.make
libtuiplusplus.a: CMakeFiles/tuiplusplus.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/noerlol/C-Projects/tuiplusplus/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libtuiplusplus.a"
	$(CMAKE_COMMAND) -P CMakeFiles/tuiplusplus.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tuiplusplus.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tuiplusplus.dir/build: libtuiplusplus.a
.PHONY : CMakeFiles/tuiplusplus.dir/build

CMakeFiles/tuiplusplus.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tuiplusplus.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tuiplusplus.dir/clean

CMakeFiles/tuiplusplus.dir/depend:
	cd /home/noerlol/C-Projects/tuiplusplus && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/noerlol/C-Projects/tuiplusplus /home/noerlol/C-Projects/tuiplusplus /home/noerlol/C-Projects/tuiplusplus /home/noerlol/C-Projects/tuiplusplus /home/noerlol/C-Projects/tuiplusplus/CMakeFiles/tuiplusplus.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/tuiplusplus.dir/depend

