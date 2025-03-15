add_subdirectory(01-Encoder)
add_subdirectory(02-Logical_values_array)
add_subdirectory(03-Complex)
add_subdirectory(04-Matrix)
add_subdirectory(05-Heap)

add_library(01-Lab STATIC ${SOURCES})

target_link_libraries(01-Lab PRIVATE
    Encoder
    LogicalValuesArray
    Complex
    Matrix
    Heap
)
