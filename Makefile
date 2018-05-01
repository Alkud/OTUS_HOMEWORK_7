# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/local/cmake-3.9.2/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/local/cmake-3.9.2/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local/fast

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/local/cmake-3.9.2/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/local/cmake-3.9.2/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components

.PHONY : list_install_components/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/local/cmake-3.9.2/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/local/cmake-3.9.2/bin/ccmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target test
test:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running tests..."
	/usr/local/cmake-3.9.2/bin/ctest --force-new-ctest-process $(ARGS)
.PHONY : test

# Special rule for the target test
test/fast: test

.PHONY : test/fast

# Special rule for the target package
package: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Run CPack packaging tool..."
	/usr/local/cmake-3.9.2/bin/cpack --config ./CPackConfig.cmake
.PHONY : package

# Special rule for the target package
package/fast: package

.PHONY : package/fast

# Special rule for the target package_source
package_source:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Run CPack packaging tool for source..."
	/usr/local/cmake-3.9.2/bin/cpack --config ./CPackSourceConfig.cmake /home/travis/build/Alkud/OTUS_HOMEWORK_7/CPackSourceConfig.cmake
.PHONY : package_source

# Special rule for the target package_source
package_source/fast: package_source

.PHONY : package_source/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/local/cmake-3.9.2/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/local/cmake-3.9.2/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/travis/build/Alkud/OTUS_HOMEWORK_7/CMakeFiles /home/travis/build/Alkud/OTUS_HOMEWORK_7/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/travis/build/Alkud/OTUS_HOMEWORK_7/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named input_reader

# Build rule for target.
input_reader: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 input_reader
.PHONY : input_reader

# fast build rule for target.
input_reader/fast:
	$(MAKE) -f CMakeFiles/input_reader.dir/build.make CMakeFiles/input_reader.dir/build
.PHONY : input_reader/fast

#=============================================================================
# Target rules for targets named input_processor

# Build rule for target.
input_processor: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 input_processor
.PHONY : input_processor

# fast build rule for target.
input_processor/fast:
	$(MAKE) -f CMakeFiles/input_processor.dir/build.make CMakeFiles/input_processor.dir/build
.PHONY : input_processor/fast

#=============================================================================
# Target rules for targets named logger

# Build rule for target.
logger: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 logger
.PHONY : logger

# fast build rule for target.
logger/fast:
	$(MAKE) -f CMakeFiles/logger.dir/build.make CMakeFiles/logger.dir/build
.PHONY : logger/fast

#=============================================================================
# Target rules for targets named command_processor

# Build rule for target.
command_processor: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 command_processor
.PHONY : command_processor

# fast build rule for target.
command_processor/fast:
	$(MAKE) -f CMakeFiles/command_processor.dir/build.make CMakeFiles/command_processor.dir/build
.PHONY : command_processor/fast

#=============================================================================
# Target rules for targets named bulk

# Build rule for target.
bulk: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 bulk
.PHONY : bulk

# fast build rule for target.
bulk/fast:
	$(MAKE) -f CMakeFiles/bulk.dir/build.make CMakeFiles/bulk.dir/build
.PHONY : bulk/fast

#=============================================================================
# Target rules for targets named publisher

# Build rule for target.
publisher: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 publisher
.PHONY : publisher

# fast build rule for target.
publisher/fast:
	$(MAKE) -f CMakeFiles/publisher.dir/build.make CMakeFiles/publisher.dir/build
.PHONY : publisher/fast

#=============================================================================
# Target rules for targets named otus_hw_7_test

# Build rule for target.
otus_hw_7_test: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 otus_hw_7_test
.PHONY : otus_hw_7_test

# fast build rule for target.
otus_hw_7_test/fast:
	$(MAKE) -f CMakeFiles/otus_hw_7_test.dir/build.make CMakeFiles/otus_hw_7_test.dir/build
.PHONY : otus_hw_7_test/fast

bulk.o: bulk.cpp.o

.PHONY : bulk.o

# target to build an object file
bulk.cpp.o:
	$(MAKE) -f CMakeFiles/bulk.dir/build.make CMakeFiles/bulk.dir/bulk.cpp.o
.PHONY : bulk.cpp.o

bulk.i: bulk.cpp.i

.PHONY : bulk.i

# target to preprocess a source file
bulk.cpp.i:
	$(MAKE) -f CMakeFiles/bulk.dir/build.make CMakeFiles/bulk.dir/bulk.cpp.i
.PHONY : bulk.cpp.i

bulk.s: bulk.cpp.s

.PHONY : bulk.s

# target to generate assembly for a file
bulk.cpp.s:
	$(MAKE) -f CMakeFiles/bulk.dir/build.make CMakeFiles/bulk.dir/bulk.cpp.s
.PHONY : bulk.cpp.s

library/command_processor.o: library/command_processor.cpp.o

.PHONY : library/command_processor.o

# target to build an object file
library/command_processor.cpp.o:
	$(MAKE) -f CMakeFiles/command_processor.dir/build.make CMakeFiles/command_processor.dir/library/command_processor.cpp.o
.PHONY : library/command_processor.cpp.o

library/command_processor.i: library/command_processor.cpp.i

.PHONY : library/command_processor.i

# target to preprocess a source file
library/command_processor.cpp.i:
	$(MAKE) -f CMakeFiles/command_processor.dir/build.make CMakeFiles/command_processor.dir/library/command_processor.cpp.i
.PHONY : library/command_processor.cpp.i

library/command_processor.s: library/command_processor.cpp.s

.PHONY : library/command_processor.s

# target to generate assembly for a file
library/command_processor.cpp.s:
	$(MAKE) -f CMakeFiles/command_processor.dir/build.make CMakeFiles/command_processor.dir/library/command_processor.cpp.s
.PHONY : library/command_processor.cpp.s

library/input_processor.o: library/input_processor.cpp.o

.PHONY : library/input_processor.o

# target to build an object file
library/input_processor.cpp.o:
	$(MAKE) -f CMakeFiles/input_processor.dir/build.make CMakeFiles/input_processor.dir/library/input_processor.cpp.o
.PHONY : library/input_processor.cpp.o

library/input_processor.i: library/input_processor.cpp.i

.PHONY : library/input_processor.i

# target to preprocess a source file
library/input_processor.cpp.i:
	$(MAKE) -f CMakeFiles/input_processor.dir/build.make CMakeFiles/input_processor.dir/library/input_processor.cpp.i
.PHONY : library/input_processor.cpp.i

library/input_processor.s: library/input_processor.cpp.s

.PHONY : library/input_processor.s

# target to generate assembly for a file
library/input_processor.cpp.s:
	$(MAKE) -f CMakeFiles/input_processor.dir/build.make CMakeFiles/input_processor.dir/library/input_processor.cpp.s
.PHONY : library/input_processor.cpp.s

library/input_reader.o: library/input_reader.cpp.o

.PHONY : library/input_reader.o

# target to build an object file
library/input_reader.cpp.o:
	$(MAKE) -f CMakeFiles/input_reader.dir/build.make CMakeFiles/input_reader.dir/library/input_reader.cpp.o
.PHONY : library/input_reader.cpp.o

library/input_reader.i: library/input_reader.cpp.i

.PHONY : library/input_reader.i

# target to preprocess a source file
library/input_reader.cpp.i:
	$(MAKE) -f CMakeFiles/input_reader.dir/build.make CMakeFiles/input_reader.dir/library/input_reader.cpp.i
.PHONY : library/input_reader.cpp.i

library/input_reader.s: library/input_reader.cpp.s

.PHONY : library/input_reader.s

# target to generate assembly for a file
library/input_reader.cpp.s:
	$(MAKE) -f CMakeFiles/input_reader.dir/build.make CMakeFiles/input_reader.dir/library/input_reader.cpp.s
.PHONY : library/input_reader.cpp.s

library/logger.o: library/logger.cpp.o

.PHONY : library/logger.o

# target to build an object file
library/logger.cpp.o:
	$(MAKE) -f CMakeFiles/logger.dir/build.make CMakeFiles/logger.dir/library/logger.cpp.o
.PHONY : library/logger.cpp.o

library/logger.i: library/logger.cpp.i

.PHONY : library/logger.i

# target to preprocess a source file
library/logger.cpp.i:
	$(MAKE) -f CMakeFiles/logger.dir/build.make CMakeFiles/logger.dir/library/logger.cpp.i
.PHONY : library/logger.cpp.i

library/logger.s: library/logger.cpp.s

.PHONY : library/logger.s

# target to generate assembly for a file
library/logger.cpp.s:
	$(MAKE) -f CMakeFiles/logger.dir/build.make CMakeFiles/logger.dir/library/logger.cpp.s
.PHONY : library/logger.cpp.s

library/publisher.o: library/publisher.cpp.o

.PHONY : library/publisher.o

# target to build an object file
library/publisher.cpp.o:
	$(MAKE) -f CMakeFiles/publisher.dir/build.make CMakeFiles/publisher.dir/library/publisher.cpp.o
.PHONY : library/publisher.cpp.o

library/publisher.i: library/publisher.cpp.i

.PHONY : library/publisher.i

# target to preprocess a source file
library/publisher.cpp.i:
	$(MAKE) -f CMakeFiles/publisher.dir/build.make CMakeFiles/publisher.dir/library/publisher.cpp.i
.PHONY : library/publisher.cpp.i

library/publisher.s: library/publisher.cpp.s

.PHONY : library/publisher.s

# target to generate assembly for a file
library/publisher.cpp.s:
	$(MAKE) -f CMakeFiles/publisher.dir/build.make CMakeFiles/publisher.dir/library/publisher.cpp.s
.PHONY : library/publisher.cpp.s

otus_hw_7_test.o: otus_hw_7_test.cpp.o

.PHONY : otus_hw_7_test.o

# target to build an object file
otus_hw_7_test.cpp.o:
	$(MAKE) -f CMakeFiles/otus_hw_7_test.dir/build.make CMakeFiles/otus_hw_7_test.dir/otus_hw_7_test.cpp.o
.PHONY : otus_hw_7_test.cpp.o

otus_hw_7_test.i: otus_hw_7_test.cpp.i

.PHONY : otus_hw_7_test.i

# target to preprocess a source file
otus_hw_7_test.cpp.i:
	$(MAKE) -f CMakeFiles/otus_hw_7_test.dir/build.make CMakeFiles/otus_hw_7_test.dir/otus_hw_7_test.cpp.i
.PHONY : otus_hw_7_test.cpp.i

otus_hw_7_test.s: otus_hw_7_test.cpp.s

.PHONY : otus_hw_7_test.s

# target to generate assembly for a file
otus_hw_7_test.cpp.s:
	$(MAKE) -f CMakeFiles/otus_hw_7_test.dir/build.make CMakeFiles/otus_hw_7_test.dir/otus_hw_7_test.cpp.s
.PHONY : otus_hw_7_test.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... install/local"
	@echo "... install/strip"
	@echo "... list_install_components"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... test"
	@echo "... package"
	@echo "... input_reader"
	@echo "... input_processor"
	@echo "... package_source"
	@echo "... logger"
	@echo "... install"
	@echo "... command_processor"
	@echo "... bulk"
	@echo "... publisher"
	@echo "... otus_hw_7_test"
	@echo "... bulk.o"
	@echo "... bulk.i"
	@echo "... bulk.s"
	@echo "... library/command_processor.o"
	@echo "... library/command_processor.i"
	@echo "... library/command_processor.s"
	@echo "... library/input_processor.o"
	@echo "... library/input_processor.i"
	@echo "... library/input_processor.s"
	@echo "... library/input_reader.o"
	@echo "... library/input_reader.i"
	@echo "... library/input_reader.s"
	@echo "... library/logger.o"
	@echo "... library/logger.i"
	@echo "... library/logger.s"
	@echo "... library/publisher.o"
	@echo "... library/publisher.i"
	@echo "... library/publisher.s"
	@echo "... otus_hw_7_test.o"
	@echo "... otus_hw_7_test.i"
	@echo "... otus_hw_7_test.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
