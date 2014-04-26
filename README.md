[![Build Status](https://travis-ci.org/rcsole/Atena.svg?branch=master)](https://travis-ci.org/rcsole/Atena)

# Atena Game Engine
## Sprint 2
### Objectives
* Game State Machine
* Extend GameObjectFactory
* Input keys generator

## How to build
### Linux
#### Dependencies
* CMake
* SDL2
* SDL2_image
* Box2D
* Jansson

*You can follow the steps in .travis.yml to install the dependencies*

#### CLI Make
```bash
mkdir build
cd build && cmake ..
make
./src/Atena
```

#### Build for Code::Blocks
```bash
mkdir build
cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
codeblocks Atena.cbp
```

## Powered by
* **[SDL2](https://www.libsdl.org/)**

* **[SDL2_image](https://www.libsdl.org/projects/SDL_image/)**

* **[Box2D](http://box2d.org/)** *(Physics)*

* **[Jansson](http://www.digip.org/jansson/)** *(JSON parsing)*

#### Notes
* If it complains about libSDL2-2.0.so.1 not found, try running `sudo ldconfig`
