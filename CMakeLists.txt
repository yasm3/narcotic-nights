cmake_minimum_required (VERSION 3.15)

set(CMAKE_CXX_STANDARD 17)

project(NarcoticNights)

find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)

file(GLOB ENGINE_SOURCES src/engine/*.cpp)
file(GLOB GAME_SOURCES src/game/*.cpp)

include_directories(include/engine)
include_directories(include/game)

add_executable(narcoticnights ${ENGINE_SOURCES} ${GAME_SOURCES})

target_link_libraries(narcoticnights PRIVATE SDL2::SDL2 SDL2::SDL2main SDL2_image::SDL2_image)
