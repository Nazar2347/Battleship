
project (ExternalLibrary)

include (FetchContent)



FetchContent_Declare(
	raylib
	GIT_REPOSITORY https://github.com/raysan5/raylib.git
	GIT_TAG 5.5
)

 set(FETCHCONTENT_BASE_DIR ${CMAKE_SOURCE_DIR}/external)

FetchContent_MakeAvailable(raylib)


add_library(${PROJECT_NAME} INTERFACE)

#RayLib
target_link_libraries(${PROJECT_NAME} INTERFACE raylib)

