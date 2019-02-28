SET(MCU "atmega324pa")
SET(F_CPU "8000000")
SET(CMAKE_SYSTEM_NAME Generic)
cmake_minimum_required(VERSION 3.6)   # CMake version check
set(CMAKE_CXX_STANDARD 11)


# For some reason, these paths have to be absolute, otherwise
# CLion won't be able to find headers etc.
SET(CMAKE_C_COMPILER /usr/bin/avr-gcc)

SET(CMAKE_CXX_COMPILER /usr/bin/avr-gcc)

SET(CMAKE_C_FLAGS "-MMD -mmcu=${MCU} -DF_CPU=${F_CPU} -Os -I /usr/avr/include")
SET(CMAKE_C_LINK_FLAGS "-mmcu=${MCU}")

project(main)



file(GLOB_RECURSE sourceFiles "*.cpp")


