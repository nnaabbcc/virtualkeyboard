
set(module_name widget_example)
add_executable(widget_example WIN32
    widget_example.cpp
)

target_link_libraries(${module_name} PRIVATE
    Qt5::Widgets
)

set_target_properties(${module_name} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/bin/"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/bin/"
    RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO "${CMAKE_BINARY_DIR}/bin/"
    RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL "${CMAKE_BINARY_DIR}/bin/"
    DEBUG_POSTFIX "_d"
)