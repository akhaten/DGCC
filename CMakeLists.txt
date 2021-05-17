cmake_minimum_required(VERSION 3.16)

project(DGCC)

set(NAME_LIB "DGCC")

add_subdirectory(docs)

include_directories(
  headers/Stack/)

add_library(${NAME_LIB}
  headers/Stack/stack.h
  src/Stack/stack.c)

target_include_directories(${NAME_LIB} PUBLIC
  "${CMAKE_CURRENT_SOURCE_DIR}/headers"
  "${CMAKE_CURRENT_SOURCE_DIR}/src")

