cmake_minimum_required(VERSION 3.4.1)

# Set code repository root
set(CODE_REPOSIORY_ROOT ${PROJECT_SOURCE_DIR}/..)
# Set final libraries output folder
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CODE_REPOSIORY_ROOT}/libs/XplatCppSdk/${ANDROID_ABI})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CODE_REPOSIORY_ROOT}/libs/XplatCppSdk/${ANDROID_ABI})

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

SET(JSONCPP_WITH_TESTS OFF CACHE BOOL "No tests")
SET(JSONCPP_WITH_POST_BUILD_UNITTEST OFF "Automatically run unit-tests as a post build step")
SET(JSONCPP_WITH_WARNING_AS_ERROR OFF "Force compilation to fail if a warning occurs")
SET(JSONCPP_WITH_PKGCONFIG_SUPPORT OFF "Generate and install .pc files")
SET(JSONCPP_WITH_CMAKE_PACKAGE OFF "Generate and install cmake package files")
SET(BUILD_SHARED_LIBS OFF "Build jsoncpp_lib as a shared library.")
SET(BUILD_STATIC_LIBS ON "Build jsoncpp_lib static library.")
add_subdirectory(../../../external/jsoncpp ${BINARY_DIR}/jsoncpp/lib_json)

add_compile_options(
        "-D ENABLE_PLAYFABSERVER_API"
        "-D ENABLE_PLAYFABADMIN_API"
)

add_library(XplatCppSdk
        SHARED
        ${SOURCES}
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
        jsoncpp_lib_static
)