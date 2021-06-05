cmake_minimum_required(VERSION 3.17)
project("Tarea III")
set(CMAKE_CXX_STANDARD 20)

include_directories(src)

add_executable(paritycheck
        "src/parity check.cpp"
        )
add_executable(LRC
        "src/Longitudinal Redundancy Check .cpp"
        )
add_executable(hammingcode
        "src/Hamming Code.cpp"
        )