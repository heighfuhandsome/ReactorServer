cmake_minimum_required(VERSION 3.0.0)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

#set(${EXECUTABLE_OUTPUT_PATH} ./bin)

add_subdirectory(${PROJECT_SOURCE_DIR}/src)

add_executable(demo main.cpp)