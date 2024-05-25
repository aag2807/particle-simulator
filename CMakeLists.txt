cmake_minimum_required(VERSION 3.28)
project(Particles_test)

set(CMAKE_CXX_STANDARD 17)

# Find SFML package
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Add the source files
add_executable(Particles_test main.cpp
        Particle.cpp
        Particle.h
        ParitcleSimulator.cpp
        ParitcleSimulator.h)

# Link SFML libraries
target_link_libraries(Particles_test sfml-graphics sfml-window sfml-system)
