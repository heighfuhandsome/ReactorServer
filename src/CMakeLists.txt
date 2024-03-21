include_directories(${CMAKE_CURRENT_SOURCE_DIR})

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SRC_LIST)

link_libraries(pthread)

add_library(reactor STATIC ${SRC_LIST})
