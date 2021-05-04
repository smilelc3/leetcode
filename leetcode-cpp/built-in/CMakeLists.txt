cmake_minimum_required(VERSION 3.5.1)

project(built-in)

# 将.（当前文件夹）下编译用的源文件添加到一个宏列表中
aux_source_directory(. DIR_BUILT_IN_SRCS)
# 将指定的源文件生成链接文件，然后添加到工程中
add_library(built-in STATIC ${DIR_BUILT_IN_SRCS})


