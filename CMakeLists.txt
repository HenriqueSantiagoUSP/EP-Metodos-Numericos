cmake_minimum_required(VERSION 3.10)
project(EP C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)

set(SOURCES
    src/random.c
    src/ep_tarefa1.c
    src/ep_tarefa2.c
    src/ep_tarefa3.c
    src/ep_tarefa4.c
    src/ep_tarefa5.c
)

# executável principal 
add_executable(ep
    src/ep.c
    ${SOURCES}
)

add_executable(test_ep_tarefa1
    tests/test_ep_tarefa1.c
    ${SOURCES}
)

add_executable(test_ep_tarefa2
    tests/test_ep_tarefa2.c
    ${SOURCES}
)

add_executable(test_ep_tarefa3
    tests/test_ep_tarefa3.c
    ${SOURCES}
)

add_executable(test_ep_tarefa4
    tests/test_ep_tarefa4.c
    ${SOURCES}
)

add_executable(test_ep_tarefa5
    tests/test_ep_tarefa5.c
    ${SOURCES}
)

add_compile_definitions(RESOURCES_DIR="${CMAKE_SOURCE_DIR}/resources/")

target_link_libraries(ep m)
target_link_libraries(test_ep_tarefa1 m)
target_link_libraries(test_ep_tarefa2 m)
target_link_libraries(test_ep_tarefa3 m)
target_link_libraries(test_ep_tarefa4 m)
target_link_libraries(test_ep_tarefa5 m)