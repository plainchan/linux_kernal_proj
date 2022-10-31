cmake_minimum_required(VERSION 3.5)

project(pthread_usage)

add_executable(${PROJECT_NAME} main.c)

target_include_directories(${PROJECT_NAME}
    PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
    pthread
)
