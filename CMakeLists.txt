cmake_minimum_required(VERSION 2.8.6 FATAL_ERROR)

set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake")
include(cotire)

add_definitions(-Wall)
#add_definitions(-Wall -Werror)

# Keep build process generic for v[34]
message("Toolchain File: ${CMAKE_TOOLCHAIN_FILE}")
if(CMAKE_TOOLCHAIN_FILE)
    # this stuff doesn't work in the toolchain file
    message("Toolchain Location: ${_CMAKE_TOOLCHAIN_LOCATION}")
    message("Toolchain prefix: ${_CMAKE_TOOLCHAIN_PREFIX}")
    message("CTC_DIR: ${CTC_DIR}")
    add_definitions(-DCROSS_COMPILING_FOR_ROBOT)
    if(${CTC_DIR} MATCHES geode)
        message("Nao v3 geode build detected")
        add_definitions(-march=geode -mtune=geode)
    elseif(${CTC_DIR} MATCHES atom)
        message("Nao v4 atom build detected")
        if(${CTC_DIR} MATCHES 1.12)
            add_definitions(-march=core2 -mtune=pentium -mfpmath=sse)
        else(${CTC_DIR} MATCHES 1.12)
            add_definitions(-march=atom -mtune=atom)
        endif(${CTC_DIR} MATCHES 1.12)
    else(${CTC_DIR} MATCHES geode)
        message(FATAL_ERROR "Unknown CTC_DIR")
    endif(${CTC_DIR} MATCHES geode)
    set(CMAKE_C_FLAGS   "--sysroot=${CTC_DIR}/sysroot ${CMAKE_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "--sysroot=${CTC_DIR}/sysroot ${CMAKE_CXX_FLAGS}")
else(CMAKE_TOOLCHAIN_FILE)
    message(WARNING "Toolchain not set, so not cross-compiling.")
    add_definitions(-DNATIVE_COMPILING_FOR_SIMULATION)
endif(CMAKE_TOOLCHAIN_FILE)

if(EXCL_OPENGL)
    add_definitions(-DEXCL_OPENGL)
    message("Excluding OpenGL features")
else(EXCL_OPENGL)
    message("Including OpenGL features")
endif(EXCL_OPENGL)

include("${CMAKE_CURRENT_SOURCE_DIR}/bootstrap.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/bootstrap-eigen.cmake")

add_subdirectory(robot)
add_subdirectory(utils)
