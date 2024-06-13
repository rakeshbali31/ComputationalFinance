cmake_minimum_required(VERSION 3.28)
project(MonteCarlo)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_library(BSModel SHARED src/BSModel.cpp)
add_library(PathDepOption SHARED src/PathDepOption.cpp)
add_library(AsianOption SHARED src/AsianOption.cpp)
add_library(EuropeanOption SHARED src/EuropeanOption.cpp)

target_link_libraries(AsianOption EuropeanOption)
target_link_libraries(PathDepOption BSModel)

add_executable(MonteCarlo main.cpp)
target_link_libraries(MonteCarlo PathDepOption AsianOption EuropeanOption)
