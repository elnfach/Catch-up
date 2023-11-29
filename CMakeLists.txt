cmake_minimum_required(VERSION 3.26)

project(CatchUp)

add_subdirectory(Engine)
add_subdirectory(Game)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT CatchUpEngine)