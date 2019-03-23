cmake_minimum_required(VERSION 3.4.1)

include_directories(
        ../../../code
        ../../../code/source
        ../../../code/include
        ../../../external/jsoncpp/include
        ../../../external/jsoncpp/src/lib_json
)

file(GLOB SOURCES 
        "*.cpp"
        "*.h")

file(GLOB JSONCPP 
        "../../../external/jsoncpp/src/lib_json/*.cpp"
        "../../../external/jsoncpp/include/*.h"
        )

add_compile_options(
        "-D ENABLE_PLAYFABSERVER_API"
        "-D ENABLE_PLAYFABADMIN_API"
)

add_library(XplatCppSdk
        STATIC
        ${SOURCES}
        ${JSONCPP}
        "../../../code/stdafx.cpp"
        "../../../code/stdafx.h"
        )

SET_TARGET_PROPERTIES(XplatCppSdk
        PROPERTIES COMPILE_FLAGS "-Wno-unused-value \
                                  -Wno-unused-parameter \
                                  -Wno-unknown-pragmas \
                                  -Wno-unused-variable \
                                  -Wno-deprecated-declarations \
                                  -Wno-reorder \
                                  -Wno-nonportable-include-path"
        )

target_link_libraries(
        XplatCppSdk
        jsoncpp_lib
)