# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/xj/projects/ReactorServer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xj/projects/ReactorServer/build

# Include any dependencies generated for this target.
include src/CMakeFiles/reactor.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/reactor.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/reactor.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/reactor.dir/flags.make

src/CMakeFiles/reactor.dir/Channel.cpp.o: src/CMakeFiles/reactor.dir/flags.make
src/CMakeFiles/reactor.dir/Channel.cpp.o: ../src/Channel.cpp
src/CMakeFiles/reactor.dir/Channel.cpp.o: src/CMakeFiles/reactor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xj/projects/ReactorServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/reactor.dir/Channel.cpp.o"
	cd /home/xj/projects/ReactorServer/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/reactor.dir/Channel.cpp.o -MF CMakeFiles/reactor.dir/Channel.cpp.o.d -o CMakeFiles/reactor.dir/Channel.cpp.o -c /home/xj/projects/ReactorServer/src/Channel.cpp

src/CMakeFiles/reactor.dir/Channel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/reactor.dir/Channel.cpp.i"
	cd /home/xj/projects/ReactorServer/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xj/projects/ReactorServer/src/Channel.cpp > CMakeFiles/reactor.dir/Channel.cpp.i

src/CMakeFiles/reactor.dir/Channel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/reactor.dir/Channel.cpp.s"
	cd /home/xj/projects/ReactorServer/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xj/projects/ReactorServer/src/Channel.cpp -o CMakeFiles/reactor.dir/Channel.cpp.s

src/CMakeFiles/reactor.dir/Dispatch.cpp.o: src/CMakeFiles/reactor.dir/flags.make
src/CMakeFiles/reactor.dir/Dispatch.cpp.o: ../src/Dispatch.cpp
src/CMakeFiles/reactor.dir/Dispatch.cpp.o: src/CMakeFiles/reactor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xj/projects/ReactorServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/reactor.dir/Dispatch.cpp.o"
	cd /home/xj/projects/ReactorServer/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/reactor.dir/Dispatch.cpp.o -MF CMakeFiles/reactor.dir/Dispatch.cpp.o.d -o CMakeFiles/reactor.dir/Dispatch.cpp.o -c /home/xj/projects/ReactorServer/src/Dispatch.cpp

src/CMakeFiles/reactor.dir/Dispatch.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/reactor.dir/Dispatch.cpp.i"
	cd /home/xj/projects/ReactorServer/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xj/projects/ReactorServer/src/Dispatch.cpp > CMakeFiles/reactor.dir/Dispatch.cpp.i

src/CMakeFiles/reactor.dir/Dispatch.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/reactor.dir/Dispatch.cpp.s"
	cd /home/xj/projects/ReactorServer/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xj/projects/ReactorServer/src/Dispatch.cpp -o CMakeFiles/reactor.dir/Dispatch.cpp.s

src/CMakeFiles/reactor.dir/EventLoop.cpp.o: src/CMakeFiles/reactor.dir/flags.make
src/CMakeFiles/reactor.dir/EventLoop.cpp.o: ../src/EventLoop.cpp
src/CMakeFiles/reactor.dir/EventLoop.cpp.o: src/CMakeFiles/reactor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xj/projects/ReactorServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/reactor.dir/EventLoop.cpp.o"
	cd /home/xj/projects/ReactorServer/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/reactor.dir/EventLoop.cpp.o -MF CMakeFiles/reactor.dir/EventLoop.cpp.o.d -o CMakeFiles/reactor.dir/EventLoop.cpp.o -c /home/xj/projects/ReactorServer/src/EventLoop.cpp

src/CMakeFiles/reactor.dir/EventLoop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/reactor.dir/EventLoop.cpp.i"
	cd /home/xj/projects/ReactorServer/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xj/projects/ReactorServer/src/EventLoop.cpp > CMakeFiles/reactor.dir/EventLoop.cpp.i

src/CMakeFiles/reactor.dir/EventLoop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/reactor.dir/EventLoop.cpp.s"
	cd /home/xj/projects/ReactorServer/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xj/projects/ReactorServer/src/EventLoop.cpp -o CMakeFiles/reactor.dir/EventLoop.cpp.s

src/CMakeFiles/reactor.dir/Socket.cpp.o: src/CMakeFiles/reactor.dir/flags.make
src/CMakeFiles/reactor.dir/Socket.cpp.o: ../src/Socket.cpp
src/CMakeFiles/reactor.dir/Socket.cpp.o: src/CMakeFiles/reactor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xj/projects/ReactorServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/reactor.dir/Socket.cpp.o"
	cd /home/xj/projects/ReactorServer/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/reactor.dir/Socket.cpp.o -MF CMakeFiles/reactor.dir/Socket.cpp.o.d -o CMakeFiles/reactor.dir/Socket.cpp.o -c /home/xj/projects/ReactorServer/src/Socket.cpp

src/CMakeFiles/reactor.dir/Socket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/reactor.dir/Socket.cpp.i"
	cd /home/xj/projects/ReactorServer/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xj/projects/ReactorServer/src/Socket.cpp > CMakeFiles/reactor.dir/Socket.cpp.i

src/CMakeFiles/reactor.dir/Socket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/reactor.dir/Socket.cpp.s"
	cd /home/xj/projects/ReactorServer/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xj/projects/ReactorServer/src/Socket.cpp -o CMakeFiles/reactor.dir/Socket.cpp.s

# Object files for target reactor
reactor_OBJECTS = \
"CMakeFiles/reactor.dir/Channel.cpp.o" \
"CMakeFiles/reactor.dir/Dispatch.cpp.o" \
"CMakeFiles/reactor.dir/EventLoop.cpp.o" \
"CMakeFiles/reactor.dir/Socket.cpp.o"

# External object files for target reactor
reactor_EXTERNAL_OBJECTS =

src/libreactor.a: src/CMakeFiles/reactor.dir/Channel.cpp.o
src/libreactor.a: src/CMakeFiles/reactor.dir/Dispatch.cpp.o
src/libreactor.a: src/CMakeFiles/reactor.dir/EventLoop.cpp.o
src/libreactor.a: src/CMakeFiles/reactor.dir/Socket.cpp.o
src/libreactor.a: src/CMakeFiles/reactor.dir/build.make
src/libreactor.a: src/CMakeFiles/reactor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xj/projects/ReactorServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX static library libreactor.a"
	cd /home/xj/projects/ReactorServer/build/src && $(CMAKE_COMMAND) -P CMakeFiles/reactor.dir/cmake_clean_target.cmake
	cd /home/xj/projects/ReactorServer/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/reactor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/reactor.dir/build: src/libreactor.a
.PHONY : src/CMakeFiles/reactor.dir/build

src/CMakeFiles/reactor.dir/clean:
	cd /home/xj/projects/ReactorServer/build/src && $(CMAKE_COMMAND) -P CMakeFiles/reactor.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/reactor.dir/clean

src/CMakeFiles/reactor.dir/depend:
	cd /home/xj/projects/ReactorServer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xj/projects/ReactorServer /home/xj/projects/ReactorServer/src /home/xj/projects/ReactorServer/build /home/xj/projects/ReactorServer/build/src /home/xj/projects/ReactorServer/build/src/CMakeFiles/reactor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/reactor.dir/depend
