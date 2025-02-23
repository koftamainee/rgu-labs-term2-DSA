add_subdirectory(06-Binary_priority_queue)
add_subdirectory(07-Binomial_priority_queue)
add_subdirectory(08-Fibonacci_priority_queue)
add_subdirectory(09-Leftist_priority_queue)
add_subdirectory(10-Skew_priority_queue)
add_subdirectory(11-Treap)

add_library(PriorityQueue STATIC ${SOURCES})


target_link_libraries(PriorityQueue PRIVATE
    BinaryPriorityQueue
    BinomialPriorityQueue
    FibonacciPriorityQueue
    LeftistPriorityQueue
    SkewPriorityQueue
    Treap
)
