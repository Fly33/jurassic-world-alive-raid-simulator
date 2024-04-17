cmake_minimum_required(VERSION 3.10)
project(JWAcalc)

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    message(FATAL_ERROR "Visual Studio is not supported.")
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall -fmessage-length=0 -fopenmp")

add_executable(JWAcalc
    logger.cpp
    strprintf.cpp
    input.cpp
    arguments.cpp
    utils.cpp
    JWAcalc.cpp
    dex.cpp
    stats.cpp
    expression.cpp
    ability.cpp
    modifiers.cpp
    dino.cpp
    actions.cpp
)

target_link_libraries(JWAcalc -static -static-libstdc++ -static-libgcc -Wl,--whole-archive -lpthread -Wl,--no-whole-archive -fopenmp)
