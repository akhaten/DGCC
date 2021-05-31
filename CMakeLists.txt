cmake_minimum_required(VERSION 3.16)

project(DGCC)

add_subdirectory(docs)

include_directories(
  headers/Collection/)

set(headers
    headers/Collection/stack.h
    headers/Collection/queue.h
    headers/Collection/list.h)

set(sources
    src/Collection/stack.c
    src/Collection/queue.c
    src/Collection/list.c)
    
add_library(${CMAKE_PROJECT_NAME} ${headers} ${sources})

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC
  "${CMAKE_CURRENT_SOURCE_DIR}/headers"
  "${CMAKE_CURRENT_SOURCE_DIR}/src")

