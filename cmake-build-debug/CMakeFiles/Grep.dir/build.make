# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Kingdel\CLionProjects\Grep

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Kingdel\CLionProjects\Grep\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Grep.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Grep.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Grep.dir/flags.make

CMakeFiles/Grep.dir/main.c.obj: CMakeFiles/Grep.dir/flags.make
CMakeFiles/Grep.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Kingdel\CLionProjects\Grep\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Grep.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Grep.dir\main.c.obj   -c C:\Users\Kingdel\CLionProjects\Grep\main.c

CMakeFiles/Grep.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Grep.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Kingdel\CLionProjects\Grep\main.c > CMakeFiles\Grep.dir\main.c.i

CMakeFiles/Grep.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Grep.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Kingdel\CLionProjects\Grep\main.c -o CMakeFiles\Grep.dir\main.c.s

# Object files for target Grep
Grep_OBJECTS = \
"CMakeFiles/Grep.dir/main.c.obj"

# External object files for target Grep
Grep_EXTERNAL_OBJECTS =

Grep.exe: CMakeFiles/Grep.dir/main.c.obj
Grep.exe: CMakeFiles/Grep.dir/build.make
Grep.exe: CMakeFiles/Grep.dir/linklibs.rsp
Grep.exe: CMakeFiles/Grep.dir/objects1.rsp
Grep.exe: CMakeFiles/Grep.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Kingdel\CLionProjects\Grep\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Grep.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Grep.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Grep.dir/build: Grep.exe

.PHONY : CMakeFiles/Grep.dir/build

CMakeFiles/Grep.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Grep.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Grep.dir/clean

CMakeFiles/Grep.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Kingdel\CLionProjects\Grep C:\Users\Kingdel\CLionProjects\Grep C:\Users\Kingdel\CLionProjects\Grep\cmake-build-debug C:\Users\Kingdel\CLionProjects\Grep\cmake-build-debug C:\Users\Kingdel\CLionProjects\Grep\cmake-build-debug\CMakeFiles\Grep.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Grep.dir/depend

