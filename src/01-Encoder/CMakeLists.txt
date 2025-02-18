file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
add_library(Encoder STATIC ${SOURCES})
target_include_directories(Encoder PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

