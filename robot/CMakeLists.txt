cmake_minimum_required(VERSION 2.8.0 FATAL_ERROR)

find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIR} ${CMAKE_CURRENT_SOURCE_DIR})

#SET(BOOST_ROOT ~/projects/boost_1_59_0/)
#SET(BOOST_LIBRARYDIR ~/projects/boost_1_59_0/libs/)
#SET(Boost_INCLUDE_DIR ~/projects/boost_1_59_0/boost/)

if(CMAKE_TOOLCHAIN_FILE)
  include("${CMAKE_CURRENT_SOURCE_DIR}/libagent.cmake")
endif(CMAKE_TOOLCHAIN_FILE)

include("${CMAKE_CURRENT_SOURCE_DIR}/runswift.cmake")

if(CMAKE_TOOLCHAIN_FILE)
  include("${CMAKE_CURRENT_SOURCE_DIR}/robot.cmake")
else(CMAKE_TOOLCHAIN_FILE)
  #simrobot has been removed
endif(CMAKE_TOOLCHAIN_FILE)

include("${CMAKE_CURRENT_SOURCE_DIR}/testrunswift.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/benchrunswift.cmake")
cotire(agent robot-static runswift soccer-static soccer)
