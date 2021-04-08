# only for cmake --version >= 3.5.1
cmake_minimum_required(VERSION 3.5.1)

project(leetcode-cpp)

enable_testing()

include_directories(built-in)


add_subdirectory(built-in/googletest-release-1.10.0)


add_subdirectory(balanced-binary-tree)
add_subdirectory(built-in)
add_subdirectory(flatten-binary-tree-to-linked-list)
add_subdirectory(gray-code)
add_subdirectory(linked-list-cycle)
add_subdirectory(longest-consecutive-sequence)
add_subdirectory(minimum-depth-of-binary-tree)
add_subdirectory(pascals-triangle)
add_subdirectory(path-sum)
add_subdirectory(path-sum-ii)
add_subdirectory(single-number)
add_subdirectory(single-number-ii)
add_subdirectory(word-break)