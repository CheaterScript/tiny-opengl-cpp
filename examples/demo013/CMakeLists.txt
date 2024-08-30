# 搜索源文件
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp" "src/*.h")

# 定义动态库
add_executable(demo013 ${SOURCES})
target_link_libraries(demo013 PUBLIC rendering_engine)