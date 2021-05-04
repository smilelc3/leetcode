cmake_minimum_required(VERSION 3.5.1)

project(leetcode-cpp)

# 启用对此目录及子目录的测试，该命令应位于源目录的根目录中
enable_testing()
# 引入build-in依赖
include_directories(built-in)

# 添加Google gtest/benchmark 项目
add_subdirectory(built-in/googletest-release-1.10.0)
add_subdirectory(built-in/benchmark-1.5.3)


# 生成所有子目录到变量 SUBDIRS
file(GLOB SUBDIRS RELATIVE ${CMAKE_CURRENT_LIST_DIR} ${CMAKE_CURRENT_LIST_DIR}/*)
# 遍历所有子目录，如果子目录下存在 CMakeLists.txt 文件，add_subdirectory
foreach (SUBDIR ${SUBDIRS})
    if (EXISTS ${CMAKE_CURRENT_LIST_DIR}/${SUBDIR}/CMakeLists.txt)
        message(STATUS "found target: ${SUBDIR}")
        add_subdirectory(${SUBDIR})
    endif ()
endforeach ()
