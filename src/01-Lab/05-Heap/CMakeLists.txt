add_subdirectory(06-Binary_heap)
add_subdirectory(07-Binomial_heap)
add_subdirectory(08-Fibonacci_heap)
add_subdirectory(09-Leftist_heap)
add_subdirectory(10-Skew_heap)
add_subdirectory(11-Treap)

add_library(Heap STATIC ${SOURCES})


target_link_libraries(Heap PRIVATE
    Binary_heap
    Binomial_heap
    Fibonacci_heap
    Leftist_heap
    Skew_heap
    Treap
)
