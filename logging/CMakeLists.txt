cmake_minimum_required(VERSION 3.5)

project(logginglib)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE "Debug")
set(COMPILE_OPTIONS -Wall -Wextra -pedantic -Werror)

add_library(logginglib SHARED
            src/Logger.cpp)
            
target_include_directories(logginglib PUBLIC include)
target_compile_options(logginglib PRIVATE ${COMPILE_OPTIONS})

if(build_test)
add_executable(loggertest src/testapp.cpp)
target_include_directories(loggertest PUBLIC include)
target_link_libraries(loggertest logginglib)
target_compile_options(loggertest PRIVATE ${COMPILE_OPTIONS})
endif()