add_subdirectory(DataStructs)
add_subdirectory(SortAlgos)

add_executable(${PROJECT_NAME} main.cpp)

# Dadurch funktionieren meine includes (für den Compiler)
target_include_directories(
    ${PROJECT_NAME}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/DataStructs
    ${CMAKE_CURRENT_SOURCE_DIR}/SortAlgos
)

# Dadurch wird der Code gefunden (für den Linker)
target_link_libraries(
    ${PROJECT_NAME}
    PO_DataStructs
    PO_SortAlgos
)