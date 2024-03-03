cmake_minimum_required(VERSION 3.22)
project(skiplist)

set(CMAKE_CXX_STANDARD 23)

# Set compiler flags globally
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer -g -O2")

# Set linker flags for AddressSanitizer globally
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address")
add_subdirectory(tests)
add_subdirectory(benchmark)