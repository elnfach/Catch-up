cmake_minimum_required(VERSION 3.26)

set(DIRECTORY_NAME CatchUpEngine)

set(ENGINE_PUBLIC_INCLUDES
	include/application.h
	include/object.h
	include/script_behaviour.h
	include/component.h
	include/game_object.h
	include/components/transform.h
	include/components/drawable.h
	include/components/vector2f.h
	include/components/colliders/collider.h
)

set(ENGINE_PRIVATE_INCLUDES
	src/events/application_event.h
	src/events/ingame_event.h
	src/events/mouse_event.h
	src/events/key_event.h
	src/events/event.h
	src/renderer/renderer.h
	src/renderer/SDL/sdl_renderer.h
	src/window/window.h
	src/props.h
	src/window/SDL/sdl_window.h
)

set(ENGINE_PRIVATE_SOURCES
	src/application.cpp
	src/window/SDL/sdl_window.cpp
	src/renderer/SDL/sdl_renderer.cpp
	src/include/component.cpp
	src/include/script_behaviour.cpp
	src/include/game_object.cpp
	src/include/components/transform.cpp
	src/include/components/drawable.cpp
	src/include/object.cpp
	src/include/components/vector2f.cpp
	src/include/components/colliders/collider.cpp
)

set(ENGINE_ALL_SOURCES
	${ENGINE_PUBLIC_INCLUDES}
	${ENGINE_PRIVATE_INCLUDES}
	${ENGINE_PRIVATE_SOURCES}
)

add_library(${DIRECTORY_NAME} STATIC
	${ENGINE_ALL_SOURCES}
)

source_group(TREE  ${CMAKE_CURRENT_SOURCE_DIR} FILES
	${ENGINE_ALL_SOURCES}
)

target_include_directories(${DIRECTORY_NAME} PUBLIC include)
target_include_directories(${DIRECTORY_NAME} PRIVATE src)
target_compile_features(${DIRECTORY_NAME} PUBLIC cxx_std_20)

add_subdirectory(libs/SDL ${CMAKE_CURRENT_BINARY_DIR}/SDL)
target_link_libraries(${DIRECTORY_NAME} PRIVATE SDL3::SDL3)