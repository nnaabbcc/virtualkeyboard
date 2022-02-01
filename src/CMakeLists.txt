set(module_name virtualkeyboardplugin)

add_library(${module_name} SHARED
    virtual_keyboard_plugin.cpp
    virtual_keyboard_context.cpp
)

target_link_libraries(${module_name} PRIVATE
    Qt5::Gui
    Qt5::Quick
)

target_include_directories(${module_name} PRIVATE
    ${Qt5Gui_PRIVATE_INCLUDE_DIRS}
)

set_target_properties(${module_name} PROPERTIES
    AUTOMOC ON
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/bin/platforminputcontexts"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/bin/platforminputcontexts"
    RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO "${CMAKE_BINARY_DIR}/bin/platforminputcontexts"
    RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL "${CMAKE_BINARY_DIR}/bin/platforminputcontexts"
    DEBUG_POSTFIX "_d"
)
