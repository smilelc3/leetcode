cmake_minimum_required(VERSION 3.14)

project(leetcode-c)

# 当前编译器ID
message(STATUS "CMAKE_C_COMPILER_ID: ${CMAKE_C_COMPILER_ID}")

# 设置 C 标准
set(CMAKE_C_STANDARD 11)

# 使用Visual Studio编译额外的修改
if ("${CMAKE_C_COMPILER_ID}" STREQUAL "MSVC")
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

# 启用对此目录及子目录的测试，该命令应位于源目录的根目录中
enable_testing()

# 启动自下载
include(FetchContent)

# FetchContent获取Unity
message(STATUS "3rd-party: start fetch ThrowTheSwitch/Unity ...")
FetchContent_Declare(Unity GIT_REPOSITORY https://hub.fastgit.org/ThrowTheSwitch/Unity.git)      # 镜像站加速
FetchContent_MakeAvailable(Unity)
message(STATUS "3rd-party: fetch ThrowTheSwitch/Unity success !")

# 设置 C 标准
set(CMAKE_C_STANDARD 11)

# 引入built-in依赖
include_directories(built-in)
add_subdirectory(built-in)

# 生成所有子目录到变量 SUBDIRS
file(GLOB SUBDIRS RELATIVE ${CMAKE_CURRENT_LIST_DIR} ${CMAKE_CURRENT_LIST_DIR}/*)
# 遍历所有子目录，如果子目录下存在同名源代码和同名-test测试代码，创建测试对象
foreach (SUBDIR ${SUBDIRS})
    # 检测test代码
    if (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${SUBDIR}/${SUBDIR}-test.c)
        message(STATUS "found target: ${SUBDIR}")
        # 编译test代码
        add_executable(${SUBDIR}-test ${SUBDIR}/${SUBDIR}-test.c)
        if ("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU" OR
            "${CMAKE_C_COMPILER_ID}" STREQUAL "Clang" OR 
            "${CMAKE_C_COMPILER_ID}" STREQUAL "AppleClang")
            # 链接math库
            target_link_libraries(${SUBDIR}-test m)
        endif ()
        # 链接built-in库
        target_link_libraries(${SUBDIR}-test built-in)
        # 链接ASan库
        target_compile_options(${SUBDIR}-test PRIVATE -fsanitize=address)
        target_link_options(${SUBDIR}-test PRIVATE -fsanitize=address)
        # 链接unity测试库
        target_link_libraries(${SUBDIR}-test unity)
        # 运行测试
        add_test(${SUBDIR}-test ${SUBDIR}-test)
    endif ()
endforeach ()
