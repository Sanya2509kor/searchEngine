cmake_minimum_required(VERSION 3.30)
project(search_engine)

set(CMAKE_CXX_STANDARD 23)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)

add_executable(search_engine main.cpp
        ConverterJSON.cpp
        ConverterJSON.h
        InvertedIndex.cpp
        InvertedIndex.h
        SearchServer.cpp
        SearchServer.h)

target_link_libraries(search_engine PRIVATE nlohmann_json::nlohmann_json)

add_subdirectory(test)



