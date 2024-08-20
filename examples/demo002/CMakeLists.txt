# 搜索源文件
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp" "src/*.h")

# 定义动态库
add_executable(demo002 ${SOURCES})
target_link_libraries(demo002 PUBLIC rendering_engine)

# set_target_properties(demo002 PROPERTIES
#     RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
# )