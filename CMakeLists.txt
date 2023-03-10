cmake_minimum_required(VERSION 3.5)
project (ProjMedianOf3 VERSION 1.0.0 LANGUAGES CXX )

#=== CREATING COMPILING DATABASE ===#
# Currently CMake (since 2.8.5) supports generation of compilation databases
# for Unix Makefile builds (Ninja builds in the works) with the option
# CMAKE_EXPORT_COMPILE_COMMANDS.
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

#=== SETTING VARIABLES ===#
# Appending to existing flags the correct way (two methods)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic")
# string(APPEND CMAKE_CXX_FLAGS " -Wall -Werror")


#=== ADDING SUBDIRECTORIES ===#
# The add_subdirectory() command allows a project to bring another directory into the build. That
# directory must have its own CMakeLists.txt file which will be processed at the point where
# add_subdirectory() is called and a corresponding directory will be created for it in the project’s
set ( TEST_NAME "run_tests")
add_subdirectory(tests)    # This will ask the tests to be generated
# set ( APP_NAME "some_app")
# add_subdirectory(src)
