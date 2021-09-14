cmake_minimum_required(VERSION 3.20)
project(philo_bonus C)

set(CMAKE_C_STANDARD 99)

add_executable(philo_bonus
        main.c
        life_cycle.c
        parser.c
        philo.c
        utils.c
        utils_part_two.c
        philo.h)
