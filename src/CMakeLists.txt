# Author: Ricard Sole
# Date: 30 March 2014

# Add subdirectories
add_subdirectory(Core)
add_subdirectory(Utils)
add_subdirectory(Textures)
add_subdirectory(Examples)

# Set all core libs to ${CORE_LIBS}
set(CORE_LIBS
    CORE
    TEXMGR
    SPRITE
    UTILS

    jansson
    Box2D
    SDL2
    SDL2_image
)

# GLOB all files in current directory
file(GLOB SRCS *.cpp *.h)

add_executable(Atena ${SRCS})
target_link_libraries(Atena ${CORE_LIBS})
