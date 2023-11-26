cmake_minimum_required(VERSION 3.27)

set(DIRECTORY_NAME CatchUpGame)

add_executable(${DIRECTORY_NAME}
	src/main.cpp
)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /subsystem:windows")
target_link_libraries(${DIRECTORY_NAME} CatchUpEngine)
set_target_properties(${DIRECTORY_NAME} PROPERTIES RUNTIME_OUTPUT_DERICTORIES ${CMAKE_BINARY_DIR}/bin/)