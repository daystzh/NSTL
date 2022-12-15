set(BINARY ${CMAKE_PROJECT_NAME}_benchmark)

file(GLOB_RECURSE BENCHMARK_SOURCES LIST_DIRECTORIES false *.h *.cpp)

set(SOURCES ${BENCHMARK_SOURCES})

add_executable(${BINARY} ${BENCHMARK_SOURCES})

target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib benchmark)