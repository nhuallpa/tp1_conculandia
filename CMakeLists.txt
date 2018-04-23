cmake_minimum_required(VERSION 3.9)
project(tp1_conculandia)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
        )


add_subdirectory("${PROJECT_SOURCE_DIR}/Util")
add_subdirectory("${PROJECT_SOURCE_DIR}/Fifos")
add_subdirectory("${PROJECT_SOURCE_DIR}/Modelo")

add_executable(tp1_conculandia ${SOURCE} ${HEADERS})
