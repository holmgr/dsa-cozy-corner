cmake_minimum_required(VERSION 2.8.2)

project(DSA)

include(CTest)

if (CMAKE_VERSION VERSION_LESS 3.2)
  set(UPDATE_DISCONNECTED_IF_AVAILABLE "")
else()
  set(UPDATE_DISCONNECTED_IF_AVAILABLE "UPDATE_DISCONNECTED 1")
endif()

include(DownloadProject.cmake)
      download_project(PROJ                googletest
      GIT_REPOSITORY      https://github.com/google/googletest.git
      GIT_TAG             master
      ${UPDATE_DISCONNECTED_IF_AVAILABLE}
)

# Specify the minimum version for CMake

cmake_minimum_required(VERSION 2.8)

# Project's name

project(dsa)
# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(PROJECT_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)

# The following folder will be included
include_directories("${PROJECT_SOURCE_DIR}")

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})

# When using CMake 2.8.11 or later, header path dependencies
# are automatically added to the gtest and gmock targets.
# For earlier CMake versions, we have to explicitly add the
# required directories to the header search path ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include"
  "${gmock_SOURCE_DIR}/include")
endif()

# Trivial example using gtest and gmock
add_executable(example ${PROJECT_SOURCE_DIR}/example.cpp)
target_link_libraries(example gtest gmock_main)
add_test(NAME example_test COMMAND example)
