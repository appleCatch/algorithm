#CMake最低版本号要求
cmake_minimum_required(VERSION 3.12)
#项目信息
project(algorithm)
#使用C++ 11标准
set(CMAKE_CXX_STANDARD 11)
#指定生成目标
#add_executable(algorithm)

# Add the source in project root directory
aux_source_directory(./src DIRSRCS)
# Add header file include directories
include_directories(./src ./src/aimtoffer ./src/chapter_3 ./src/test)
# Add block directories
add_subdirectory(src/aimtoffer)
add_subdirectory(src/chapter_3)
add_subdirectory(src/test)

# Target
add_executable(algorithm ${DIRSRCS} src/main.cpp)
target_link_libraries(algorithm src/aimtoffer src/chapter_3 src/test)