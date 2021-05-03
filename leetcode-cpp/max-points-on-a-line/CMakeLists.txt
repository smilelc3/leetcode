# only for cmake --version >= 3.5.1
cmake_minimum_required(VERSION 3.5.1)

# 创建EXEC变量，可以用${EXEC}获取
set(EXEC max-points-on-a-line)
# project名
project(${EXEC})
# 设置 C++14 标准
set(CMAKE_CXX_STANDARD 14)
# Google Test/Benchmark 需要 Threads 库支持
find_package(Threads REQUIRED)


# 编译test代码
add_executable(${EXEC} max-points-on-a-line-test.cpp)
target_link_libraries(${EXEC} gtest ${CMAKE_THREAD_LIBS_INIT})
# 添加built-in库依赖
target_link_libraries(${EXEC} built-in)
# 运行测试
add_test(${EXEC} ${EXEC})



# 编译benchmark代码
add_executable(${EXEC}-benchmark ${EXEC}-benchmark.cpp)
# 添加 google benchmark 依赖
target_link_libraries(${EXEC}-benchmark benchmark)
# 添加built-in库依赖
target_link_libraries(${EXEC} built-in)
