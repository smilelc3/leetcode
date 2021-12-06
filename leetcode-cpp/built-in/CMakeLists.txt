# project名
project(built-in)

# 设置 C 标准
set(CMAKE_C_STANDARD 11)

# 将.（当前文件夹）下编译用的源文件添加到一个宏列表中
aux_source_directory(. BUILT_IN_SRCS)

# 除去测试代码
list(REMOVE_ITEM BUILT_IN_SRCS ./built-in-test.c)

# 将指定的源文件生成链接文件，然后添加到工程中
add_library(built-in STATIC ${BUILT_IN_SRCS})

# built-in 对象添加头
target_include_directories(built-in PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/)