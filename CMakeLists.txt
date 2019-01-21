cmake_minimum_required(VERSION 3.0.0)
project(camera)
find_package( OpenCV REQUIRED )

add_executable(camera camera.cpp)

target_link_libraries(camera ${OpenCV_LIBS})