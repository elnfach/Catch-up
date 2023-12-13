cmake_minimum_required(VERSION 3.26)

set(DIRECTORY_NAME CatchUpGame)

set(CATCH_UP_INCLUDES
	include/wolf/wolf.h
	include/body.h

	include/wall/wall.h

	include/hare/hare.h

	include/entity/entity.h
	include/entity/entity_type.h

	include/event/event_manager.h

	include/catch_up.h

	include/utils/RayCast.h
)

set(CATCH_UP_SOURCES
	src/scripts/entity/entity.cpp

	src/scripts/wolf/wolf.cpp
	src/scripts/body/body.cpp

	src/scripts/hare/hare.cpp

	src/scripts/wall/wall.cpp

	src/scripts/catch_up.cpp

	src/scripts/event/event_manager.cpp

	src/utils/RayCast.cpp

	src/main.cpp
)

set(CATCH_UP_ALL_SOURCES
	${CATCH_UP_INCLUDES}
	${CATCH_UP_SOURCES}
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES
	${CATCH_UP_ALL_SOURCES}
)
include_directories(include)

add_executable(${DIRECTORY_NAME}
	${CATCH_UP_ALL_SOURCES}
)

target_link_libraries(${DIRECTORY_NAME} CatchUpEngine EnTT::EnTT)
set_target_properties(${DIRECTORY_NAME} PROPERTIES RUNTIME_OUTPUT_DERICTORIES ${CMAKE_BINARY_DIR}/bin/)