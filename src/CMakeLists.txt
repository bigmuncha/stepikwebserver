cmake_minimum_required(VERSION 2.8)

project(webserv)

set(SOURCE_EXE main.cpp)

set(STRINGTREAT_LIB stringtreat.cpp)

set(PARSER_LIB parser.cpp)

add_library(stringtreat ${STRINGTREAT_LIB})
add_library(parser ${PARSER_LIB})

find_package(Boost 1.75.0 REQUIRED COMPONENTS  filesystem thread)
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})

  add_executable(main ${SOURCE_EXE})

  target_link_libraries(main stringtreat  parser ${Boost_LIBRARIES})
endif()
