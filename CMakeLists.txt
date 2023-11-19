cmake_minimum_required(VERSION 3.25)
project(PEA1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

add_executable(PEA1 main.cpp FileReader.cpp FileReader.h Randomizer.cpp Randomizer.h Matrix.cpp Matrix.h TSPBruteForce.cpp TSPBruteForce.h Timer.cpp Timer.h BranchAndBound.cpp BranchAndBound.cpp BranchAndBound.h Cmp.h Node.cpp Node.h Tests.cpp Tests.h Menu.cpp Menu.h FileWriter.cpp FileWriter.h)
