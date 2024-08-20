cmake_minimum_required(VERSION 3.5...3.21)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(LearnOpenGL VERSION 0.1.0 LANGUAGES C CXX)

# 设置动态库和可执行文件的输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 添加GLAD库
add_library(glad SHARED extern/glad/src/glad.c)
target_include_directories(glad PUBLIC extern/glad/include)

# 添加第三方库
set(BUILD_SHARED_LIBS ON)
add_subdirectory(extern/glfw)
add_subdirectory(extern/glm)

# 添加子目录
add_subdirectory(src)
add_subdirectory(examples)

# install(TARGETS rendering_engine DESTINATION lib)
# install(DIRECTORY include/rendering_engine DESTINATION include)