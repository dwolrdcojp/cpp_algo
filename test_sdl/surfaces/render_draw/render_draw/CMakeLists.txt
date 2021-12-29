cmake_minimum_required(VERSION 3.22.1)

#set the project name
project(prog)

find_package(SDL2 REQUIRED)
include_directories("/Users/max/Library/Frameworks/SDL2.framework/")
#add the executable
add_executable(prog main.cpp)
target_link_libraries(prog "/Users/max/Library/Frameworks/SDL2.framework/Versions/A/SDL2")
# target_include_directories(prog PUBLIC "/Users/max/Library/Frameworks/SDL2.framework/Headers")
#specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
