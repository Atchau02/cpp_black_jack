cmake_minimum_required(VERSION 3.20)
project(blackjack VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(blackjack ${SOURCES})

target_include_directories(blackjack PRIVATE ${CMAKE_SOURCE_DIR}/include)
