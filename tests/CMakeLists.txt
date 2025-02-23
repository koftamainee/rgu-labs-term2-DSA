add_subdirectory(01-Lab)

add_library(Tests STATIC ${SOURCES})

target_link_libraries(Tests PRIVATE
  01-Lab_tests
)

target_link_libraries(rgu-labs PRIVATE
  Tests
)
