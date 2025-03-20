cmake_minimum_required(VERSION 3.31)
project(rgu-labs LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_FLAGS_DEBUG_INIT "-g -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE_INIT "-O3")       


if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(rgu-labs src/main.cpp)

add_subdirectory(src)
add_subdirectory(tests)


