# Comment compiler

## Sur Linux

### Pré-réquis:
- git
- gcc
- ninja
- cmake
- SDL et SDL_image

Tout installer avec Ubuntu 22.04:

```
sudo apt update && sudo apt install build-essential ninja-build git cmake libsdl2-2.0-0 libsdl2-image-2.0-0 libsdl2-dev libsdl2-image-dev
```
 
1) Récupérez le code source

2) À la racine du projet:

```
cmake --preset linux-x64-debug
cmake --build --preset linux-debug
```

3) Le programme compilé se trouve dans ```build/linux-x64-debug```
