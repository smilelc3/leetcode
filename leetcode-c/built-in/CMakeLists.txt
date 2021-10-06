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