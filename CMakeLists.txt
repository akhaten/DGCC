cmake_minimum_required(VERSION 3.16)
project(DGCC)

add_subdirectory(docs)

include_directories(
  include/
  include/Collections/
  include/Iterators/
  src/Collections/
)

set(HEADERS
  
  include/errors.h
  include/types.h

  include/Collections/stack.h
  include/Collections/queue.h
  include/Collections/list.h
  include/Collections/array.h

  include/Iterators/stackiterator.h
  include/Iterators/queueiterator.h
  include/Iterators/listiterator.h
  
  
)

set(SOURCES
  src/Collections/stack.c
  src/Collections/queue.c
  src/Collections/list.c
  src/Collections/array.c
)

add_library(${CMAKE_PROJECT_NAME}
  ${HEADERS} ${SOURCES})

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC
  "${CMAKE_CURRENT_SOURCE_DIR}/include"
  "${CMAKE_CURRENT_SOURCE_DIR}/src")









