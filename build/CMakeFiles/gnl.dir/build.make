# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /Users/jiyeolee/.brew/Cellar/cmake/3.25.2/bin/cmake

# The command to remove a file.
RM = /Users/jiyeolee/.brew/Cellar/cmake/3.25.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/jiyeolee/WORKSPACE/get_next_line

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jiyeolee/WORKSPACE/build

# Include any dependencies generated for this target.
include CMakeFiles/gnl.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/gnl.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/gnl.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gnl.dir/flags.make

CMakeFiles/gnl.dir/get_next_line.c.o: CMakeFiles/gnl.dir/flags.make
CMakeFiles/gnl.dir/get_next_line.c.o: /Users/jiyeolee/WORKSPACE/get_next_line/get_next_line.c
CMakeFiles/gnl.dir/get_next_line.c.o: CMakeFiles/gnl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jiyeolee/WORKSPACE/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/gnl.dir/get_next_line.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/gnl.dir/get_next_line.c.o -MF CMakeFiles/gnl.dir/get_next_line.c.o.d -o CMakeFiles/gnl.dir/get_next_line.c.o -c /Users/jiyeolee/WORKSPACE/get_next_line/get_next_line.c

CMakeFiles/gnl.dir/get_next_line.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gnl.dir/get_next_line.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jiyeolee/WORKSPACE/get_next_line/get_next_line.c > CMakeFiles/gnl.dir/get_next_line.c.i

CMakeFiles/gnl.dir/get_next_line.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gnl.dir/get_next_line.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jiyeolee/WORKSPACE/get_next_line/get_next_line.c -o CMakeFiles/gnl.dir/get_next_line.c.s

CMakeFiles/gnl.dir/get_next_line_bonus.c.o: CMakeFiles/gnl.dir/flags.make
CMakeFiles/gnl.dir/get_next_line_bonus.c.o: /Users/jiyeolee/WORKSPACE/get_next_line/get_next_line_bonus.c
CMakeFiles/gnl.dir/get_next_line_bonus.c.o: CMakeFiles/gnl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jiyeolee/WORKSPACE/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/gnl.dir/get_next_line_bonus.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/gnl.dir/get_next_line_bonus.c.o -MF CMakeFiles/gnl.dir/get_next_line_bonus.c.o.d -o CMakeFiles/gnl.dir/get_next_line_bonus.c.o -c /Users/jiyeolee/WORKSPACE/get_next_line/get_next_line_bonus.c

CMakeFiles/gnl.dir/get_next_line_bonus.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gnl.dir/get_next_line_bonus.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jiyeolee/WORKSPACE/get_next_line/get_next_line_bonus.c > CMakeFiles/gnl.dir/get_next_line_bonus.c.i

CMakeFiles/gnl.dir/get_next_line_bonus.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gnl.dir/get_next_line_bonus.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jiyeolee/WORKSPACE/get_next_line/get_next_line_bonus.c -o CMakeFiles/gnl.dir/get_next_line_bonus.c.s

CMakeFiles/gnl.dir/get_next_line_utils.c.o: CMakeFiles/gnl.dir/flags.make
CMakeFiles/gnl.dir/get_next_line_utils.c.o: /Users/jiyeolee/WORKSPACE/get_next_line/get_next_line_utils.c
CMakeFiles/gnl.dir/get_next_line_utils.c.o: CMakeFiles/gnl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jiyeolee/WORKSPACE/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/gnl.dir/get_next_line_utils.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/gnl.dir/get_next_line_utils.c.o -MF CMakeFiles/gnl.dir/get_next_line_utils.c.o.d -o CMakeFiles/gnl.dir/get_next_line_utils.c.o -c /Users/jiyeolee/WORKSPACE/get_next_line/get_next_line_utils.c

CMakeFiles/gnl.dir/get_next_line_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gnl.dir/get_next_line_utils.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jiyeolee/WORKSPACE/get_next_line/get_next_line_utils.c > CMakeFiles/gnl.dir/get_next_line_utils.c.i

CMakeFiles/gnl.dir/get_next_line_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gnl.dir/get_next_line_utils.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jiyeolee/WORKSPACE/get_next_line/get_next_line_utils.c -o CMakeFiles/gnl.dir/get_next_line_utils.c.s

CMakeFiles/gnl.dir/get_next_line_utils_bonus.c.o: CMakeFiles/gnl.dir/flags.make
CMakeFiles/gnl.dir/get_next_line_utils_bonus.c.o: /Users/jiyeolee/WORKSPACE/get_next_line/get_next_line_utils_bonus.c
CMakeFiles/gnl.dir/get_next_line_utils_bonus.c.o: CMakeFiles/gnl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jiyeolee/WORKSPACE/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/gnl.dir/get_next_line_utils_bonus.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/gnl.dir/get_next_line_utils_bonus.c.o -MF CMakeFiles/gnl.dir/get_next_line_utils_bonus.c.o.d -o CMakeFiles/gnl.dir/get_next_line_utils_bonus.c.o -c /Users/jiyeolee/WORKSPACE/get_next_line/get_next_line_utils_bonus.c

CMakeFiles/gnl.dir/get_next_line_utils_bonus.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gnl.dir/get_next_line_utils_bonus.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jiyeolee/WORKSPACE/get_next_line/get_next_line_utils_bonus.c > CMakeFiles/gnl.dir/get_next_line_utils_bonus.c.i

CMakeFiles/gnl.dir/get_next_line_utils_bonus.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gnl.dir/get_next_line_utils_bonus.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jiyeolee/WORKSPACE/get_next_line/get_next_line_utils_bonus.c -o CMakeFiles/gnl.dir/get_next_line_utils_bonus.c.s

CMakeFiles/gnl.dir/main.c.o: CMakeFiles/gnl.dir/flags.make
CMakeFiles/gnl.dir/main.c.o: /Users/jiyeolee/WORKSPACE/get_next_line/main.c
CMakeFiles/gnl.dir/main.c.o: CMakeFiles/gnl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jiyeolee/WORKSPACE/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/gnl.dir/main.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/gnl.dir/main.c.o -MF CMakeFiles/gnl.dir/main.c.o.d -o CMakeFiles/gnl.dir/main.c.o -c /Users/jiyeolee/WORKSPACE/get_next_line/main.c

CMakeFiles/gnl.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gnl.dir/main.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jiyeolee/WORKSPACE/get_next_line/main.c > CMakeFiles/gnl.dir/main.c.i

CMakeFiles/gnl.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gnl.dir/main.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jiyeolee/WORKSPACE/get_next_line/main.c -o CMakeFiles/gnl.dir/main.c.s

# Object files for target gnl
gnl_OBJECTS = \
"CMakeFiles/gnl.dir/get_next_line.c.o" \
"CMakeFiles/gnl.dir/get_next_line_bonus.c.o" \
"CMakeFiles/gnl.dir/get_next_line_utils.c.o" \
"CMakeFiles/gnl.dir/get_next_line_utils_bonus.c.o" \
"CMakeFiles/gnl.dir/main.c.o"

# External object files for target gnl
gnl_EXTERNAL_OBJECTS =

gnl: CMakeFiles/gnl.dir/get_next_line.c.o
gnl: CMakeFiles/gnl.dir/get_next_line_bonus.c.o
gnl: CMakeFiles/gnl.dir/get_next_line_utils.c.o
gnl: CMakeFiles/gnl.dir/get_next_line_utils_bonus.c.o
gnl: CMakeFiles/gnl.dir/main.c.o
gnl: CMakeFiles/gnl.dir/build.make
gnl: CMakeFiles/gnl.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jiyeolee/WORKSPACE/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable gnl"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gnl.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gnl.dir/build: gnl
.PHONY : CMakeFiles/gnl.dir/build

CMakeFiles/gnl.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gnl.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gnl.dir/clean

CMakeFiles/gnl.dir/depend:
	cd /Users/jiyeolee/WORKSPACE/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jiyeolee/WORKSPACE/get_next_line /Users/jiyeolee/WORKSPACE/get_next_line /Users/jiyeolee/WORKSPACE/build /Users/jiyeolee/WORKSPACE/build /Users/jiyeolee/WORKSPACE/build/CMakeFiles/gnl.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gnl.dir/depend

