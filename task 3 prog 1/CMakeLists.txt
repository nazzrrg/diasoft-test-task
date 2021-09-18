include(FetchContent)

FetchContent_Declare(json
        GIT_REPOSITORY https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent
        GIT_TAG v3.7.3)

FetchContent_GetProperties(json)
if(NOT json_POPULATED)
    FetchContent_Populate(json)
    add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

cmake_minimum_required(VERSION 3.20)
project(task_3_prog_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(task_3_prog_1 main.cpp)
target_link_libraries(task_3_prog_1 PRIVATE nlohmann_json::nlohmann_json)
