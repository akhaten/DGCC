cmake_minimum_required(VERSION 3.16)

project(DGCC)

add_subdirectory(docs)

include_directories(
  headers/Collection/)

add_library(${CMAKE_PROJECT_NAME}
  headers/Collection/stack.h
  src/Collection/stack.c
  headers/Collection/list.h
  src/Collection/list.c)

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC
  "${CMAKE_CURRENT_SOURCE_DIR}/headers"
  "${CMAKE_CURRENT_SOURCE_DIR}/src")

