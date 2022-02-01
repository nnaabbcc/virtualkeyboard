
set(module_name quick_example)
add_executable(quick_example WIN32
    quick_example.cpp
    quick_example.qrc
)

target_link_libraries(${module_name} PRIVATE
    Qt5::Quick
)

set_target_properties(${module_name} PROPERTIES
    AUTORCC ON
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/bin/"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/bin/"
    RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO "${CMAKE_BINARY_DIR}/bin/"
    RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL "${CMAKE_BINARY_DIR}/bin/"
    DEBUG_POSTFIX "_d"
)