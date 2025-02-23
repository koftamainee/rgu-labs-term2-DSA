add_subdirectory(01-Lab)

add_executable(rgu-labs main.cpp)

target_link_libraries(rgu-labs PRIVATE
  01-Lab
)

