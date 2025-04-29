
project (ExternalLibrary)


FetchContent_Declare(   
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.8.1  
)

FetchContent_Declare(
	raylib
	GIT_REPOSITORY https://github.com/raysan5/raylib.git
	GIT_TAG 5.5

)
 set(FETCHCONTENT_BASE_DIR ${CMAKE_SOURCE_DIR}/external)

FetchContent_MakeAvailable(raylib)
FetchContent_MakeAvailable(Catch2) 




add_library(${PROJECT_NAME} INTERFACE)

#RayLib
target_link_libraries(${PROJECT_NAME} INTERFACE raylib)

#Cathc2
target_link_libraries(${PROJECT_NAME} INTERFACE Catch2::Catch2WithMain)