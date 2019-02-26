cmake_minimum_required(VERSION 3.5)

project(version)

message(STATUS "Compiler: ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS "CMAKE_CXX_STANDARD: ${CMAKE_CXX_STANDARD}")

add_subdirectory(lib)

add_executable(version version.cc)
target_link_libraries(version lib)

add_executable(version_with_requirements version.cc)
target_link_libraries(version_with_requirements lib)
target_compile_features(version_with_requirements PUBLIC cxx_std_11)
