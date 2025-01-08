cmake_minimum_required(VERSION 3.10)
project(CitiesProject)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the source files
set(SOURCES
    main.cpp
    City.cpp
    CityManager.cpp
    Coordinates.cpp
    LinkedList.h
    Node.h
    Utility.h
)

# Add the executable
add_executable(CitiesProject ${SOURCES})
