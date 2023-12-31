
cmake_minimum_required(VERSION 3.13.4)

project(ping-pong)
set(CMAKE_CXX_STANDARD 11)

file(GLOB SOURCES "*.cpp")
add_executable(ping-pong ${SOURCES} glad.c)
include_directories(include)

target_include_directories(${PROJECT_NAME} PUBLIC "/usr/local/include/")
target_link_libraries(${PROJECT_NAME} "/usr/local/lib/libglfw.3.3.dylib")
target_link_libraries(${PROJECT_NAME} "/usr/local/lib/libassimp.5.3.0.dylib")
