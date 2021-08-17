cmake_minimum_required(VERSION 3.5.1)

project(leetcode-c)

# 设置 C 标准
set(CMAKE_C_STANDARD 11)

# 使用Visual Studio编译额外的修改
if (MSVC)
    # MSVC默认以MD(多线程DLL)动态链接库文件，不适合本项目，替换MD为MT（多线程静态）
    set(CompilerFlags
            CMAKE_C_FLAGS
            CMAKE_C_FLAGS_DEBUG
            CMAKE_C_FLAGS_RELEASE
            CMAKE_C_FLAGS_MINSIZEREL
            CMAKE_C_FLAGS_RELWITHDEBINFO
            )
    foreach(CompilerFlag ${CompilerFlags})
        string(REPLACE "/MD" "/MT" ${CompilerFlag} "${${CompilerFlag}}")
    endforeach()
    # 指定代码文件编码格式为utf-8 (无BOM)
    add_compile_options(/utf-8)

endif()

# 启动AddressSanitizer (ASan)功能
add_compile_options(-fsanitize=address)

# 启用对此目录及子目录的测试，该命令应位于源目录的根目录中
enable_testing()

# 引入built-in依赖
include_directories(built-in)

# 添加Unity 单元测试项目
add_subdirectory(built-in/Unity-2.5.2)

# 生成所有子目录到变量 SUBDIRS
file(GLOB SUBDIRS RELATIVE ${CMAKE_CURRENT_LIST_DIR} ${CMAKE_CURRENT_LIST_DIR}/*)
# 遍历所有子目录，如果子目录下存在 CMakeLists.txt 文件，add_subdirectory
foreach (SUBDIR ${SUBDIRS})
    if (EXISTS ${CMAKE_CURRENT_LIST_DIR}/${SUBDIR}/CMakeLists.txt)
        message(STATUS "found target: ${SUBDIR}")
        add_subdirectory(${SUBDIR})
    endif ()
endforeach ()