
# 创建静态库 (或动态库，如果需要)
add_library(application STATIC application.cpp)

# 将 application 目录的头文件路径设置为 PUBLIC，使主项目也可以访问
target_include_directories(application PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
