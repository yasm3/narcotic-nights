cmake_minimum_required (VERSION 3.15)

set(CMAKE_CXX_STANDARD 17)

project(NarcoticNights)

find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)
find_package(nlohmann_json REQUIRED)
find_package(SDL2_ttf CONFIG REQUIRED)

file(GLOB ENGINE_SOURCES src/engine/*.cpp)
file(GLOB GAME_SOURCES src/game/*.cpp)
file(GLOB IMGUI_SOURCES src/imgui/*.cpp)

include_directories(include/engine)
include_directories(include/game)
include_directories(include/imgui)

add_executable(narcoticnights ${ENGINE_SOURCES} ${GAME_SOURCES} ${IMGUI_SOURCES})

target_link_libraries(narcoticnights PRIVATE SDL2::SDL2 SDL2::SDL2main SDL2_image::SDL2_image nlohmann_json::nlohmann_json SDL2_ttf::SDL2_ttf)

# Copy data to build folder
file(COPY ${CMAKE_SOURCE_DIR}/data DESTINATION ${CMAKE_BINARY_DIR})
message(STATUS "Data copied to build folder")

find_package(Doxygen)
if(DOXYGEN_FOUND)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/doc/doxyfile ${CMAKE_CURRENT_BINARY_DIR}/doc/image.doxy @ONLY)

    add_custom_target(doc
        COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/doc/image.doxy
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "Doxygen doc generation"
        VERBATIM
    )
else()
    message(WARNING "Doxygen not installed")
endif()
