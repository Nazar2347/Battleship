project (RenderLibrary)

add_library (${PROJECT_NAME} 
	./include/render.h
	./src/render.cpp
)

target_include_directories (${PROJECT_NAME} 
	PUBLIC ./include
	PRIVATE ./src)