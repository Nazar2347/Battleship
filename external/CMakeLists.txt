
project (ExternalLibrary)


add_library(${PROJECT_NAME} INTERFACE)

#RayLib
add_subdirectory(raylib)
target_link_libraries(${PROJECT_NAME} INTERFACE raylib)

#Cathc2
add_subdirectory(Catch2)
target_link_libraries(${PROJECT_NAME} INTERFACE Catch2::Catch2WithMain)