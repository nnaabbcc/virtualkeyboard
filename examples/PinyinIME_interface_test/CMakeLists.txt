set(module_name PinyinIMEInterfaceTest)

add_executable(${module_name}
    PinyinIME_interface_test.cpp
)

target_link_libraries(${module_name} PRIVATE
    PinyinIME
    Qt::Core
)
