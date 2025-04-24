project (RenderLibrary)

file (GLOB_RECURSE RENDER_HEADERS CONFIGURE_DEPENDS "./include/*.h")
file (GLOB_RECURSE RENDER_SOURCE CONFIGURE_DEPENDS "./src/*.cpp")

add_library (${PROJECT_NAME} 
	${RENDER_HEADERS}
	${RENDER_SOURCE}
)

target_include_directories (${PROJECT_NAME} 
	PUBLIC ./include
	PRIVATE ./src)

target_link_libraries(${PROJECT_NAME} PUBLIC ExternalLibrary)
target_link_libraries(${PROJECT_NAME} PRIVATE CoreLibrary)