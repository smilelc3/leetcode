cmake_minimum_required(VERSION 3.16)

project(built-in)

aux_source_directory(. DIR_BUILT_IN_SRCS)
add_library(built-in STATIC ${DIR_BUILT_IN_SRCS})


