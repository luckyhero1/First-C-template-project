add_subdirectory(DataStructs)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(
    ${PROJECT_NAME}
    PRIVATE
    DataStructs
)

target_link_libraries(${PROJECT_NAME} PO_DataStructs)
