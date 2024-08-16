# 搜索源文件
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "*.cpp" "*.h")

# 定义动态库
add_library(rendering_engine SHARED ${SOURCES})
target_include_directories(rendering_engine PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(rendering_engine PUBLIC ${PROJECT_SOURCE_DIR}/extern/stb)
target_link_libraries(rendering_engine PUBLIC glfw glad)