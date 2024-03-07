cmake_minimum_required (VERSION 3.8)

project ("narcotic-nights")

find_package(SDL2 REQUIRED)

add_executable(narcotic-nights
	src/main.cpp
	src/Game.cpp
	src/Logger.cpp
	src/Graphics.cpp
)

target_link_libraries(narcotic-nights SDL2::SDL2 SDL2::SDL2main)