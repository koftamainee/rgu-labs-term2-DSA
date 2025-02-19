file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
add_library(LogicalValuesArray STATIC ${SOURCES})
target_include_directories(LogicalValuesArray
 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

