cmake_minimum_required(VERSION 2.6)

# Project name and version
project(gpio_driver)

# Add the subdirectory for source files
add_subdirectory(src)

# Include directories for headers
include_directories(${PROJECT_SOURCE_DIR}/include)

# Define version information
set(MAJOR "0")
set(MINOR "1")
set(PATCH "1")

# Configure packaging using CPack
set(CPACK_SOURCE_GENERATOR "TGZ")
set(CPACK_SOURCE_PACKAGE_FILE_NAME "${CMAKE_PROJECT_NAME}-${MAJOR}.${MINOR}.${PATCH}")
set(CPACK_SOURCE_IGNORE_FILES "/build/;${CPACK_SOURCE_IGNORE_FILES}")
include(CPack)
