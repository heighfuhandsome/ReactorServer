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
CMAKE_BINARY_DIR = /home/xj/projects/ReactorServer/cmake-build-debug-docker_ubuntu

# Include any dependencies generated for this target.
include ReactorServer/CMakeFiles/reactor.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include ReactorServer/CMakeFiles/reactor.dir/compiler_depend.make

# Include the progress variables for this target.
include ReactorServer/CMakeFiles/reactor.dir/progress.make

# Include the compile flags for this target's objects.
include ReactorServer/CMakeFiles/reactor.dir/flags.make

ReactorServer/CMakeFiles/reactor.dir/Acceptor.cpp.o: ReactorServer/CMakeFiles/reactor.dir/flags.make
ReactorServer/CMakeFiles/reactor.dir/Acceptor.cpp.o: ../ReactorServer/Acceptor.cpp
ReactorServer/CMakeFiles/reactor.dir/Acceptor.cpp.o: ReactorServer/CMakeFiles/reactor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xj/projects/ReactorServer/cmake-build-debug-docker_ubuntu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object ReactorServer/CMakeFiles/reactor.dir/Acceptor.cpp.o"
	cd /home/xj/projects/ReactorServer/cmake-build-debug-docker_ubuntu/ReactorServer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT ReactorServer/CMakeFiles/reactor.dir/Acceptor.cpp.o -MF CMakeFiles/reactor.dir/Acceptor.cpp.o.d -o CMakeFiles/reactor.dir/Acceptor.cpp.o -c /home/xj/projects/ReactorServer/ReactorServer/Acceptor.cpp

ReactorServer/CMakeFiles/reactor.dir/Acceptor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/reactor.dir/Acceptor.cpp.i"
	cd /home/xj/projects/ReactorServer/cmake-build-debug-docker_ubuntu/ReactorServer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xj/projects/ReactorServer/ReactorServer/Acceptor.cpp > CMakeFiles/reactor.dir/Acceptor.cpp.i

ReactorServer/CMakeFiles/reactor.dir/Acceptor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/reactor.dir/Acceptor.cpp.s"
	cd /home/xj/projects/ReactorServer/cmake-build-debug-docker_ubuntu/ReactorServer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xj/projects/ReactorServer/ReactorServer/Acceptor.cpp -o CMakeFiles/reactor.dir/Acceptor.cpp.s

ReactorServer/CMakeFiles/reactor.dir/Buffer.cpp.o: ReactorServer/CMakeFiles/reactor.dir/flags.make
ReactorServer/CMakeFiles/reactor.dir/Buffer.cpp.o: ../ReactorServer/Buffer.cpp
ReactorServer/CMakeFiles/reactor.dir/Buffer.cpp.o: ReactorServer/CMakeFiles/reactor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xj/projects/ReactorServer/cmake-build-debug-docker_ubuntu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object ReactorServer/CMakeFiles/reactor.dir/Buffer.cpp.o"
	cd /home/xj/projects/ReactorServer/cmake-build-debug-docker_ubuntu/ReactorServer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT ReactorServer/CMakeFiles/reactor.dir/Buffer.cpp.o -MF CMakeFiles/reactor.dir/Buffer.cpp.o.d -o CMakeFiles/reactor.dir/Buffer.cpp.o -c /home/xj/projects/ReactorServer/ReactorServer/Buffer.cpp

ReactorServer/CMakeFiles/reactor.dir/Buffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/reactor.dir/Buffer.cpp.i"
	cd /home/xj/projects/ReactorServer/cmake-build-debug-docker_ubuntu/ReactorServer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xj/projects/ReactorServer/ReactorServer/Buffer.cpp > CMakeFiles/reactor.dir/Buffer.cpp.i

ReactorServer/CMakeFiles/reactor.dir/Buffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/reactor.dir/Buffer.cpp.s"
	cd /home/xj/projects/ReactorServer/cmake-build-debug-docker_ubuntu/ReactorServer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xj/projects/ReactorServer/ReactorServer/Buffer.cpp -o CMakeFiles/reactor.dir/Buffer.cpp.s

ReactorServer/CMakeFiles/reactor.dir/Channel.cpp.o: ReactorServer/CMakeFiles/reactor.dir/flags.make
ReactorServer/CMakeFiles/reactor.dir/Channel.cpp.o: ../ReactorServer/Channel.cpp
ReactorServer/CMakeFiles/reactor.dir/Channel.cpp.o: ReactorServer/CMakeFiles/reactor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xj/projects/ReactorServer/cmake-build-debug-docker_ubuntu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object ReactorServer/CMakeFiles/reactor.dir/Channel.cpp.o"
	cd /home/xj/projects/ReactorServer/cmake-build-debug-docker_ubuntu/ReactorServer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT ReactorServer/CMakeFiles/reactor.dir/Channel.cpp.o -MF CMakeFiles/reactor.dir/Channel.cpp.o.d -o CMakeFiles/reactor.dir/Channel.cpp.o -c /home/xj/projects/ReactorServer/ReactorServer/Channel.cpp

ReactorServer/CMakeFiles/reactor.dir/Channel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/reactor.dir/Channel.cpp.i"
	cd /home/xj/projects/ReactorServer/cmake-build-debug-docker_ubuntu/ReactorServer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xj/projects/ReactorServer/ReactorServer/Channel.cpp > CMakeFiles/reactor.dir/Channel.cpp.i

ReactorServer/CMakeFiles/reactor.dir/Channel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/reactor.dir/Channel.cpp.s"
	cd /home/xj/projects/ReactorServer/cmake-build-debug-docker_ubuntu/ReactorServer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xj/projects/ReactorServer/ReactorServer/Channel.cpp -o CMakeFiles/reactor.dir/Channel.cpp.s

ReactorServer/CMakeFiles/reactor.dir/Dispatch.cpp.o: ReactorServer/CMakeFiles/reactor.dir/flags.make
ReactorServer/CMakeFiles/reactor.dir/Dispatch.cpp.o: ../ReactorServer/Dispatch.cpp
ReactorServer/CMakeFiles/reactor.dir/Dispatch.cpp.o: ReactorServer/CMakeFiles/reactor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xj/projects/ReactorServer/cmake-build-debug-docker_ubuntu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object ReactorServer/CMakeFiles/reactor.dir/Dispatch.cpp.o"
	cd /home/xj/projects/ReactorServer/cmake-build-debug-docker_ubuntu/ReactorServer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT ReactorServer/CMakeFiles/reactor.dir/Dispatch.cpp.o -MF CMakeFiles/reactor.dir/Dispatch.cpp.o.d -o CMakeFiles/reactor.dir/Dispatch.cpp.o -c /home/xj/projects/ReactorServer/ReactorServer/Dispatch.cpp

ReactorServer/CMakeFiles/reactor.dir/Dispatch.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/reactor.dir/Dispatch.cpp.i"
	cd /home/xj/projects/ReactorServer/cmake-build-debug-docker_ubuntu/ReactorServer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xj/projects/ReactorServer/ReactorServer/Dispatch.cpp > CMakeFiles/reactor.dir/Dispatch.cpp.i

ReactorServer/CMakeFiles/reactor.dir/Dispatch.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/reactor.dir/Dispatch.cpp.s"
	cd /home/xj/projects/ReactorServer/cmake-build-debug-docker_ubuntu/ReactorServer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xj/projects/ReactorServer/ReactorServer/Dispatch.cpp -o CMakeFiles/reactor.dir/Dispatch.cpp.s

ReactorServer/CMakeFiles/reactor.dir/EventLoop.cpp.o: ReactorServer/CMakeFiles/reactor.dir/flags.make
ReactorServer/CMakeFiles/reactor.dir/EventLoop.cpp.o: ../ReactorServer/EventLoop.cpp
ReactorServer/CMakeFiles/reactor.dir/EventLoop.cpp.o: ReactorServer/CMakeFiles/reactor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xj/projects/ReactorServer/cmake-build-debug-docker_ubuntu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object ReactorServer/CMakeFiles/reactor.dir/EventLoop.cpp.o"
	cd /home/xj/projects/ReactorServer/cmake-build-debug-docker_ubuntu/ReactorServer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT ReactorServer/CMakeFiles/reactor.dir/EventLoop.cpp.o -MF CMakeFiles/reactor.dir/EventLoop.cpp.o.d -o CMakeFiles/reactor.dir/EventLoop.cpp.o -c /home/xj/projects/ReactorServer/ReactorServer/EventLoop.cpp

ReactorServer/CMakeFiles/reactor.dir/EventLoop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/reactor.dir/EventLoop.cpp.i"
	cd /home/xj/projects/ReactorServer/cmake-build-debug-docker_ubuntu/ReactorServer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xj/projects/ReactorServer/ReactorServer/EventLoop.cpp > CMakeFiles/reactor.dir/EventLoop.cpp.i

ReactorServer/CMakeFiles/reactor.dir/EventLoop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/reactor.dir/EventLoop.cpp.s"
	cd /home/xj/projects/ReactorServer/cmake-build-debug-docker_ubuntu/ReactorServer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xj/projects/ReactorServer/ReactorServer/EventLoop.cpp -o CMakeFiles/reactor.dir/EventLoop.cpp.s

ReactorServer/CMakeFiles/reactor.dir/EventLoopThreadPoll.cpp.o: ReactorServer/CMakeFiles/reactor.dir/flags.make
ReactorServer/CMakeFiles/reactor.dir/EventLoopThreadPoll.cpp.o: ../ReactorServer/EventLoopThreadPoll.cpp
ReactorServer/CMakeFiles/reactor.dir/EventLoopThreadPoll.cpp.o: ReactorServer/CMakeFiles/reactor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xj/projects/ReactorServer/cmake-build-debug-docker_ubuntu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object ReactorServer/CMakeFiles/reactor.dir/EventLoopThreadPoll.cpp.o"
	cd /home/xj/projects/ReactorServer/cmake-build-debug-docker_ubuntu/ReactorServer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT ReactorServer/CMakeFiles/reactor.dir/EventLoopThreadPoll.cpp.o -MF CMakeFiles/reactor.dir/EventLoopThreadPoll.cpp.o.d -o CMakeFiles/reactor.dir/EventLoopThreadPoll.cpp.o -c /home/xj/projects/ReactorServer/ReactorServer/EventLoopThreadPoll.cpp

ReactorServer/CMakeFiles/reactor.dir/EventLoopThreadPoll.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/reactor.dir/EventLoopThreadPoll.cpp.i"
	cd /home/xj/projects/ReactorServer/cmake-build-debug-docker_ubuntu/ReactorServer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xj/projects/ReactorServer/ReactorServer/EventLoopThreadPoll.cpp > CMakeFiles/reactor.dir/EventLoopThreadPoll.cpp.i

ReactorServer/CMakeFiles/reactor.dir/EventLoopThreadPoll.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/reactor.dir/EventLoopThreadPoll.cpp.s"
	cd /home/xj/projects/ReactorServer/cmake-build-debug-docker_ubuntu/ReactorServer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xj/projects/ReactorServer/ReactorServer/EventLoopThreadPoll.cpp -o CMakeFiles/reactor.dir/EventLoopThreadPoll.cpp.s

ReactorServer/CMakeFiles/reactor.dir/InetAddr.cpp.o: ReactorServer/CMakeFiles/reactor.dir/flags.make
ReactorServer/CMakeFiles/reactor.dir/InetAddr.cpp.o: ../ReactorServer/InetAddr.cpp
ReactorServer/CMakeFiles/reactor.dir/InetAddr.cpp.o: ReactorServer/CMakeFiles/reactor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xj/projects/ReactorServer/cmake-build-debug-docker_ubuntu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object ReactorServer/CMakeFiles/reactor.dir/InetAddr.cpp.o"
	cd /home/xj/projects/ReactorServer/cmake-build-debug-docker_ubuntu/ReactorServer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT ReactorServer/CMakeFiles/reactor.dir/InetAddr.cpp.o -MF CMakeFiles/reactor.dir/InetAddr.cpp.o.d -o CMakeFiles/reactor.dir/InetAddr.cpp.o -c /home/xj/projects/ReactorServer/ReactorServer/InetAddr.cpp

ReactorServer/CMakeFiles/reactor.dir/InetAddr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/reactor.dir/InetAddr.cpp.i"
	cd /home/xj/projects/ReactorServer/cmake-build-debug-docker_ubuntu/ReactorServer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xj/projects/ReactorServer/ReactorServer/InetAddr.cpp > CMakeFiles/reactor.dir/InetAddr.cpp.i

ReactorServer/CMakeFiles/reactor.dir/InetAddr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/reactor.dir/InetAddr.cpp.s"
	cd /home/xj/projects/ReactorServer/cmake-build-debug-docker_ubuntu/ReactorServer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xj/projects/ReactorServer/ReactorServer/InetAddr.cpp -o CMakeFiles/reactor.dir/InetAddr.cpp.s

ReactorServer/CMakeFiles/reactor.dir/Socket.cpp.o: ReactorServer/CMakeFiles/reactor.dir/flags.make
ReactorServer/CMakeFiles/reactor.dir/Socket.cpp.o: ../ReactorServer/Socket.cpp
ReactorServer/CMakeFiles/reactor.dir/Socket.cpp.o: ReactorServer/CMakeFiles/reactor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xj/projects/ReactorServer/cmake-build-debug-docker_ubuntu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object ReactorServer/CMakeFiles/reactor.dir/Socket.cpp.o"
	cd /home/xj/projects/ReactorServer/cmake-build-debug-docker_ubuntu/ReactorServer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT ReactorServer/CMakeFiles/reactor.dir/Socket.cpp.o -MF CMakeFiles/reactor.dir/Socket.cpp.o.d -o CMakeFiles/reactor.dir/Socket.cpp.o -c /home/xj/projects/ReactorServer/ReactorServer/Socket.cpp

ReactorServer/CMakeFiles/reactor.dir/Socket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/reactor.dir/Socket.cpp.i"
	cd /home/xj/projects/ReactorServer/cmake-build-debug-docker_ubuntu/ReactorServer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xj/projects/ReactorServer/ReactorServer/Socket.cpp > CMakeFiles/reactor.dir/Socket.cpp.i

ReactorServer/CMakeFiles/reactor.dir/Socket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/reactor.dir/Socket.cpp.s"
	cd /home/xj/projects/ReactorServer/cmake-build-debug-docker_ubuntu/ReactorServer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xj/projects/ReactorServer/ReactorServer/Socket.cpp -o CMakeFiles/reactor.dir/Socket.cpp.s

ReactorServer/CMakeFiles/reactor.dir/TcpConnect.cpp.o: ReactorServer/CMakeFiles/reactor.dir/flags.make
ReactorServer/CMakeFiles/reactor.dir/TcpConnect.cpp.o: ../ReactorServer/TcpConnect.cpp
ReactorServer/CMakeFiles/reactor.dir/TcpConnect.cpp.o: ReactorServer/CMakeFiles/reactor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xj/projects/ReactorServer/cmake-build-debug-docker_ubuntu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object ReactorServer/CMakeFiles/reactor.dir/TcpConnect.cpp.o"
	cd /home/xj/projects/ReactorServer/cmake-build-debug-docker_ubuntu/ReactorServer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT ReactorServer/CMakeFiles/reactor.dir/TcpConnect.cpp.o -MF CMakeFiles/reactor.dir/TcpConnect.cpp.o.d -o CMakeFiles/reactor.dir/TcpConnect.cpp.o -c /home/xj/projects/ReactorServer/ReactorServer/TcpConnect.cpp

ReactorServer/CMakeFiles/reactor.dir/TcpConnect.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/reactor.dir/TcpConnect.cpp.i"
	cd /home/xj/projects/ReactorServer/cmake-build-debug-docker_ubuntu/ReactorServer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xj/projects/ReactorServer/ReactorServer/TcpConnect.cpp > CMakeFiles/reactor.dir/TcpConnect.cpp.i

ReactorServer/CMakeFiles/reactor.dir/TcpConnect.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/reactor.dir/TcpConnect.cpp.s"
	cd /home/xj/projects/ReactorServer/cmake-build-debug-docker_ubuntu/ReactorServer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xj/projects/ReactorServer/ReactorServer/TcpConnect.cpp -o CMakeFiles/reactor.dir/TcpConnect.cpp.s

ReactorServer/CMakeFiles/reactor.dir/TcpServer.cpp.o: ReactorServer/CMakeFiles/reactor.dir/flags.make
ReactorServer/CMakeFiles/reactor.dir/TcpServer.cpp.o: ../ReactorServer/TcpServer.cpp
ReactorServer/CMakeFiles/reactor.dir/TcpServer.cpp.o: ReactorServer/CMakeFiles/reactor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xj/projects/ReactorServer/cmake-build-debug-docker_ubuntu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object ReactorServer/CMakeFiles/reactor.dir/TcpServer.cpp.o"
	cd /home/xj/projects/ReactorServer/cmake-build-debug-docker_ubuntu/ReactorServer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT ReactorServer/CMakeFiles/reactor.dir/TcpServer.cpp.o -MF CMakeFiles/reactor.dir/TcpServer.cpp.o.d -o CMakeFiles/reactor.dir/TcpServer.cpp.o -c /home/xj/projects/ReactorServer/ReactorServer/TcpServer.cpp

ReactorServer/CMakeFiles/reactor.dir/TcpServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/reactor.dir/TcpServer.cpp.i"
	cd /home/xj/projects/ReactorServer/cmake-build-debug-docker_ubuntu/ReactorServer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xj/projects/ReactorServer/ReactorServer/TcpServer.cpp > CMakeFiles/reactor.dir/TcpServer.cpp.i

ReactorServer/CMakeFiles/reactor.dir/TcpServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/reactor.dir/TcpServer.cpp.s"
	cd /home/xj/projects/ReactorServer/cmake-build-debug-docker_ubuntu/ReactorServer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xj/projects/ReactorServer/ReactorServer/TcpServer.cpp -o CMakeFiles/reactor.dir/TcpServer.cpp.s

# Object files for target reactor
reactor_OBJECTS = \
"CMakeFiles/reactor.dir/Acceptor.cpp.o" \
"CMakeFiles/reactor.dir/Buffer.cpp.o" \
"CMakeFiles/reactor.dir/Channel.cpp.o" \
"CMakeFiles/reactor.dir/Dispatch.cpp.o" \
"CMakeFiles/reactor.dir/EventLoop.cpp.o" \
"CMakeFiles/reactor.dir/EventLoopThreadPoll.cpp.o" \
"CMakeFiles/reactor.dir/InetAddr.cpp.o" \
"CMakeFiles/reactor.dir/Socket.cpp.o" \
"CMakeFiles/reactor.dir/TcpConnect.cpp.o" \
"CMakeFiles/reactor.dir/TcpServer.cpp.o"

# External object files for target reactor
reactor_EXTERNAL_OBJECTS =

../lib/libreactor.a: ReactorServer/CMakeFiles/reactor.dir/Acceptor.cpp.o
../lib/libreactor.a: ReactorServer/CMakeFiles/reactor.dir/Buffer.cpp.o
../lib/libreactor.a: ReactorServer/CMakeFiles/reactor.dir/Channel.cpp.o
../lib/libreactor.a: ReactorServer/CMakeFiles/reactor.dir/Dispatch.cpp.o
../lib/libreactor.a: ReactorServer/CMakeFiles/reactor.dir/EventLoop.cpp.o
../lib/libreactor.a: ReactorServer/CMakeFiles/reactor.dir/EventLoopThreadPoll.cpp.o
../lib/libreactor.a: ReactorServer/CMakeFiles/reactor.dir/InetAddr.cpp.o
../lib/libreactor.a: ReactorServer/CMakeFiles/reactor.dir/Socket.cpp.o
../lib/libreactor.a: ReactorServer/CMakeFiles/reactor.dir/TcpConnect.cpp.o
../lib/libreactor.a: ReactorServer/CMakeFiles/reactor.dir/TcpServer.cpp.o
../lib/libreactor.a: ReactorServer/CMakeFiles/reactor.dir/build.make
../lib/libreactor.a: ReactorServer/CMakeFiles/reactor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xj/projects/ReactorServer/cmake-build-debug-docker_ubuntu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX static library ../../lib/libreactor.a"
	cd /home/xj/projects/ReactorServer/cmake-build-debug-docker_ubuntu/ReactorServer && $(CMAKE_COMMAND) -P CMakeFiles/reactor.dir/cmake_clean_target.cmake
	cd /home/xj/projects/ReactorServer/cmake-build-debug-docker_ubuntu/ReactorServer && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/reactor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
ReactorServer/CMakeFiles/reactor.dir/build: ../lib/libreactor.a
.PHONY : ReactorServer/CMakeFiles/reactor.dir/build

ReactorServer/CMakeFiles/reactor.dir/clean:
	cd /home/xj/projects/ReactorServer/cmake-build-debug-docker_ubuntu/ReactorServer && $(CMAKE_COMMAND) -P CMakeFiles/reactor.dir/cmake_clean.cmake
.PHONY : ReactorServer/CMakeFiles/reactor.dir/clean

ReactorServer/CMakeFiles/reactor.dir/depend:
	cd /home/xj/projects/ReactorServer/cmake-build-debug-docker_ubuntu && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xj/projects/ReactorServer /home/xj/projects/ReactorServer/ReactorServer /home/xj/projects/ReactorServer/cmake-build-debug-docker_ubuntu /home/xj/projects/ReactorServer/cmake-build-debug-docker_ubuntu/ReactorServer /home/xj/projects/ReactorServer/cmake-build-debug-docker_ubuntu/ReactorServer/CMakeFiles/reactor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : ReactorServer/CMakeFiles/reactor.dir/depend

