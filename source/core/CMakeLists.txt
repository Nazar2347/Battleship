project (CoreLibrary)

file (GLOB_RECURSE CORE_HEADERS CONFIGURE_DEPENDS "./include/*.h")
file (GLOB_RECURSE CORE_SOURCE CONFIGURE_DEPENDS "./src/*.cpp")

add_library(${PROJECT_NAME} 
		${CORE_HEADERS} 
		${CORE_SOURCE}	
		)
target_include_directories(${PROJECT_NAME}
		PUBLIC ./include
		PRIVATE ./src	
)
target_link_libraries(${PROJECT_NAME} PUBLIC RenderLibrary)