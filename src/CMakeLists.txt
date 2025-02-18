add_subdirectory(01-Encoder)
# add_subdirectory(02-Logical_values_array)
# add_subdirectory(03-Complex_number)
# add_subdirectory(04-Matrix)
# add_subdirectory(05-Priority_queue)

add_executable(rgu-labs main.cpp)

target_link_libraries(rgu-labs PRIVATE
    Encoder
    # LogicalValuesArray
    # ComplexNumber
    # Matrix
    # PriorityQueue
)

