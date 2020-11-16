cmake_minimum_required(VERSION 3.8)
project(crunch)

file(GLOB_RECURSE SOURCES "crnlib/*.cpp" "crnlib/*.h" "inc/*.h")

add_library(crunch STATIC ${SOURCES})
target_include_directories(crunch
	PRIVATE
        "crnlib/"
	PUBLIC
		"inc/"
)
