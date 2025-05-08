CMAKE_MINIMUM_REQUIRED(VERSION 3.22)
project(FullFlow C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_subdirectory(fileSearcher)

add_executable(fullFlow main.c)

target_link_libraries(fullFlow PRIVATE fileSearcher)
