# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /usr/local/cmake-3.9.2/bin/cmake

# The command to remove a file.
RM = /usr/local/cmake-3.9.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/travis/build/Alkud/OTUS_HOMEWORK_7

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/travis/build/Alkud/OTUS_HOMEWORK_7

# Include any dependencies generated for this target.
include CMakeFiles/publisher.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/publisher.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/publisher.dir/flags.make

CMakeFiles/publisher.dir/library/publisher.cpp.o: CMakeFiles/publisher.dir/flags.make
CMakeFiles/publisher.dir/library/publisher.cpp.o: library/publisher.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/travis/build/Alkud/OTUS_HOMEWORK_7/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/publisher.dir/library/publisher.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/publisher.dir/library/publisher.cpp.o -c /home/travis/build/Alkud/OTUS_HOMEWORK_7/library/publisher.cpp

CMakeFiles/publisher.dir/library/publisher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/publisher.dir/library/publisher.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/travis/build/Alkud/OTUS_HOMEWORK_7/library/publisher.cpp > CMakeFiles/publisher.dir/library/publisher.cpp.i

CMakeFiles/publisher.dir/library/publisher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/publisher.dir/library/publisher.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/travis/build/Alkud/OTUS_HOMEWORK_7/library/publisher.cpp -o CMakeFiles/publisher.dir/library/publisher.cpp.s

CMakeFiles/publisher.dir/library/publisher.cpp.o.requires:

.PHONY : CMakeFiles/publisher.dir/library/publisher.cpp.o.requires

CMakeFiles/publisher.dir/library/publisher.cpp.o.provides: CMakeFiles/publisher.dir/library/publisher.cpp.o.requires
	$(MAKE) -f CMakeFiles/publisher.dir/build.make CMakeFiles/publisher.dir/library/publisher.cpp.o.provides.build
.PHONY : CMakeFiles/publisher.dir/library/publisher.cpp.o.provides

CMakeFiles/publisher.dir/library/publisher.cpp.o.provides.build: CMakeFiles/publisher.dir/library/publisher.cpp.o


# Object files for target publisher
publisher_OBJECTS = \
"CMakeFiles/publisher.dir/library/publisher.cpp.o"

# External object files for target publisher
publisher_EXTERNAL_OBJECTS =

libpublisher.a: CMakeFiles/publisher.dir/library/publisher.cpp.o
libpublisher.a: CMakeFiles/publisher.dir/build.make
libpublisher.a: CMakeFiles/publisher.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/travis/build/Alkud/OTUS_HOMEWORK_7/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libpublisher.a"
	$(CMAKE_COMMAND) -P CMakeFiles/publisher.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/publisher.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/publisher.dir/build: libpublisher.a

.PHONY : CMakeFiles/publisher.dir/build

CMakeFiles/publisher.dir/requires: CMakeFiles/publisher.dir/library/publisher.cpp.o.requires

.PHONY : CMakeFiles/publisher.dir/requires

CMakeFiles/publisher.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/publisher.dir/cmake_clean.cmake
.PHONY : CMakeFiles/publisher.dir/clean

CMakeFiles/publisher.dir/depend:
	cd /home/travis/build/Alkud/OTUS_HOMEWORK_7 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/travis/build/Alkud/OTUS_HOMEWORK_7 /home/travis/build/Alkud/OTUS_HOMEWORK_7 /home/travis/build/Alkud/OTUS_HOMEWORK_7 /home/travis/build/Alkud/OTUS_HOMEWORK_7 /home/travis/build/Alkud/OTUS_HOMEWORK_7/CMakeFiles/publisher.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/publisher.dir/depend

