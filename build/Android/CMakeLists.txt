# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

# Set code repository root
set(CODE_REPOSIORY_ROOT ${PROJECT_SOURCE_DIR}/../..)

# Set final static libraries output folder
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CODE_REPOSIORY_ROOT}/output/android/${ANDROID_ABI}/debug/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CODE_REPOSIORY_ROOT}/output/android/${ANDROID_ABI}/release/lib)

# Source dir point out where the sorce code located.
# /external
set(EXTERNAL_SOURCE_DIR ${CODE_REPOSIORY_ROOT}/external)
set(SOURCE_DIR ${CODE_REPOSIORY_ROOT}/code)

# BINARY_DIR is a temp folder used by cmake itself.
# Binary folder can be remove freely.
# See more details: https://cmake.org/cmake/help/v3.4/command/add_subdirectory.html
# /output/android/
set(BINARY_DIR ${CODE_REPOSIORY_ROOT}/build/Android/output/${ANDROID_ABI}/obj)

option(BUILD_SHARED_LIBS "Build shared jsoncpp" ON) #ON by default

add_subdirectory(../../../external/jsoncpp/src/lib_json ${BINARY_DIR}/jsoncpp/lib_json)