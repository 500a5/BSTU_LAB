# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.1.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.1.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\500a5\CLionProjects\vych_9

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\500a5\CLionProjects\vych_9\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/vych_9.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/vych_9.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/vych_9.dir/flags.make

CMakeFiles/vych_9.dir/main.c.obj: CMakeFiles/vych_9.dir/flags.make
CMakeFiles/vych_9.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\500a5\CLionProjects\vych_9\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/vych_9.dir/main.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\vych_9.dir\main.c.obj   -c C:\Users\500a5\CLionProjects\vych_9\main.c

CMakeFiles/vych_9.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/vych_9.dir/main.c.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\500a5\CLionProjects\vych_9\main.c > CMakeFiles\vych_9.dir\main.c.i

CMakeFiles/vych_9.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/vych_9.dir/main.c.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\500a5\CLionProjects\vych_9\main.c -o CMakeFiles\vych_9.dir\main.c.s

# Object files for target vych_9
vych_9_OBJECTS = \
"CMakeFiles/vych_9.dir/main.c.obj"

# External object files for target vych_9
vych_9_EXTERNAL_OBJECTS =

vych_9.exe: CMakeFiles/vych_9.dir/main.c.obj
vych_9.exe: CMakeFiles/vych_9.dir/build.make
vych_9.exe: CMakeFiles/vych_9.dir/linklibs.rsp
vych_9.exe: CMakeFiles/vych_9.dir/objects1.rsp
vych_9.exe: CMakeFiles/vych_9.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\500a5\CLionProjects\vych_9\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable vych_9.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\vych_9.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/vych_9.dir/build: vych_9.exe

.PHONY : CMakeFiles/vych_9.dir/build

CMakeFiles/vych_9.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\vych_9.dir\cmake_clean.cmake
.PHONY : CMakeFiles/vych_9.dir/clean

CMakeFiles/vych_9.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\500a5\CLionProjects\vych_9 C:\Users\500a5\CLionProjects\vych_9 C:\Users\500a5\CLionProjects\vych_9\cmake-build-debug C:\Users\500a5\CLionProjects\vych_9\cmake-build-debug C:\Users\500a5\CLionProjects\vych_9\cmake-build-debug\CMakeFiles\vych_9.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/vych_9.dir/depend

