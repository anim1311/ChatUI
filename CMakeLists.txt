cmake_minimum_required(VERSION 3.5)
project(IMGUI_GLFW_OPENGL3)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/imgui)
include_directories(${CMAKE_SOURCE_DIR}/imgui/backends)
include_directories(${CMAKE_SOURCE_DIR}/src)

# Source files
file(GLOB SOURCES
     main.cpp
     ${CMAKE_SOURCE_DIR}/imgui/*.cpp
     ${CMAKE_SOURCE_DIR}/imgui/backends/*.cpp
     ${CMAKE_SOURCE_DIR}/src/*.cpp)

# Define the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Find and link GLFW
find_package(glfw3 REQUIRED)
target_link_libraries(${PROJECT_NAME} glfw)

# Platform-specific configurations
if(APPLE)
    find_library(OpenGL_LIBRARY OpenGL)
    find_library(COCOA_LIBRARY Cocoa)
    find_library(IOKIT_LIBRARY IOKit)
    find_library(COREVIDEO_LIBRARY CoreVideo)
    target_link_libraries(${PROJECT_NAME} ${OpenGL_LIBRARY} ${COCOA_LIBRARY} ${IOKIT_LIBRARY} ${COREVIDEO_LIBRARY} glfw)
elseif(UNIX AND NOT APPLE)
    find_package(OpenGL REQUIRED)
    target_link_libraries(${PROJECT_NAME} ${OPENGL_gl_LIBRARY} glfw)
elseif(WIN32)
    target_link_libraries(${PROJECT_NAME} glfw3 gdi32 opengl32 imm32)
endif()
