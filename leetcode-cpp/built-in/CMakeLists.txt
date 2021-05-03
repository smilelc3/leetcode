cmake_minimum_required(VERSION 3.5.1)

project(built-in)

aux_source_directory(. DIR_BUILT_IN_SRCS)
add_library(built-in STATIC ${DIR_BUILT_IN_SRCS})


