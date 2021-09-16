cmake_minimum_required(VERSION 3.14)

project(leetcode-cpp)

# 设置 C++14 标准
set(CMAKE_CXX_STANDARD 14)

# 使用Visual Studio编译额外的修改
if (MSVC)
    # MSVC默认以MD(多线程DLL)动态链接库文件，不适合本项目，替换MD为MT（多线程静态）
    set(CompilerFlags
            CMAKE_CXX_FLAGS
            CMAKE_CXX_FLAGS_DEBUG
            CMAKE_CXX_FLAGS_RELEASE
            CMAKE_CXX_FLAGS_MINSIZEREL
            CMAKE_CXX_FLAGS_RELWITHDEBINFO
            )
    foreach (CompilerFlag ${CompilerFlags})
        string(REPLACE "/MD" "/MT" ${CompilerFlag} "${${CompilerFlag}}")
    endforeach ()

    # 指定编译器的标准一致性模式(支持关键词：and or not)
    add_compile_options(/permissive-)
    # 指定代码文件编码格式为utf-8 (无BOM)
    add_compile_options(/utf-8)
endif ()

# 启用AddressSanitizer (ASan)功能
add_compile_options(-fsanitize=address)

# 启用对此目录及子目录的测试，该命令应位于源目录的根目录中
enable_testing()

# 启动自下载
include(FetchContent)

# FetchContent获取GTest
FetchContent_Declare(googletest GIT_REPOSITORY https://github.com/google/googletest.git)
set(INSTALL_GTEST OFF)       # 不安装GTest
FetchContent_MakeAvailable(googletest)
message(STATUS "fetch 3rd-party: GoogleTest success !")

# git获取Google benchmark
FetchContent_Declare(benchmark GIT_REPOSITORY https://github.com/google/benchmark.git)
set(BENCHMARK_ENABLE_TESTING OFF)       # 不编译benchmark测试项
set(BENCHMARK_ENABLE_INSTALL OFF)       # 不安装benchmark
FetchContent_MakeAvailable(benchmark)
message(STATUS "fetch 3rd-party: Google benchmark success !")


# 引入build-in依赖
include_directories(built-in)

# 生成所有子目录到变量 SUBDIRS
file(GLOB SUBDIRS RELATIVE ${CMAKE_CURRENT_LIST_DIR} ${CMAKE_CURRENT_LIST_DIR}/*)
# 遍历所有子目录，如果子目录下存在 CMakeLists.txt 文件，add_subdirectory
foreach (SUBDIR ${SUBDIRS})
    if (EXISTS ${CMAKE_CURRENT_LIST_DIR}/${SUBDIR}/CMakeLists.txt)
        message(STATUS "found target: ${SUBDIR}")
        add_subdirectory(${SUBDIR})
    endif ()
endforeach ()