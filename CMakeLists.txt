cmake_minimum_required(VERSION 3.0.0)
project(group_data)

add_subdirectory(group_data_lib)

message("GROUP_DATA_LIB_INCLUDE_DIRS = ${GROUP_DATA_LIB_INCLUDE_DIRS}")
message("GROUP_DATA_LIB_LIBRARIES = ${GROUP_DATA_LIB_LIBRARIES}")

add_executable(${PROJECT_NAME} main.c)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov")

target_include_directories(${PROJECT_NAME} PUBLIC ${GROUP_DATA_LIB_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${GROUP_DATA_LIB_LIBRARIES})

add_subdirectory(tests)
