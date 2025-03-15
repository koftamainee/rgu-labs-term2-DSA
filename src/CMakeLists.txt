add_subdirectory(cstd)
add_subdirectory(01-Lab)
add_subdirectory(02-Lab)

target_link_libraries(rgu-labs PRIVATE
  cstd
  01-Lab
  02-Lab
)
