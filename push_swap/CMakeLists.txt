cmake_minimum_required(VERSION 3.0.0)
project(push_swap VERSION 0.1.0)

include(CTest)
enable_testing()

file(GLOB PROJ_SRC "*.h" "*.c")
add_executable(push_swap ${PROJ_SRC})

FIND_LIBRARY(UNIT_LIB NAMES ft PATHS /Users/jiyeolee/WORKSPACE/push_swap/Libft)
target_link_libraries(push_swap PRIVATE ${UNIT_LIB})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
