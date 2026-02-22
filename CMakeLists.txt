cmake_minimum_required(VERSION 3.15)
project(tracker3d)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include our headers from the include/ folder
include_directories(include)

# Define the executable: name it 'tracker', built from main.cpp
add_executable(tracker src/main.cpp src/detector_sim.cpp)


