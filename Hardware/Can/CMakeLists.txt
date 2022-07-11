# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.5)

# Set the project name
project (CanTest VERSION 1.0)

include_directories(
  include
)
  
file(GLOB_RECURSE CAN_SRCS "src/*.cpp")
add_library(Can ${CAN_SRCS})

# add the executable
add_executable(CanTest main.cpp)
target_link_libraries(CanTest Can)

