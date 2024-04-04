cmake_minimum_required (VERSION 3.15)

set(CMAKE_CXX_STANDARD 17)

project(NarcoticNights)

find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)
find_package(nlohmann_json REQUIRED)

file(GLOB ENGINE_SOURCES src/engine/*.cpp)
file(GLOB GAME_SOURCES src/game/*.cpp)
file(GLOB IMGUI_SOURCES src/imgui/*.cpp)

include_directories(include/engine)
include_directories(include/game)
include_directories(include/imgui)

add_executable(narcoticnights ${ENGINE_SOURCES} ${GAME_SOURCES} ${IMGUI_SOURCES})

target_link_libraries(narcoticnights PRIVATE SDL2::SDL2 SDL2::SDL2main SDL2_image::SDL2_image nlohmann_json::nlohmann_json)

# Copy assets to build folder
file(COPY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR})
message(STATUS "Assets copied to build folder")