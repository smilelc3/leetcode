cmake_minimum_required(VERSION 3.5.1)

# 获取当前目录到变量 CURRENT_FOLDER
string(REGEX REPLACE ".*/\(.*\)" "\\1" CURRENT_FOLDER ${CMAKE_CURRENT_SOURCE_DIR})

# project名
project(${CURRENT_FOLDER})

# 设置 C 标准
set(CMAKE_C_STANDARD 11)

# 将.（当前文件夹）下编译用的源文件添加到一个宏列表中
aux_source_directory(. DIR_BUILT_IN_SRCS)

# 除去测试代码
list(REMOVE_ITEM DIR_BUILT_IN_SRCS ./${CURRENT_FOLDER}-test.c)
# 将指定的源文件生成链接文件，然后添加到工程中
add_library(built-in STATIC ${DIR_BUILT_IN_SRCS})



# 检测test代码
if (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${CURRENT_FOLDER}-test.c)
    # 编译test代码
    add_executable(${CURRENT_FOLDER}-test ${CURRENT_FOLDER}-test.c)
    # 链接unity测试库
    target_link_libraries(${CURRENT_FOLDER}-test unity)
    if (NOT MSVC)
        # 链接ASan库，用作内存检查
        target_link_libraries(${CURRENT_FOLDER}-test asan)
        # 链接math库
        target_link_libraries(${CURRENT_FOLDER}-test m)
    endif ()
    # 链接built-in库
    target_link_libraries(${CURRENT_FOLDER}-test built-in)
    # 运行测试
    add_test(${CURRENT_FOLDER} ${CURRENT_FOLDER}-test)
else ()
    message(STATUS "${CMAKE_CURRENT_SOURCE_DIR}/${CURRENT_FOLDER}-test.c source file not found! -> skip test")
endif ()

