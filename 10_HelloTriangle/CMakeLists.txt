cmake_minimum_required(VERSION 3.10)
project(HelloTriangle)

set(CMAKE_CXX_STANDARD 11)

add_definitions(-DDEBUG)

# 添加 GLAD
# add_library(glad src/glad.c)
include_directories(
    SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/thirdParty/include
)
link_directories(
	SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/thirdParty/lib
)

add_subdirectory(wrapper)
add_subdirectory(application)

# 查找 GLFW
# find_package(OpenGL REQUIRED)
# find_package(glfw3 REQUIRED)

# 添加可执行文件
add_executable(HelloTriangle src/main.cpp src/glad.c)
 
# 链接库
target_link_libraries(HelloTriangle wrapper glfw.3.dylib application)
