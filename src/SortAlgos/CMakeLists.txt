add_library(PO_SortAlgos
    BubbleSort.cpp
)

target_include_directories(
    PO_SortAlgos
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)