cmake_minimum_required(VERSION 3.5)

project(pipe_usage)

add_executable(${PROJECT_NAME} main.c)

target_include_directories(${PROJECT_NAME}
    PRIVATE
    INCLUDE
)

