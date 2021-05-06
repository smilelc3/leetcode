cmake_minimum_required(VERSION 3.5.1)

# 获取当前目录到变量 CURRENT_FOLDER
string(REGEX REPLACE ".*/\(.*\)" "\\1" CURRENT_FOLDER ${CMAKE_CURRENT_SOURCE_DIR})
# project名
project(${CURRENT_FOLDER})
# 设置 C++14 标准
set(CMAKE_CXX_STANDARD 14)
# Google Test/Benchmark 需要 Threads 库支持
find_package(Threads REQUIRED)

# Windows 平台路径长度限制：260，缩短名称，不然编译失败
set(test_target_short_name constr-bin-tree-from-in-post-test)

# 检测test代码
if (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${CURRENT_FOLDER}-test.cpp)
    # 编译test代码
    add_executable(${test_target_short_name} ${CURRENT_FOLDER}-test.cpp)
    target_link_libraries(${test_target_short_name} gtest ${CMAKE_THREAD_LIBS_INIT})
    # 添加built-in库依赖
    target_link_libraries(${test_target_short_name} built-in)
    # 运行测试
    add_test(${CURRENT_FOLDER} ${test_target_short_name})
else ()
    message(STATUS "${CMAKE_CURRENT_SOURCE_DIR}/${CURRENT_FOLDER}-test.cpp source file not found! -> skip test")
endif ()


# 检测benchmark代码
if (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${CURRENT_FOLDER}-benchmark.cpp)
    # 编译benchmark代码
    add_executable(${CURRENT_FOLDER}-benchmark ${CURRENT_FOLDER}-benchmark.cpp)
    # 添加 google benchmark 依赖
    target_link_libraries(${CURRENT_FOLDER}-benchmark benchmark ${CMAKE_THREAD_LIBS_INIT})
    # 添加built-in库依赖
    target_link_libraries(${CURRENT_FOLDER}-benchmark built-in)
endif ()
