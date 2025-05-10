cmake_minimum_required(VERSION 3.30)
project (Battleship)

include(FetchContent)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(./source/app)
add_subdirectory(./source/core)
add_subdirectory(./source/render)
add_subdirectory(./external)
add_subdirectory(./tests)

install(TARGETS MainExecutable)

set (CPACK_PACKAGE_NAME "BattleShip")
set (CPACK_PACKAGE_VENDOR "Nazar2347")


set(CPACK_SOURCE_IGNORE_FILES
    "/build/"
    "/\\\\.git/"
    "/\\\\.vs/"
    "/\\\\.vscode/"
)
include (CPack)