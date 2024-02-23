set(TEST_NAME allTests)
include(FetchContent)
set(SOURCE_FILES allTests.cpp)

add_executable(${TEST_NAME})
target_sources(${TEST_NAME} PRIVATE ${SOURCE_FILES})
target_link_libraries(${TEST_NAME} src)
set_property(TARGET ${TEST_NAME} PROPERTY CXX_STANDARD 11)
add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
