cmake_minimum_required(VERSION 2.8)

project(webserv)

set(SOURCE_EXE main.cpp)

set(STRINGTREAT_LIB stringtreat.cpp)
set(CLIENTHANDLER_LIB client_handler.cpp)

set(PARSER_LIB parser.cpp)

add_library(stringtreat ${STRINGTREAT_LIB})
add_library(parser ${PARSER_LIB})
add_library(client_handler ${CLIENTHANDLER_LIB})

find_package(Boost REQUIRED COMPONENTS  filesystem thread system)
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})

  add_executable(final ${SOURCE_EXE})

  target_link_libraries(final client_handler stringtreat  parser ${Boost_LIBRARIES})
endif()
