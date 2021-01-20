cmake_minimum_required(VERSION 3.10)

project(webserv)

set(SOURCE_EXE server.cpp)

set(SOURCE_LIB stringtreat.cpp)

add_library(stringtreat ${SOURCE_LIB})

find_package(Boost 1.75.0 REQUIRED COMPONENTS  filesystem thread)
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})

  add_executable(server ${SOURCE_EXE})

  target_link_libraries(server stringtreat ${Boost_LIBRARIES})
endif()
