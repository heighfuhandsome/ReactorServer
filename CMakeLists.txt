cmake_minimum_required(VERSION 3.0.0)

project(ReactorServer CXX)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)

add_compile_options(--std=c++17)

add_subdirectory(${PROJECT_SOURCE_DIR}/ReactorServer)

link_libraries(pthread reactor)

add_executable(demo main.cpp)
