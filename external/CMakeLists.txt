
project (ExternalLibrary)


add_library(${PROJECT_NAME} INTERFACE)

#RayLib
add_subdirectory(raylib)
target_link_libraries(${PROJECT_NAME} INTERFACE raylib)


