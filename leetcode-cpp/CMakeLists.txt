# only for cmake --version >= 3.5.1
cmake_minimum_required(VERSION 3.5.1)

project(leetcode)

enable_testing()

include_directories(built-in)

add_subdirectory(balanced-binary-tree)
add_subdirectory(built-in)
add_subdirectory(gray-code)
add_subdirectory(linked-list-cycle)
add_subdirectory(minimum-depth-of-binary-tree)
add_subdirectory(path-sum)


