project (UnitTests)

include (FetchContent)

file (GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS *.cpp) #gather all tests files

FetchContent_Declare(   
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.8.1  
)

FetchContent_MakeAvailable(Catch2)

add_executable(${PROJECT_NAME} ${TEST_SOURCES})


#connect Catch2 and raylib library
target_link_libraries(${PROJECT_NAME} 
    PRIVATE ExternalLibrary
    PRIVATE Catch2::Catch2WithMain
    PRIVATE CoreLibrary
)


list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)



enable_testing()
include(CTest)
include(Catch)
catch_discover_tests(${PROJECT_NAME})

add_custom_target(AllTests ALL
    COMMAND ${CMAKE_CTEST_COMMAND} ${CMAKE_BINARY_DIR}
    DEPENDS UnitTests
    COMMENT "Running tests"
) #allow program run unit tests during build proccess