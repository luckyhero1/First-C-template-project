cmake_minimum_required(VERSION 3.20)
project(CppTemplate_Sort_and_Struct_Visualisation)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# Subdirectory einbinden
add_subdirectory(src)
add_subdirectory(docs)