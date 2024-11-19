# Include the include directory for header files
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)

# Define the library
add_library(gpio_lib gpio.c)

# Define the executable
add_executable(gpio_tester gpio_tester.c)

# Link the library to the executable
target_link_libraries(gpio_tester gpio_lib)

# Install the library in the lib directory
install(TARGETS gpio_lib DESTINATION lib)

# Install the executable in the bin directory
install(TARGETS gpio_tester DESTINATION bin)

# Install the header files in the include directory
set(INCLUDE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/../include/gpio.h)
install(FILES ${INCLUDE_FILES} DESTINATION include)
