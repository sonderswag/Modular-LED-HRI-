cmake_minimum_required(VERSION 3.5)
include_directories ("${PROJECT_SOURCE_DIR}/../NeoPixelCodeConverter")
include_directories ("${PROJECT_SOURCE_DIR}/../LightParameter")
add_subdirectory("${PROJECT_SOURCE_DIR}/../NeoPixelCodeConverter" "${PROJECT_SOURCE_DIR}/NeoPixelCodeConverter")
add_subdirectory("${PROJECT_SOURCE_DIR}/../LightParameter" "${PROJECT_SOURCE_DIR}/LightParameter")

add_executable(neopixelexample example.cpp)
target_link_libraries (neopixelexample LightParameter NeoPixelCodeConverter)
