cmake_minimum_required(VERSION 3.5.0)
project(LearnOpenGL VERSION 0.1.0 LANGUAGES C CXX)

# 引入头文件目录
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# 搜索源码文件

file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.h")

# 指定库文件搜索目录
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/GLAD)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/GLFW)
add_executable(LearnOpenGL ${SOURCES})
target_link_libraries(LearnOpenGL glad)
target_link_libraries(LearnOpenGL glfw3)
target_link_libraries(LearnOpenGL glfw3dll)

