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
CMAKE_COMMAND = /home/adriano/Downloads/CLion-2021.1/clion-2021.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/adriano/Downloads/CLion-2021.1/clion-2021.1/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/media/adriano/DATA/Google Drive/Mestrado/UFOP/2020/PCC104/lista/semana3"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/media/adriano/DATA/Google Drive/Mestrado/UFOP/2020/PCC104/lista/semana3/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/semana3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/semana3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/semana3.dir/flags.make

CMakeFiles/semana3.dir/main.cpp.o: CMakeFiles/semana3.dir/flags.make
CMakeFiles/semana3.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/media/adriano/DATA/Google Drive/Mestrado/UFOP/2020/PCC104/lista/semana3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/semana3.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/semana3.dir/main.cpp.o -c "/media/adriano/DATA/Google Drive/Mestrado/UFOP/2020/PCC104/lista/semana3/main.cpp"

CMakeFiles/semana3.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/semana3.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/media/adriano/DATA/Google Drive/Mestrado/UFOP/2020/PCC104/lista/semana3/main.cpp" > CMakeFiles/semana3.dir/main.cpp.i

CMakeFiles/semana3.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/semana3.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/media/adriano/DATA/Google Drive/Mestrado/UFOP/2020/PCC104/lista/semana3/main.cpp" -o CMakeFiles/semana3.dir/main.cpp.s

# Object files for target semana3
semana3_OBJECTS = \
"CMakeFiles/semana3.dir/main.cpp.o"

# External object files for target semana3
semana3_EXTERNAL_OBJECTS =

semana3: CMakeFiles/semana3.dir/main.cpp.o
semana3: CMakeFiles/semana3.dir/build.make
semana3: matplotplusplus/source/matplot/libmatplot.a
semana3: matplotplusplus/source/3rd_party/libnodesoup.a
semana3: CMakeFiles/semana3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/media/adriano/DATA/Google Drive/Mestrado/UFOP/2020/PCC104/lista/semana3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable semana3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/semana3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/semana3.dir/build: semana3

.PHONY : CMakeFiles/semana3.dir/build

CMakeFiles/semana3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/semana3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/semana3.dir/clean

CMakeFiles/semana3.dir/depend:
	cd "/media/adriano/DATA/Google Drive/Mestrado/UFOP/2020/PCC104/lista/semana3/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/media/adriano/DATA/Google Drive/Mestrado/UFOP/2020/PCC104/lista/semana3" "/media/adriano/DATA/Google Drive/Mestrado/UFOP/2020/PCC104/lista/semana3" "/media/adriano/DATA/Google Drive/Mestrado/UFOP/2020/PCC104/lista/semana3/cmake-build-debug" "/media/adriano/DATA/Google Drive/Mestrado/UFOP/2020/PCC104/lista/semana3/cmake-build-debug" "/media/adriano/DATA/Google Drive/Mestrado/UFOP/2020/PCC104/lista/semana3/cmake-build-debug/CMakeFiles/semana3.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/semana3.dir/depend

