cmake_minimum_required(VERSION 3.14)

# 获取当前目录到变量 CURRENT_FOLDER
string(REGEX REPLACE ".*/\(.*\)" "\\1" CURRENT_FOLDER ${CMAKE_CURRENT_SOURCE_DIR})

# project名
project(${CURRENT_FOLDER})

# 设置 C++14 标准
set(CMAKE_CXX_STANDARD 14)

# Windows 平台路径长度限制：260，缩短名称，不然编译失败
set(TARGET_SHORT_NAME constr-bin-tree-from-in-post)

# 检测test代码
if (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${CURRENT_FOLDER}-test.cpp)
    # 编译test代码
    add_executable(${TARGET_SHORT_NAME}-test ${CURRENT_FOLDER}-test.cpp)
    target_link_libraries(${TARGET_SHORT_NAME}-test gtest_main)
    # 链接asan库
    if (NOT MSVC)
        target_link_libraries(${TARGET_SHORT_NAME}-test asan)
    endif ()
    # 链接built-in库依赖
    target_link_libraries(${TARGET_SHORT_NAME}-test built-in)
    # 运行Gtest测试
    add_test(${CURRENT_FOLDER} ${TARGET_SHORT_NAME}-test)
endif ()

# 检测benchmark代码
if (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${CURRENT_FOLDER}-benchmark.cpp)
    # 编译benchmark代码
    add_executable(${TARGET_SHORT_NAME}-benchmark ${CURRENT_FOLDER}-benchmark.cpp)
    # 链接benchmark库
    target_link_libraries(${TARGET_SHORT_NAME}-benchmark benchmark_main ${CMAKE_USE_PTHREADS_INIT})
    # 链接ASan库
    if (NOT MSVC)
        target_link_libraries(${TARGET_SHORT_NAME}-benchmark asan)
    endif ()
    # 链接built-in库
    target_link_libraries(${TARGET_SHORT_NAME}-benchmark built-in)
    # 运行benchmark测试
    add_test(${CURRENT_FOLDER} ${TARGET_SHORT_NAME}-benchmark)
endif ()
