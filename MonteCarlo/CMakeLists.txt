cmake_minimum_required(VERSION 3.28)
project(MonteCarlo)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_library(BSModel SHARED src/BSModel.cpp)
add_library(PathDepOption SHARED src/PathDepOption.cpp)
add_library(ArithmeticAsianCall SHARED src/ArithmeticAsianCall.cpp)
add_library(GeometricAsianCall SHARED src/GeometricAsianCall.cpp)

target_link_libraries(PathDepOption BSModel)

add_executable(MonteCarlo main.cpp)
target_link_libraries(MonteCarlo PathDepOption ArithmeticAsianCall GeometricAsianCall)
