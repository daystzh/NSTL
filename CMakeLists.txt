cmake_minimum_required(VERSION 3.24)
project(tinySTL)
enable_testing()
set(CMAKE_CXX_STANDARD 14)
option(ENABLE_UNIT_TESTS "Enable unit tests" OFF)
message(STATUS "Enable testing: ${ENABLE_UNIT_TESTS}")

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        e38ef3be887afc0089005e394c5001002e313960
        OVERRIDE_FIND_PACKAGE
)

FetchContent_Populate(googletest)
add_subdirectory(${googletest_SOURCE_DIR})


FetchContent_Declare(
        benchmark
        GIT_REPOSITORY https://github.com/google/benchmark.git
        GIT_TAG        da652a748675b679947710117329e9f77f374f2d
        OVERRIDE_FIND_PACKAGE
)

FetchContent_Populate(benchmark)
add_subdirectory(${benchmark_SOURCE_DIR})

OPTION(ENABLE_ASAN "Enable build with address sanitizer" OFF)
IF (ENABLE_ASAN)
    message("Enable build with address sanitizer")
    SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fno-omit-frame-pointer -fsanitize=address")
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-omit-frame-pointer -fsanitize=address")
    SET(CMAKE_LINKER_FLAGS_DEBUG  "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
ENDIF()

include_directories(src)

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(benchmark)
