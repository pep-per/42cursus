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
CMAKE_SOURCE_DIR = /Users/jiyeolee/WORKSPACE/push_swap

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jiyeolee/WORKSPACE/push_swap/build

# Include any dependencies generated for this target.
include CMakeFiles/push_swap.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/push_swap.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/push_swap.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/push_swap.dir/flags.make

CMakeFiles/push_swap.dir/Initialization.c.o: CMakeFiles/push_swap.dir/flags.make
CMakeFiles/push_swap.dir/Initialization.c.o: /Users/jiyeolee/WORKSPACE/push_swap/Initialization.c
CMakeFiles/push_swap.dir/Initialization.c.o: CMakeFiles/push_swap.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jiyeolee/WORKSPACE/push_swap/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/push_swap.dir/Initialization.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/push_swap.dir/Initialization.c.o -MF CMakeFiles/push_swap.dir/Initialization.c.o.d -o CMakeFiles/push_swap.dir/Initialization.c.o -c /Users/jiyeolee/WORKSPACE/push_swap/Initialization.c

CMakeFiles/push_swap.dir/Initialization.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/push_swap.dir/Initialization.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jiyeolee/WORKSPACE/push_swap/Initialization.c > CMakeFiles/push_swap.dir/Initialization.c.i

CMakeFiles/push_swap.dir/Initialization.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/push_swap.dir/Initialization.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jiyeolee/WORKSPACE/push_swap/Initialization.c -o CMakeFiles/push_swap.dir/Initialization.c.s

CMakeFiles/push_swap.dir/error_handling.c.o: CMakeFiles/push_swap.dir/flags.make
CMakeFiles/push_swap.dir/error_handling.c.o: /Users/jiyeolee/WORKSPACE/push_swap/error_handling.c
CMakeFiles/push_swap.dir/error_handling.c.o: CMakeFiles/push_swap.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jiyeolee/WORKSPACE/push_swap/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/push_swap.dir/error_handling.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/push_swap.dir/error_handling.c.o -MF CMakeFiles/push_swap.dir/error_handling.c.o.d -o CMakeFiles/push_swap.dir/error_handling.c.o -c /Users/jiyeolee/WORKSPACE/push_swap/error_handling.c

CMakeFiles/push_swap.dir/error_handling.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/push_swap.dir/error_handling.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jiyeolee/WORKSPACE/push_swap/error_handling.c > CMakeFiles/push_swap.dir/error_handling.c.i

CMakeFiles/push_swap.dir/error_handling.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/push_swap.dir/error_handling.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jiyeolee/WORKSPACE/push_swap/error_handling.c -o CMakeFiles/push_swap.dir/error_handling.c.s

CMakeFiles/push_swap.dir/greedy_a.c.o: CMakeFiles/push_swap.dir/flags.make
CMakeFiles/push_swap.dir/greedy_a.c.o: /Users/jiyeolee/WORKSPACE/push_swap/greedy_a.c
CMakeFiles/push_swap.dir/greedy_a.c.o: CMakeFiles/push_swap.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jiyeolee/WORKSPACE/push_swap/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/push_swap.dir/greedy_a.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/push_swap.dir/greedy_a.c.o -MF CMakeFiles/push_swap.dir/greedy_a.c.o.d -o CMakeFiles/push_swap.dir/greedy_a.c.o -c /Users/jiyeolee/WORKSPACE/push_swap/greedy_a.c

CMakeFiles/push_swap.dir/greedy_a.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/push_swap.dir/greedy_a.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jiyeolee/WORKSPACE/push_swap/greedy_a.c > CMakeFiles/push_swap.dir/greedy_a.c.i

CMakeFiles/push_swap.dir/greedy_a.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/push_swap.dir/greedy_a.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jiyeolee/WORKSPACE/push_swap/greedy_a.c -o CMakeFiles/push_swap.dir/greedy_a.c.s

CMakeFiles/push_swap.dir/greedy_b.c.o: CMakeFiles/push_swap.dir/flags.make
CMakeFiles/push_swap.dir/greedy_b.c.o: /Users/jiyeolee/WORKSPACE/push_swap/greedy_b.c
CMakeFiles/push_swap.dir/greedy_b.c.o: CMakeFiles/push_swap.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jiyeolee/WORKSPACE/push_swap/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/push_swap.dir/greedy_b.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/push_swap.dir/greedy_b.c.o -MF CMakeFiles/push_swap.dir/greedy_b.c.o.d -o CMakeFiles/push_swap.dir/greedy_b.c.o -c /Users/jiyeolee/WORKSPACE/push_swap/greedy_b.c

CMakeFiles/push_swap.dir/greedy_b.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/push_swap.dir/greedy_b.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jiyeolee/WORKSPACE/push_swap/greedy_b.c > CMakeFiles/push_swap.dir/greedy_b.c.i

CMakeFiles/push_swap.dir/greedy_b.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/push_swap.dir/greedy_b.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jiyeolee/WORKSPACE/push_swap/greedy_b.c -o CMakeFiles/push_swap.dir/greedy_b.c.s

CMakeFiles/push_swap.dir/indexing.c.o: CMakeFiles/push_swap.dir/flags.make
CMakeFiles/push_swap.dir/indexing.c.o: /Users/jiyeolee/WORKSPACE/push_swap/indexing.c
CMakeFiles/push_swap.dir/indexing.c.o: CMakeFiles/push_swap.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jiyeolee/WORKSPACE/push_swap/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/push_swap.dir/indexing.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/push_swap.dir/indexing.c.o -MF CMakeFiles/push_swap.dir/indexing.c.o.d -o CMakeFiles/push_swap.dir/indexing.c.o -c /Users/jiyeolee/WORKSPACE/push_swap/indexing.c

CMakeFiles/push_swap.dir/indexing.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/push_swap.dir/indexing.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jiyeolee/WORKSPACE/push_swap/indexing.c > CMakeFiles/push_swap.dir/indexing.c.i

CMakeFiles/push_swap.dir/indexing.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/push_swap.dir/indexing.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jiyeolee/WORKSPACE/push_swap/indexing.c -o CMakeFiles/push_swap.dir/indexing.c.s

CMakeFiles/push_swap.dir/main.c.o: CMakeFiles/push_swap.dir/flags.make
CMakeFiles/push_swap.dir/main.c.o: /Users/jiyeolee/WORKSPACE/push_swap/main.c
CMakeFiles/push_swap.dir/main.c.o: CMakeFiles/push_swap.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jiyeolee/WORKSPACE/push_swap/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/push_swap.dir/main.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/push_swap.dir/main.c.o -MF CMakeFiles/push_swap.dir/main.c.o.d -o CMakeFiles/push_swap.dir/main.c.o -c /Users/jiyeolee/WORKSPACE/push_swap/main.c

CMakeFiles/push_swap.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/push_swap.dir/main.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jiyeolee/WORKSPACE/push_swap/main.c > CMakeFiles/push_swap.dir/main.c.i

CMakeFiles/push_swap.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/push_swap.dir/main.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jiyeolee/WORKSPACE/push_swap/main.c -o CMakeFiles/push_swap.dir/main.c.s

CMakeFiles/push_swap.dir/operation.c.o: CMakeFiles/push_swap.dir/flags.make
CMakeFiles/push_swap.dir/operation.c.o: /Users/jiyeolee/WORKSPACE/push_swap/operation.c
CMakeFiles/push_swap.dir/operation.c.o: CMakeFiles/push_swap.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jiyeolee/WORKSPACE/push_swap/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/push_swap.dir/operation.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/push_swap.dir/operation.c.o -MF CMakeFiles/push_swap.dir/operation.c.o.d -o CMakeFiles/push_swap.dir/operation.c.o -c /Users/jiyeolee/WORKSPACE/push_swap/operation.c

CMakeFiles/push_swap.dir/operation.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/push_swap.dir/operation.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jiyeolee/WORKSPACE/push_swap/operation.c > CMakeFiles/push_swap.dir/operation.c.i

CMakeFiles/push_swap.dir/operation.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/push_swap.dir/operation.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jiyeolee/WORKSPACE/push_swap/operation.c -o CMakeFiles/push_swap.dir/operation.c.s

CMakeFiles/push_swap.dir/parsing.c.o: CMakeFiles/push_swap.dir/flags.make
CMakeFiles/push_swap.dir/parsing.c.o: /Users/jiyeolee/WORKSPACE/push_swap/parsing.c
CMakeFiles/push_swap.dir/parsing.c.o: CMakeFiles/push_swap.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jiyeolee/WORKSPACE/push_swap/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/push_swap.dir/parsing.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/push_swap.dir/parsing.c.o -MF CMakeFiles/push_swap.dir/parsing.c.o.d -o CMakeFiles/push_swap.dir/parsing.c.o -c /Users/jiyeolee/WORKSPACE/push_swap/parsing.c

CMakeFiles/push_swap.dir/parsing.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/push_swap.dir/parsing.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jiyeolee/WORKSPACE/push_swap/parsing.c > CMakeFiles/push_swap.dir/parsing.c.i

CMakeFiles/push_swap.dir/parsing.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/push_swap.dir/parsing.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jiyeolee/WORKSPACE/push_swap/parsing.c -o CMakeFiles/push_swap.dir/parsing.c.s

CMakeFiles/push_swap.dir/preprocessing.c.o: CMakeFiles/push_swap.dir/flags.make
CMakeFiles/push_swap.dir/preprocessing.c.o: /Users/jiyeolee/WORKSPACE/push_swap/preprocessing.c
CMakeFiles/push_swap.dir/preprocessing.c.o: CMakeFiles/push_swap.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jiyeolee/WORKSPACE/push_swap/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/push_swap.dir/preprocessing.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/push_swap.dir/preprocessing.c.o -MF CMakeFiles/push_swap.dir/preprocessing.c.o.d -o CMakeFiles/push_swap.dir/preprocessing.c.o -c /Users/jiyeolee/WORKSPACE/push_swap/preprocessing.c

CMakeFiles/push_swap.dir/preprocessing.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/push_swap.dir/preprocessing.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jiyeolee/WORKSPACE/push_swap/preprocessing.c > CMakeFiles/push_swap.dir/preprocessing.c.i

CMakeFiles/push_swap.dir/preprocessing.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/push_swap.dir/preprocessing.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jiyeolee/WORKSPACE/push_swap/preprocessing.c -o CMakeFiles/push_swap.dir/preprocessing.c.s

CMakeFiles/push_swap.dir/printing.c.o: CMakeFiles/push_swap.dir/flags.make
CMakeFiles/push_swap.dir/printing.c.o: /Users/jiyeolee/WORKSPACE/push_swap/printing.c
CMakeFiles/push_swap.dir/printing.c.o: CMakeFiles/push_swap.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jiyeolee/WORKSPACE/push_swap/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/push_swap.dir/printing.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/push_swap.dir/printing.c.o -MF CMakeFiles/push_swap.dir/printing.c.o.d -o CMakeFiles/push_swap.dir/printing.c.o -c /Users/jiyeolee/WORKSPACE/push_swap/printing.c

CMakeFiles/push_swap.dir/printing.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/push_swap.dir/printing.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jiyeolee/WORKSPACE/push_swap/printing.c > CMakeFiles/push_swap.dir/printing.c.i

CMakeFiles/push_swap.dir/printing.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/push_swap.dir/printing.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jiyeolee/WORKSPACE/push_swap/printing.c -o CMakeFiles/push_swap.dir/printing.c.s

CMakeFiles/push_swap.dir/range.c.o: CMakeFiles/push_swap.dir/flags.make
CMakeFiles/push_swap.dir/range.c.o: /Users/jiyeolee/WORKSPACE/push_swap/range.c
CMakeFiles/push_swap.dir/range.c.o: CMakeFiles/push_swap.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jiyeolee/WORKSPACE/push_swap/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/push_swap.dir/range.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/push_swap.dir/range.c.o -MF CMakeFiles/push_swap.dir/range.c.o.d -o CMakeFiles/push_swap.dir/range.c.o -c /Users/jiyeolee/WORKSPACE/push_swap/range.c

CMakeFiles/push_swap.dir/range.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/push_swap.dir/range.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jiyeolee/WORKSPACE/push_swap/range.c > CMakeFiles/push_swap.dir/range.c.i

CMakeFiles/push_swap.dir/range.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/push_swap.dir/range.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jiyeolee/WORKSPACE/push_swap/range.c -o CMakeFiles/push_swap.dir/range.c.s

CMakeFiles/push_swap.dir/searching.c.o: CMakeFiles/push_swap.dir/flags.make
CMakeFiles/push_swap.dir/searching.c.o: /Users/jiyeolee/WORKSPACE/push_swap/searching.c
CMakeFiles/push_swap.dir/searching.c.o: CMakeFiles/push_swap.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jiyeolee/WORKSPACE/push_swap/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object CMakeFiles/push_swap.dir/searching.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/push_swap.dir/searching.c.o -MF CMakeFiles/push_swap.dir/searching.c.o.d -o CMakeFiles/push_swap.dir/searching.c.o -c /Users/jiyeolee/WORKSPACE/push_swap/searching.c

CMakeFiles/push_swap.dir/searching.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/push_swap.dir/searching.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jiyeolee/WORKSPACE/push_swap/searching.c > CMakeFiles/push_swap.dir/searching.c.i

CMakeFiles/push_swap.dir/searching.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/push_swap.dir/searching.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jiyeolee/WORKSPACE/push_swap/searching.c -o CMakeFiles/push_swap.dir/searching.c.s

CMakeFiles/push_swap.dir/sorting.c.o: CMakeFiles/push_swap.dir/flags.make
CMakeFiles/push_swap.dir/sorting.c.o: /Users/jiyeolee/WORKSPACE/push_swap/sorting.c
CMakeFiles/push_swap.dir/sorting.c.o: CMakeFiles/push_swap.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jiyeolee/WORKSPACE/push_swap/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object CMakeFiles/push_swap.dir/sorting.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/push_swap.dir/sorting.c.o -MF CMakeFiles/push_swap.dir/sorting.c.o.d -o CMakeFiles/push_swap.dir/sorting.c.o -c /Users/jiyeolee/WORKSPACE/push_swap/sorting.c

CMakeFiles/push_swap.dir/sorting.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/push_swap.dir/sorting.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jiyeolee/WORKSPACE/push_swap/sorting.c > CMakeFiles/push_swap.dir/sorting.c.i

CMakeFiles/push_swap.dir/sorting.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/push_swap.dir/sorting.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jiyeolee/WORKSPACE/push_swap/sorting.c -o CMakeFiles/push_swap.dir/sorting.c.s

CMakeFiles/push_swap.dir/stack1.c.o: CMakeFiles/push_swap.dir/flags.make
CMakeFiles/push_swap.dir/stack1.c.o: /Users/jiyeolee/WORKSPACE/push_swap/stack1.c
CMakeFiles/push_swap.dir/stack1.c.o: CMakeFiles/push_swap.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jiyeolee/WORKSPACE/push_swap/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building C object CMakeFiles/push_swap.dir/stack1.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/push_swap.dir/stack1.c.o -MF CMakeFiles/push_swap.dir/stack1.c.o.d -o CMakeFiles/push_swap.dir/stack1.c.o -c /Users/jiyeolee/WORKSPACE/push_swap/stack1.c

CMakeFiles/push_swap.dir/stack1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/push_swap.dir/stack1.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jiyeolee/WORKSPACE/push_swap/stack1.c > CMakeFiles/push_swap.dir/stack1.c.i

CMakeFiles/push_swap.dir/stack1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/push_swap.dir/stack1.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jiyeolee/WORKSPACE/push_swap/stack1.c -o CMakeFiles/push_swap.dir/stack1.c.s

CMakeFiles/push_swap.dir/stack2.c.o: CMakeFiles/push_swap.dir/flags.make
CMakeFiles/push_swap.dir/stack2.c.o: /Users/jiyeolee/WORKSPACE/push_swap/stack2.c
CMakeFiles/push_swap.dir/stack2.c.o: CMakeFiles/push_swap.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jiyeolee/WORKSPACE/push_swap/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building C object CMakeFiles/push_swap.dir/stack2.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/push_swap.dir/stack2.c.o -MF CMakeFiles/push_swap.dir/stack2.c.o.d -o CMakeFiles/push_swap.dir/stack2.c.o -c /Users/jiyeolee/WORKSPACE/push_swap/stack2.c

CMakeFiles/push_swap.dir/stack2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/push_swap.dir/stack2.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jiyeolee/WORKSPACE/push_swap/stack2.c > CMakeFiles/push_swap.dir/stack2.c.i

CMakeFiles/push_swap.dir/stack2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/push_swap.dir/stack2.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jiyeolee/WORKSPACE/push_swap/stack2.c -o CMakeFiles/push_swap.dir/stack2.c.s

# Object files for target push_swap
push_swap_OBJECTS = \
"CMakeFiles/push_swap.dir/Initialization.c.o" \
"CMakeFiles/push_swap.dir/error_handling.c.o" \
"CMakeFiles/push_swap.dir/greedy_a.c.o" \
"CMakeFiles/push_swap.dir/greedy_b.c.o" \
"CMakeFiles/push_swap.dir/indexing.c.o" \
"CMakeFiles/push_swap.dir/main.c.o" \
"CMakeFiles/push_swap.dir/operation.c.o" \
"CMakeFiles/push_swap.dir/parsing.c.o" \
"CMakeFiles/push_swap.dir/preprocessing.c.o" \
"CMakeFiles/push_swap.dir/printing.c.o" \
"CMakeFiles/push_swap.dir/range.c.o" \
"CMakeFiles/push_swap.dir/searching.c.o" \
"CMakeFiles/push_swap.dir/sorting.c.o" \
"CMakeFiles/push_swap.dir/stack1.c.o" \
"CMakeFiles/push_swap.dir/stack2.c.o"

# External object files for target push_swap
push_swap_EXTERNAL_OBJECTS =

push_swap: CMakeFiles/push_swap.dir/Initialization.c.o
push_swap: CMakeFiles/push_swap.dir/error_handling.c.o
push_swap: CMakeFiles/push_swap.dir/greedy_a.c.o
push_swap: CMakeFiles/push_swap.dir/greedy_b.c.o
push_swap: CMakeFiles/push_swap.dir/indexing.c.o
push_swap: CMakeFiles/push_swap.dir/main.c.o
push_swap: CMakeFiles/push_swap.dir/operation.c.o
push_swap: CMakeFiles/push_swap.dir/parsing.c.o
push_swap: CMakeFiles/push_swap.dir/preprocessing.c.o
push_swap: CMakeFiles/push_swap.dir/printing.c.o
push_swap: CMakeFiles/push_swap.dir/range.c.o
push_swap: CMakeFiles/push_swap.dir/searching.c.o
push_swap: CMakeFiles/push_swap.dir/sorting.c.o
push_swap: CMakeFiles/push_swap.dir/stack1.c.o
push_swap: CMakeFiles/push_swap.dir/stack2.c.o
push_swap: CMakeFiles/push_swap.dir/build.make
push_swap: /Users/jiyeolee/WORKSPACE/push_swap/Libft/libft.a
push_swap: CMakeFiles/push_swap.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jiyeolee/WORKSPACE/push_swap/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Linking C executable push_swap"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/push_swap.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/push_swap.dir/build: push_swap
.PHONY : CMakeFiles/push_swap.dir/build

CMakeFiles/push_swap.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/push_swap.dir/cmake_clean.cmake
.PHONY : CMakeFiles/push_swap.dir/clean

CMakeFiles/push_swap.dir/depend:
	cd /Users/jiyeolee/WORKSPACE/push_swap/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jiyeolee/WORKSPACE/push_swap /Users/jiyeolee/WORKSPACE/push_swap /Users/jiyeolee/WORKSPACE/push_swap/build /Users/jiyeolee/WORKSPACE/push_swap/build /Users/jiyeolee/WORKSPACE/push_swap/build/CMakeFiles/push_swap.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/push_swap.dir/depend
