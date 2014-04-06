# Atena Game Engine
## Sprint 1
### Objectives
* Basic sprite manager
* Basic input manager
* Basic texture manager

## How to build
### Linux
```bash
cd build && cmake ..
make
./src/Atena
```

## Powered by
* **[SDL2](https://www.libsdl.org/)**

* **[SDL2_image](https://www.libsdl.org/projects/SDL_image/)**

* **[Box2D](http://box2d.org/)** *(Physics)*

* **[Jansson](http://www.digip.org/jansson/)** *(JSON parsing)*

#### Notes
* If it complains about libSDL2-2.0.so.1 not found, try running `sudo ldconfig`
