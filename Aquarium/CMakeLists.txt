project( Aquarium )

file( GLOB HEADER_FILES *.hpp )
file( GLOB SOURCE_FILES *.cpp )

include_directories( ${CMAKE_SOURCE_DIR}/AquariumLib )
include_directories( ${CMAKE_SOURCE_DIR}/AquariumRenderer )
include_directories( ${CMAKE_SOURCE_DIR}/AquariumAppsCommon )

add_executable( ${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES} )
target_link_libraries( ${PROJECT_NAME}
	AquariumLib
	AquariumRenderer
	AquariumAppsCommon
)
