# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nelarus-pc/Documents/compiladores/trabalho_semestre/Etapa3/etapa3_prj

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nelarus-pc/Documents/compiladores/trabalho_semestre/Etapa3

# Include any dependencies generated for this target.
include CMakeFiles/etapa3_prj.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/etapa3_prj.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/etapa3_prj.dir/flags.make

CMakeFiles/etapa3_prj.dir/main.c.o: CMakeFiles/etapa3_prj.dir/flags.make
CMakeFiles/etapa3_prj.dir/main.c.o: etapa3_prj/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nelarus-pc/Documents/compiladores/trabalho_semestre/Etapa3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/etapa3_prj.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/etapa3_prj.dir/main.c.o   -c /home/nelarus-pc/Documents/compiladores/trabalho_semestre/Etapa3/etapa3_prj/main.c

CMakeFiles/etapa3_prj.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/etapa3_prj.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nelarus-pc/Documents/compiladores/trabalho_semestre/Etapa3/etapa3_prj/main.c > CMakeFiles/etapa3_prj.dir/main.c.i

CMakeFiles/etapa3_prj.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/etapa3_prj.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nelarus-pc/Documents/compiladores/trabalho_semestre/Etapa3/etapa3_prj/main.c -o CMakeFiles/etapa3_prj.dir/main.c.s

# Object files for target etapa3_prj
etapa3_prj_OBJECTS = \
"CMakeFiles/etapa3_prj.dir/main.c.o"

# External object files for target etapa3_prj
etapa3_prj_EXTERNAL_OBJECTS =

etapa3_prj: CMakeFiles/etapa3_prj.dir/main.c.o
etapa3_prj: CMakeFiles/etapa3_prj.dir/build.make
etapa3_prj: CMakeFiles/etapa3_prj.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nelarus-pc/Documents/compiladores/trabalho_semestre/Etapa3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable etapa3_prj"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/etapa3_prj.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/etapa3_prj.dir/build: etapa3_prj

.PHONY : CMakeFiles/etapa3_prj.dir/build

CMakeFiles/etapa3_prj.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/etapa3_prj.dir/cmake_clean.cmake
.PHONY : CMakeFiles/etapa3_prj.dir/clean

CMakeFiles/etapa3_prj.dir/depend:
	cd /home/nelarus-pc/Documents/compiladores/trabalho_semestre/Etapa3 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nelarus-pc/Documents/compiladores/trabalho_semestre/Etapa3/etapa3_prj /home/nelarus-pc/Documents/compiladores/trabalho_semestre/Etapa3/etapa3_prj /home/nelarus-pc/Documents/compiladores/trabalho_semestre/Etapa3 /home/nelarus-pc/Documents/compiladores/trabalho_semestre/Etapa3 /home/nelarus-pc/Documents/compiladores/trabalho_semestre/Etapa3/CMakeFiles/etapa3_prj.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/etapa3_prj.dir/depend

