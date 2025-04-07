# Narcotic Nights

First true project with C++: 2D roguelite game with top-view with self-built C++/SDL2 game engine.

# Build project

## GNU/Linux

**Requirements:** 
- gcc / g++
- cmake and ninja
- Libraries: ``sdl2`` ``sdl2_image`` ``SDL2_mixer`` ``sdl2_ttf`` ``nlohmann-json``

For Ubuntu 24.04 : ``sudo apt update && sudo apt install -y gcc g++ cmake ninja-build libsdl2-dev libsdl2-image-dev libsdl2-mixer-dev libsdl2-ttf-dev nlohmann-json3-dev``

1) At root of project, let's configure with ``cmake --preset linux-x64-debug`` (or linux-x64-release for release mode)
2) Build : ``cd build/linux-x64-debug && ninja all`` (or release)

## Windows
- Visual Studio with C++ module installed
- vcpkg
  
1) Open with Visual Studio and configure with one preset
2) Waits during VCPKG installs requirements
3) Build and run

## Doxygen documentations

- ``ninja doc`` from ``build`` folder
