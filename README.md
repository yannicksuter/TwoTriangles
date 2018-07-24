I want to explore how raymarching and other shader-selfcontained drawing technics work. This application is a container to experiment with everything I stumble on.

wherewasi (v.1)
---------------
- finally, start exploring marching rays....

build
-----
```sh
mkdir build
cd build
cmake ..
make
./twotriangles
```

dependencies
------------
this repository uses submodules. either checkout with --recursive option or add dependencies later using:

```sh
git submodule init
git submodule update
```

- glew: https://github.com/Perlmint/glew-cmake
- glfw: https://github.com/glfw/glfw
- glm: https://github.com/g-truc/glm

reads
-----
- http://antongerdelan.net/opengl/hellotriangle.html
- https://github.com/ArthurSonzogni/OpenGL_CMake_Skeleton
