add_subdirectory(01-Bigint)
add_subdirectory(02-Bigfloat)

add_library(02-Lab STATIC ${SOURCES})

target_link_libraries(02-Lab PRIVATE
  Bigint
  Bigfloat
)
