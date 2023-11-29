cmake_minimum_required(VERSION 3.26)

set(DIRECTORY_NAME CatchUpGame)

add_executable(${DIRECTORY_NAME}
	src/entity/Wolf.h
	src/entity/Wall.h
	src/entity/Hare.h
	src/entity/BoxCollider.h
	src/entity/entity.h
	src/entity/entity_type.h
	src/entity/entity.cpp
	src/main.cpp
)

target_link_libraries(${DIRECTORY_NAME} CatchUpEngine)
set_target_properties(${DIRECTORY_NAME} PROPERTIES RUNTIME_OUTPUT_DERICTORIES ${CMAKE_BINARY_DIR}/bin/)