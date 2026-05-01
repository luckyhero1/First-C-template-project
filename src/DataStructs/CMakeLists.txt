add_library(PO_DataStructs
    dummy.cpp
)

target_include_directories(
    PO_DataStructs
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)
