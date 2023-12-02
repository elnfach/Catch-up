cmake_minimum_required(VERSION 3.26)

set(DIRECTORY_NAME CatchUpEngine)

set(ENGINE_PUBLIC_INCLUDES
	include/application.h
	include/object.h
	include/component.h
	include/game_object.h
	include/script_behaviour.h

	include/components/transform.h
	include/components/drawable/drawable.h
	include/components/drawable/rectangle_drawable.h
	include/components/vector2f.h
	include/components/colliders/collider.h
)

set(ENGINE_PRIVATE_INCLUDES
	src/Catch-up/props.h

	src/Catch-up/core/window.h

	src/Catch-up/include/scene.h

	src/Catch-up/events/application_event.h
	src/Catch-up/events/ingame_event.h
	src/Catch-up/events/mouse_event.h
	src/Catch-up/events/key_event.h
	src/Catch-up/events/event.h

	src/Catch-up/renderer/renderer.h
	src/Catch-up/renderer/renderer_api.h

	src/Platform/SDL/sdl_window.h
	src/Platform/SDL/sdl_renderer_api.h
)

set(ENGINE_PRIVATE_SOURCES
	src/Catch-up/core/application.cpp

	src/Catch-up/renderer/renderer.cpp
	src/Catch-up/renderer/renderer_api.cpp

	src/Catch-up/include/component.cpp
	src/Catch-up/include/scene.cpp
	src/Catch-up/include/components/vector2f.cpp

	src/Catch-up/include/components/transform.cpp
	src/Catch-up/include/components/drawable/drawable.cpp
	src/Catch-up/include/components/drawable/rectangle_drawable.cpp

	src/Catch-up/include/components/colliders/collider.cpp

	src/Catch-up/include/script_behaviour.cpp
	src/Catch-up/include/game_object.cpp
	src/Catch-up/include/object.cpp

	src/Platform/SDL/sdl_window.cpp
	src/Platform/SDL/sdl_renderer_api.cpp
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

add_subdirectory(libs/entt ${CMAKE_CURRENT_BINARY_DIR}/entt)
target_link_libraries(${DIRECTORY_NAME} PRIVATE EnTT::EnTT)

add_subdirectory(libs/SDL ${CMAKE_CURRENT_BINARY_DIR}/SDL)
target_link_libraries(${DIRECTORY_NAME} PRIVATE SDL3::SDL3)