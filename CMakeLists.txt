cmake_minimum_required(VERSION 2.8)

project(webserv)

set(SOURCE_EXE main.cpp)

set(STRINGTREAT_LIB stringtreat.cpp)
set(CLIENTHANDLER_LIB client_handler.cpp)

set(PARSER_LIB parser.cpp)

add_library(stringtreat ${STRINGTREAT_LIB})
add_library(parser ${PARSER_LIB})
add_library(client_handler ${CLIENTHANDLER_LIB})


add_executable(final ${SOURCE_EXE})
target_link_libraries(final client_handler stringtreat  parser )
