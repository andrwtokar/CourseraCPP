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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\tokar\GitHub\CourseraCPP\Yellow_belt\Summation of matrices"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\tokar\GitHub\CourseraCPP\Yellow_belt\Summation of matrices\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Summation_of_matrices.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Summation_of_matrices.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Summation_of_matrices.dir/flags.make

CMakeFiles/Summation_of_matrices.dir/main.cpp.obj: CMakeFiles/Summation_of_matrices.dir/flags.make
CMakeFiles/Summation_of_matrices.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\tokar\GitHub\CourseraCPP\Yellow_belt\Summation of matrices\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Summation_of_matrices.dir/main.cpp.obj"
	C:\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Summation_of_matrices.dir\main.cpp.obj -c "C:\Users\tokar\GitHub\CourseraCPP\Yellow_belt\Summation of matrices\main.cpp"

CMakeFiles/Summation_of_matrices.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Summation_of_matrices.dir/main.cpp.i"
	C:\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\tokar\GitHub\CourseraCPP\Yellow_belt\Summation of matrices\main.cpp" > CMakeFiles\Summation_of_matrices.dir\main.cpp.i

CMakeFiles/Summation_of_matrices.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Summation_of_matrices.dir/main.cpp.s"
	C:\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\tokar\GitHub\CourseraCPP\Yellow_belt\Summation of matrices\main.cpp" -o CMakeFiles\Summation_of_matrices.dir\main.cpp.s

# Object files for target Summation_of_matrices
Summation_of_matrices_OBJECTS = \
"CMakeFiles/Summation_of_matrices.dir/main.cpp.obj"

# External object files for target Summation_of_matrices
Summation_of_matrices_EXTERNAL_OBJECTS =

Summation_of_matrices.exe: CMakeFiles/Summation_of_matrices.dir/main.cpp.obj
Summation_of_matrices.exe: CMakeFiles/Summation_of_matrices.dir/build.make
Summation_of_matrices.exe: CMakeFiles/Summation_of_matrices.dir/linklibs.rsp
Summation_of_matrices.exe: CMakeFiles/Summation_of_matrices.dir/objects1.rsp
Summation_of_matrices.exe: CMakeFiles/Summation_of_matrices.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\tokar\GitHub\CourseraCPP\Yellow_belt\Summation of matrices\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Summation_of_matrices.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Summation_of_matrices.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Summation_of_matrices.dir/build: Summation_of_matrices.exe

.PHONY : CMakeFiles/Summation_of_matrices.dir/build

CMakeFiles/Summation_of_matrices.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Summation_of_matrices.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Summation_of_matrices.dir/clean

CMakeFiles/Summation_of_matrices.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\tokar\GitHub\CourseraCPP\Yellow_belt\Summation of matrices" "C:\Users\tokar\GitHub\CourseraCPP\Yellow_belt\Summation of matrices" "C:\Users\tokar\GitHub\CourseraCPP\Yellow_belt\Summation of matrices\cmake-build-debug" "C:\Users\tokar\GitHub\CourseraCPP\Yellow_belt\Summation of matrices\cmake-build-debug" "C:\Users\tokar\GitHub\CourseraCPP\Yellow_belt\Summation of matrices\cmake-build-debug\CMakeFiles\Summation_of_matrices.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Summation_of_matrices.dir/depend

