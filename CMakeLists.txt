cmake_minimum_required(VERSION 3.19.2)
project(philosophers C)

set(CMAKE_C_STANDARD 99)

FILE(GLOB PHILO_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/*.h
        ${CMAKE_CURRENT_SOURCE_DIR}/*.c
        )
list(FILTER PHILO_SOURCES EXCLUDE REGEX "${CMAKE_CURRENT_SOURCE_DIR}/main_test.c")
list(FILTER PHILO_SOURCES EXCLUDE REGEX "${CMAKE_CURRENT_SOURCE_DIR}/utils_test.c")
list(FILTER PHILO_SOURCES EXCLUDE REGEX "${CMAKE_CURRENT_SOURCE_DIR}/philo_test.h")
list(FILTER PHILO_SOURCES EXCLUDE REGEX "${CMAKE_CURRENT_SOURCE_DIR}/sandbox.c")

message(STATUS ${PHILO_SOURCES})

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pthread")

add_executable(philosophers
        ${PHILO_SOURCES})
#target_compile_options(philosophers PRIVATE
#        -pthread)

