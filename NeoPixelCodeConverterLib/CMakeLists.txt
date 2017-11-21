cmake_minimum_required(VERSION 3.5)
include_directories ("${PROJECT_SOURCE_DIR}/NeoPixelCodeConverter")
include_directories ("${PROJECT_SOURCE_DIR}/LightParameter")
add_subdirectory (LightParameter)
add_subdirectory (NeoPixelCodeConverter)

add_executable(neopixeltest out.cpp)
target_link_libraries (neopixeltest LightParameter NeoPixelCodeConverter)
