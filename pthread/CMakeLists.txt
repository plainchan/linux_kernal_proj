cmake_minimum_required(VERSION 3.5)

project(pthread_usage)

add_executable(${PROJECT_NAME} main.c)

target_include_directories(${PROJECT_NAME}
    PRIVATE
    INCLUDE
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
    pthread
)
