project(MainExecutable)

add_executable(${PROJECT_NAME} 
	./main.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC 
	./)



target_link_libraries (${PROJECT_NAME} 
	PRIVATE CoreLibrary
	PRIVATE RenderLibrary
	PRIVATE ExternalLibrary)