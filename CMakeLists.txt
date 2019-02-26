cmake_minimum_required(VERSION 3.5)

project(version)

message(STATUS "Compiler: ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS "Standard: ${CMAKE_CXX_STANDARD}")

add_subdirectory(lib)

add_executable(version version.cc)
target_link_libraries(version lib)
