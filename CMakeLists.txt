cmake_minimum_required(VERSION 3.16)
project(DGCC)


include_directories(
  include/
  include/Collections/
  include/Iterators/
  src/Collections/
)

set(STACK
  include/includes.h
  include/Collections/stack.h
  include/Iterators/stackiterator.h
  src/Collections/stack.c)

set(QUEUE
  include/includes.h
  include/Collections/queue.h
  include/Iterators/queueiterator.h
  src/Collections/queue.c)

set(LIST
  include/includes.h
  include/Collections/list.h
  include/Iterators/listiterator.h
  src/Collections/list.c)

add_library(${CMAKE_PROJECT_NAME}
  ${STACK} ${QUEUE} ${LIST})

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC
  "${CMAKE_CURRENT_SOURCE_DIR}/include"
  "${CMAKE_CURRENT_SOURCE_DIR}/src")









