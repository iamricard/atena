cxx_binary(
  name = 'atena',
  srcs = [
    'src/main.cpp'
  ],
  deps = [
    ':core',
    ':sprite',
    ':textures',
    ':utils'
  ]
)

cxx_library(
  name = 'core',
  srcs = glob(['src/Core/*.cpp']),
  exported_headers = glob(['src/Core/*.h'])
)

cxx_library(
  name = 'sprite',
  srcs = glob(['src/Sprite/*.cpp']),
  exported_headers = glob(['src/Sprite/Sprite.h'])
)

cxx_library(
  name = 'textures',
  srcs = glob(['src/Textures/*.cpp']),
  exported_headers = glob(['src/Textures/*.h'])
)

cxx_library(
  name = 'utils',
  exported_headers = glob(['src/Utils/*.h'])
)
