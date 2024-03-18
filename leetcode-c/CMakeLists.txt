cmake_minimum_required(VERSION 3.14)

project(leetcode-c)

# 当前cmake版本
message(STATUS "CMAKE_VERSION: ${CMAKE_VERSION}")

# 开启 warning as error
if (${CMAKE_VERSION} VERSION_GREATER_EQUAL "3.24")
    set(CMAKE_COMPILE_WARNING_AS_ERROR ON)  # New in cmake version 3.24
endif ()

# 当前编译器ID
message(STATUS "CMAKE_C_COMPILER_ID: ${CMAKE_C_COMPILER_ID}")

set(CMAKE_VERBOSE_MAKEFILEON ON)

# 设置 C11 标准
set(CMAKE_C_STANDARD 11)

# 使用Visual Studio编译额外的修改
if ("${CMAKE_C_COMPILER_ID}" STREQUAL "MSVC")
    # 指定使用math库中的定义宏
    add_compile_definitions(_USE_MATH_DEFINES)
    # CRT不安全函数版本不做告警
    add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
    # 指定代码文件编码格式为utf-8 (无BOM)
    add_compile_options(/utf-8)
endif ()

# 检查编译器是否支持ASAN
include(CheckCCompilerFlag)
list(APPEND CMAKE_REQUIRED_LINK_OPTIONS "-fsanitize=address")
check_c_compiler_flag("-fsanitize=address" COMPILER_SUPPORTS_ASAN)

# 检查是否需要链接math库
check_c_compiler_flag("-lm" NEED_LINK_MATH)

# 引入built-in依赖
add_subdirectory(built-in)

# 启用对此目录及子目录的测试，该命令应位于源目录的根目录中
enable_testing()

# 启动自下载
include(FetchContent)

# FetchContent获取uthash
message(STATUS "3rd-party: start fetch troydhanson/uthash...")
FetchContent_Declare(
        uthash
        GIT_REPOSITORY https://github.com/troydhanson/uthash.git
        GIT_TAG master
)
FetchContent_Populate(uthash)
include_directories(${uthash_SOURCE_DIR}/src/)
message(STATUS "3rd-party: fetch troydhanson/uthash success!")


# FetchContent获取Unity
message(STATUS "3rd-party: start fetch ThrowTheSwitch/Unity...")
FetchContent_Declare(
        Unity
        GIT_REPOSITORY https://github.com/ThrowTheSwitch/Unity.git
        GIT_TAG master
)
FetchContent_MakeAvailable(Unity)
target_compile_definitions(unity PUBLIC UNITY_INCLUDE_DOUBLE)  # 允许使用double类型
if ("${CMAKE_C_COMPILER_ID}" STREQUAL "MSVC")
    target_compile_options(unity PRIVATE /wd5045)   # MSVC会报Spectre缓解漏洞告警，第三方忽略
endif ()
message(STATUS "3rd-party: fetch ThrowTheSwitch/Unity success!")


# FetchContent获取ubench.h
message(STATUS "3rd-party: start fetch sheredom/ubench.h...")
FetchContent_Declare(
        ubench.h
        GIT_REPOSITORY https://github.com/sheredom/ubench.h.git
        GIT_TAG master
)
FetchContent_Populate(ubench.h)
message(STATUS "3rd-party: include ubench.h to project...")
include_directories(${ubench.h_SOURCE_DIR}/)
message(STATUS "3rd-party: fetch sheredom/ubench.h success!")

# 生成所有子目录到变量 SUBDIRS
file(GLOB SUBDIRS RELATIVE ${CMAKE_CURRENT_LIST_DIR} ${CMAKE_CURRENT_LIST_DIR}/*)
# 遍历所有子目录，如果子目录下存在同名源代码和同名-test单元测试代码或者-benchmark性能测试代码，创建测试对象
foreach (SUBDIR ${SUBDIRS})
    # 检测test代码
    if (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${SUBDIR}/${SUBDIR}-test.c)
        message(STATUS "found unit test target: ${SUBDIR}-test")
        # 编译test代码
        add_executable(${SUBDIR}-test ${SUBDIR}/${SUBDIR}-test.c)
        # 链接ASAN库
        if (COMPILER_SUPPORTS_ASAN)
            target_compile_options(${SUBDIR}-test PRIVATE -fsanitize=address)
            target_link_options(${SUBDIR}-test PRIVATE -fsanitize=address)
        endif ()
        if (NEED_LINK_MATH) # 链接math库
            target_link_libraries(${SUBDIR}-test m)
        endif ()
        # 链接built-in库
        target_link_libraries(${SUBDIR}-test built-in)
        # 链接unity测试库
        target_link_libraries(${SUBDIR}-test unity)
        # 运行测试
        add_test(${SUBDIR}-test ${SUBDIR}-test)
    endif ()
    # 检测benchmark代码
    if (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${SUBDIR}/${SUBDIR}-benchmark.c)
        message(STATUS "found benchmark target: ${SUBDIR}-benchmark")
        # 编译benchmark代码
        add_executable(${SUBDIR}-benchmark ${SUBDIR}/${SUBDIR}-benchmark.c)
        if (NEED_LINK_MATH) # 链接math库
            target_link_libraries(${SUBDIR}-benchmark m)
        endif ()
        # 链接built-in库
        target_link_libraries(${SUBDIR}-benchmark built-in)
        # 运行测试
        add_test(${SUBDIR}-benchmark ${SUBDIR}-benchmark)
    endif ()
endforeach ()
