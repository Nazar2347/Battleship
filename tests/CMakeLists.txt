project (UnitTests)

add_executable(${PROJECT_NAME} ./tests.cpp)


#connect Catch2 and raylib library
target_link_libraries(${PROJECT_NAME} PRIVATE ExternalLibrary
    PRIVATE Catch2::Catch2WithMain)

target_include_directories(${PROJECT_NAME} PUBLIC . 
    PRIVATE ${CMAKE_SOURCE_DIR}/external/Catch2/src/catch2)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/external/Catch2/extras")
include(CTest)
include(Catch)

catch_discover_tests(${PROJECT_NAME})

#allow program run unit tests during build proccess
add_custom_target(AllTests ALL
    COMMAND ${CMAKE_CTEST_COMMAND} ${CMAKE_BINARY_DIR}
    DEPENDS UnitTests
    COMMENT "Running tests"
    )
    enable_testing()