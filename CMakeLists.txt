cmake_minimum_required(VERSION 3.19)
project(semana3)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory (matplotplusplus)

add_executable(semana3 main.cpp)

target_link_libraries (semana3 PUBLIC matplot)

# TODO: Add tests and install targets if needed.
