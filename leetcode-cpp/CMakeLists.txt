cmake_minimum_required(VERSION 3.14)

project(leetcode-cpp)

# 当前cmake版本
message(STATUS "CMAKE_VERSION: ${CMAKE_VERSION}")

# 开启 warning as error
if (${CMAKE_VERSION} VERSION_GREATER_EQUAL "3.24")
    set(CMAKE_COMPILE_WARNING_AS_ERROR ON)  # New in cmake version 3.24
endif ()

# 当前平台和编译器信息
message(STATUS "CMAKE_SYSTEM_NAME: ${CMAKE_SYSTEM_NAME}")
message(STATUS "CMAKE_SYSTEM_PROCESSOR: ${CMAKE_SYSTEM_PROCESSOR}")
message(STATUS "CMAKE_CXX_COMPILER_ID: ${CMAKE_CXX_COMPILER_ID}")

# 设置 C++17 标准
set(CMAKE_CXX_STANDARD 17)

# 输出 compile_commands.json 文件
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 使用Visual Studio编译额外的修改
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    # 指定使用math库中的定义宏
    add_compile_definitions(_USE_MATH_DEFINES)
    # 指定编译器的标准一致性模式(支持关键词：and or not)
    add_compile_options(/permissive-)
    # 指定代码文件编码格式为utf-8 (无BOM)
    add_compile_options(/utf-8)
endif ()

# 检查编译器是否支持ASAN
include(CheckCXXCompilerFlag)
list(APPEND CMAKE_REQUIRED_LINK_OPTIONS "-fsanitize=address")
check_cxx_compiler_flag("-fsanitize=address" COMPILER_SUPPORTS_ASAN)

# 启用对此目录及子目录的测试，该命令应位于源目录的根目录中
enable_testing()

# 启动自下载
include(FetchContent)

# FetchContent获取GTest
message(STATUS "3rd-party: start fetch GoogleTest...")
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG main
)
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)   # 新的Visual Studio项目默认动态链接C运行时库，而GTest默认静态链接。启用该选项，使gtest也动态链接C运行时库
endif ()
FetchContent_MakeAvailable(googletest)
message(STATUS "3rd-party: fetch GoogleTest success!")

# git获取Google benchmark
message(STATUS "3rd-party: start fetch Google benchmark...")
FetchContent_Declare(
        benchmark
        GIT_REPOSITORY https://github.com/google/benchmark.git
        GIT_TAG main
)
set(BENCHMARK_ENABLE_TESTING OFF)  # 不编译benchmark测试项
FetchContent_MakeAvailable(benchmark)
message(STATUS "3rd-party: fetch Google benchmark success!")

# 引入build-in依赖
add_subdirectory(built-in)

# 生成所有子目录到变量 SUBDIRS
file(GLOB SUBDIRS RELATIVE ${CMAKE_CURRENT_LIST_DIR} ${CMAKE_CURRENT_LIST_DIR}/*)
# 遍历所有子目录
foreach (SUBDIR ${SUBDIRS})
    # 检测test代码
    if (EXISTS ${CMAKE_CURRENT_LIST_DIR}/${SUBDIR}/${SUBDIR}-test.cpp)
        message(STATUS "found unit test target: ${SUBDIR}-test")
        # 编译test代码
        add_executable(${SUBDIR}-test ${CMAKE_CURRENT_LIST_DIR}/${SUBDIR}/${SUBDIR}-test.cpp)
        # 链接ASAN库
        if (COMPILER_SUPPORTS_ASAN)
            target_compile_options(${SUBDIR}-test PRIVATE -fsanitize=address)
            target_link_options(${SUBDIR}-test PRIVATE -fsanitize=address)
        endif ()
        # 链接built-in库依赖
        target_link_libraries(${SUBDIR}-test built-in)
        # 链接Gtest库依赖
        target_link_libraries(${SUBDIR}-test gtest_main)
        # 运行test测试
        add_test(${SUBDIR}-test ${SUBDIR}-test)
    endif ()
    # 检测benchmark代码
    if (EXISTS ${CMAKE_CURRENT_LIST_DIR}/${SUBDIR}/${SUBDIR}-benchmark.cpp)
        message(STATUS "found benchmark target: ${SUBDIR}-benchmark")
        # 编译benchmark代码
        add_executable(${SUBDIR}-benchmark ${CMAKE_CURRENT_LIST_DIR}/${SUBDIR}/${SUBDIR}-benchmark.cpp)
        # 链接built-in库
        target_link_libraries(${SUBDIR}-benchmark built-in)
        # 链接benchmark库
        target_link_libraries(${SUBDIR}-benchmark benchmark_main ${CMAKE_USE_PTHREADS_INIT})
        # 运行benchmark测试
        add_test(${SUBDIR}-benchmark ${SUBDIR}-benchmark)
    endif ()
endforeach ()
