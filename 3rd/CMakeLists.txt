
add_library(PinyinIME
    PinyinIME/share/pinyinime.cpp
    PinyinIME/share/matrixsearch.cpp
    PinyinIME/share/dictlist.cpp
    PinyinIME/share/dicttrie.cpp
    PinyinIME/share/spellingtrie.cpp
    PinyinIME/share/lpicache.cpp
    PinyinIME/share/utf16char.cpp
    PinyinIME/share/searchutility.cpp
    PinyinIME/share/splparser.cpp
    PinyinIME/share/mystdlib.cpp
    PinyinIME/share/ngram.cpp
    PinyinIME/share/userdict.cpp
)
if (WIN32)
    target_compile_definitions(PinyinIME PRIVATE
        _CRT_SECURE_NO_WARNINGS
        _CRT_NONSTDC_NO_DEPRECATE
    )
endif()

target_include_directories(PinyinIME PUBLIC
    PinyinIME/include
)

if (NOT WIN32)
    target_link_libraries(PinyinIME PRIVATE
        pthread)
endif()

add_executable(PinyinIMEDictBuilder
    PinyinIME/command/pinyinime_dictbuilder.cpp
    PinyinIME/share/dicttrie.cpp
    PinyinIME/share/dictlist.cpp
    PinyinIME/share/spellingtrie.cpp
    PinyinIME/share/spellingtable.cpp
    PinyinIME/share/splparser.cpp
    PinyinIME/share/searchutility.cpp
    PinyinIME/share/ngram.cpp
    PinyinIME/share/mystdlib.cpp
    PinyinIME/share/lpicache.cpp
    PinyinIME/share/dictbuilder.cpp
    PinyinIME/share/utf16char.cpp
    PinyinIME/share/utf16reader.cpp
)

target_compile_definitions(PinyinIMEDictBuilder PRIVATE
    ___BUILD_MODEL___
)

if (WIN32)
    target_compile_definitions(PinyinIMEDictBuilder PRIVATE
        _CRT_SECURE_NO_WARNINGS
        _CRT_NONSTDC_NO_DEPRECATE
    )
endif()

set_target_properties(PinyinIMEDictBuilder PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/"
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/bin/"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/bin/"
    RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO "${CMAKE_BINARY_DIR}/bin/"
    RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL "${CMAKE_BINARY_DIR}/bin/"
    DEBUG_POSTFIX "_d"
)
