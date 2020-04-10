cmake_minimum_required(VERSION 3.5)

project(miniserver)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE "Debug")
set(COMPILE_OPTIONS -Wall -Wextra -pedantic -Werror)

add_executable(miniserver src/MiniServer.cpp)
            
add_subdirectory(logging)

target_include_directories(miniserver PUBLIC include)
target_link_libraries(miniserver logginglib)
target_compile_options(miniserver PRIVATE ${COMPILE_OPTIONS})