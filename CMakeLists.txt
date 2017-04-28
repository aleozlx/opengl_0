cmake_minimum_required(VERSION 2.6)
project(opengl_0)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${opengl_0_SOURCE_DIR}/cmake_scripts")

find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)

set(CMAKE_CXX_FLAGS "-std=c++11 --pedantic-errors -Wall -Wextra")

add_executable(opengl_0 main.cpp)
set(LIBRARIES ${SDL2_LIBRARY} ${OPENGL_LIBRARY} ${CMAKE_DL_LIBS})
target_link_libraries(opengl_0 ${LIBRARIES})

install(TARGETS opengl_0 RUNTIME DESTINATION bin)
