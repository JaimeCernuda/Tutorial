cmake_minimum_required(VERSION 3.10)
project(Tutorial)

set(CMAKE_CXX_STANDARD 17)

#------------------------------------------------------------------------------
# Global variables
#------------------------------------------------------------------------------
set(ROOT ${CMAKE_CURRENT_SOURCE_DIR})

#------------------------------------------------------------------------------
# Options
#------------------------------------------------------------------------------
option(BUILD_SHARED_LIBS "Build shared libraries (.dll/.so) instead of static ones (.lib/.a)" ON)
option(ENABLE_COVERAGE "Enable coverage calaculation" OFF)

#------------------------------------------------------------------------------
# Optimization
#------------------------------------------------------------------------------
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(WARNING "Building in debug mode")
    set(CMAKE_CXX_FLAGS "-g -O0 ${CMAKE_CXX_FLAGS}")
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    message(STATUS "Building in release mode")
    set(CMAKE_CXX_FLAGS "-g -O3 ${CMAKE_CXX_FLAGS}")
endif()

#------------------------------------------------------------------------------
# External libraries
#------------------------------------------------------------------------------
## Hermes
#find_package(Hermes CONFIG REQUIRED)
#message(STATUS "found Hermes at ${Hermes_DIR}")
#
## COEUS
#find_package(ADIOS2 REQUIRED)
#message(STATUS "Found Adios2")

# MPI
find_package(MPI REQUIRED COMPONENTS C CXX)

#Gtest
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        f8d7d77c06936315286eb55f8de22cd23c188571
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
#------------------------------------------------------------------------------
# Code Coverage
#------------------------------------------------------------------------------
if(ENABLE_COVERAGE)
    set(COVERAGE_FLAGS "-fprofile-arcs -ftest-coverage" CACHE STRING
            "Flags to the coverage program to perform coverage inspection")
    mark_as_advanced(COVERAGE_FLAGS)

    macro(set_coverage_flags target)
        set_target_properties(${target}
                PROPERTIES
                COMPILE_FLAGS ${COVERAGE_FLAGS}
                LINK_FLAGS ${COVERAGE_FLAGS}
                )
    endmacro()
endif()

#------------------------------------------------------------------------------
# Build
#------------------------------------------------------------------------------
add_subdirectory(src)

#------------------------------------------------------------------------------
# Build tests + benchmarks
#------------------------------------------------------------------------------
set(TEST_MAIN ${PROJECT_SOURCE_DIR}/test)
enable_testing()
add_subdirectory(test)
