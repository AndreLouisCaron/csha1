#
# Secure hash algorithm (SHA-1) implementation in C.
#

cmake_minimum_required(VERSION 2.6)

project(csha1)

  # base paths to source files.
set(code_path ${CMAKE_CURRENT_SOURCE_DIR}/code)
set(demo_path ${CMAKE_CURRENT_SOURCE_DIR}/demo)

  # core library and c++ wrappers.
file(GLOB code_headers ${code_path}/*.h ${code_path}/*.hpp)
file(GLOB code_sources ${code_path}/*.c ${code_path}/*.cpp)
add_library(sha1
  STATIC ${code_sources} ${code_headers})

  # build demo programs on standalone build.
if(${PROJECT_NAME} STREQUAL ${CMAKE_PROJECT_NAME})

  include_directories(${code_path})

  add_executable(demo ${demo_path}/demo.cpp)
  target_link_libraries(demo sha1)
  add_dependencies(demo sha1)

  add_executable(sha ${demo_path}/sha.cpp)
  target_link_libraries(sha sha1)
  add_dependencies(sha sha1)

endif()
