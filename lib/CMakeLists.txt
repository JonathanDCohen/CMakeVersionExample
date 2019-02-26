cmake_minimum_required(VERSION 3.5)
project(lib)
add_library(lib STATIC lib.h lib.cc)
target_compile_features(lib PRIVATE cxx_std_11)
