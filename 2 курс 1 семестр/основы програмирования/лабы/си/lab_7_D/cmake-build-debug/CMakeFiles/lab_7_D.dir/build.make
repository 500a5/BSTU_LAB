# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\500a5\CLionProjects\lab_7_D

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\500a5\CLionProjects\lab_7_D\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lab_7_D.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lab_7_D.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab_7_D.dir/flags.make

CMakeFiles/lab_7_D.dir/main.c.obj: CMakeFiles/lab_7_D.dir/flags.make
CMakeFiles/lab_7_D.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\500a5\CLionProjects\lab_7_D\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/lab_7_D.dir/main.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\lab_7_D.dir\main.c.obj   -c C:\Users\500a5\CLionProjects\lab_7_D\main.c

CMakeFiles/lab_7_D.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab_7_D.dir/main.c.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\500a5\CLionProjects\lab_7_D\main.c > CMakeFiles\lab_7_D.dir\main.c.i

CMakeFiles/lab_7_D.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab_7_D.dir/main.c.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\500a5\CLionProjects\lab_7_D\main.c -o CMakeFiles\lab_7_D.dir\main.c.s

# Object files for target lab_7_D
lab_7_D_OBJECTS = \
"CMakeFiles/lab_7_D.dir/main.c.obj"

# External object files for target lab_7_D
lab_7_D_EXTERNAL_OBJECTS =

lab_7_D.exe: CMakeFiles/lab_7_D.dir/main.c.obj
lab_7_D.exe: CMakeFiles/lab_7_D.dir/build.make
lab_7_D.exe: CMakeFiles/lab_7_D.dir/linklibs.rsp
lab_7_D.exe: CMakeFiles/lab_7_D.dir/objects1.rsp
lab_7_D.exe: CMakeFiles/lab_7_D.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\500a5\CLionProjects\lab_7_D\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable lab_7_D.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\lab_7_D.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab_7_D.dir/build: lab_7_D.exe

.PHONY : CMakeFiles/lab_7_D.dir/build

CMakeFiles/lab_7_D.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\lab_7_D.dir\cmake_clean.cmake
.PHONY : CMakeFiles/lab_7_D.dir/clean

CMakeFiles/lab_7_D.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\500a5\CLionProjects\lab_7_D C:\Users\500a5\CLionProjects\lab_7_D C:\Users\500a5\CLionProjects\lab_7_D\cmake-build-debug C:\Users\500a5\CLionProjects\lab_7_D\cmake-build-debug C:\Users\500a5\CLionProjects\lab_7_D\cmake-build-debug\CMakeFiles\lab_7_D.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab_7_D.dir/depend

