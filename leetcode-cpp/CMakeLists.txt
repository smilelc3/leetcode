cmake_minimum_required(VERSION 3.5.1)

project(leetcode-cpp)

# 使用Visual Studio编译额外的修改
if (MSVC)
    # MSVC默认以MD(多线程DLL)动态链接库文件，不适合本项目，替换MD为MT（多线程静态）
    set(CompilerFlags
            CMAKE_CXX_FLAGS
            CMAKE_CXX_FLAGS_DEBUG
            CMAKE_CXX_FLAGS_RELEASE
            CMAKE_CXX_FLAGS_MINSIZEREL
            CMAKE_CXX_FLAGS_RELWITHDEBINFO
            CMAKE_C_FLAGS
            CMAKE_C_FLAGS_DEBUG
            CMAKE_C_FLAGS_RELEASE
            CMAKE_C_FLAGS_MINSIZEREL
            CMAKE_C_FLAGS_RELWITHDEBINFO
            )
    foreach(CompilerFlag ${CompilerFlags})
        string(REPLACE "/MD" "/MT" ${CompilerFlag} "${${CompilerFlag}}")
    endforeach()

    # 指定编译器的标准一致性模式(支持关键词：and or not)
    add_compile_options(/permissive-)
    # 指定代码文件编码格式为utf-8 (无BOM)
    add_compile_options(/utf-8)
endif()

message(${CMAKE_CXX_FLAGS_RELEASE})

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
