file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
add_library(Binomial_heap STATIC ${SOURCES})
set(SOURCES ${SOURCES} PARENT_SCOPE)
