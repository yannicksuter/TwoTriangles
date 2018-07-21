# Projects Settings
#cmake_minimum_required (VERSION 2.8)
cmake_minimum_required(VERSION 3.10)
project (twotriangles)

# Compilation flags
list(APPEND CMAKE_CXX_FLAGS "-std=c++11")
add_definitions(-Wall)

if(NOT MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated-declarations -Wno-writable-strings -Wdelete-non-virtual-dtor")
else(NOT MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4005 /wd4305 /wd4018")
endif(NOT MSVC)

# glfw
set(GLFW_BUILD_EXAMPLES OFF CACHE STRING "" FORCE)
set(GLFW_BUILD_TESTS    OFF CACHE STRING "" FORCE)
set(GLFW_INSTALL        OFF CACHE STRING "" FORCE)
add_subdirectory(lib/glfw)
include_directories(lib/glfw/include)

# glew
add_definitions(-DGLEW_STATIC)
option(glew-cmake_BUILD_SHARED "" OFF)
add_subdirectory(lib/glew)
include_directories(lib/glew/include lib/glew/src)

# glm
include_directories(lib/glm)

# Build executable
file(GLOB_RECURSE source_files ${PROJECT_SOURCE_DIR}/src/*)
add_executable(twotriangles ${source_files})
target_link_libraries(twotriangles glfw ${GLFW_LIBRARIES} libglew_static)
