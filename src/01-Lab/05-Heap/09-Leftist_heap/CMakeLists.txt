file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
add_library(Leftist_heap STATIC ${SOURCES})
set(SOURCES ${SOURCES} PARENT_SCOPE)
