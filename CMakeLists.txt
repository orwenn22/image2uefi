cmake_minimum_required(VERSION 3.26)
project(image2uefi)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(raylib)

add_executable(image2uefi main.cpp)
target_link_libraries(image2uefi PRIVATE raylib)
