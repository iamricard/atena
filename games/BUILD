cc_binary(
  name = "simple",
  srcs = ["simple.cc"],
  copts = [
    "-I/usr/local/include/SDL2",
    "-I/usr/local/include",
    "-D_THREAD_SAFE",
    "-Wall",
    "-Wno-unused",
  ],
  linkopts = [
    "-L/usr/local/lib -lSDL2",
    "-L/usr/lib -lSDL2_image",
    "-ljansson",
  ],
  deps = [
    "//lib:core",
    "//lib:input",
    "//lib:textures",
  ],
)
