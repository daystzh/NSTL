set(BINARY ${CMAKE_PROJECT_NAME})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)
set(SOURCES ${SOURCES})
#add_library(${BINARY}_run ${SOURCES})
add_library(${BINARY}_lib STATIC ${SOURCES})
#add_library(tinySTL STATIC gcd.h)