cmake_minimum_required(VERSION 3.12)

project(PfauenhofProject)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)


# Define the source files
set(SOURCES
    src/main.cpp
    src/postgress.cpp
)

# Include directories
include_directories(header)

# Create an executable target
add_executable(pfauenhof ${SOURCES})

# Link necessary libraries
target_link_libraries(pfauenhof
    -lpqxx
    -lpq
    # Other libraries (if needed)
)

# Set the output directory for the executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


