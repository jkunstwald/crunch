cmake_minimum_required(VERSION 3.8)
project(crunch)

option(CRNLIB_BUILD_DLL "Build Crunch as a shared library (DLL)" OFF)

file(GLOB_RECURSE SOURCES "crnlib/*.cpp" "crnlib/*.h" "inc/*.h")

if (CRNLIB_BUILD_DLL)
    add_library(crunch SHARED ${SOURCES})
    target_compile_definitions(crunch
        PRIVATE
            CRNLIB_DLL
        PUBLIC
            CRNLIB_BUILD_DLL
    )
else()
    add_library(crunch STATIC ${SOURCES})
endif()

target_include_directories(crunch
    PRIVATE
        "crnlib/"
    PUBLIC
        "inc/"
)
